/*
 * Author: Haskell Cappers (2521071)
 * Project: PA3 - Complexity and Sorting
 * Colaborators: David Greni
 * Implemented by: Haskell Cappers
 * Course: CS315
 * Due Date: October 30, 2023
 * Purpose: The purpose of this code is to implent the bubble sort while using a test client to test the code.
 */
public class BubbleSort {

    public void bSort(int array [], int x){
        if (x == 1){
            return;
        }

        for (int i = 0; i < x - 1; i++){
            if (array[i] > array[i + 1]){
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
            bSort(array, x - 1);
        }
    }
}