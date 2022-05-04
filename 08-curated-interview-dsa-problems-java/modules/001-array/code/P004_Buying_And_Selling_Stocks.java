/**
 *  Buying And Selling Stock
 *  -   You have been given the prices of 'N' stocks in an array where each array 
 *      element represents the stock price for that day. You need to find the       
 *      maximum profit which you can make by buying and selling the stocks. You 
 *      may make as many transactions as you want but can not have more than one 
 *      transaction at a time i.e, if you have the stock, you need to sell it 
 *      first, and then only you can buy it again.
 *  
 *  Input format :
 *  -   The first line contains an integer 't' which denotes the number of test 
 *      cases or queries to be run. Then the test cases follow.
 *  -   The first line of each test case or query contains an integer 'N' 
 *      representing the total number of days for which you have stock prices.
 *  -   The second line contains 'N' single space-separated integers representing 
 *      the price of the stock on i-th day.
 *  
 *  Output Format :
 *  -   For each test case, print the maximum profit that you can earn.
 *  -   Output for every test case will be printed in a separate line.
 *  
 *  Note :
 *  -   You are not required to print anything explicitly. Just implement the 
 *      function.
 *  
 *  Constraints :
 *      1 <= t <= 10^2
 *      0 <= N <= 10^5
 *      
 *  Time Limit: 1 sec
 *  
 *  Sample Input 1 :
 *      1
 *      7
 *      1 2 3 4 5 6 7
 *  Sample Output 1 :
 *      6
 *  Explanation :
 *      We can make the maximum profit by buying the stock on the first day and         
 *      selling it on the last day.
 *  
 *  Sample Input 2 :
 *      1
 *      7
 *      7 6 5 4 3 2 1
 *  Sample Output 2 :
 *      0
 *  Explanation :
 *      We can make the maximum profit by not buying the stock.
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Solution4 {
    // Solution O(n)
    public static long getMaximumProfit (int n, long[] values) {
        int buyIdx=0;
        long profit = 0;
        for(int sellIdx=1; sellIdx<n; sellIdx++){
            if(values[sellIdx-1] > values[sellIdx]){
                profit += values[sellIdx-1]-values[buyIdx];
                buyIdx = sellIdx;
            }
            if(sellIdx==n-1){
                profit += values[sellIdx] - values[buyIdx];
            }
        }
        return profit;
    }

    // Another way O(n)
    public static long getMaximumProfitSol(int n, long[] values) {
        if(n <= 1){
            return 0;
        }
        long profit = 0L;
        int buyDay = 0, sellDay = 1;
        while(sellDay < n){
            if(values[sellDay] > values[buyDay]){
                profit += values[sellDay] - values[buyDay];
            }
            buyDay++;
            sellDay++;
        }
        return profit;
    }
}

public class P004_Buying_And_Selling_Stocks {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            long[] input = takeInput();
            System.out.println(Solution4.getMaximumProfit(input.length, input));
            System.out.println(Solution4.getMaximumProfitSol(input.length, input));
        }
        br.close();
    }

    public static long[] takeInput() throws IOException {
        int size = Integer.parseInt(br.readLine().trim());
        long[] input = new long[size];
        if (size == 0) {
            return input;
        }
        String[] strNums = br.readLine().split("\\s");
        for (int i = 0; i < size; ++i) {
            input[i] = Long.parseLong(strNums[i]);
        }
        return input;
    }
}
