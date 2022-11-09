package lab4;


import asg.cliche.Command;
import asg.cliche.ShellFactory;
import com.martiansoftware.jsap.FlaggedOption;
import com.martiansoftware.jsap.JSAP;
import com.martiansoftware.jsap.JSAPException;
import com.martiansoftware.jsap.JSAPResult;
import java.io.File;
import java.util.Arrays;
import util.integrator.Integrator;
import util.integrator.RungeKuttaIntegrator;
import util.integrator.TrapezoidIntegrator;
import util.matrix.FileMatrixReader;
import util.matrix.MatrixReader;

public class Main {

    public static void main(String[] args)
        throws Exception {
        ShellFactory.createConsoleShell("lab4", "", new Main()).commandLoop();
    }
    
    @Command
    public void trapezoid() 
        throws Exception {
        trapezoid(new String[0]);
    }
    
    @Command
    public void trapezoid(String... args)
        throws Exception {
        
        JSAPResult config = parseConfig(args);
        
        if (config == null) { return; }
        
        Integrator integrator = new TrapezoidIntegrator(config.getInt("verbose"));
        System.out.println(Arrays.toString(integrator.integrate(
            new FileMatrixReader(new File(config.getString("A"))).read(), 
            config.getDoubleArray("init"), 
            new FileMatrixReader(new File(config.getString("B"))).read(), 
            config.getDouble("from"), 
            config.getDouble("to"), 
            config.getDouble("step")
        )));
    }
    
    @Command
    public void rungeKutta() 
        throws Exception {
        rungeKutta(new String[0]);
    }
    
    @Command
    public void rungeKutta(String... args)
        throws Exception {
        
        JSAPResult config = parseConfig(args);
        
        if (config == null) { return; }
        
        Integrator integrator = new RungeKuttaIntegrator(config.getInt("verbose"));
        System.out.println(Arrays.toString(integrator.integrate(
            new FileMatrixReader(new File(config.getString("A"))).read(), 
            config.getDoubleArray("init"), 
            new FileMatrixReader(new File(config.getString("B"))).read(), 
            config.getDouble("from"), 
            config.getDouble("to"), 
            config.getDouble("step")
        )));
    }
    
    private JSAPResult parseConfig(String[] args) 
        throws JSAPException {
        
        JSAP parser = new JSAP();

        FlaggedOption opt = new FlaggedOption("verbose")
                .setStringParser(JSAP.INTEGER_PARSER)
                .setDefault("0").setShortFlag('v').setLongFlag("verbose");

        parser.registerParameter(opt);

        opt = new FlaggedOption("from")
                .setStringParser(JSAP.DOUBLE_PARSER)
                .setDefault("0").setShortFlag('f')
                .setLongFlag("from");

        parser.registerParameter(opt);

        opt = new FlaggedOption("to")
                .setStringParser(JSAP.DOUBLE_PARSER)
                .setDefault("1").setShortFlag('t')
                .setLongFlag("to");

        parser.registerParameter(opt);

        opt = new FlaggedOption("step")
                .setStringParser(JSAP.DOUBLE_PARSER)
                .setDefault(".1").setShortFlag('s')
                .setLongFlag("step");

        parser.registerParameter(opt);

        opt = new FlaggedOption("A")
                .setStringParser(JSAP.STRING_PARSER)
                .setDefault("data/lab4/A.txt").setShortFlag('a')
                .setLongFlag("A");

        parser.registerParameter(opt);

        opt = new FlaggedOption("B")
                .setStringParser(JSAP.STRING_PARSER)
                .setDefault("data/lab4/B.txt").setShortFlag('b')
                .setLongFlag("B");

        parser.registerParameter(opt);
        
        opt = new FlaggedOption("init")
            .setStringParser(JSAP.DOUBLE_PARSER)
            .setAllowMultipleDeclarations(true)
            .setDefault(new String[] {
                "1", "1"
            }).setList(true).setListSeparator(' ')
            .setLongFlag("init").setShortFlag('i');

        parser.registerParameter(opt);

        JSAPResult config = parser.parse(args);

        if (!config.success()) {
            showError(parser);
            return null;
        }
        
        return config;
    }

    private void showError(JSAP parser) {
        System.err.println("Usage: java " + this.getClass().getName());
        System.err.println("                " + parser.getUsage());
        System.err.println();
        System.err.println(parser.getHelp());
    }

}
