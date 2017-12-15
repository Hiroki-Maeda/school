class ex1 {
    public static void main (String[] args) {
	System.out.println("(1)");
	System.out.println(" 10-9-8-7= " +(10-9-8-7));
	System.out.println(" ((10-9)-8)-7=" +(((10-9)-8)-7));
	System.out.println(" 10-(9-(8-7))=" +(10-(9-(8-7))));
	System.out.println("(2)");
	System.out.println(" 20/5*2=" +(20/5*2));
	System.out.println(" (20/5)*2="+((20/5)*2));
	System.out.println(" 20/(5*2)="+((20/5)*2));
	
	System.out.println("(3)");
	System.out.println(" 10+20%3="+(10+20%3));
	System.out.println(" (10+20)%3="+((10+20)%3));
	System.out.println(" 10+(20%3)="+(10+(20%3)));
	
	System.out.println("(4)");
	System.out.println(" !true&&false="+(!true&&false));
	System.out.println(" (!true)&&false="+((!true)&&false));
	System.out.println(" !(true&&false)="+(!(true&&false)));
			   }
}
			   
/*********************************************
q238059h@ias005:~/program/network/1208$ java ex1
(1)
 10-9-8-7= -14
 ((10-9)-8)-7=-14
 10-(9-(8-7))=2
(2)
 20/5*2=8
 (20/5)*2=8
 20/(5*2)=8
(3)
 10+20%3=12
 (10+20)%3=0
 10+(20%3)=12
(4)
 !true&&false=false
 (!true)&&false=false
 !(true&&false)=true

*********************************************/
