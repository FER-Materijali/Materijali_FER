package lab2;


import functions.F4;
import junit.framework.Assert;
import org.junit.Test;

public class TF4 {

    @Test(expected = IndexOutOfBoundsException.class)
    public void checkInvalidDimension() {
        new F4().value(new double[] {1});
    }

    @Test
    public void checkValue() {
        double t1 = (3.3 - 2.2) * (3.3 + 2.2);
        double t2 = (3.3 * 3.3 + 2.2 * 2.2);
        Assert.assertEquals(Math.abs(t1) + Math.sqrt(t2), new F4().value(new double[] {3.3, 2.2}), 1e-9);
    }

}
