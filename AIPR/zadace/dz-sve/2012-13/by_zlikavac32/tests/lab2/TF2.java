package lab2;


import functions.F2;
import junit.framework.Assert;
import org.junit.Test;

public class TF2 {

    @Test(expected = IndexOutOfBoundsException.class)
    public void checkInvalidDimension() {
        new F2().value(new double[] {1});
    }

    @Test
    public void checkValue() {
        Assert.assertEquals(.53, new F2().value(new double[] {3.3, 2.1}), 1e-9);
    }

}
