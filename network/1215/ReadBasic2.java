import java.io.*;
class ReadBasic2{
    public static void main (String[] args){
	try{FileInputStream fis;
	    fis=new FileInputStream("foo.txt");
	    InputStreamReader isr;
	    isr=new InputStreamReader(fis);
	    BufferedReader reader;
	    reader = new BufferedReader(isr);
	    String line;
	    while((line = reader.readLine())!=null){
		System.out.println(line);
	    }
	    reader.close();
	}
	catch(FileNotFoundException e){
	    System.out.println("File Not Found!");
	}
	catch(IOException e){
	    System.out.println("IO Exception!");
	}
    }
}
