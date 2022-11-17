

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapred.MapReduceBase;
import org.apache.hadoop.mapred.Mapper;
import org.apache.hadoop.mapred.OutputCollector;
import org.apache.hadoop.mapred.Reporter;

public class Map extends MapReduceBase 
   implements Mapper<LongWritable, Text, Text, IntWritable>{

	@Override
	public void map(LongWritable k1, Text v1,
			OutputCollector<Text, IntWritable> out, Reporter rep)
	throws IOException {
		
		String url = (v1.toString()).split(" +")[0];
		if(!url.isEmpty()) out.collect( new Text( url ), new IntWritable(1) );
		
	}
	
	

}
