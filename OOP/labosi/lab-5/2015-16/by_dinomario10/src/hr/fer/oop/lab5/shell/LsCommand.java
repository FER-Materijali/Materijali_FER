package hr.fer.oop.lab5.shell;

import java.io.File;
import java.nio.file.Path;
import java.text.DateFormat;
import java.text.DecimalFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * A command that is used for writing out the current contents of a directory.
 * There may or may not be a given argument. In case there is a given argument
 * (non-null), the argument must be a directory in order for the command to its
 * list contents. In case there is no argument (argument is {@code null}), this
 * commands lists the contents of the current working directory.<br>
 * While listing directory's contents, this command also writes out if it
 * stumbled upon a file or a directory. In case of a file, this command writes
 * out the file's size in bytes.
 *
 * @author dinomario10
 */
public class LsCommand extends AbstractCommand {

	/**
	 * Constructs a new command object of type {@code LsCommand}.
	 */
	public LsCommand() {
		super("LS", "Lists directory contents.");
	}

	@Override
	public CommandStatus execute(Environment env, String s) {
		Path path;
		if (s == null) {
			path = env.getCurrentPath();
		} else {
			path = Helper.resolveAbsolutePath(env, s);
			if (path == null) {
				env.writeln("Invalid path!");
				return CommandStatus.CONTINUE;
			}
		}
		File dir = path.toFile();
		
		if (!dir.exists()) {
			env.writeln("The system cannot find the path specified.");
			return CommandStatus.CONTINUE;
		}
		if (dir.isFile()) {
			env.writeln("Cannot list contents of a file with this command.");
			return CommandStatus.CONTINUE;
		}
		
		env.writeln(" Directory of " + path);
		env.writeln("");
		
		DateFormat dateFormat = new SimpleDateFormat("dd.MM.yyyy.  HH:mm");
		DecimalFormat decimalFormat = new DecimalFormat("###,###.##");

		File[] files = path.toFile().listFiles();
		int noFiles = 0;
		int noDirs = 0;
		long filesLength = 0;
		
		for (File file : files) {
			String name = file.getName();
			Date date = new Date(file.lastModified());
			
			env.write(dateFormat.format(date) + "");
			if (file.isFile()) {
				noFiles++;
				long size = file.length();
				filesLength += size;
				env.write(String.format(" %17s ", decimalFormat.format(size)));
			} else {
				noDirs++;
				env.write("    <DIR>          ");
			}
			env.writeln(name);			
		}
		env.writeln(String.format("%15d", noFiles) + " File(s), " + decimalFormat.format(filesLength) + " bytes");
		env.writeln(String.format("%15d", noDirs) + " Dir(s)");
		
		return CommandStatus.CONTINUE;
	}

}
