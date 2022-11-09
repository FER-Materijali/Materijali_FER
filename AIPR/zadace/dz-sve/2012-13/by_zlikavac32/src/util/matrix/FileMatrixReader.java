package util.matrix;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class FileMatrixReader implements MatrixReader {

    private BufferedReader reader;

    public FileMatrixReader(File file)
        throws IOException {
        reader = new BufferedReader(new FileReader(file));
    }

    public Matrix read() {

        Matrix m = null;

        try {
            List<double[]> list = new ArrayList<double[]>();

            String l = reader.readLine();

            if (l == null) { return m; }

            String[] temp = l.split("\\s+");

            int cols = temp.length;

            double[] row = new double[cols];
            for (int i = 0; i < cols; i++) {
                row[i] = Double.parseDouble(temp[i]);
            }

            list.add(row);

            for (l = reader.readLine(); l != null; l = reader.readLine()) {

                temp = l.split("\\s+");

                row = new double[cols];
                for (int i = 0; i < cols; i++) {
                    row[i] = Double.parseDouble(temp[i]);
                }

                list.add(row);
            }

            m = new Matrix(list.toArray(new double[0][0]));

        } catch (IOException e) { }

        return m;
    }

}
