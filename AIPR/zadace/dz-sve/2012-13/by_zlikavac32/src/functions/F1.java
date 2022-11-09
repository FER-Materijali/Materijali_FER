package functions;

import util.optimization.Function;

public class F1 implements Function {

    @Override
    public double value(double[] x) {
        double t1 = (x[0] * x[0] - x[1]);
        double t2 = (1 - x[0]);
        return 10 * t1 * t1 + t2 * t2;
    }

}
