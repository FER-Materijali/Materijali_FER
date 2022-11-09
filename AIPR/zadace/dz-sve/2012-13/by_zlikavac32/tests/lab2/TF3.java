package lab2;


import functions.F3;
import junit.framework.Assert;
import org.junit.Test;

public class TF3 {

    @Test(expected = IndexOutOfBoundsException.class)
    public void checkInvalidDimension() {
        new F3(new double[0]).value(new double[] {1});
    }

    @Test
    public void checkValue() {
        Assert.assertEquals(2, new F3(new double[] {1}).value(new double[] {2}), 1e-9);
    }

}
