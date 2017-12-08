import java.io.*;
class Hello2 {
    public static void main (String[] args) throws IOException{
	BufferedReader br = new BufferedReader(
					       new InputStreamReader(System.in));
    System.out.print("What's your name?");
    String name = br.readLine();
    System.out.println("Hello, " +name);
    }
}
