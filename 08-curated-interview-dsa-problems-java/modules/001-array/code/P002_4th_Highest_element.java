/**
 *  4th Highest Element
 *  -   Given an array 'ARR' of 'N' integers. Find the fourth highest element present 
 *      in the give 'ARR'. Return the minimum value of an integer which is -2147483648 
 *      if there it does not exists.
 *  
 *  Input format:
 *  -   The first line of input contains the integer 'N' representing the size of 
 *      the array.
 *  -   The second line of input contains N space-separated integers representing 
 *      the array elements.
 *  
 *  Output Format:
 *  -   The only output line contains the fourth-largest element if present, otherwise 
 *      print -2147483648
 *  
 *  Note:
 *  -   You are not required to explicitly print the output, it has already been 
 *      taken care of. Just implement the function.
 *  
 *  Constraints :
 *      1 <= N < 10^6
 *      -10^6 <= ARR[i] <= 10^6
 *      Where 'ARR[i]' denotes the 'ARR' element at 'ith' position.
 *  
 *  Time Limit: 1 sec
 *  
 *  Follow Up:
 *      Try solving this problem in O(N) time complexity.
 *  
 *  Sample Input 1:
 *      5
 *      3 5 1 3 1
 *  Sample Output 1:
 *      1
 *  Explanation Of Sample Input 1:
 *      5 is the largest element, 3 is the second-largest element, again we have a 3 so 
 *      it's the third largest and 1 is the fourth-largest, hence the answer 1.
 *  
 *  Sample Input 2:
 *      4
 *      9 9 9 9
 *  Sample Output 2:
 *      9
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;

class Solution2 {   
    // Solution using PriorityQueue - O(n)
    public static int getFourthLargest(int[] arr) {
        if(arr.length < 4){
            return Integer.MIN_VALUE;
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i=0; i<arr.length; i++){
            pq.add(arr[i]);
            if(pq.size() > 4){
                pq.poll();
            }
        }
        return pq.peek();
    }
    
    // Solution Sorting - O(nlogn)
    public static int getFourthLargestSorting(int[] arr) {
        Arrays.sort(arr);
        int index = arr.length - 4;
        if(index < 0){
            return Integer.MIN_VALUE;
        }
        return arr[index];
    }
}

public class P002_4th_Highest_element {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static int[] takeInput() throws IOException {
        int n = Integer.parseInt(br.readLine().trim());
        int arr[] = new int[n];
        if (n == 0) {
            return arr;
        }
        String[] listInts = br.readLine().split("\\s");
        for (int i = 0; i < n; ++i) {
            arr[i] = Integer.parseInt(listInts[i]);
        }
        return arr;
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        int[] arr = takeInput();
        System.out.println(Solution2.getFourthLargest(arr));
        // System.out.println(Solution2.getFourthLargestSorting(arr));
    } 
}
