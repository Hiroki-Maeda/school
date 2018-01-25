class Person {
  String name;
  Person amigo;
}

class Person2 {
  String name;
  Person2 amigo;
  Person2(String str) {
      name = str;
  } 
}

class Person3 {
  String name;
  Person3 amigo;
  Person3(Person3 obj) {
      amigo = obj;
  } 
}

class Person4 {
  String name;
  Person4 amigo;
  Person4(Person4 obj) {
      amigo = obj;
  } 

  void close(){
      if(amigo!=null){
          amigo.close();
      }
      System.out.println("Closing:"+name+",");
  }
}

class NP2010 {
  public static void main (String args[]) {
  Person kotani;
  kotani = new Person();

  Person akira;
  akira = new Person();

  Person syuji;
  syuji = new Person();

  Person sakusya;
  sakusya = new Person();

  kotani.name = "Nobuta";
  akira.name = "Akira";
  syuji.name = "Syuji";
  sakusya.name = "Sakusya";

  kotani.amigo=akira;
  akira.amigo=syuji;
  syuji.amigo=sakusya;
  sakusya.amigo=null;

  System.out.println("Amigos of "+kotani.name+" are "+kotani.amigo.name+", "+kotani.amigo.amigo.name+", and "+kotani.amigo.amigo.amigo.name+".");

  Person2 kotani2;
  Person2 akira2;
  Person2 syuji2;
  Person2 sakusya2; 

  kotani2 = new Person2("Nobuta");
  akira2 = new Person2("Akira");
  syuji2 = new Person2("Syuji");
  sakusya2 = new Person2("Sakusya");

  kotani2.amigo=akira2;
  akira2.amigo=syuji2;
  syuji2.amigo=sakusya2;
  sakusya2.amigo=null;

  System.out.println("Amigos of "+kotani2.name+" are "+kotani2.amigo.name+", "+kotani2.amigo.amigo.name+", and "+kotani2.amigo.amigo.amigo.name+".");

  Person3 kotani3;
  Person3 akira3;
  Person3 syuji3;
  Person3 sakusya3; 

  sakusya3 = new Person3(null);
  syuji3 = new Person3(sakusya3);
  akira3 = new Person3(syuji3);
  kotani3 = new Person3(akira3);

  sakusya3.name = "Sakusya";
  syuji3.name = "Syuji";
  akira3.name = "Akira"; 
  kotani3.name = "Nobuta"; 

  System.out.println("Amigos of "+kotani3.name+" are "+kotani3.amigo.name+", "+kotani3.amigo.amigo.name+", and "+kotani3.amigo.amigo.amigo.name+".");

  Person4 kotani4;
  Person4 akira4;
  Person4 syuji4;
  Person4 sakusya4; 

  sakusya4 = new Person4(null);
  syuji4 = new Person4(sakusya4);
  akira4 = new Person4(syuji4);
  kotani4 = new Person4(akira4);

  sakusya4.name = "Sakusya";
  syuji4.name = "Syuji";
  akira4.name = "Akira"; 
  kotani4.name = "Nobuta"; 

  kotani4.close();
  }
}

/************************************
Amigos of Nobuta are Akira, Syuji, and Sakusya.
Amigos of Nobuta are Akira, Syuji, and Sakusya.
Amigos of Nobuta are Akira, Syuji, and Sakusya.
Closing:Sakusya,
Closing:Syuji,
Closing:Akira,
Closing:Nobuta,
**************************************/