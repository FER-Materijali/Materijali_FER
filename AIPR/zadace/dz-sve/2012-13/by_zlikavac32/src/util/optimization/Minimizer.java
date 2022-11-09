package util.optimization;

public interface Minimizer {

    public double[] minimize(double[] start, Function f);

}
