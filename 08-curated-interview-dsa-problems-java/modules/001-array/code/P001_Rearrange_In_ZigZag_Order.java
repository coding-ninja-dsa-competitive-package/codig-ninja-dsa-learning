/**
 *  Rearrange In ZigZag Order
 *  -   You are given an array/list 'ARR' of 'N' distinct elements. Rearrange 
 *      'ARR' elements in a zig-zag fashion such that for every odd position 
 *      ‘i’ in the array 'ARR', 'ARR'[i] should be greater than 'ARR'[i-1] and 
 *      'ARR'[i] should be greater than 'ARR'[i+1].
 *  -   For example:
 *          Given ‘N’ = 4, and 'ARR' = { 4, 3, 2, 1} 
 *          Then a possible zig zag rearrangement is 3, 4, 1, 2.
 *  -   Note:
 *      -   You are supposed to return the modified array. If there are multiple 
 *          answers for a particular array, any of the possible solutions are 
 *          accepted. It is given that a zig-zag array is always possible for 
 *          a given array.
 *  
 *  Input format:
 *  -   The first line of input contains an integer ‘T’ denoting the number of 
 *      test cases.
 *  -   The first line of each test case contains a single integer, ‘N,’ where 
 *      ‘N’ is the number of elements of the array.
 *  -   The second line of each test case contains ‘N’ space-separated integers, 
 *      denoting 'ARR' elements.
 *  
 *  Output Format :
 *  -   For each test case, print the elements of the given 'ARR' arranged in a 
 *      zig-zag manner. 
 *  -   The runner function will print a single line containing a single integer 
 *      which denotes whether the returned array is in zig-zag fashion or not.
 *  
 *  Note:
 *  -   You are not required to print the expected output; it has already been 
 *      taken care of. Just implement the function.
 *  
 *  Constraints:
 *      1 <= ‘T’ <= 10
 *      1 <= ‘N’ <= 5*10^3
 *      0 <= 'ARR'[i] <= 10 ^ 6
 *  
 *  Time Limit: 1sec.
 *   
 *  Sample Input 1 :
 *      2
 *      4
 *      4 3 2 1
 *      5
 *      2 4 6 8 10
 *  Sample Output 1 :
 *      1
 *      1   
 *  Explanation of the Sample Input 1:
 *  -   For the first test case :  
 *      One possible configuration can be 3 4 1 2. Therefore, the array can be 
 *      converted into a zig-zag fashion.
 *  -   For the second test case:
 *      One possible configuration can be 2, 8, 6, 10, 4. Therefore the given 
 *      array can be converted.
 *  
 *  Sample Input 2 :
 *      2
 *      4
 *      3 2 4 5
 *      5
 *      6 1 3 2 5
 *  Sample Output 2 :
 *      1
 *      1
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

class Solution1 {

    public static void swap(ArrayList<Integer> arr, int i, int j){
        int temp = arr.get(i);
        arr.set(i, arr.get(i+1));
        arr.set(i+1, temp);
    }

    // Efficient Approach - O(n)
	public static ArrayList<Integer> zigZag(ArrayList<Integer> arr, int n) {
        boolean flag = true;
        for (int i=0; i<n-1; i++){
            if (flag && arr.get(i) > arr.get(i+1)) {
                swap(arr, i , i+1);
            } else if(!flag && arr.get(i) < arr.get(i+1)) {
                swap(arr, i , i+1);
            }
            flag = !flag; 
        }
        return arr;
	}

    // Sorting Approach - O(nlogn) - TLE for large input set
	public static ArrayList<Integer> zigZagSortingApproach(ArrayList<Integer> arr, int n) {
        Collections.sort(arr);
        for (int i=1; i<n-1; i+=2){
            swap(arr, i, i+1);
        }
        return arr;
	}
}

public class P001_Rearrange_In_ZigZag_Order {
    private static int t;
    private static ArrayList<ArrayList<Integer>> arr;

    private static void takeInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine().split(" ")[0]);

        arr = new ArrayList<ArrayList<Integer>>(t);

        String []data;

        for (int i = 0; i < t; i++) {
            int n;
            n = Integer.parseInt(br.readLine().split(" ")[0]);
            data = br.readLine().trim().split(" ");
            arr.add(new ArrayList<Integer>(n));

            for (int j = 0; j < n; j++) {
                arr.get(i).add(Integer.parseInt(data[j]));
            }

        }
    }

    private static boolean check(ArrayList<Integer> arr, int n) {
        for (int i = 1 ; i < n ; i += 2) {
            if (i + 1 < n) {
                if (arr.get(i).intValue() < arr.get(i + 1).intValue()) {
                    return false;
                }
            }

            if (arr.get(i).intValue()  < arr.get(i - 1).intValue() ) {
                return false;
            }
        }
        return true;
    }

    private static void executeAndPrintOutput() {
        for (int i = 0; i < t; i++) {

            int sizearr = arr.get(i).size();
            ArrayList<Integer> ans = Solution1.zigZag(arr.get(i), sizearr);
            // ArrayList<Integer> ans = Solution.zigZagSortingApproach(arr.get(i), sizearr);

            int sizz = ans.size();
            boolean finalans = check(ans, sizz);
            if (finalans){
                System.out.println("1");
            } else {
                System.out.println("0");
            }
        }
    }

    public static void main(String[] args) throws IOException {
        takeInput();
        executeAndPrintOutput();
    }
}