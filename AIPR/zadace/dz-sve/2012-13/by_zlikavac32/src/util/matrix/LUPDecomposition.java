package util.matrix;

public class LUPDecomposition implements Decomposition {

    private static double eps = 1e-9;

    private Matrix p;

    public void decompose(Matrix m) {
        check(m);
        p = new Matrix(m.rows(), m.rows());
        for (int i = 0; i < m.rows(); i++) {
            p.set(i, i, 1);
            for (int j = i + 1; j < m.rows(); j++) {
                p.set(i, j, 0);
                p.set(j, i, 0);
            }
        }
        for (int i = 0; i < m.rows() - 1; i++) {
            int max = i;
            for (int j = i + 1; j < m.rows(); j++) {
                if (Math.abs(m.get(max, i)) < Math.abs(m.get(j, i))) {
                    max = j;
                }
            }
            if (max != i) {
                m.swapRow(i, max);
                p.swapRow(i, max);
            }
            if (Math.abs(m.get(i, i)) < eps) {
                throw new ZeroPivotException();
            }
            for (int j = i + 1; j < m.rows(); j++) {
                m.set(j, i, m.get(j, i) / m.get(i, i));
                for (int k = i + 1; k < m.rows(); k++) {
                    m.set(j, k, m.get(j, k) - m.get(i, k) * m.get(j, i));
                }
            }
        }
    }

    public Matrix getPermutationMatrix() { return p.copy(); }

    public void check(Matrix m) {
        if (!m.isSquareMatrix()) {
            throw new MatrixDimensionException("Matrix must be square matrix");
        }
    }
}
