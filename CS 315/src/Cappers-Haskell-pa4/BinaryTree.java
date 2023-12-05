/*
 * Assignment: PA4 - BST and Heap
 * File Name: BinaryTree.java
 * Author: Haskell Cappers (2521071)
 * Date: 2/26/2019
 * Description: This program takes in a text file and counts the number of times each word appears in the file. 
 * It will sort the words and sort them aphabetically. Each time the word shows up it increases the count by one. 
 * It will then print out the words and the number of times they appear in the file.
 * After building the binary tree, this program will then add the words to a heap and sort them by the number of times they appear.
 * It will then print out the words and the number of times they appear in the file in descending order.
*/
import java.util.ArrayList;
import java.util.List;

public class BinaryTree {

  private WordNode root; //creating the root node

  public BinaryTree() {
    root = null;
  }

  public static class WordNode { //building the nodes for the tree with the giving information.
    String word;
    WordNode left;
    WordNode right;
    int count;

    public WordNode(String word) { //constructor for the nodes
      this.word = word;
      this.left = null;
      this.right = null;
      this.count = 1;
    }
  }
   
  private WordNode insert(WordNode root, String word) { //inserting the nodes into the tree
    if (root == null) {
      return new WordNode(word);
    }

    int comparison = word.compareTo(root.word); //comparing the words to see where they go in the tree

    if (comparison < 0) { //if the word is less than the root it goes to the left
      root.left = insert(root.left, word);
    } else if (comparison > 0) { //if the word is greater than the root it goes to the right
      root.right = insert(root.right, word);
    }else{
      root.count++; //if the word is the same as the root it increases the count by one
    }

    return root;
  }

  public void insert(String word) {
    root = insert(root, word); //inserting the nodes into the tree
  }

  public void inOrderTraversal(WordNode root, List<WordNode> list){
    if (root != null){
      inOrderTraversal(root.left, list); //traversing the tree in order
      list.add(root);//adding the nodes to the list
      inOrderTraversal(root.right, list);//traversing the tree in order
    }
  }

  public void inOrderTraversal(){
    List <WordNode> traversedList = new ArrayList<>();//creating a list to store the nodes
    inOrderTraversal(root, traversedList);//traversing the tree in order

    for (WordNode node : traversedList){
      System.out.println(node.word + ", " + node.count);//printing out the nodes
    }
  }

  public void buildHeap(Heap wordHeap){
    List <WordNode> traversedList = new ArrayList<>();//creating a list to store the nodes
    inOrderTraversal(root, traversedList);//traversing the tree in order
    wordHeap.addAll(traversedList);//adding the nodes to the heap based on the number of times they appear
  }
}
