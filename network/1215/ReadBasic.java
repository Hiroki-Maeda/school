import java.io.*;
class ReadBasic {
    public static void main(String[] args){
	try {
	    InputStreamReader isr;
	    isr = new InputStreamReader(System.in);
	    BufferedReader reader;
	    reader = new BufferedReader(isr);

	    String line;
	    while((line = reader.readLine())!=null){
		System.out.println(line);
	    }
	}
	catch(IOException e){
	    System.out.println("IO Exception");
	}
    }
}
