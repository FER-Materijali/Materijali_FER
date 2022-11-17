import java.io.IOException;

import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapred.FileInputFormat;
import org.apache.hadoop.mapred.FileOutputFormat;
import org.apache.hadoop.mapred.JobClient;
import org.apache.hadoop.mapred.JobConf;

public class VideoCount {
    public static void main(String[] args) throws IOException {
        if (args.length != 2) {
            System.err.println("Usage: VideoCount <input path> <output path>");
            System.exit(-1);
        }
        JobConf conf = new JobConf(VideoCount.class);
        conf.setJobName("Video count");
        FileInputFormat.addInputPath(conf, new Path(args[0]));
        FileOutputFormat.setOutputPath(conf, new Path(args[1]));
        conf.setMapperClass(VideoCountMap.class);
        conf.setReducerClass(VideoCountReduce.class);
        conf.setOutputKeyClass(Text.class);
        conf.setOutputValueClass(IntWritable.class);
        JobClient.runJob(conf);
    }
}