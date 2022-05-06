/**
 *  Ninja vs Board
 *  -   Ninja is feeling bored today. So he went for a walk and thought of a 
 *      problem. Can you help him in solving it?
 *  -   He has a 2D board ‘ARR’ with ‘N’ rows and ‘M’ columns. He wants is to 
 *      find a rectangle having the maximum sum on the board.
 *  -   Rectangle sum is the sum of values of integers present within its boundary.
 *      For Example
 *          Consider following matrix:
 *              1   2   -1  -4  -20
 *              -8  -3   4   2   1
 *              3   8    10  1   3
 *              -4   -1  1   7   -6 
 *  
 *      The rectangle (1,1) to (3,3) is the rectangle with the maximum sum, i.e. 29.
 *                  -3  4   2
 *                  8   10  1
 *                  -1  1   7
 * 
 *  Input Format
 *  -   The first line of input contains an integer ‘T’ denoting the number of 
 *      test cases to run. Then the test cases follow.
 *  -   The first line of each test case contains two space-separated integers 
 *      ‘N’ and ‘M’ denoting the number of rows and number of columns respectively.
 *  -   The next ‘N’ lines contain ‘M’ space-separated integers denoting the 
 *      elements of ARR.    
 *  
 *  Output Format
 *  -   For each test case, print the value of the sum for the maximum sum rectangle.
 *  -   Print the output of each test case in a separate line.
 *  
 *  Note
 *  -   You do not need to print anything; it has already been taken care of. 
 *      Just implement the given function.
 *  
 *  Constraints
 *       1 <= T <= 10
 *       1 <= M, N <= 75
 *       -10^5 <= ARR[i][j] <= 10^5
 *  Time Limit: 1 sec
 *  
 *  Sample Input 1
 *      2
 *      1 2
 *      -1 1
 *      2 2
 *      -1 1
 *      2 2
 *  Sample Output 1
 *      1   
 *      4
 *  Explanation of Input 1
 *      The maximum sum rectangle corresponding to the first test case is-
 *                  1
 *      The maximum sum rectangle corresponding to the second test case is-
 *                  2 2
 *  
 *  Sample Input 2
 *      1
 *      4 5
 *      1 2 -1 -4 -20
 *      -8 -3  4 2 1
 *      3  8 10 1 3
 *      -4 -1 1 7 -6
 *  Sample Output 2
 *      29
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

class Solution9{
    private static int kadane(int arr[], int n){
        int currSum=0, maxSoFar=Integer.MIN_VALUE;
        for(int i=0; i<n; i++){
            currSum += arr[i];
            if(currSum > maxSoFar){
                maxSoFar = currSum;
            }
            if(currSum < 0){
                currSum = 0;
            }
        }
        return maxSoFar;
    }

    public static int maxSumRectangle(int[][] arr, int n, int m){
        int maxSum = Integer.MIN_VALUE;
        // starting column (i)
        for(int i=0; i<m; i++){
            int[] temp = new int[n];
            // loop from starting column to last column
            for(int j=i; j<m; j++){
                // loop from 0th row to last row
                for(int k=0; k<n; k++){
                    temp[k] += arr[k][j];
                }
                maxSum = Math.max(maxSum, kadane(temp, n));
            }
        }
        return maxSum;
    }
}

public class P009_Ninja_Vs_Board {
    private static int t;
    private static ArrayList<Integer> ns;
    private static ArrayList<Integer> ms;
    private static ArrayList<int[][]> matrices;

    private static void takeInput() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine().trim());
        ns = new ArrayList<>();
        ms = new ArrayList<>();
        matrices = new ArrayList<>();

        for (int T = 0; T < t; T++) {
            String line = br.readLine().trim();
            String[] temp = line.trim().split("\\s+");
            int n = Integer.parseInt(temp[0]);
            int m = Integer.parseInt(temp[1]);
            ns.add(n);
            ms.add(m);
            int[][] matrix = new int[n][m];

            for (int i = 0; i < n; i++) {
                String line2 = br.readLine().trim();
                String[] temp2 = line2.trim().split("\\s+");
                for (int j = 0; j < m; j++) {
                    matrix[i][j] = Integer.parseInt(temp2[j]);
                }
            }
            matrices.add(matrix);
        }
    }

    private static void executeAndPrintOutput() {
        for (int i = 0; i < t; i++) {
            //  ArrayList<Integer> ans;
            int ans = Solution9.maxSumRectangle(matrices.get(i), ns.get(i), ms.get(i));
            System.out.println(ans);
        }
    }
    public static void main(String[] args) throws Exception {
        takeInput();
        executeAndPrintOutput();

    }
}