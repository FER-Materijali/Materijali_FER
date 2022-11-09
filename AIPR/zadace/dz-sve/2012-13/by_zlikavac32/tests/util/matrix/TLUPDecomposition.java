package util.matrix;

import junit.framework.Assert;
import org.junit.Test;

public class TLUPDecomposition {

    @Test
    public void hasSolution() {
        Matrix m = new Matrix(new double[][] {
            {4, 10, 5, -9},
            {-4, 6, 6, 3},
            {-8, 4, 2, 6},
            {-4, 8, 1, -3}
        });
        LUPDecomposition d = new LUPDecomposition();
        d.decompose(m);
        Assert.assertTrue(m.equals(new Matrix(new double[][] {
            {-8, 4, 2, 6},
            {-.5, 12, 6, -6},
            {.5, 1 / 3., 3, 2},
            {.5, .5, -1, -1}
        })));;
        Assert.assertTrue(d.getPermutationMatrix().equals(new Matrix(new double[][] {
            {0, 0, 1, 0},
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 1}
        })));
    }

    @Test
    public void noLUhasLUPSolution() {
        Matrix m = new Matrix(new double[][] {
                {1, 1, 1},
                {1, 1, 3},
                {1, 3, 3}
        });
        LUPDecomposition d = new LUPDecomposition();
        d.decompose(m);
        Assert.assertTrue(m.equals(new Matrix(new double[][] {
                {1, 1, 1},
                {1, 2, 2},
                {1, 0, 2}
        })));
    }

    @Test(expected = MatrixDimensionException.class)
    public void notSquareM() {
        Matrix m = new Matrix(new double[][] {
                {1, 1, 1},
                {1, 1, 3}
        });
        new LUPDecomposition().decompose(m);
    }


    @Test(expected = ZeroPivotException.class)
    public void noSolution() {
        Matrix m = new Matrix(new double[][] {
                {1, 2, 4},
                {1, 2, 3},
                {1, 2, 5}
        });
        LUPDecomposition d = new LUPDecomposition();
        d.decompose(m);
    }
}
