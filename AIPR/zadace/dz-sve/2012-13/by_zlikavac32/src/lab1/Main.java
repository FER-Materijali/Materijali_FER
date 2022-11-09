package lab1;

import util.equation.Solver;
import util.matrix.FileMatrixReader;
import util.matrix.FileMatrixWriter;
import util.matrix.Matrix;

import java.io.File;
import java.io.IOException;

public class Main {

    public static void main(String[] args)
        throws IOException {
        if (args.length < 4) {
            printUsage(); return;
        }
        Matrix A = new FileMatrixReader(new File(args[0])).read();
        Matrix y = new FileMatrixReader(new File(args[1])).read();
        Matrix x = null;
        if (args[3].equals("LU")) {
            x = Solver.LU.solve(A, y);
        } else if (args[3].equals("LUP")) {
            x = Solver.LUP.solve(A, y);
        } else {
            printUsage(); return;
        }
        if (x == null) {
            System.out.println("System has not solution or current method is not able to find one");
            return ;
        }
        new FileMatrixWriter(new File(args[2])).write(x);
    }

    private static void printUsage() {
        System.out.println("Usage: java -cp APR.jar lab1.main <path/to/mat1> <path/to/mat2> <path/to/matSol> LU|LUP");
    }

}
