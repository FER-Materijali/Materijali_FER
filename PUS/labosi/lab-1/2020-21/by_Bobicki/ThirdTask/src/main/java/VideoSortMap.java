import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class VideoSortMap extends Mapper<LongWritable, Text, IntWritable, Text> {
    public void map(LongWritable key, Text value, Context context) throws java.io.IOException, InterruptedException {
        String[] parts = (value.toString()).split("\t");
        String id = parts[0];
        int views = Integer.parseInt(parts[1]);
        context.write(new IntWritable(views), new Text(id));
    }
}
