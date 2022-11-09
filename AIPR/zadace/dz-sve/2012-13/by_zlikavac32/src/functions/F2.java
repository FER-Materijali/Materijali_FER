package functions;

import util.optimization.Function;

public class F2 implements Function {

    @Override
    public double value(double[] x) {
        double t1 = (x[0] - 4);
        double t2 = (x[1] - 2);
        return t1 * t1 + 4 * t2 * t2;
    }

}
