import java.io.*;
class Seq {
char nc;
Seq next;
}
class Ex2 {
static int chkCdn(String sq, String cdn)
    int count=0;
    for(int i=0;sq[3+i]!=\0;i++){
	if(sq.charAt(0+i)==cdn.charAt(0+i)){
	    if(sq.charAt(1+i)==cdn.charAt(1+i)){
		if(sq.charAt(2+i)==sq.charAt(2+i)){
		    count++;
		}
	    }
	}
	
    }
    return count;
}
static Seq srchS(Seq sq,String startcdn){

}
static Seq srchE(Seq sq,String[] stopcdn){
省略
}
public static void main(String[] args){
String mrna="GCAUGCAUGCGCAUGUGUAAGCAU";
String startcdn="AUG";
String[] stopcdn ={"UAA","UAG","UGA"};
Seq sq1,sq2,sq2end,sq2stop;
Seq pt;
int nth=0;
int numfound = chkCdn(mrna,startcdn);
System.out.println(numfound);
sq1 = new Seq();
pt= sq1;
for(nth=0;nth<mrna.length()-1;nth=nth+1){
pt.nc=mrna.charAt(nth);
pt.next= new Seq();
pt=pt.next;
}
pt.nc=mrna.charAt(nth);
pt.next=null;
for(pt=sq1;pt!=null;pt=pt.next){
System.out.print(pt.nc);
}
System.out.println();
sq2=srchS(sq1,startcdn);
if(sq2==null){
System.out.println("Start: Not found");
} else{
sq2stop=srchE(sq2,stopcdn);
if(sq2stop==null){
System.out.println("Stop: Not found");
} else {
sq2end=sq2stop.next.next.next;
for(pt=sq2;pt!=sq2end;pt=pt.next){
System.out.print(pt.nc);
}
System.out.println();
}
}
}
}
