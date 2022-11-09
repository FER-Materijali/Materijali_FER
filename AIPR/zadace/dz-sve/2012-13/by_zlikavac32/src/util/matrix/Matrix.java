package util.matrix;

import java.text.DecimalFormat;
import java.util.Arrays;
import util.equation.Solver;

public class Matrix {

    private double[][] data;

    private static DecimalFormat format = new DecimalFormat("0.000000");

    private int rows;

    private int cols;

    private static double eps = 1e-6;

    public Matrix(int rows, int cols) {
        data = new double[rows][cols];
        this.rows = rows;
        this.cols = cols;
    }

    public int rows() {
        return rows;
    }

    public int cols() {
        return cols;
    }

    public Matrix(double[][] in) {
        if (in.length == 0) { return; }
        int colsL = in[0].length;
        data = new double[in.length][colsL];
        rows = in.length;
        this.cols = colsL;

        for (int i = 0; i < data.length; i++) {
            data[i] = Arrays.copyOf(in[i], colsL);
        }
    }

    /**
     *
     * @param i
     * @param j
     * @return
     */
    public Matrix swapRow(int i, int j) {
        double[] temp = data[i];
        data[i] = data[j];
        data[j] = temp;
        return this;
    }

    public Matrix copy() {
        return new Matrix(data);
    }

    /**
     * Adds matrix passed as param to current matrix and changes original matrix.
     * @param m
     * @return
     */
    public Matrix add(Matrix m) {
        checkSameDimensions(m);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] += m.data[i][j];
            }
        }
        return this;
    }

    public boolean isSquareMatrix() { return cols == rows; }

    /**
     * Subtracts matrix passed as param from current matrix and changes original matrix.
     * @param m
     * @return
     */
    public Matrix sub(Matrix m) {
        checkSameDimensions(m);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] -= m.data[i][j];
            }
        }
        return this;
    }

    /**
     * Transposes this matrix and changes original matrix.
     * @return
     */
    public Matrix transpose() {
        double[][] temp = new double[cols][rows];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                temp[j][i] = data[i][j];
            }
        }
        rows ^= cols;
        cols ^= rows;
        rows ^= cols;
        data = temp;
        return this;
    }

    /**
     * Multiplies this matrix with scalar value s and changes original matrix.
     * @param s
     * @return
     */
    public Matrix mult(double s) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] *= s;
            }
        }
        return this;
    }

    /**
     * Multiplies this matrix with matrix m and changes original matrix.
     * @param m
     * @return
     */
    public Matrix mult(Matrix m) {
        if (cols != m.rows) {
            throw new MatrixDimensionException("First columns and second rows must be equal");
        }
        double[][] temp = new double[rows][m.cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                double sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += data[i][k] * m.data[k][j];
                }
                temp[i][j] = sum;
            }
        }
        data = temp;
        cols = m.cols;
        return this;
    }

    private void checkSameDimensions(Matrix m) {
        if (m.rows != rows || m.cols != cols)  {
            throw new MatrixDimensionException("First and second matrix must be equal");
        }
    }

    public void set(int i, int j, double val) {
        data[i][j] = val;
    }

    public double get(int i, int j) {
        return data[i][j];
    }
    
    public double[] getRow(int i) {
        return Arrays.copyOf(data[i], cols);
    }
    
    public double[] getCol(int j) {
        double[] c = new double[rows];
        for (int i = 0; i < rows; i++) {
            c[i] = data[i][j];
        }
        return c;
    }
    
    public Matrix inverse() {
        if (!isSquareMatrix()) {
            throw new MatrixDimensionException("Matrix must be square matrix");
        }
        return Solver.LUP.solve(this, unitary(rows));
    }
    
    public static Matrix unitary(int dimension) {
        double[][] m = new double[dimension][dimension];
        for (int i = 0; i < dimension; i++) {
            m[i][i] = 1;
            for (int j = i + 1; j < dimension; j++) {
                m[i][j] = 0;
                m[j][i] = 0;
            }
        }
        return new Matrix(m);
    }
    
    @Override
    public String toString() {
        if (data == null) { return ""; }
        StringBuilder b = new StringBuilder(1000);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                b.append(format.format(data[i][j]));
                if (j + 1 < cols) {
                    b.append(" ");
                }
            }
            if (i + 1 < rows) { b.append("\n"); }
        }
        return b.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Matrix)) { return false; }
        if (this == obj) { return true; }
        Matrix o = (Matrix) obj;
        if (rows != o.rows && cols != o.cols) { return false; }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (Math.abs(data[i][j] - o.data[i][j]) > eps) { return false; }
            }
        }

        return true;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 71 * hash + Arrays.deepHashCode(data);
        return hash;
    }

}
