
package util.integrator;

import java.util.Arrays;
import util.matrix.Matrix;

/**
 *
 * @author marijan
 */
public class TrapezoidIntegrator implements Integrator {
    
    private int verboseStep;
    
    public TrapezoidIntegrator() {
        this(0);
    }
    
    public TrapezoidIntegrator(int verboseStep) {
        this.verboseStep = verboseStep;
    }
    
    @Override
    public double[] integrate(Matrix system, double[] initial, Matrix other, double from, double to, double step) {
        Matrix AT = system.mult(2 / step);
        Matrix RInv = Matrix.unitary(system.rows()).sub(AT).inverse();
        Matrix B = RInv.copy().mult(other.mult(2 / step));
        Matrix R = RInv.mult(Matrix.unitary(system.rows()).add(AT));
        
        Matrix xk = new Matrix(new double[][] {
            initial
        }).transpose();
        
        for (int i = 0, limit = (int) Math.floor((to - from) / step); i < limit; i++) {
            if (verboseStep > 0 && (i % verboseStep) == 0) {
                System.out.println("X" + i + " = " + Arrays.toString(xk.getCol(0)));
            }
            xk = R.copy().mult(xk).add(B);
        }
        double[] col = xk.getCol(0);
        
        for (int i = 0, limit = col.length / 2; i < limit; i++) {
            double temp = col[i];
            col[i] = col[col.length - i - 1];
            col[col.length - i - 1] = temp;
        }
        return col;
    }
    
}
