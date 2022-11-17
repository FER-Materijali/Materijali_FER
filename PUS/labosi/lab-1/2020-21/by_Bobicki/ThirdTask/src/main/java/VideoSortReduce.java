import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class VideoSortReduce extends Reducer<IntWritable, Text, Text, IntWritable> {
    public void reduce(IntWritable key, Iterable<Text> values, Context context) throws java.io.IOException, InterruptedException {
        for (Text value : values) {
            context.write(value, key);
        }
    }
}