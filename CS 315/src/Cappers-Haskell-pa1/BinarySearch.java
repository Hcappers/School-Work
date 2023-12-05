public class BinarySearch{
	public static void main(String[] args){
    	int[] array = new int[args.length - 1]; //array is the size of the arguments minus the key
    	int key = Integer.parseInt(args[0]); //key is the first argument
    	int index = -1; //index is the return value
    	for(int i = 0; i < args.length - 1; i++){ //fill array with the rest of the arguments
   	  		array[i] = Integer.parseInt(args[i+1]);
    	}
    	index = rank(key, array); //call rank method
    	System.out.println("Index = " + index); 
	}
	//Source: Algorithms textbook, by: Robert Sedgewick & Kevin Wayne
	public static int rank(int key, int[] a){ 
		return rank(key, a, 0, a.length - 1); //
	}
	public static int rank(int key, int[] a, int lo, int hi){ 
		if (lo > hi){
			return -1;
		}
		int mid = lo + (hi - lo) / 2;
		if (key < a[mid]){ 
			return rank(key, a, lo, mid - 1);
		}else if (key > a[mid]){
			return rank(key, a, mid + 1, hi);
		}else{
			return mid;
		}
	}
}
