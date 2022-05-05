/**
 *  Divide In Three Way
 *  -   You are given an array/list of N positive integers and a range [X, Y], 
 *      where 'X' and 'Y' are two integers. You are supposed to modify the given 
 *      array/list such that the following conditions will be satisfied:
 *      1. All the elements of the array strictly smaller than ‘X’ should come first.
 *      2. All the elements of the array between the range [X, Y] should come next.
 *      3. All the elements of the array strictly greater than ‘Y’ should come last.
 *      
 *  Input Format :
 *  -   The first line of the input contains an integer T denoting the number of 
 *      test cases.
 *  -   The first line of each test case contains three space-separated integers 
 *      N, X, Y, denoting the size of the array, the first element of the range, 
 *      and the second element of the range [X, Y] respectively.
 *  -   The second line of each test case contains N space-separated integers 
 *      representing the elements of the array.
 * 
 *  Output Format :
 *  -   The output of the test case will be “Correct” if you have modified the 
 *      array correctly else it will be “Incorrect” without quotes. 
 *  -   The output of each test case will be printed in a separate line.
 *  
 *  Note :
 *  -   You do not need to print anything, it has already been taken care of. 
 *      Just implement the given function.
 *  
 *  Constraints :
 *      1 <= T <= 5
 *      1 <= N <= 5000
 *      0 <= arr[i] <= 10^9
 *      0 <= a, b <= 10^9
 *  
 *  Sample Input 1 :
 *      1
 *      5 2 3   
 *      2 0 1 3 4
 *  Sample Output 1 :   
 *      Correct
 *  Explanation for Sample Output 1:
 *      After modifying the array according to the given condition, we will 
 *      get 0 1 2 3 4 . Since this element array satisfies the required properties, 
 *      so we will get output as Correct.
 *  
 *  Sample Input 2 :
 *      1
 *      5 4 6
 *      1 3 5 7 9
 *  Sample Output 2 :
 *      Correct
 */
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Solution5 {
    // Solution O(n)
    public static ArrayList<Integer> threeWayPartition(ArrayList<Integer> arr, int n, int a, int b) {
        int[] temp = new int[n];
        int j=0, k=n-1, countA=0, countB=0;
        for(int i=0; i<n; i++){
            if(arr.get(i)<a){
                temp[j++] = arr.get(i);
            } else if (arr.get(i) == a) {
                countA++;
            }else if (arr.get(i) > b){
                temp[k--] = arr.get(i);
            } else if(arr.get(i) == b){
                countB++;
            }
        }
        while(j<k && countA > 0){
            temp[j++] = a;
        }
        while(j<k && countB > 0){
            temp[j++] = b;
        }
        for(int i=0; i<n; i++){
            arr.set(i, temp[i]);
        }
        return arr;
    }

    // Another way - Enhanced - O(n)
    public static ArrayList<Integer> threeWayPartitionEnhanced(ArrayList<Integer> arr, int n, int a, int b) {
        int low=0, high=n-1;
        int idx = 0;
        while(idx <= high){
            if(arr.get(idx) < a){
                int temp = arr.get(idx);
                arr.set(idx, arr.get(low));
                arr.set(low, temp);
                idx++;
                low++;
            } else if (arr.get(idx) > b){
                int temp = arr.get(idx);
                arr.set(idx, arr.get(high));
                arr.set(high, temp);
                high--;
            } else {
                idx++;
            }
        }
        return arr;
    }

    // Solution O(nlogn)
    public static ArrayList<Integer> threeWayPartitionSorting(ArrayList<Integer> arr, int n, int a, int b) {
        Collections.sort(arr);
        return arr;
    }
}

public class P005_Divide_In_Three_Way {

    private static int t;
    private static ArrayList<ArrayList<Integer>> tArrays;
    private static ArrayList<ArrayList<Integer>> tvalues;

    private static void takeInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine().split(" ")[0]);

        tArrays = new ArrayList<ArrayList<Integer>>(t);
        tvalues = new ArrayList<ArrayList<Integer>>(t);
        String []data;

        for (int i = 0; i < t; i++) {
            data = br.readLine().trim().split(" ");
            int n, a, b;
            n = Integer.parseInt(data[0]);
            a = Integer.parseInt(data[1]);
            b = Integer.parseInt(data[2]);


            tArrays.add(new ArrayList<Integer>(n));
            data = br.readLine().trim().split(" ");

            for (int j = 0; j < n; j++) {
                tArrays.get(i).add(Integer.parseInt(data[j]));
            }
            tvalues.add(new ArrayList<Integer>(2));
            tvalues.get(i).add(n);
            tvalues.get(i).add(a);
            tvalues.get(i).add(b);
        }
    }

    private static void executeAndPrintOutput() {
        for (int i = 0; i < t; i++) {

            ArrayList<Integer> ans = Solution5.threeWayPartition(tArrays.get(i), tvalues.get(i).get(0), tvalues.get(i).get(1), tvalues.get(i).get(2));
            String result = new String("Incorrect");
            int a = tvalues.get(i).get(1);
            int b = tvalues.get(i).get(2);
            if (checkHash(ans, tArrays.get(i)) && checker(ans, a, b))
                result = new String("Correct");
            System.out.print( result + "\n");
        }
    }

    private static boolean checkHash(ArrayList<Integer> a, ArrayList<Integer>  b) {
        Collections.sort(a);
        Collections.sort(b);

        for (int i = 0; i < a.size(); i++)
            if (a.get(i).equals(b.get(i)) == false)
                return false;
        return true;
    }

    private static boolean checker(ArrayList<Integer>  arr, int a, int b) {
        int n = arr.size();
        int less = 0, big = 0;
        for (int e : arr) {
            if (e < a) less++;
            if (e > b) big++;
        }
        boolean ok = true;
        int lessIdx = less - 1;
        int bigIdx = n - big;
        for (int i = 0; (i < n) && ok; i++) {
            if (i <= lessIdx && arr.get(i) >= a) {
                ok = false;
            }
            if (i >= bigIdx && arr.get(i) <= b) {
                ok = false;
            }
            if (i > lessIdx && i < bigIdx) {
                if (arr.get(i) < a || arr.get(i) > b) {
                    ok = false;
                }
            }
        }
        return ok;
    }

    public static void main(String[] args) throws IOException {
        takeInput();
        executeAndPrintOutput();
    }
}