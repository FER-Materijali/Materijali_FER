package util.matrix;

public class ForwardSubstitution implements Substitution {

    @Override
    public Matrix substitute(Matrix l, Matrix b) {
        check(l, b);
        Matrix m = new Matrix(new double[b.rows()][1]);

        for (int i = 0; i < b.rows(); i++) {
            double sum = b.get(i, 0);
            for (int j = 0; j < i; j++) {
                sum -= l.get(i, j) * m.get(j, 0);
            }
            m.set(i, 0, sum);
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
