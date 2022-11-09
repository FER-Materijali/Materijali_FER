package util.matrix;

import junit.framework.Assert;
import org.junit.Test;

public class TLUDecomposition {

    @Test
    public void hasSolution() {
        Matrix m = new Matrix(new double[][] {
            {4, 3, 2, 1},
            {4, 6, 1, -1},
            {-8, 3, -5, -6},
            {12, 12, 7, 4}
        });
        new LUDecomposition().decompose(m);
        Assert.assertTrue(m.equals(new Matrix(new double[][] {
            {4, 3, 2, 1},
            {1, 3, -1, -2},
            {-2, 3, 2, 2},
            {3, 1, 1,  1}
        })));
    }

    @Test(expected = MatrixDimensionException.class)
    public void notSquareM() {
        Matrix m = new Matrix(new double[][] {
                {1, 1, 1},
                {1, 1, 3}
        });
        new LUDecomposition().decompose(m);
    }

    @Test(expected = ZeroPivotException.class)
    public void noSolution() {
        Matrix m = new Matrix(new double[][] {
                {1, 1, 1},
                {1, 1, 3},
                {1, 3, 3}
        });
        new LUDecomposition().decompose(m);
    }
}
