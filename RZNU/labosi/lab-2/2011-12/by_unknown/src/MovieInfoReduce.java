

import java.io.IOException;
import java.util.Iterator;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapred.MapReduceBase;
import org.apache.hadoop.mapred.OutputCollector;
import org.apache.hadoop.mapred.Reducer;
import org.apache.hadoop.mapred.Reporter;

public class MovieInfoReduce extends MapReduceBase
implements Reducer<Text, IntWritable, Text, IntWritable>{

	@Override
	public void reduce(Text url, Iterator<IntWritable> occurences,
			OutputCollector<Text, IntWritable> out, Reporter rep)
	throws IOException {
		
		int occurenceSum = 0;
		
		while( occurences.hasNext() ){
			occurenceSum += occurences.next().get();
		}
		
		out.collect( url, new IntWritable(occurenceSum) );
		
	}
	
	

}
