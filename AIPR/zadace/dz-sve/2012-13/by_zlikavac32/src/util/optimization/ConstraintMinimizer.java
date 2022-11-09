package util.optimization;

public interface ConstraintMinimizer extends Minimizer {

    public void addExplicitConstraint(int dimension, double min, double max);

    public void addImplicitConstraint(Constraint c);

    public void clearExplicitConstraint();

    public void clearImplicitConstraint();

}
