public class TestQueue {
    public static void testingQueue(Queue<String> queue){
        System.out.println("Testing Queue");
        System.out.println("The queue is currently empty: " + queue.isEmpty()); //expect true
        
        //Testing the enqueue method
        queue.enqueue("First");
        queue.enqueue("Second");
        queue.enqueue("Third");
        
        //Testing the size method
        System.out.println("The size of the queue is currently: " + queue.size()); //expect 3
        
        //Testing the printFwd method for testing the order of the queue
        queue.printFwd(); //expect First, Second, Third

        //Testing the peek method
        System.out.println("The top of the queue is: " + queue.peek()); //expect First

        //Testing the dequeue method
        System.out.println("The item that was removed from the queue is: " + queue.dequeue()); //expect First

        //Testign peek method again
        System.out.println("The top of the queue is: " + queue.peek()); //expect Second
        
        //Testing dequeue method again
        System.out.println("The item that was removed from the queue is: " + queue.dequeue()); //expect Second

        //Testing the peek method again
        System.out.println("The top of the queue is: " + queue.peek()); //expect Third
        
        //Testing dequeue method again
        System.out.println("The item that was removed from the queue is: " + queue.dequeue()); //expect Third

        //Testing the isEmpty method again
        System.out.println("The queue is currently empty: " + queue.isEmpty()); //expect true

        System.out.println("Testing Queue Complete");
    }
}