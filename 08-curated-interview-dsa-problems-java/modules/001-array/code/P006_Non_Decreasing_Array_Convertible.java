/**
 *  Non-Decreasing Array Convertible
 *  -   You have been given an integer array/list 'ARR' of size 'N'. You are 
 *      supposed to tell that if it could become non-decreasing by modifying at 
 *      most 1 element.
 *  -   We define an array as non-decreasing, if ARR[i] <= ARR[i + 1] holds for 
 *      every i (0-based) such that (0 <= i <= N - 2).
 *  
 *  Input format :
 *  -   The first line contains an integer 'T' which denotes the number of test 
 *      cases or queries to be run. Then the test cases follow.
 *  -   The first line of each test case contains an Integer 'N' denoting the 
 *      size of the array/list.
 *  -   The second line of each test case contains 'N' space-separated Integers 
 *      denoting the array/list.
 *  
 *  Output format :
 *  -   For each test case, print a single line containing "true" if it's possible 
 *      to make 'ARR' non-decreasing array with modifying at most one element or 
 *      "false" otherwise. 
 *  -   The output for every test case will be printed in a separate line.
 *  
 *  Note :
 *  -   You do not need to print anything, it has already been taken care of.  
 *      Just implement the given function.
 *  
 *  Constraints :
 *      1 <= T <= 50
 *      1 <= N <= 10 ^ 4
 *      - 10 ^ 9 <= ARR[i] <= 10 ^ 9
 *      Where 'N' is the size of the given array/list.
 *      And, ARR[i] denotes the i-th element in the array/list 'ARR'.
 * 
 *  Time Limit: 1sec
 *  
 *  Sample Input 1 :
 *      2
 *      4
 *      10 2 7 5
 *      3   
 *      8 4 2
 *  Sample Output 1 :
 *      true
 *      false
 *  Explanation to Sample Input 1 :
 *  -   For Test Case 1 we can have a possible non-decreasing array: 10 8 7 5
 *      Where only the element at index 1 has been modified.
 *  -   For Test Case 2 there is no possible way to make the array non-decreasing 
 *      by modifying at most 1 element.
 *  
 *  Sample Input 2 :
 *      2
 *      6
 *      -2 -7 -8 -9-10 2
 *      5
 *      31 31 31 31 31
 *  Sample Output 2 :
 *      true
 *      false
 *  Explanation to Sample Input 2 :
 *  -   For Test Case 1 we can have a possible non-decreasing array: 
 *      -2 -7 -8 -9-10 -12
 *      Where only the element at index 5 has been modified
 *  -   For Test Case 2 there is no possible way to make the array non-decreasing 
 *      by modifying at most 1 element.
 */
import java.util.Scanner;

class Solution6 {
    // Solution O(n)
    public static boolean isPossible(int[] arr, int n) {
        int modCount = 0;
        for (int i=1; i<n; i++) {              
            if (arr[i] < arr[i-1]) {
                modCount++;
                if (i == 1 || i == n-1) {
                    continue;
                }
				// if element to modify is arr[i] or arr[i-1]
                if ((arr[i-1] <= arr[i+1]) || (arr[i-2] <= arr[i])) {
                    continue;
                }
                return false;
            }
        }
        return modCount <= 1;
    }
}

public class P006_Non_Decreasing_Array_Convertible {
    static Scanner s = new Scanner(System.in);

    public static void main(String[] args) {
        int testCases = s.nextInt();
        while (testCases > 0) {
            int n = s.nextInt();
            int arr[] = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = s.nextInt();
            }
            if (Solution6.isPossible(arr, n)) {
                System.out.println("true");
            } else {
                System.out.println("false");
            }
            testCases--;
        }
    }
}
