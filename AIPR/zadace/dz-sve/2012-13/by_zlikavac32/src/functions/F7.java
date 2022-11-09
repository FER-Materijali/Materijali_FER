package functions;

import util.optimization.Function;

public class F7 implements Function {

    private int n;

    public F7(int n) {
        this.n = n;
    }

    @Override
    public double value(double[] x) {
        double sum = 0;
        for (double i : x) {
            sum += i * i;
        }
        double t = Math.sin(50 * Math.pow(sum, .1));
        return Math.pow(sum, .25) * (t * t + 1);
    }

}
