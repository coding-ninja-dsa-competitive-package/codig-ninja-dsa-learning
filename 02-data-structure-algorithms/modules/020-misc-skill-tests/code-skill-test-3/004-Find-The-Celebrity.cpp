#include<iostream>

using namespace std;

/**
 *  Find the Celebrity
 *  -   There is a party of N people, out of which only one person is known 
 *      to everyone (known as the celebrity). That person may be present at 
 *      the party or maybe not. If that person is present he(she) doesn't know 
 *      anyone present at the party. We can only ask the question "does A know 
 *      B? “. Find the celebrity in a minimum number of questions.
 *  -   You will be given a square matrix M[][] where if an element of row i 
 *      and column j is set to 1 it means the ith person knows the jth person. 
 *      You need to complete the function which finds the celebrity if present 
 *      else returns -1.
 *  Note: Here M[i][i]=0
 *  
 *  Input Format:
 *      The first line of input contains the size of matrix M[][] and the 
 *      following line of input contains the space-separated elements of matrix M[][].
 *  Output Format:
 *      The only output line contains an integer denoting the celebrity at the party.
 *  
 *  Constraints:
 *      Size of matrix M[][] should lie between the range [2,500].
 *  
 *  Sample Input:
 *      3
 *      0 1 0 0 0 0 0 1 0
 *  Sample Output:
 *      1
 *  Explanation;
 *      The matrix for the above input is:
 *      0 1 0
 *      0 0 0 
 *      0 1 0
 *      Here,  the celebrity is the person with index 1. So, output will be 1.
 */

int celebrity(int n, int** mat){
	// consider problem as graph and maintain the incoming & outgoing count 
	// suppose A, C knows B then B has 2 incoming count and 0 as outgoing count.
	int *in = new int[n];
	int *out = new int[n];
	for(int i=0; i<n; i++){
		in[i] = 0;
		out[i] = 0;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int celeb = mat[i][j];
			out[i] += celeb;
			in[j] += celeb;
		}
	}

	//	Answer would be the node where incoming count is n-1, outgoing count is 0.
	for(int i=0; i<n; i++){
		if(in[i] == n-1 && out[i] == 0){
			return i;
		}
	}
	return -1;
}

int main() {
    int n;
	cin>>n;
	int** mat=new int*[n];
	for(int i=0;i<n;i++){
		mat[i]=new int[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
		}
	}
	cout<<celebrity(n,mat);

    return 0;
}