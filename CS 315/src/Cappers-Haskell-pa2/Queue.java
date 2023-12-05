import java.util.NoSuchElementException;

public class Queue<Item> {
  private int counter; // number of elements on queue

  // Node class made so the queue can be made
  private class Node {
    private Item item;
    private Node next;
  }

  private Node first; // beginning of the Queue
  private Node last; // end of the Queue

  public Queue() {
    first = null; // initializing the first node to null
    last = null; // initializing the last node to null
    counter = 0; // initializing the counter to 0
  }

  // the function of this method is to add a node at the last position due to FIFO
  public void enqueue(Item item) {
    Node oldLast = last; // saves the value of the last node
    last = new Node(); // creates a new node in the last position
    last.item = item; // Takes the item value that was passed in and puts it into the node that was
                      // just created
    last.next = null; // sets the next node to null
    if (isEmpty()) {
      first = last;
    } else {
      oldLast.next = last;
    }
    counter++; // increment the counter by one to show that there is another node in the queue.
  }

  // the function of this method is to remove the most recently added item
  public Item dequeue() {
    if (isEmpty())
      throw new NoSuchElementException("Error: The queue is empty");
    Item item = first.item; // save item to return
    first = first.next; // delete first node
    // if item is not equal to null then the counter goes down by one
    if (item != null) {
      counter--;
    }
    return item; // returns the item that was deleted
  }

  // the function of this method is to get the item at the front of the list
  public Item peek() {
    if (isEmpty())
      throw new NoSuchElementException("Error: The queue is empty");
    return first.item;
  }

  //the function of this method is to print the queue in order
  public void printFwd() {
    if(isEmpty()) throw new NoSuchElementException("Error: The queue is empty");
    Node curr = first; // setting the current node to the head
    // loop to go through the list until the current node is equal to the location
    for (int i = 0; i < counter; i++) {
      // if the current node is equal to null then the list is empty
      if (curr == null) {
        System.out.println("The queue is empty");
      }
      // print the info of the current node
      System.out.println(curr.item);
      // setting the current node to the next node
      curr = curr.next;
    }
  }

  // the function of this method is to see if the queue is empty
  public boolean isEmpty() {
    return (first == null);
  }

  // the function of this method is to get the size of the queue
  public int size() {
    return counter;
  }

  public static void main(String[] args) {
    TestQueue.testingQueue(new Queue<String>()); 
  }
}
