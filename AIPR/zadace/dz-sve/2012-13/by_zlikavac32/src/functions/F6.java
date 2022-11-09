package functions;

import util.optimization.Function;

public class F6 implements Function {

    private int n;

    public F6(int n) {
        this.n = n;
    }

    @Override
    public double value(double[] x) {
        double sum = 0;
        for (double i : x) {
            sum += i * i;
        }
        double tUp = Math.sin(Math.sqrt(sum));
        double sumDown = 1 + .001 * sum;
        return .5 + (tUp * tUp - .5) / (sumDown * sumDown);
    }

}
