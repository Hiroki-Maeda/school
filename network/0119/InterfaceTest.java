import java.io.*;

interface D{
    int x=7;
    void func();
}

class E implements D{
    public void func(){
	System.out.println("class E"+x);
    }
}

class InterfaceTest{
    public static void main(String[] args){
	E obj= new E();
	System.out.println(obj.x);
	obj.func();
    }
}
