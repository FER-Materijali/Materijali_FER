package functions;

import util.optimization.Function;

public class F3 implements Function {

    private double[] params;

    public F3(double[] params) {
        this.params = params;
    }

    @Override
    public double value(double[] x) {
        double t = 0;
        for (int i = 0; i < x.length; i++) {
            double p = (x[i] - params[i]);
            t += p * p;
        }
        return t;
    }

}
