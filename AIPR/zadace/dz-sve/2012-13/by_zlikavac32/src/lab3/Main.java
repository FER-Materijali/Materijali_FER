package lab3;


import functions.F7;
import functions.F6;
import asg.cliche.Command;
import asg.cliche.ShellFactory;
import com.martiansoftware.jsap.FlaggedOption;
import com.martiansoftware.jsap.JSAP;
import com.martiansoftware.jsap.JSAPResult;
import com.martiansoftware.jsap.Switch;
import functions.F3;
import functions.F4;
import util.ga.SASEGASA;
import util.optimization.Function;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args)
        throws Exception {
        ShellFactory.createConsoleShell("lab3", "", new Main()).commandLoop();
    }
    
    @Command
    public void sasegasa() 
        throws Exception {
        sasegasa(new String[0]);
    }
    
    @Command
    public void sasegasa(String... args)
        throws Exception {
        JSAP parser = new JSAP();

        FlaggedOption opt = new FlaggedOption("population")
                .setStringParser(JSAP.INTEGER_PARSER)
                .setDefault("100").setShortFlag('p').setLongFlag("population");

        parser.registerParameter(opt);

        opt = new FlaggedOption("function")
                .setStringParser(JSAP.INTEGER_PARSER)
                .setRequired(true).setShortFlag('f')
                .setLongFlag("function");

        parser.registerParameter(opt);

        opt = new FlaggedOption("mutProb")
                .setStringParser(JSAP.DOUBLE_PARSER)
                .setDefault(".025").setShortFlag('b').setLongFlag("mutProb");

        parser.registerParameter(opt);

        opt = new FlaggedOption("successRatio")
                .setStringParser(JSAP.DOUBLE_PARSER)
                .setDefault(".6").setShortFlag('s').setLongFlag("successRatio");

        parser.registerParameter(opt);

        opt = new FlaggedOption("maxSelectionPressure")
                .setStringParser(JSAP.DOUBLE_PARSER)
                .setDefault("7").setShortFlag('m').setLongFlag("maxSelectionPressure");

        parser.registerParameter(opt);

        opt = new FlaggedOption("comparisonFactor")
                .setStringParser(JSAP.DOUBLE_PARSER)
                .setDefault(".35").setShortFlag('i').setLongFlag("comparisonFactor");

        parser.registerParameter(opt);

        opt = new FlaggedOption("villages")
            .setStringParser(JSAP.INTEGER_PARSER)
            .setDefault("4").setShortFlag('t').setLongFlag("villages");

        parser.registerParameter(opt);

        opt = new FlaggedOption("generations")
                .setStringParser(JSAP.INTEGER_PARSER)
                .setDefault("300").setShortFlag('g').setLongFlag("generations");

        parser.registerParameter(opt);

        Switch sw = new Switch("verbose")
                .setShortFlag('v').setLongFlag("verbose");

        parser.registerParameter(sw);

        opt = new FlaggedOption("sample")
                .setStringParser(JSAP.INTEGER_PARSER)
                .setDefault("1").setShortFlag('d').setLongFlag("sample");

        parser.registerParameter(opt);

        opt = new FlaggedOption("dimension")
                .setStringParser(JSAP.INTEGER_PARSER)
                .setDefault("3").setShortFlag('n').setLongFlag("dimension");

        parser.registerParameter(opt);

        opt = new FlaggedOption("params")
                .setStringParser(JSAP.DOUBLE_PARSER)
                .setAllowMultipleDeclarations(true)
                .setList(true).setListSeparator(' ')
                .setLongFlag("params").setShortFlag('h');

        parser.registerParameter(opt);

        JSAPResult config = parser.parse(args);

        if (!config.success()) {
            showError(parser);
            return ;
        }

        int n = config.getInt("dimension");

        Function f;

        switch (config.getInt("function")) {
            case 3 :
                f = new F3(config.getDoubleArray("params"));
                break;
            case 4 :
                f = new F4();
                break;
            case 6 :
                f = new F6(n);
                break;
            case 7 :
                f = new F7(n);
                break;
            default :
                System.err.println("Available functions are 3, 4, 6 and 7");
                return ;
        }

        double[][] r = new double[n][2];

        for (int i = 0; i < n; i++) {
            r[i][0] = -100;
            r[i][1] = 100;
        }

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        for (String line = reader.readLine(); line != null && !line.equals(""); line = reader.readLine()) {
            String[] parts = line.split("\\s+");
            int i = Integer.parseInt(parts[0]) - 1;
            r[i][0] = Double.parseDouble(parts[1]);
            r[i][1] = Double.parseDouble(parts[2]);
        }

        SASEGASA alg = new SASEGASA(
            f, new IndividualProvider(1e-9, r), config.getInt("villages"),
            config.getInt("population"),
            config.getInt("generations"), config.getDouble("successRatio"),
            config.getDouble("maxSelectionPressure"),
            config.getDouble("comparisonFactor"), config.getDouble("mutProb")
        );
        alg.run(config.getBoolean("verbose"));
        System.out.println(alg.getBest());
    }

    private void showError(JSAP parser) {
        System.err.println("Usage: java " + this.getClass().getName());
        System.err.println("                " + parser.getUsage());
        System.err.println();
        System.err.println(parser.getHelp());
    }

}
