/**
 *  White Subtree
 *  -   You are given a tree consisting of n vertices. A tree is a connected 
 *      undirected graph with n−1 edges. Each vertex v of this tree has a 
 *      colour assigned to it (av=1 if the vertex v is white and 0 if the 
 *      vertex v is black).
 *  -   You have to solve the following problem for each vertex v: What is 
 *      the maximum difference between the number of white and the number 
 *      of black vertices you can obtain if you choose some subtree of the 
 *      given tree that contains the vertex v?
 *  -   The subtree of the tree is the connected subgraph of the given tree. 
 *      More formally, if you choose the subtree that contains cntw 
 *      (white vertices) and cntb (black vertices), you have to maximize cntw−cntb.
 * 
 *  Input Format:
 *      First line of input will contain T(number of test cases), each test 
 *      case follows as.
 *      Line 1: contain an integer N (number of vertex in the tree)
 *      Line 2: contian N space separated integers where Ith integer denote 
 *      the colour of the Ith vertex(1 for white and 0 for black).
 *      Next N - 1 lines will contain two space-separated integers v and u 
 *      denoting the edge between vertex u and v
 *  
 *  Constraints:
 *      1 <= T <= 50
 *      1 <= N <= 10^5
 *      0 <= arr[i] <= 1
 *  
 *  Output Format:
 *      for each test case print n space-separated integers res1,res2,…,resn, where 
 *      resi is the maximum possible difference between the number of white and 
 *      black vertices in some subtree that contains the vertex i in new line 
 *  
 *  Sample Input 1:
 *      1
 *      9
 *      0 1 1 1 0 0 0 0 1   
 *      1 2
 *      1 3
 *      3 4
 *      3 5
 *      2 6
 *      4 7
 *      6 8
 *      5 9
 *  Sample Output 1:
 *      2 2 2 2 2 1 1 0 2 
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    // write your code here
    return 0;
}