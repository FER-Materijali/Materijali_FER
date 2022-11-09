package lab2;


import functions.F1;
import junit.framework.Assert;
import org.junit.Test;

public class TF1 {

    @Test(expected = IndexOutOfBoundsException.class)
    public void checkInvalidDimension() {
        new F1().value(new double[] {1});
    }

    @Test
    public void checkValue() {
        Assert.assertEquals(600.875, new F1().value(new double[] {.5, 8}), 1e-9);
    }

}
