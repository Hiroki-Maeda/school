class Person {
String name;
Person amigo;
}

class Seisyun {
public static void main (String args[]) {

    Person syuji = new Person();
    Person akira =new Person();
    Person kotani = new Person();
    
    syuji.name = "Syuji";
    akira.name = "Akira";
    kotani.name = "Nobuta";
    
    syuji.amigo = akira;
    akira.amigo = kotani;
    kotani.amigo = syuji;

System.out.println("Amigos of "+syuji.name+" are "+syuji.amigo.name+" and "+syuji.amigo.amigo.name+".");
System.out.println("Amigos of "+akira.name+" are "+akira.amigo.name+" and "+akira.amigo.amigo.name+".");
System.out.println("Amigos of "+kotani.name+" are "+kotani.amigo.name+" and "+kotani.amigo.amigo.name+".");
}
}

/**************************************
Amigos of Syuji are Akira and Nobuta.
Amigos of Akira are Nobuta and Syuji.
Amigos of Nobuta are Syuji and Akira.
***************************************/