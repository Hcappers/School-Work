public class TestStack {
    public static void testStack(Stack<String> stack){
        System.out.println("Testing Stack");
        System.out.println("The stack is currently empty: " + stack.isEmpty()); //expect true

        //Testing the push method
        stack.push("First");
        //Testing the top method
        System.out.println("The item at the top of the stack is: " + stack.top()); //expect First
        stack.push("Second");
        //Testing the top method again
        System.out.println("The item at the top of the stack is: " + stack.top()); //expect Second
        stack.push("Third");
        //Teting the top method again
        System.out.println("The item at the top of the stack is: " + stack.top()); //expect Third

        //Testing the size method
        System.out.println("The size of the stack is currently: " + stack.size()); //expect 3
        //Testing the printFwd method
        stack.printFwd(); //expect Third, Second, First

        //Testing the pop method
        System.out.println("The item that was deleted was: " + stack.pop()); //expect Third
        System.out.println("The item that was deleted was: " + stack.pop()); //expect Second
        System.out.println("The item that was deleted was: " + stack.pop()); //expect First

        //Testing the isEmpty method again
        System.out.println("The stack is currently empty: " + stack.isEmpty()); //expect true
        System.out.println("The size of the stack is currently: " + stack.size()); //expect 0
        System.out.println("Testing Stack Complete");
    }
}
