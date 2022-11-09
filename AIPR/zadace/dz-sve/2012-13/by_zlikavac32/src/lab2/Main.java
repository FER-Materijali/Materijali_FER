package lab2;

import functions.F3;
import functions.F2;
import functions.F4;
import functions.F1;
import asg.cliche.Command;
import asg.cliche.ShellFactory;
import com.martiansoftware.jsap.FlaggedOption;
import com.martiansoftware.jsap.JSAP;
import com.martiansoftware.jsap.JSAPResult;
import util.optimization.BoxMinimizer;
import util.optimization.Constraint;
import util.optimization.Function;
import util.optimization.HookeJeevesMinimizer;

import java.io.IOException;
import java.util.Arrays;

public class Main {

    public static void main(String[] args)
        throws IOException {
        ShellFactory.createConsoleShell("lab2", "", new Main()).commandLoop();
    }

    /**
     * Runs Box algorithm using default settings
     * @throws Exception
     */
    @Command
    public void box()
        throws Exception {
        boxHelper(new String[0]);
    }

    /**
     * Runs Box algorithm using settings passed as params. Call with -h param to get help
     * @param args
     * @throws Exception
     */
    @Command
    public void box(String... args)
        throws Exception {
        boxHelper(args);
    }

    /**
     * Runs Hooke-Jeeves algorithm using default settings
     * @throws Exception
     */
    @Command
    public void hookeJeeves()
        throws Exception {
        hookeJeeves(new String[0]);
    }

    /**
     * Runs Hooke-Jeeves algorithm using settings passed as params. Call with -h param to get help
     * @param args
     * @throws Exception
     */
    @Command
    public void hookeJeeves(String... args)
        throws Exception {
        hookeJeevesHelper(args);
    }

    private void hookeJeevesHelper(String[] args)
        throws Exception {
        JSAP parser = new JSAP();

        FlaggedOption opt = new FlaggedOption("function")
            .setStringParser(JSAP.INTEGER_PARSER)
            .setRequired(true).setShortFlag('f')
            .setLongFlag("function");

        parser.registerParameter(opt);

        opt = new FlaggedOption("dx")
            .setStringParser(JSAP.DOUBLE_PARSER)
            .setAllowMultipleDeclarations(true)
            .setDefault(new String[] {
                ".5", ".5", ".5", ".5", ".5"
            }).setList(true).setListSeparator(' ')
            .setLongFlag("dx").setShortFlag('x');

        parser.registerParameter(opt);

        opt = new FlaggedOption("error")
                .setStringParser(JSAP.DOUBLE_PARSER)
                .setAllowMultipleDeclarations(true)
                .setDefault(new String[]{
                        "1e-9", "1e-9", "1e-9", "1e-9", "1e-9"
                }).setList(true).setListSeparator(' ')
                .setLongFlag("error").setShortFlag('e');

        parser.registerParameter(opt);

        opt = new FlaggedOption("params")
                .setStringParser(JSAP.DOUBLE_PARSER)
                .setAllowMultipleDeclarations(true)
                .setList(true).setListSeparator(' ')
                .setLongFlag("params").setShortFlag('p');

        parser.registerParameter(opt);

        opt = new FlaggedOption("start")
                .setStringParser(JSAP.DOUBLE_PARSER)
                .setAllowMultipleDeclarations(true)
                .setList(true).setListSeparator(' ')
                .setLongFlag("start").setShortFlag('s')
                .setRequired(true);

        parser.registerParameter(opt);

        JSAPResult config = parser.parse(args);

        if (!config.success()) {
            printUsage(parser);
            return ;
        }

        Function f = null;

        switch (config.getInt("function")) {
            case 1 :
                f = new F1();
                break;
            case 2 :
                f = new F2();
                break;
            case 3 :
                f = new F3(config.getDoubleArray("params"));
                break;
            case 4 :
                f = new F4();
                break;
            default :
                System.err.println("Available functions are 1, 2, 3 and 4");
                return ;
        }

        HookeJeevesMinimizer hj = new HookeJeevesMinimizer(config.getDoubleArray("dx"), config.getDoubleArray("error"));
        double[] ret = hj.minimize(config.getDoubleArray("start"), f);
        for (int i = 0; i < ret.length; i++) {
            ret[i] = Math.round(ret[i] * 1e4) / 1e4;
        }
        System.out.println(Arrays.toString(ret));
    }

    private void boxHelper(String[] args)
        throws Exception {
        JSAP parser = new JSAP();

        FlaggedOption opt = new FlaggedOption("function")
                .setStringParser(JSAP.INTEGER_PARSER)
                .setRequired(true).setShortFlag('f')
                .setLongFlag("function");

        parser.registerParameter(opt);

        opt = new FlaggedOption("alfa")
                .setStringParser(JSAP.DOUBLE_PARSER)
                .setDefault("1.3")
                .setLongFlag("alfa").setShortFlag('a');

        parser.registerParameter(opt);

        opt = new FlaggedOption("epsilon")
                .setStringParser(JSAP.DOUBLE_PARSER)
                .setDefault("1e-9")
                .setLongFlag("epsilon").setShortFlag('e');

        parser.registerParameter(opt);

        opt = new FlaggedOption("params")
                .setStringParser(JSAP.DOUBLE_PARSER)
                .setAllowMultipleDeclarations(true)
                .setList(true).setListSeparator(' ')
                .setLongFlag("params").setShortFlag('p');

        parser.registerParameter(opt);

        opt = new FlaggedOption("start")
                .setStringParser(JSAP.DOUBLE_PARSER)
                .setAllowMultipleDeclarations(true)
                .setList(true).setListSeparator(' ')
                .setLongFlag("start").setShortFlag('s')
                .setRequired(true);

        parser.registerParameter(opt);

        JSAPResult config = parser.parse(args);

        if (!config.success()) {
            printUsage(parser);
            return ;
        }

        Function f = null;

        switch (config.getInt("function")) {
            case 1 :
                f = new F1();
                break;
            case 2 :
                f = new F2();
                break;
            case 3 :
                f = new F3(config.getDoubleArray("params"));
                break;
            case 4 :
                f = new F4();
                break;
            default :
                System.err.println("Available functions are 1, 2, 3 and 4");
                return ;
        }

        double[] start = config.getDoubleArray("start");

        BoxMinimizer box = new BoxMinimizer(config.getDouble("alfa"), config.getDouble("epsilon"));
        for (int i = 0; i < start.length; i++) {
            box.addExplicitConstraint(i, -100, 100);
        }
        box.addImplicitConstraint(new Constraint() {
            @Override
            public boolean valid(double[] x) {
                return x[0] - x[1] <= 0;
            }
        });
        box.addImplicitConstraint(new Constraint() {
            @Override
            public boolean valid(double[] x) {
                return x[0] - 2 <= 0;
            }
        });
        double[] ret = box.minimize(start, f);
        for (int i = 0; i < ret.length; i++) {
            ret[i] = Math.round(ret[i] * 1e4) / 1e4;
        }
        System.out.println(Arrays.toString(ret));
    }

    private void printUsage(JSAP parser) {
        System.err.println();
        System.err.println("Usage: java " + this.getClass().getName());
        System.err.println("                " + parser.getUsage());
        System.err.println();
        System.err.println(parser.getHelp());
    }

}
