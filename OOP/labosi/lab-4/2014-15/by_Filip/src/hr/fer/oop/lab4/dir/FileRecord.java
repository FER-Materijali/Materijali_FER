package hr.fer.oop.lab4.dir;

import java.io.File;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * Used for representing a row in the print format of the {@link Dir}.
 * 
 * @author Filip Hreniæ
 * @version 1.0
 */
public class FileRecord {
    /**
     * File from which we create a record
     */
    private File file;
    /**
     * Type of each character.
     */
    private List<String> types;
    /**
     * List of file attributes used for print. I.e name, last modification
     */
    private List<String> attributes;

    /**
     * Creates a new record.
     * 
     * @param file file being recorded
     * @param types types of attributes
     */
    public FileRecord(File file, List<String> types) {
        this.file = file;
        this.types = new ArrayList<>(types);
        this.createAttributes();
    }

    /**
     * Creates file attributes and stores it in internal list of attributes
     */
    private void createAttributes() {
        this.attributes = new ArrayList<>();
        int limit = this.types.size();

        for (int i = 0; i < limit; i++) {
            String s = this.types.get(i);
            String added = "";

            if (s.equals("n")) {
                added = this.file.getName();

            } else if (s.equals("t")) {
                if (this.file.isDirectory()) {
                    added = "d";
                } else {
                    added = "f";
                }

            } else if (s.equals("s")) {
                added = String.valueOf(this.file.length());

            } else if (s.equals("m")) {
                Date date = new Date(this.file.lastModified());
                SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
                String formatDate = sdf.format(date);
                added = formatDate;

            } else if (s.equals("h")) {
                if (this.file.isHidden()) {
                    added = "h";
                } else {
                    added = " ";
                }

            } else {
                throw new IllegalArgumentException("Unkown attribute: " + s);
            }

            this.attributes.add(added);
        }
    }

    /**
     * Returns the record in <code>| att_1 | att_2 | ... | att_n |</code> format.
     * 
     * @param maxSizes sizes to format the record
     * @return record in expected format
     */
    public String printRecord(List<Integer> maxSizes) {
        StringBuilder s = new StringBuilder();
        int limit = this.attributes.size();

        s.append("|");
        for (int i = 0; i < limit; i++) {
            String format = "";
            if (this.types.get(i).equals("s")) {
                format = " %"; // right indentation
            } else {
                format = " %-"; // left indentation
            }
            s.append(String.format(format + maxSizes.get(i) + "s |", this.getAttribute(i)));
        }
        return s.toString();
    }

    /**
     * Gets file attribute at index <code>index</code>.
     * 
     * @param index wanted index
     * @return attribute attribute at index
     */
    public String getAttribute(int index) {
        return this.attributes.get(index);
    }
}
