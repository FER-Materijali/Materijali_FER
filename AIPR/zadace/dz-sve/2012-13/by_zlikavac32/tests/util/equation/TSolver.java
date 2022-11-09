package util.equation;

import junit.framework.Assert;
import org.junit.Test;
import util.matrix.Matrix;

public class TSolver {

    @Test
    public void LUSolver() {
        Assert.assertTrue(new Matrix(new double[][] {
            {1}, {2}, {3}
        }).equals(Solver.LU.solve(new Matrix(new double[][] {
            {1, 2, 3},
            {3, 2, 1},
            {1, 3, 2}
        }), new Matrix(new double[][] {
            {14}, {10}, {13}
        }))));
    }

    @Test
    public void LUSolverNoSolution() {
        Assert.assertNull(Solver.LU.solve(new Matrix(new double[][] {
            {1, 1, 1},
            {1, 1, 3},
            {1, 3, 3}
        }), new Matrix(new double[][] {
            {14}, {10}, {13}
        })));
    }

    @Test
    public void LUPSolver() {
        Assert.assertTrue(new Matrix(new double[][] {
                {1}, {2}, {3}
        }).equals(Solver.LUP.solve(new Matrix(new double[][] {
                {1, 2, 3},
                {3, 2, 1},
                {1, 3, 2}
        }), new Matrix(new double[][] {
                {14}, {10}, {13}
        }))));
    }

    @Test
    public void LUPSolverMatrix() {
        System.out.println(Solver.LUP.solve(new Matrix(new double[][] {
                {1, 2, 3},
                {3, 2, 1},
                {1, 3, 2}
        }), new Matrix(new double[][] {
                {1, 0, 0}, {0, 1, 0}, {0, 0, 1}
        })));
        Assert.assertTrue(new Matrix(new double[][] {
                {0.083333, 0.416667, -0.333333},
                {-0.416667, -0.083333, 0.666667},
                {0.583333, -0.083333, -0.333333}
        }).equals(Solver.LUP.solve(new Matrix(new double[][] {
                {1, 2, 3},
                {3, 2, 1},
                {1, 3, 2}
        }), new Matrix(new double[][] {
                {1, 0, 0}, {0, 1, 0}, {0, 0, 1}
        }))));
    }

    @Test
    public void LUPSolverNoSolution() {
        Assert.assertNull(Solver.LUP.solve(new Matrix(new double[][] {
                {1, 1, 1},
                {1, 1, 3},
                {1, 1, 3}
        }), new Matrix(new double[][] {
                {14}, {10}, {13}
        })));
    }

}
