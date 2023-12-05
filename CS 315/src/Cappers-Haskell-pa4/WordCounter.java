 public class WordCounter {

  private BinaryTree wordTree;
  private Heap wordHeap;

  public WordCounter(){
    wordTree = new BinaryTree();
    wordHeap = new Heap();
  }

  public void countWords(String [] words){
    for (String word : words){//for each word in the array of words
      wordTree.insert(word);//insert the word into the tree
    }
    wordTree.buildHeap(wordHeap);//build the heap
  }
  

  public static void main(String[] args) {
    String input = "input.txt";//input file
    WordCounter wordCounter = new WordCounter();//creating a new word counter
    System.out.println("Printing the words from the binary tree in order and the words from the heap in descending order.");
    System.out.println("Alphabetical order: ");
    wordCounter.countWords(InputReader.parseInputFile(input)); //counting the words in the input file
    wordCounter.wordTree.inOrderTraversal(); //printing the words in the tree in order
     System.out.println();
    System.out.println("Descending order:");
    wordCounter.wordHeap.DescendingOrder(); //printing the words in the heap in descending order
  }
}
