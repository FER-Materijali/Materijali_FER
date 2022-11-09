package util.matrix;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class FileMatrixWriter implements MatrixWriter {

    private BufferedWriter writer;

    public FileMatrixWriter(File file)
        throws IOException {
        writer = new BufferedWriter(new FileWriter(file));
    }

    @Override
    public boolean write(Matrix m) {
        try {
            writer.write(m.toString());
            writer.flush();
        } catch (IOException e) {
            return false;
        }
        return true;
    }
}
