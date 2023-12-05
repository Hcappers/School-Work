import java.util.NoSuchElementException;

public class LinkedList <Item> implements List <Item> {
  // Node class that will be used to create the linked list
  private class Node {
    Item info;
    Node next;
  }

  private Node head; // head of the list
  private Node tail; // tail of the list

  // makes an empty linked list
  public LinkedList() {
    head = null;
    tail = null;
  }

  // the funcktion of this method is to get the item at a certain location
  public Item getAt(int loc) {
    if(isEmpty() || loc < 0) throw new NoSuchElementException("Stack underflow");
    Node curr = head; // setting the current node to the head
    // loop to go through the list until the current node is equal to the location
    for (int i = 0; i < loc; i++) {
      // if the current node is equal to null then the list is empty
      if (curr == null) {
        return null;
      }
      // setting the previous node to the current node
      curr = curr.next;
    }
    // return the info of the current node
    return curr.info;
  }

  // the function of this method is to delete an item at a certain location
  public Item deleteAt(int loc) {
    if(isEmpty() || loc < 0) throw new NoSuchElementException("Stack underflow");
    Node curr = head; // setting the current node to the head
    Node prev = null; // setting the previous node to null
    // loop to go through the list until the current node is equal to the location
    for (int i = 0; i < loc; i++) {
      // if the current node is equal to null then the list is empty
      if (curr == null) {
        return null;
      }
      // setting the previous node to the current node
      prev = curr;
      // setting the current node to the next node
      curr = curr.next;
    }
    // if the current node is equal to the head then the head moves to the next node
    if (curr == head) {
      head = head.next;
    } else {
      // if the current node is not equal to the head then the previous node moves to
      // the next node
      prev.next = curr.next;
    }
    // if the current node is equal to the tail then the tail moves to the previous
    // node
    if (curr == tail) {
      tail = prev;
    }
    // return the info of the current node
    return curr.info;
  }

  // the function of this method is to add an item to the head of the list
  public void addToHead(Item item) {
    Node newNode = new Node();
    newNode.info = item;
    newNode.next = head;
    head = newNode;
    // if the tail is equal to null then the tail is equal to the new node
    if (tail == null) {
      tail = newNode;
    }
  }

  // the function of this method is to add an item to the back of the list
  public void addToTail(Item item) {
    Node newNode = new Node();
    newNode.info = item;
    newNode.next = null; //
    if (tail == null) {
      head = newNode;
    } else {
      tail.next = newNode;
    }
    tail = newNode;
  }

  // the function of this method is to add an item at a certain location
  public void addAt(int loc, Item item) {
    Node newNode = new Node();
    newNode.info = item;
    Node curr = head;
    Node prev = null;
    for (int i = 0; i < loc; i++) {
      if (curr == null) {
        return;
      }
      prev = curr;
      curr = curr.next;
    }
    if (curr == head) {
      newNode.next = head;
      head = newNode;
    } else {
      newNode.next = curr;
      prev.next = newNode;
    }
    if (curr == null) {
      tail = newNode;
    }
  }

  // the function of this method is to print the list forward
  public void printFwd() {
    if (isEmpty())throw new NoSuchElementException("Stack underflow");
    Node curr = head;
    while (curr != null) {
      System.out.println(curr.info + " ");
      curr = curr.next;
    }
  }

  // the function of this method is to print the list backwards
  public void printRev() {
    if (isEmpty())throw new NoSuchElementException("Error");
    Node curr = head;
    Node prev = null;
    Node next = null;
    while (curr != null) {
      next = curr.next;
      curr.next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
    curr = head;
    while (curr != null) {
      System.out.println(curr.info);
      curr = curr.next;
    }
  }

  // the function of this method is to check if the list is empty
  public boolean isEmpty() {
    return (head == null);
  }

  public static void main(String[] args) {
    TestLinkedList.testLL(new LinkedList<Integer>());
  }
}
