package util.optimization;

import java.util.Arrays;

public class HookeJeevesMinimizer implements Minimizer {

    private double[] dx;

    private double[] e;

    public HookeJeevesMinimizer(double[] dx, double[] e) {
        this.dx = dx;
        this.e = e;
    }

    @Override
    public double[] minimize(double[] start, Function f) {
        double[] dx = Arrays.copyOf(this.dx, this.dx.length);
        double[] base = Arrays.copyOf(start, start.length);
        while (!isMinimal(dx)) {
            double[] newPoint = Arrays.copyOf(start, start.length);
            for (int i = 0; i < start.length; i++) {
                double t1 = f.value(newPoint);
                newPoint[i] += dx[i];
                double t2 = f.value(newPoint);
                if (t2 > t1) {
                    newPoint[i] -= 2 * dx[i];
                    t2 = f.value(newPoint);
                    if (t2 > t1) {
                        newPoint[i] += dx[i];
                    }
                }
            }

            if (f.value(newPoint) < f.value(base)) {
                for (int i = 0; i < start.length; i++) {
                    start[i] = 2 * newPoint[i] - base[i];
                }
                base = Arrays.copyOf(newPoint, newPoint.length);
            } else {
                for (int i = 0; i < dx.length; i++) {
                    dx[i] /= 2;
                }
                start = Arrays.copyOf(base, base.length);
            }
        }
        return start;
    }

    private boolean isMinimal(double[] dx) {
        for (int i = 0; i < dx.length; i++) {
            if (dx[i] > e[i]) {
                return false;
            }
        }
        return true;
    }

}
