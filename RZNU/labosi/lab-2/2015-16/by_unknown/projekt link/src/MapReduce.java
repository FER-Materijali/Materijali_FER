

import java.io.IOException;

import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapred.JobConf;
import org.apache.hadoop.mapred.FileInputFormat;
import org.apache.hadoop.mapred.FileOutputFormat;
import org.apache.hadoop.mapred.JobClient;

public class MapReduce {
	
	public static void main(String[] args) throws IOException
	{
		if( args.length != 2 ){
			System.err.println("Args: inPath outPath");	
			System.exit(-1);
		}
		
		JobConf jobConf = new JobConf( MapReduce.class );
		jobConf.setJobName("MovieInfo visit stats");
		
		FileInputFormat.addInputPath(jobConf, new Path(args[0]));
		FileOutputFormat.setOutputPath(jobConf, new Path(args[1]));
		
		jobConf.setMapperClass( Map.class );
		jobConf.setReducerClass( Reduce.class );
		jobConf.setOutputKeyClass( Text.class );
		jobConf.setOutputValueClass( IntWritable.class );
		JobClient.runJob( jobConf );		
		
	}

}
