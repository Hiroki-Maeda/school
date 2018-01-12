class Sum{
    public static void main(String[] args){
	int sum;
	int i;

	sum =0;
	for(i=0;i<args.length; i++){
	    sum+= Integer.parseInt(args[i]);
	}
	//System.out.println(args.length);
	//System.out.println(args[0]);
	System.out.println("sum= "+sum);
    }
}
