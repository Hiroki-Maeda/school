class Array_Sample {
    public static void main(String[] args){
	int sum;
	int sum2;
	int i;
	int[] a ={1,2,3,4,5};
	int[] b;
	b = new int[]{6,7,8,9,10};
	int[] c = new int[5];

	sum=0;
	for(i=0;i<a.length;i++){
	    sum+= a[i];
	}
	System.out.println("sum= "+sum);

	for(i=0;i<b.length;i++){
	    c[i]=b[i];
	    System.out.println("value= "+c[i]);
	   
		}
	sum2=0;
	for(i=0;i<c.length;i++){
	    sum2+= c[i];
	}
	System.out.println("sum2= "+sum2);
    }
}
