package util.optimization;


import junit.framework.Assert;
import functions.F2;
import functions.F3;
import org.junit.BeforeClass;
import org.junit.Test;

public class TBoxMinimizer {

    private static final double EPS = 1e-3;

    private static BoxMinimizer m;

    @BeforeClass
    public static void init() {
        m = new BoxMinimizer(1.3, 1e-9);
        for (int i = 0; i < 5; i++) {
            m.addExplicitConstraint(i, -100, 100);
        }
        m.addImplicitConstraint(new Constraint() {
            @Override
            public boolean valid(double[] x) {
                return x[0] - x[1] <= 0;
            }
        });
        m.addImplicitConstraint(new Constraint() {
            @Override
            public boolean valid(double[] x) {
                return x[0] - 2 <= 0;
            }
        });
    }

    @Test
    public void checkValueF2() {
        double[] expected = new double[] {2, 2};
        double[] got = m.minimize(new double[] {
            2, 6
        }, new F2());
        for (int i = 0; i < got.length; i++) {
            Assert.assertEquals(expected[i], got[i], EPS);
        }
    }

    @Test
    public void checkValueF3() {
        double[] expected = new double[] {2, 20, 5, 5, 5};
        double[] got = m.minimize(new double[] {
            2, 6, 7, 8, 9
        }, new F3(new double[] {
            2, 20, 5, 5, 5
        }));
        for (int i = 0; i < got.length; i++) {
            Assert.assertEquals(expected[i], got[i], EPS);
        }
    }

}
