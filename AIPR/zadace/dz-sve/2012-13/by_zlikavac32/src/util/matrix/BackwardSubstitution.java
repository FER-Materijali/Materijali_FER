package util.matrix;

public class BackwardSubstitution implements Substitution {

    @Override
    public Matrix substitute(Matrix p, Matrix y) {
        check(p, y);
        Matrix m = new Matrix(new double[p.rows()][1]);

        for (int i = p.rows() - 1; i >= 0; i--) {
            double sum = y.get(i, 0);
            for (int j = p.rows() - 1; j > i; j--) {
                sum -= p.get(i, j) * m.get(j, 0);
            }
            m.set(i, 0, sum / p.get(i, i));
        }

        return m;
    }

    private void check(Matrix f, Matrix s) {
        if (f.rows() != s.rows()) {
            throw new MatrixDimensionException("Matrices must have same number of rows");
        }
        if (!f.isSquareMatrix()) {
            throw new MatrixDimensionException("Matrix must be square matrix");
        }
    }

}
