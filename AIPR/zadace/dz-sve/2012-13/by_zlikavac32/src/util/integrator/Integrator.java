
package util.integrator;

import util.matrix.Matrix;

/**
 *
 * @author marijan
 */
public interface Integrator {
    
    public double[] integrate(Matrix system, double[] initial, Matrix other, double from, double to, double step);
    
}
