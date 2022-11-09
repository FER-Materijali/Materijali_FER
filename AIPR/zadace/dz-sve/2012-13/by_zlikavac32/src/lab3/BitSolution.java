package lab3;


import util.optimization.Function;

import java.util.Arrays;
import java.util.BitSet;
import java.util.Random;
import util.ga.Solution;

public class BitSolution implements Solution {

    public double fitness;

    public BitSet solution;

    public double[] realValues;

    public static int[] varOffsets;

    public static double[][] ranges;

    public BitSolution(BitSet solution) {
        this.solution = solution;
    }
    
    private BitSolution() { }
    
    @Override
    public int compareTo(Solution sol) {
        if (!(sol instanceof BitSolution)) { return -1; }
        BitSolution s = (BitSolution) sol;
        return Double.compare(fitness, s.fitness);
    }
    
    @Override
    public Solution copy() {
        BitSolution s = new BitSolution((BitSet) solution.clone());
        s.fitness = fitness;
        s.realValues = Arrays.copyOf(realValues, realValues.length);
        return s;
    }
    
    @Override
    public void evaluate(Function f) {
        realValues = new double[varOffsets.length - 1];

        for (int i = 0; i < realValues.length; i++) {
            double[] range = ranges[i];
            long number = 0;
            long pot = 1;
            for (int j = varOffsets[i], limit = varOffsets[i + 1]; j < limit; j++, pot <<= 1) {
                if (solution.get(j)) {
                    number += pot;
                }
            }
            realValues[i] = number * (range[1] - range[0]) / (pot - 1) + range[0];
        }

        fitness = f.value(realValues);
    }

    @Override
    public void mutate(double prob, Random r) {
        for (int i = 0, limit = solution.size(); i < limit; i++) {
            if (r.nextDouble() < prob) {
                solution.flip(i);
            }
        }
//        for (int i = 0; i < ranges.length; i++) {
//            double localProb = .01;
//            for (int j = varOffsets[i], limit = varOffsets[i + 1], len = varOffsets[i + 1] - varOffsets[i], k = len + 1; j < limit; j++, k--) {
//                if (r.nextDouble() < ((k - 1) / (double) len * (localProb - prob) + prob)) {
//                    solution.flip(j);
//                }
//            }
//        }
//        for (int i = 0; i < ranges.length; i++) {
//            double mProb = 1. / (varOffsets[i + 1] - varOffsets[i]);
//            for (int j = varOffsets[i], limit = varOffsets[i + 1]; j < limit; j++) {
//                if (r.nextDouble() < mProb) {
//                    solution.flip(j);
//                }
//            }
//        }
    }

    @Override
    public Solution recombine(Solution secondParent, Random r) {
        int size = solution.size();
        int first = r.nextInt(size);
        int second = r.nextInt(size);
        BitSolution secondParentCasted = (BitSolution) secondParent;
        while (second == first) {
            second = r.nextInt(size);
        }
        if (second < first) {
            first += second;
            second = first - second;
            first -= second;
        }
        BitSet n = new BitSet(solution.size());
        for (int i = 0; i < first; i++) {
            n.set(i, solution.get(i));
        }
        for (int i = first; i < second; i++) {
            n.set(i, secondParentCasted.solution.get(i));
        }
        for (int i = second; i < size; i++) {
            n.set(i, solution.get(i));
        }
        return new BitSolution(n);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Fitness: ").append(fitness).append("\n");
        for (int i = 0; i < realValues.length; i++) {
            sb.append(realValues[i]).append(" -> ");
            for (int j = varOffsets[i], limit = varOffsets[i + 1]; j < limit; j++) {
                sb.append(solution.get(j) ? 1 : 0);
            }
            if (i + 1 < realValues.length) { sb.append("\n"); }
        }
        return sb.toString();
    }

    @Override
    public double getFitness() {
        return fitness;
    }
    
}
