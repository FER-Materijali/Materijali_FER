import org.apache.hadoop.conf.*;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

public class MatrixMultiplyMap extends Mapper<LongWritable, Text, Text, Text> {
    public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
        Configuration conf = context.getConfiguration();
        int m = Integer.parseInt(conf.get("m"));
        int p = Integer.parseInt(conf.get("p"));
        String[] numberInMatrix = (value.toString()).split(" ");
        Text outputKey = new Text();
        Text outputValue = new Text();
        if (numberInMatrix[0].equals("a")) { // (a, i, j, a_ij)
            for (int k = 0; k < p; k++) {
                outputKey.set(numberInMatrix[1] + " " + k); // i k
                outputValue.set("a " + numberInMatrix[2] + " " + numberInMatrix[3]); // a j a_ij
                context.write(outputKey, outputValue);
            }
        } else { // (b, j, k, b_jk)
            for (int i = 0; i < m; i++) {
                outputKey.set(i + " " + numberInMatrix[2]); // i k
                outputValue.set("b " + numberInMatrix[1] + " " + numberInMatrix[3]); // b j b_jk
                context.write(outputKey, outputValue);
            }
        }
    }
}