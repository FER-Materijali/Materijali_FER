
package util.integrator;

import java.util.Arrays;
import util.matrix.Matrix;

/**
 *
 * @author marijan
 */
public class RungeKuttaIntegrator implements Integrator {
    
    private int verboseStep;
    
    public RungeKuttaIntegrator() {
        this(0);
    }
    
    public RungeKuttaIntegrator(int verboseStep) {
        this.verboseStep = verboseStep;
    }
    
    @Override
    public double[] integrate(Matrix A, double[] initial, Matrix B, double from, double to, double step) {
        Matrix xk = new Matrix(new double[][] {
            initial
        }).transpose();
        
        for (int i = 0, limit = (int) Math.floor((to - from) / step); i < limit; i++) {
            if (verboseStep > 0 && (i % verboseStep) == 0) {
                System.out.println("X" + i + " = " + Arrays.toString(xk.getCol(0)));
            }
            Matrix m1 = A.copy().mult(xk).add(B);
            Matrix m2 = A.copy().mult(m1.copy().mult(step / 2).add(xk)).add(B);
            Matrix m3 = A.copy().mult(m2.copy().mult(2 * step).sub(m1.copy().mult(step)).add(xk)).add(B);
            xk = xk.add(m1.add(m2.mult(4)).add(m3).mult(step / 6));
        }
        return xk.getCol(0);
    }
    
}
