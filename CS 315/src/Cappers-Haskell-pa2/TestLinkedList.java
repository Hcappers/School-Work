public class TestLinkedList {
    public static void testLL(List<Integer> list){
        System.out.print("Testing LinkedList");
        // Test case to see if the method for checking if the list is empty works
        System.out.println("Test Case for isEmpty() method");
        System.out.println(list.isEmpty());
    
        // Test cases to check if the method for adding to the head works
        System.out.println("Test Case for addToHead() method");
        list.addToHead(0);
        list.addToHead(2);
        list.addToHead(3);
        list.addToHead(4);
        list.addToHead(9);
    
        // test case to check if the method for adding to the tail works
        System.out.println("Test Case for addToTail() method");
        list.addToTail(5);
        list.addToTail(4);
        list.addToTail(9);
        list.addToTail(3);
        list.addToTail(2);
    
        // test case to check if the method for printing forward works
        System.out.println("Test Case for printFwd() method");
        list.printFwd();
    
        // test case to check if the method for printing backwards works
        System.out.println("Test Case for printRev() method");
        list.printRev();
    
        // test case to check if the method for checking if the list is empty works
        System.out.println("Anoter Test Case for isEmpty() method");
        System.out.println(list.isEmpty());
    
        // test case to check if the method for getting the item at a certain location
        // works
        System.out.println("Test Case for getAt() method");
        System.out.println(list.getAt(0));
        System.out.println(list.getAt(1));
        System.out.println(list.getAt(2));
        System.out.println(list.getAt(3));
        System.out.println(list.getAt(4));
    
        // test case to check if the method for deleting an item at a certain location
        // works
        System.out.println("Test Case for deleteAt() method");
        System.out.println(list.deleteAt(0));
        System.out.println(list.deleteAt(1));
        System.out.println(list.deleteAt(2));
        System.out.println(list.deleteAt(3));
        System.out.println(list.deleteAt(4));
    
        // test case to check if the method for adding an item at a certain location
        // works again
        System.out.println("Another Test Case for printFe method");
        list.printFwd();
    
        // test case to check if the method for printing backwards works again
        System.out.println("Another Test Case for printRev() method");
        list.printRev();
        System.out.println("Testing LinkedList Complete");
    }
    
}
