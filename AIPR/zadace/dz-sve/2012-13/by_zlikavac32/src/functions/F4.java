package functions;

import util.optimization.Function;

public class F4 implements Function {

    @Override
    public double value(double[] x) {
        return Math.abs((x[0] - x[1]) * (x[0] + x[1])) + Math.sqrt(x[0] * x[0] + x[1] * x[1]);
    }

}
