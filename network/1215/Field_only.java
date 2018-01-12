class Person {
    String name;
    int age;
}
class Field_only {
    public static void main (String[] args){
	Person nobuta;
	nobuta = new Person();
	nobuta.name ="Kotani";
	nobuta.age= 18;
	System.out.println(nobuta.name+" is "+nobuta.age+"years old");
    }

}
