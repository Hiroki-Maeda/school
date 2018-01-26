import java.io.*;
class Ex1 {
static double matAvrDiagElements(int[][] a){
    return (a[0][0]+a[1][1]+a[2][2])/3.0;
}
static void matProduct(int[][] a, int[][] b, int[][] c){
    int[][] temp=new int[3][3]; 
    for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
	    temp[i][j]=0;
	    for(int k=0;k<3;k++){
		temp[i][j]+=a[i][k]*b[k][j];
	    }

	}
    }
    for(int i=0;i<3;i++){y
	for(int j=0;j<3;j++){
	    c[i][j]=temp[i][j];
	}
    }
}
static void mat4thPower(int[][] a, int[][] d){

    for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
	    d[i][j]=a[i][j];
	}
    }
        for(int i=0;i<3;i++){
    	matProduct(a,d,d);
	   }
}
public static void main(String[] args){
int[][] a = {{1,2,3},{4,5,6},{7,8,9}};
int[][] b = {{9,8,7},{6,5,4},{3,2,1}};
double av;
int[][] c = new int[3][3];
int[][] d = new int[3][3];
av = matAvrDiagElements(a);
System.out.println(av);
matProduct(a,b,c);
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
System.out.print(c[i][j]+"\t");
}
System.out.println();
}
mat4thPower(a,d);
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
System.out.print(d[i][j]+"\t");
}
System.out.println();
}
}
}
