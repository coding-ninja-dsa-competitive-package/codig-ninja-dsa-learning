/**
 *  Trapped Water In Bars
 *  -   Ninja was feeling bored today. He went for a walk and thought of a problem. 
 *      You are given 'N' bars where each bar has an integral length denoted by an 
 *      array ARR[i]. It represents an elevation map wherein ARR[i] denotes the 
 *      elevation of the i-th bar. Your task is to write a function that returns 
 *      the total amount of rainwater that can be trapped in these elevations.
 *  
 *  Note :
 *  -   The width of each bar is the same and is equal to 1.
 *  
 *  Input format :
 *  -   The first line contains an integer 't' which denotes the number of test 
 *      cases or queries to be run. Then the test cases follow.
 *  -   The first line of each test case or query contains an integer 'N' 
 *      representing the size of the array/list.
 *  -   The second line contains 'N' single space-separated integers representing 
 *      the elevation of the bars.
 *  
 *  Output Format :
 *  -   For each test case, return the total water that can be trapped.
 *  -   Output for every test case will be printed in a separate line.
 *  
 *  Constraints :
 *      1 <= T <= 10
 *      0 <= N <= 10^4
 *      0 <= ARR[i] <= 10^5
 * 
 *  Time Limit: 1 sec
 *      
 *  Sample Input 1 :
 *      2
 *      3
 *      1 2 3
 *      3
 *      3 2 1
 *  Sample Output 1 :
 *      0
 *      0
 *  
 *  Sample Input 2 :
 *      2
 *      1
 *      100
 *      3
 *      5 1 5
 *  Sample Output 2 :
 *      0
 *      4
 *  
 *  Sample Input 3 :
 *      1
 *      5
 *      90 70 20 80 50
 *  Sample Output 3 :
 *      70
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Solution7 {
    // Solution O(3*n) => O(n)
    public static long getTrappedWater(long[] arr) {
        int n = arr.length;
        if(n <= 1){
            return 0;
        }
        long left[] = new long[n];
        long right[] = new long[n];
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        for(int i=1; i<n; i++){
            left[i] = Math.max(left[i-1], arr[i]);
        }
        for(int i=n-2; i>=0; i--){
            right[i] = Math.max(right[i+1], arr[i]);
        }
        long totalWater = 0;
        for(int i=0; i<n; i++){
            totalWater += Math.min(left[i], right[i]) - arr[i];
        }
        return totalWater;
    }
}

public class P007_Trapped_Water_In_Bars {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            long[] arr = takeInput();
            System.out.println(Solution7.getTrappedWater(arr));
        }
        br.close();
    }

    public static long[] takeInput() throws IOException {
        int size = Integer.parseInt(br.readLine().trim());
        long[] input = new long[size];
        if (size == 0) {
            return input;
        }

        String[] strNums;
        strNums = br.readLine().split("\\s");


        for (int i = 0; i < size; ++i) {
            input[i] = Long.parseLong(strNums[i]);
        }

        return input;
    }
}
