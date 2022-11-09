package util.optimization;

import java.util.*;

public class BoxMinimizer implements ConstraintMinimizer {

    private double alfa;

    private double e;

    private Map<Integer, double[]> explicit = new TreeMap<Integer, double[]>();

    private List<Constraint> implicit = new ArrayList<Constraint>();

    public BoxMinimizer(double alfa, double e) {
        this.alfa = alfa;
        this.e = e;
    }

    @Override
    public void addExplicitConstraint(int dimension, double min, double max) {
        if (explicit.containsKey(dimension)) {
            double[] t = explicit.get(dimension);
            explicit.put(dimension, new double[] {
                Math.min(t[0], min), Math.max(t[1], max)
            });
        } else {
            explicit.put(dimension, new double[] {min, max});
        }
    }

    @Override
    public void addImplicitConstraint(Constraint c) {
        implicit.add(c);
    }

    @Override
    public void clearExplicitConstraint() {
        explicit.clear();
    }

    @Override
    public void clearImplicitConstraint() {
        implicit.clear();
    }

    @Override
    public double[] minimize(double[] xc, Function f) {
        Random r = new Random();
        if (!implicitValid(xc)) { return null; }
        for (Map.Entry<Integer, double[]> e : explicit.entrySet()) {
            int i = e.getKey();
            double[] t = e.getValue();
            if (xc[i] < t[0] || xc[i] > t[1]) { return null; }
        }

        double[][] d = new double[2 * xc.length][xc.length];
        double[] evals = new double[d.length];
        int max = 0;
        int secondMax = 0;

        for (int i = 0; i < d.length; i++) {
            for (int j = 0; j < xc.length; j++) {
                if (explicit.containsKey(j)) {
                    double[] temp = explicit.get(j);
                    if (Double.isInfinite(temp[0]) || Double.isInfinite(temp[1])) {
                        d[i][j] = r.nextInt();
                    } else {
                        d[i][j] = temp[0] + r.nextDouble() * (temp[1] - temp[0]);
                    }
                } else { d[i][j] = r.nextInt(); }
            }

            while (!implicitValid(d[i])) {
                for (int j = 0; j < xc.length; j++) {
                    d[i][j] = (d[i][j] + xc[j]) / 2;
                }
            }
            evals[i] = f.value(d[i]);
            for (int k = 0; k < xc.length; k++) {
                xc[k] *= i;
                xc[k] += d[i][k];
                xc[k] /= i + 1;
            }
        }

        while (!isEnd(f.value(xc), d, f)) {
            max = 0;
            secondMax = -1;
            for (int i = 1; i < d.length; i++) {
                if (evals[i] > evals[max]) {
                    secondMax = max;
                    max = i;
                } else if ((secondMax == -1 || evals[i] > evals[secondMax]) && i != max) {
                    secondMax = i;
                }
            }
            double[] xr = d[max];
            for (int k = 0; k < xc.length; k++) {
                xc[k] = 0;
                for (int j = 0; j < d.length; j++) {
                    if (j == max) { continue; }
                    xc[k] += d[j][k];
                }
                xc[k] /= d.length - 1;
                xr[k] = (1 + alfa) * xc[k] - alfa * xr[k];
            }

            for (Map.Entry<Integer, double[]> e : explicit.entrySet()) {
                int i = e.getKey();
                double[] t = e.getValue();
                xr[i] = Math.min(Math.max(xr[i], t[0]), t[1]);
            }

            while (!implicitValid(xr)) {
                for (int i = 0; i < xr.length; i++) {
                    xr[i] = (xr[i] + xc[i]) / 2;
                }
            }
            evals[max] = f.value(xr);
            if (evals[max] > evals[secondMax]) {
                for (int i = 0; i < xr.length; i++) {
                    xr[i] = (xr[i] + xc[i]) / 2;
                }
                evals[max] = f.value(xr);
            }
        }

        int min = 0;
        for (int i = 0; i < d.length; i++) {
            if (evals[min] < evals[i]) { min = i; }
        }
        return d[min];
    }

    private boolean isEnd(double xcV, double[][] points, Function f) {
        double t = 0;
        for (int i = 0; i < points.length; i++) {
            double temp = (f.value(points[i]) - xcV);
            t += temp * temp;
        }
        return Math.sqrt(t / points.length) <= e;
    }

    private boolean implicitValid(double[] p) {
        for (Constraint c : implicit) {
            if (!c.valid(p)) { return false; }
        }
        return true;
    }
}
