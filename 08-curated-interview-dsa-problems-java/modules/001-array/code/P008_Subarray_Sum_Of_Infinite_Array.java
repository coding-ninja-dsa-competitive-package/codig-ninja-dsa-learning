/**
 *  Subarray Sum Of Infinite Array
 *  -   Ninja was feeling bored today. So he went for a walk and thought of a 
 *      problem. You are given an array, “A” of N integers. A new array “B” 
 *      is defined as a concatenation of array “A” for an infinite number of times. 
 *  -   For example, if the given array “A” is [1,2,3] then, infinite array “B” 
 *      is [1,2,3,1,2,3,1,2,3,.......].
 *  -   You are given Q queries, where each query consists of two integers “L“ 
 *      and “R”. Your task is to find the sum of the subarray from index “L” to 
 *      “R” (both inclusive) in the infinite array “B” for each query.
 *  
 *  Note :
 *  -   The value of the sum can be very large, return the answer as modulus 10^9+7.
 *  
 *  Input format :
 *  -   The first line of input contains a single integer T, representing the 
 *      number of test cases or queries to be run.
 *  -   Then the T test cases follow. 
 *  -   The first line of each test case contains a single integer N, denoting 
 *      the size of the array “A”.
 *  -   The second line of each test case contains N single space-separated 
 *      integers, elements of the array “A”.
 *  -   The third line of each test case contains a single integer Q, denoting 
 *      the number of queries.
 *  -   Then each of the Q lines of each test case contains two single 
 *      space-separated integers L, and R denoting the left and the  right index 
 *      of the infinite array “B” whose sum is to be returned. 
 *  
 *  Output format :
 *  -   For each test case, print Q space-separated integers that denote the 
 *      answers of the given Q queries. Print the answer to each test case in a 
 *      separate line.
 *  
 *  Note :
 *  -   You do not need to print anything, it has already been taken care of. 
 *      Just implement the given function.
 *  
 *  Constraints :
 *      1 <= T <= 100
 *      1 <= N <= 10^4   
 *      1 <= A[i] <= 10^9
 *      1 <= Q <= 10^4
 *      1 <= L = R <= 10^18
 * 
 *  Time Limit: 1 sec
 *      
 *  Sample Input 1 :
 *      1
 *      3
 *      1 2 3
 *      2
 *      1 3 
 *      1 5
 *  Sample Output 1 :   
 *      6 9
 *  Explanation to Sample Input 1 :
 *  -   For the first test case, the given array A is [1,2,3] therefore the 
 *      infinite array “B” will be [1,2,3,1,2,3,1,2,3,.......]. So the answer 
 *      for the given first query is 6 because the sum of the subarray from index 
 *      1 to 3 of infinite array “B” i.e. (B[1]+B[2]+B[3]) is 6.
 *  -   For the given second query is 9 because the sum of the subarray from index 
 *      1 to 5 of array “B” .ie (B[1]+B[2]+B[3]+B[4]+B[5]) is 9.
 *  
 *  Sample Input 2 :
 *      1
 *      4
 *      5 2 6 9
 *      3   
 *      1 5
 *      10 13
 *      7 11
 *  Sample Output 2 :
 *      27 22 28
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Solution8 {
    private static final Integer MOD = 1000000007;

    public static List<Integer> sumInRanges(int[] arr, int n, List<List<Long>> queries, int q) {
		int[] prefixSum = new int[n+1];
        prefixSum[0] = 0;
        for(int i=1; i<=n; i++){
            prefixSum[i] = (prefixSum[i-1] + arr[i-1]) % MOD;
        }
        
        List<Integer> list = new LinkedList<>();
        for(int i=0; i<q; i++){
            Long left = queries.get(i).get(0);
            Long right = queries.get(i).get(1);
            int a = (int) ((left - 1) % n);
            int b = (int) (right % n);
            int leftResult = (int) (((((left-1)/n)%MOD * prefixSum[n])%MOD + prefixSum[a%n])%MOD);
            int rightResult = (int) ((((right/n)%MOD * prefixSum[n])%MOD + prefixSum[b%n])%MOD);
            list.add((rightResult - leftResult+MOD)%MOD);
        }
		return list;
    }
}

public class P008_Subarray_Sum_Of_Infinite_Array {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        StringBuilder ans = new StringBuilder();
        while(t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            StringTokenizer tok = new StringTokenizer(br.readLine(), " ");
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(tok.nextToken());
            }
            int q = Integer.parseInt(br.readLine());
            List<List<Long>> queries = new ArrayList<>();
            for (int i = 0; i < q; i++) {
                tok = new StringTokenizer(br.readLine(), " ");
                long l = Long.parseLong(tok.nextToken());
                long r = Long.parseLong(tok.nextToken());
                queries.add(new ArrayList<Long>(Arrays.asList(l, r)));
            }
            List<Integer> answer = Solution8.sumInRanges(arr, n, queries, q);
            for (Integer x : answer) {
                ans.append(x + " ");
            }
            ans.append("\n");
        }
        System.out.print(ans);   
    }
}
