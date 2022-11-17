public class Main {
    public static void main(String[] args) throws Exception {
        if (args.length != 2) {
            System.err.println("Usage: Main <input path> <output path>");
            System.exit(-1);
        }
        VideoCount.count(args);
        VideoSort.sort();
    }
}
