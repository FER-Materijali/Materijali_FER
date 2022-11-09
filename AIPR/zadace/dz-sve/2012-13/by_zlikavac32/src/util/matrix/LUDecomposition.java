package util.matrix;

public class LUDecomposition implements Decomposition {

    private static double eps = 1e-9;

    @Override
    public void decompose(Matrix m) {
        check(m);
        for (int i = 0; i < m.rows() - 1; i++) {
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

    public void check(Matrix m) {
        if (!m.isSquareMatrix()) {
            throw new MatrixDimensionException("Matrix must be square matrix");
        }
    }
}
