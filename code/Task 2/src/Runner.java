public class Runner {
    private static ReadFile readFile = new ReadFile();

    public static void main(String[] args) {
        //Checks whether to execute a given command line argument or the default test file.
        try{
            if(args.length == 0){
                readFile.execFile("../test.txt");
            } else {
                readFile.execFile(args[0]);
            }
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}
