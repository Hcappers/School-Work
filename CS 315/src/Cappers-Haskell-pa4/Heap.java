 import java.util.PriorityQueue;
 import java.util.List;

public class Heap {
    
    private PriorityQueue<BinaryTree.WordNode> wordHeap; //creating the heap

    public Heap(){
        wordHeap = new PriorityQueue<BinaryTree.WordNode>((a, b) -> Integer.compare(b.count, a.count)); // using a lambda expression to compare the counts of each node to sort the heap in descending order. 
    }

    public void addAll(List<BinaryTree.WordNode> list){
        wordHeap.addAll(list); //adding all the nodes to the heap
    }

    public boolean isEmpty(){
        return wordHeap.isEmpty(); //checking to see if the heap is empty
    }  
    public BinaryTree.WordNode poll(){
        return wordHeap.poll(); //polling the heap, this dequeues the first element in the heap
    }

    public void DescendingOrder(){
        printWordHeap(); //printing the heap in descending order
    }

    private void printWordHeap(){
        while(!wordHeap.isEmpty()){ //while the heap is not empty
            BinaryTree.WordNode wordheapNode = wordHeap.poll();
            System.out.println(wordheapNode.word + ", " + wordheapNode.count); //logic function on printing the heap word with the count that is has as well. 
        }

    }
}
