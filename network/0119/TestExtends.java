import java.io.*;

class A{
    int x = 7;
    void funcA(){
	System.out.println("x= "+x);
    }
}

class B extends A {
    int y=8;
    void funcB(){
	System.out.println("x= "+x+"y= "+y);
    }
}

class TestExtends{
    public static void main(String[] args){
	A obj1 = new A();
	B obj2 = new B();

	System.out.println(obj1.x);
	System.out.println(obj2.x);
	System.out.println(obj2.y);
	obj1.funcA();
	obj2.funcA();
	obj2.funcB();
    }
}
