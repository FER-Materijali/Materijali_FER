package util.matrix;

import junit.framework.Assert;
import org.junit.Test;

public class TMatrix {

    private static final double eps = 1e-9;

    @Test
    public void rowsAndCols() {
        Matrix m = new Matrix(6, 7);
        Assert.assertEquals(m.rows(), 6);
        Assert.assertEquals(m.cols(), 7);

        m = new Matrix(new double[6][7]);
        Assert.assertEquals(m.rows(), 6);
        Assert.assertEquals(m.cols(), 7);
    }

    @Test
    public void isSquare() {
        Matrix m = new Matrix(6, 7);
        Assert.assertFalse(m.isSquareMatrix());

        m = new Matrix(new double[6][6]);
        Assert.assertTrue(m.isSquareMatrix());
    }

    @Test
    public void string() {
        Matrix m = new Matrix(new double[][] {
            {1, 2}, {2, 3}
        });
        Assert.assertEquals("1,000000 2,000000\n2,000000 3,000000", m.toString());
    }

    @Test
    public void isEqual() {
        Assert.assertFalse(new Matrix(1, 2).equals(null));
        Assert.assertFalse(new Matrix(1, 2).equals(new Matrix(2, 1)));
        Matrix m = new Matrix(1, 2);
        m.equals(m);
        m = new Matrix(new double[][] {
            {1, 2}, {2, 3}
        });
        Assert.assertTrue(m.equals(new Matrix(new double[][] {
            {1, 2}, {2, 3}
        })));
        Assert.assertTrue(m.equals(new Matrix(new double[][] {
            {1, 2.0000000009}, {2, 3}
        })));
        Assert.assertFalse(m.equals(new Matrix(new double[][]{
                {1, 2.000000001}, {2, 3}
        })));
    }

    @Test
    public void setAndGet() {
        Matrix m = new Matrix(6, 7);
        m.set(0, 2, 3.4);
        Assert.assertEquals(3.4, m.get(0, 2), eps);
    }

    @Test
    public void add() {
        Matrix m = new Matrix(new double[][] {
            {1, 2, 3},
            {5, 6, 7}
        });
        Assert.assertTrue(new Matrix(new double[][]{
                {2, 4, 6},
                {10, 12, 14}
        }).equals(m.add(m)));

        Assert.assertFalse(new Matrix(new double[][]{
                {2, 4, 6},
                {10, 12, 15}
        }).equals(m.add(m)));
    }

    @Test(expected = MatrixDimensionException.class)
    public void addFail() {
        Matrix m = new Matrix(new double[][] {
                {1, 2, 3},
                {5, 6, 7}
        });
        m.add(new Matrix(new double[][]{
                {2, 4, 6, 7},
                {10, 12, 14, 12}
        }));
    }

    @Test
    public void sub() {
        Matrix m = new Matrix(new double[][] {
                {1, 2, 3},
                {5, 6, 7}
        });
        Assert.assertTrue(new Matrix(new double[][] {
                {0, 0, 0},
                {0, 0, 0}
        }).equals(m.sub(m)));

        Assert.assertFalse(new Matrix(new double[][]{
                {2, 4, 6},
                {10, 12, 15}
        }).equals(m.sub(m)));
    }

    @Test(expected = MatrixDimensionException.class)
    public void subFail() {
        Matrix m = new Matrix(new double[][] {
                {1, 2, 3},
                {5, 6, 7}
        });
        m.sub(new Matrix(new double[][]{
                {2, 4, 6, 7},
                {10, 12, 14, 12}
        }));
    }

    @Test
    public void multConst() {
        Matrix m = new Matrix(new double[][] {
                {1, 2, 3},
                {5, 6, 7}
        });
        Assert.assertTrue(new Matrix(new double[][] {
                {0.5, 1, 1.5},
                {2.5, 3, 3.5}
        }).equals(m.mult(.5)));

        Assert.assertFalse(new Matrix(new double[][]{
                {2, 4, 6},
                {10, 12, 15}
        }).equals(m.mult(.5)));
    }

    @Test
    public void transpose() {
        Matrix m = new Matrix(new double[][] {
                {1, 2, 3},
                {5, 6, 7}
        });

        Assert.assertEquals(2, m.rows());
        Assert.assertEquals(3, m.cols());

        Assert.assertTrue(new Matrix(new double[][] {
            {1, 5},
            {2, 6},
            {3, 7}
        }).equals(m.transpose()));

        Assert.assertEquals(3, m.rows());
        Assert.assertEquals(2, m.cols());
    }

    @Test
    public void copy() {
        Matrix m = new Matrix(new double[][] {
                {1, 2, 3},
                {5, 6, 7}
        });

        Assert.assertTrue(m.copy().equals(m));
    }

    @Test
    public void swapRows() {
        Matrix m = new Matrix(new double[][] {
                {1, 2, 3},
                {5, 6, 7}
        });

        Assert.assertTrue(new Matrix(new double[][]{
                {5, 6, 7},
                {1, 2, 3}
        }).equals(m.swapRow(0, 1)));
    }

    @Test(expected = MatrixDimensionException.class)
    public void mulFail() {
        Matrix m = new Matrix(new double[][] {
                {1, 2, 3},
                {5, 6, 7}
        });

        m.mult(m);
    }

    @Test
    public void mult() {
        Matrix m = new Matrix(new double[][] {
                {1, 2, 3},
                {5, 6, 7},
                {9, 10, 11}
        });
        Assert.assertTrue(new Matrix(new double[][]{
                {38, 44, 50},
                {98, 116, 134},
                {158, 188, 218}
        }).equals(m.mult(m)));

        Assert.assertTrue(new Matrix(new double[][]{
                {9, 12, 15},
                {14, 19, 24},
                {19, 26, 33}
        }).equals(new Matrix(new double[][]{
                {1, 2},
                {2, 3},
                {3, 4}
        }).mult(new Matrix(new double[][]{
                {1, 2, 3},
                {4, 5, 6}
        }))));
    }

    @Test(expected = MatrixDimensionException.class)
    public void multFail() {
        new Matrix(new double[][] {
            {1, 2, 3},
            {5, 6, 7}
        }).mult(new Matrix(new double[][] {
            {1, 2, 3},
            {5, 6, 7}
        }));
    }


}
