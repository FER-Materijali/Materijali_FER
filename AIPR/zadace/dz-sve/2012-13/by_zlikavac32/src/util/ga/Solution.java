package util.ga;


import util.optimization.Function;

import java.util.Random;

public interface Solution extends Comparable<Solution> {

    public Solution copy();
    
    public void evaluate(Function f);

    public void mutate(double prob, Random r);

    public Solution recombine(Solution secondParent, Random r);
    
    public double getFitness();

}
