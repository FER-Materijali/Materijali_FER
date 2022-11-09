package util.optimization;


import junit.framework.Assert;
import functions.F1;
import functions.F2;
import functions.F3;
import functions.F4;
import org.junit.BeforeClass;
import org.junit.Test;

public class THookeJeevesMinimizer {

    private static final double EPS = 1e-5;

    private static Minimizer m;

    @BeforeClass
    public static void init() {
        m = new HookeJeevesMinimizer(new double[] {
            .5, .5
        }, new double[] {
            1e-9, 1e-9
        });
    }

    @Test
    public void checkValueF1() {
        double[] expected = new double[] {1, 1};
        double[] got = m.minimize(new double[] {
            5, 5
        }, new F1());
        for (int i = 0; i < got.length; i++) {
            Assert.assertEquals(expected[i], got[i], EPS);
        }
    }

    @Test
    public void checkValueF2() {
        double[] expected = new double[] {4, 2};
        double[] got = m.minimize(new double[] {
            5, 5
        }, new F2());
        for (int i = 0; i < got.length; i++) {
            Assert.assertEquals(expected[i], got[i], EPS);
        }
    }

    @Test
    public void checkValueF3() {
        double[] expected = new double[] {4, 5};
        double[] got = m.minimize(new double[] {
            2, -4
        }, new F3(new double[] {
            4, 5
        }));
        for (int i = 0; i < got.length; i++) {
            Assert.assertEquals(expected[i], got[i], EPS);
        }
    }

    @Test
    public void checkValueF4() {
        double[] expected = new double[] {0, 0};
        double[] got = m.minimize(new double[] {
            .25, .25
        }, new F4());
        for (int i = 0; i < got.length; i++) {
            Assert.assertEquals(expected[i], got[i], EPS);
        }
    }

}
