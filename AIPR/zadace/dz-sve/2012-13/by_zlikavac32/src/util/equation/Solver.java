package util.equation;

import util.matrix.*;

public enum Solver {

    LU {

        @Override
        public Matrix solve(Matrix a, Matrix b) {
            try {
                new LUDecomposition().decompose(a);
            } catch (ZeroPivotException e) { return null; }
            return new BackwardSubstitution().substitute(
                a, new ForwardSubstitution().substitute(a, b)
            );
        }
    }, LUP {

        @Override
        public Matrix solve(Matrix a, Matrix b) {
            LUPDecomposition d = new LUPDecomposition();
            try {
                d.decompose(a);
            } catch (ZeroPivotException e) { return null; }
            BackwardSubstitution bs = new BackwardSubstitution();
            ForwardSubstitution fs = new ForwardSubstitution();
            b = d.getPermutationMatrix().mult(b);
            if (b.cols() == 1) {
                return bs.substitute(
                    a, fs.substitute(a, b)
                );
            }
            Matrix inverse = new Matrix(a.rows(), a.cols());
            Matrix columnMatrix = new Matrix(b.rows(), 1);
            for (int i = 0, limit = a.rows(); i < limit; i++) {
                for (int j = 0; j < limit; j++) {
                    columnMatrix.set(j, 0, b.get(j, i));
                }
                Matrix temp = bs.substitute(a, fs.substitute(a, columnMatrix));
                for (int j = 0; j < limit; j++) {
                    inverse.set(j, i, temp.get(j, 0));
                }
            }
            return inverse;
        }
    };

    public abstract Matrix solve(Matrix a, Matrix b);

}
