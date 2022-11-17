import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;
import java.util.HashMap;

public class MatrixMultiplyReduce extends Reducer<Text, Text, Text, Text> {
    @Override
    public void reduce(Text key, Iterable<Text> values, Context context) throws IOException, InterruptedException {
        String[] value;
        HashMap<Integer, Integer> mapA = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> mapB = new HashMap<Integer, Integer>();
        for (Text val : values) {
            value = val.toString().split(" ");
            if (value[0].equals("a")) { // a j a_ij
                mapA.put(Integer.parseInt(value[1]), Integer.parseInt(value[2]));
            } else { // b j b_jk
                mapB.put(Integer.parseInt(value[1]), Integer.parseInt(value[2]));
            }
        }
        float result = 0.1f; // flag
        float a_ij;
        float b_jk;
        for (int j = 0; j < mapA.size(); j++) {
            a_ij = mapA.containsKey(j) ? mapA.get(j) : 0.0f;
            b_jk = mapB.containsKey(j) ? mapB.get(j) : 0.0f;
            result += a_ij * b_jk;
        }
        if (result != 0.1f) {
            context.write(null, new Text(key.toString() + " " + Math.round(result))); // i k sum(a_ij * b_jk)
        }
    }
}