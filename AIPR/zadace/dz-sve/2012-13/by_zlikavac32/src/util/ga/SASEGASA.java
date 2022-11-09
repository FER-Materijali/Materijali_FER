package util.ga;


import util.optimization.Function;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class SASEGASA {

    private IndividualProvider ip;
    
    private int villageNumber;
    
    private int populationSize;
    
    private int numGenerations;
    
    private double successRatio;
    
    private double maxSelectionPressure;
    
    private double comparisonFactor;

    private static final Random r = new Random();
    
    private Solution bestSolution;

    private double mutationProb;

    private Function f;
    
    private class ArrayProxy {
        
        private Solution[] array;
        
        private int start;
        
        private int size;
        
        public ArrayProxy(Solution[] array, int start, int size) {
            this.array = array;
            this.start = start;
            this.size = size;
        }
        
        public Solution get(int index) {
            return array[start + index];
        }

        public void set(int index, Solution data) {
            array[start + index] = data;
        }
    }
    
    private class OffspringSelection implements Runnable {

        private ArrayProxy population;
        
        private int index;
        
        private boolean verbose;
        
        private double iterationComparisonFactor;
        
        public OffspringSelection(int index, ArrayProxy population, boolean verbose, double iterationComparisonFactor) {
            this.population = population;
            this.index = index;
            this.verbose = verbose;
            this.iterationComparisonFactor = iterationComparisonFactor;
        }
        
        @Override
        public void run() {
            double currentSelectioPressure = 1;

            double localComparisonFactor = 1 - iterationComparisonFactor;
            double localSuccessRatio = successRatio;
            
            log("OffspringSelection " + index + ": Start", verbose);

            for (int i = 0; i < numGenerations && currentSelectioPressure < maxSelectionPressure; i++) {
//                log("OffspringSelection " + index + ": generation = " + i, verbose);

                List<Solution> next = new ArrayList<>(population.size);
                List<Solution> pool = new ArrayList<>((int) (population.size * maxSelectionPressure));

                int pSize = 0;

                while (next.size() < (population.size * successRatio) && (next.size() + pSize < population.size * maxSelectionPressure)) {
                    Solution first = select();
                    Solution second = select();
                    
                    Solution child = first.recombine(second, r);
                    child.mutate(mutationProb, r);
                    child.evaluate(f);

                    //Make sure first is better than second
                    if (first.compareTo(second) > 0) {
                        Solution temp = first;
                        first = second;
                        second = temp;
                    }

                    if (child.getFitness() < (second.getFitness() - (second.getFitness() - first.getFitness()) * localComparisonFactor)) {
                        next.add(child);
                    } else {
                        if (pSize < population.size) {
                            pool.add(child);
                        }
                        pSize++;
                    }
                }

                localComparisonFactor = 1 - (i / numGenerations * (.9 - iterationComparisonFactor) + iterationComparisonFactor);
                localSuccessRatio = (1 - localSuccessRatio) * i / numGenerations + localSuccessRatio;

                currentSelectioPressure = (next.size() + pSize) / (double) population.size;
                
                for (int j =  (population.size - next.size()) - pool.size(); j > 0; j--) {
                    Solution child = select().recombine(select(), r);
                    child.mutate(mutationProb, r);
                    child.evaluate(f);
                    pool.add(child);
                }
                
                for (int j = 0; j < population.size; j++) {
                    if (j < next.size()) {
                        population.set(j, next.get(j));
                    } else {
                        population.set(j, pool.get(j - next.size()));
                    }
                }
            }

            Solution localBest = null;

            for (int i = 0; i < population.size; i++) {
                if (population.get(i).compareTo(localBest) < 0) { localBest = population.get(i); }
            }
            log("OffspringSelection " + index + ": Best solution = " + localBest.getFitness(), verbose);

            log("OffspringSelection " + index + ": End", verbose);
        }
        
        private Solution select() {
            Solution first = population.get(r.nextInt(population.size));
            Solution second = population.get(r.nextInt(population.size));
            return (first.compareTo(second) < 0) ? first : second;
        }
        
    }

    public SASEGASA(Function f, IndividualProvider ip, int villageNumber, int populationSize, int numGenerations, double successRatio, double maxSelectionPressure, double comparisonFactor, double mutationProb) {
        this.ip = ip;
        this.villageNumber = villageNumber;
        this.populationSize = populationSize;
        this.numGenerations = numGenerations;
        this.successRatio = successRatio;
        this.maxSelectionPressure = maxSelectionPressure;
        this.comparisonFactor = comparisonFactor;
        this.mutationProb = mutationProb;
        this.f = f;
    }
    
    public void run() {
        run(false);
    }
    
    public void run(boolean verbose) {
        
        bestSolution = null;
        Solution[] population = new Solution[populationSize];
        log("SASEGASA: Initializing population", verbose);
        
        for (int i = 0; i < populationSize; i++) {
            Solution sol = ip.next(r);
            sol.evaluate(f);
            if (sol.compareTo(bestSolution) < 0) { bestSolution = sol; }
            population[i] = sol;
        }
        log("SASEGASA: Population initialized", verbose);
        
        if (bestSolution == null) { return; }
        
        bestSolution = bestSolution.copy();
        log("SASEGASA: Best solution = " + bestSolution.getFitness(), verbose);

        log("SASEGASA: Start", verbose);
        for (int i = villageNumber; i > 0; i--) {
            int singlePopSize = populationSize / i;
            int currentOffset = 0;
            Thread[] pool = new Thread[i];

            double iterationComparisonFactor = (villageNumber - i) / (double) villageNumber * (.9 - comparisonFactor) + comparisonFactor;
            log("SASEGASA: Creating " + i + " threads", verbose);
            for (int j = 0; j < i; j++) {
                if (j + 1 == i) {
                    singlePopSize = populationSize - currentOffset;
                }
                Thread t = new Thread(new OffspringSelection(j, new ArrayProxy(population, currentOffset, singlePopSize), verbose, iterationComparisonFactor));
                t.start();
                log("SASEGASA: Thread " + j + " created and started", verbose);
                pool[j] = t;

                currentOffset += singlePopSize;
            }
            log("SASEGASA: Waiting for " + i + " threads", verbose);
            for (int j = 0; j < i; j++) {
                try {
                    pool[j].join();
                } catch (InterruptedException e) { }
            }
            log("SASEGASA: All threads finished", verbose);
            log("SASEGASA: Updating best", verbose);
            for (Solution sol : population) {
                if (sol.compareTo(bestSolution) < 0) { bestSolution = sol; }
            }
            bestSolution = bestSolution.copy();
            log("SASEGASA: Best solution = " + bestSolution.getFitness(), verbose);
        }
        log("SASEGASA: End", verbose);
    }
    
    private static void log(String msg, boolean verbose) {
        if (verbose) {
            System.out.println(msg);
        }
    }

    public Solution getBest() { return bestSolution; }

}
