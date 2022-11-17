import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;

public class VideoSort {
    public static void sort() throws Exception {
        Configuration conf = new Configuration(true);
        Job job = new Job(conf, "Video sort");

        FileInputFormat.addInputPath(job, new Path("/out1/part-00000"));
        job.setInputFormatClass(TextInputFormat.class);
        FileOutputFormat.setOutputPath(job, new Path("/out2"));
        job.setOutputFormatClass(TextOutputFormat.class);

        job.setJarByClass(VideoSort.class);
        job.setMapperClass(VideoSortMap.class);
        job.setReducerClass(VideoSortReduce.class);

        job.setMapOutputKeyClass(IntWritable.class);
        job.setMapOutputValueClass(Text.class);
        job.setOutputKeyClass(IntWritable.class);
        job.setOutputValueClass(Text.class);

        job.setSortComparatorClass(IntegerComparator.class);

        job.waitForCompletion(true);
    }
}