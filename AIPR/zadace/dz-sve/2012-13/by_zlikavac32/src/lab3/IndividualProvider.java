package lab3;

import util.ga.*;
import java.util.BitSet;
import java.util.Random;

public class IndividualProvider implements util.ga.IndividualProvider {

    private int numBits;

    private static final double LOG2 = Math.log(2);

    public IndividualProvider(double precision, double[][] ranges) {

        numBits = 0;
        int[] varOffsets = new int[ranges.length + 1];

        for (int i = 0; i < ranges.length; i++) {
            double[] range = ranges[i];
            varOffsets[i] = numBits;
            int curr = (int) Math.round(Math.log((range[1] - range[0]) / precision) / LOG2 + .5);
            if (curr > 63 || curr < 1) {
                throw new IllegalArgumentException("Number of bits for dimension " + (i + 1) + " is not valid. It should be in range [1, 63]");
            }
            numBits += curr;
        }
        varOffsets[ranges.length] = numBits;
        BitSolution.ranges = ranges;
        BitSolution.varOffsets = varOffsets;
    }

    @Override
    public Solution next(Random random) {

        BitSet b = new BitSet(numBits);

        for (int i = 0; i < numBits; i++) {
            b.set(i, random.nextBoolean());
        }

        return new BitSolution(b);
    }

}