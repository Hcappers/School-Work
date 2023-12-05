/*
 * Author: Haskell Cappers (2521071)
 * Project: PA2 - LinkedList, Stack, and Queue
 * Colaborators: 
 * Course: CS315
 * Due Date: October 6, 2023
 * Purpose: The purpose of this program is to create a Stack and to be able to add items to the back of the list, remove the most recently added item, get the item at the front of the list, see if the stack is empty, and get the size of the stack.
 */
import java.util.NoSuchElementException;

public class Stack <Item> {
    int counter;
    Node first;
    Node last;
    private class Node {
        private Item item;
        private Node next;
    }
    public Stack() {
        first = null;
        last = null;
        counter = 0;
    }
    //the function of this method is to add an item to the front of the list
    public void push(Item item){
        Node oldFirst = first; //saves the old first node 
        first = new Node(); //makes a new node at the new first
        first.item = item; //
        first.next = oldFirst; //
        counter++; //increase the counter for the size of the stack
    }
    //the function of this method is to remove an item from the front of the list and return the delete item
    public Item pop(){
        if(isEmpty()) throw new NoSuchElementException("Stack underflow");
        Item item = first.item; //save item to return
        first = first.next; //delete first node
        //if item is not equal to null then the counter goes down by one
        if(item != null){
            counter--;
        }
        return item; //returns the item that was deleted
    }
    //the function of this method is to get the item at the front of the list
    public Item top(){
        if(isEmpty()) throw new NoSuchElementException("Stack underflow");
        return first.item;
    }
    //the function of this method is to print the stack in order
    public void printFwd(){
        Node current = first;
        while(current != null){
            System.out.println(current.item);
            current = current.next;
        }
    }
    //the function of this method is to see if the stack is empty
    public boolean isEmpty(){
        return first == null;
    }
    public int size(){
        return counter;
    }
    public static void main(String[] args){
        TestStack.testStack(new Stack<String>());
    }
}
