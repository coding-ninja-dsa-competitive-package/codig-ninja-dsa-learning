/**
 *  Design Browser History
 *  -   Your task is to maintain a data structure that supports the following 
 *      functions of a web browser.
 *      1- Browser(homepage): Set homepage of the browser
 *      2- Visit(url): Visit the url from the current page. It clears up all the 
 *         forward history.
 *      3- Back(steps): Move ‘steps’ backward in the browser history
 *      4- Forward(steps): Move ‘steps’ forward in the browser history
 *  
 *  Note:
 *  -   If you can’t move steps forward or backward, just return the last website 
 *      that can be reached.
 *  -   The Queries are in the given format-:
 *  -   The first line of each query contains the string representing the homepage 
 *      of the web browser.
 *  
 *  -   (1, url): Visit the url from the current page. 
 *      (2, steps): Move ‘steps’ backward in the browser history.
 *      (3, steps): Move ‘steps’ forward in the browser history.
 *  
 *  For example:
 *  -   You are queries as  [[“homepage.com”], [1 , “facebook.com”], [1, 
 *      “codingninjas.com”],[2, 1], [3, 1]]
 *  
 *      1 query is the query that sets the homepage as “homepage.com”.
 *      2 query is the query to visit “facebook.com”
 *      3 query is the query to visit “codingninjas.com”
 *      4 query is the query that moves back one step to “facebook.com”
 *      5 query is the query that moves forward one step to “codingninjas.com”
 *  
 *  Hence the answer is [“facebook.com”, “codingninjas.com”]
 *  
 *  Input Format:
 *  -   The first line of input contains the integer ‘T’ representing the number        
 *      of test cases.
 *  -   The second line of input contains a single integer ‘Q’, representing the 
 *      number of queries.
 *  -   The next ‘Q’ lines contain space-separated strings and integers denoting 
 *      the queries.    
 *     
 *  Output Format:
 *  -   For each test case, print space-separated strings representing the output 
 *      of the queries.
 *  -   Print a separate line for each test case.
 *  
 *  Constraints:
 *      1 <= T <= 5
 *      2 <= Q <= 10^5
 *      1 <= |url| <= 10^3
 *      1 <= steps <= 10^5
 *  Time Limit: 1 sec
 *  
 *  Note:
 *  -   You do not need to print anything. It has already been taken care of. 
 *      Just implement the function.
 *  
 *  Sample Input 1:
 *      2
 *      5
 *      homepage.com
 *      1 facebook.com
 *      1 codingninjas.com    
 *      2 1
 *      3 1
 *      5
 *      home.com
 *      1 web.com
 *      1 site.com
 *      2 2
 *      3 1
 *  Explaination:   
 *  -   For the first test case, 
 *  -   1 query is the query that sets the homepage as “homepage.com”.
 *  -   2 query is the query to visit “facebook.com”
 *  -   3 query is the query to visit “codingninjas.com”
 *  -   4 query is the query that moves back one step to “facebook.com”
 *  -   5 query is the query that moves forward one step to “codingninjas.com”
 * 
 *  Hence the answer is [“facebook.com”, “codingninjas.com”]
 *  For the second test case, 
 *      1 query is the query that sets the homepage as “home.com”.
 *      2 query is the query to visit “web.com”
 *      3 query is the query to visit “site.com”
 *      4 query is the query that moves back two steps to “home.com”
 *      5 query is the query that moves forward one step to “web.com”
 *  
 *  Hence the answer is [“fhome.com”, “web.com”]
 *  Sample Output 1
 *      facebook.com codingninjas.com
 *      home.com web.com
 *  
 *  Sample Input 2:
 *      2   
 *      4
 *      Homepage.com
 *      1 page.com
 *      2 3
 *      3 3 
 *      5
 *      Page.com
 *      1 codingNinjas.com
 *      1 check.com
 *      3 1
 *      2 4
 *  
 *  Sample Output 2:
 *      Homepage.com page.com 
 *      check.com Page.com 
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;
import java.util.ArrayList;
import java.util.Stack;

// Using ArrayList - T(n) = O(1) , S(n) = O(n)
class Browser {
    private List<String> urls = new ArrayList<>();
    private int index = -1;
    private int lastIndex = -1;
	 
	public Browser(String homePage) {
		visit(homePage);
	}

	public void visit(String string) {
		if (++index < urls.size()){
          urls.set(index, string);
        } else {
          urls.add(string);
        }
        lastIndex = index;
	}

	public String back(int parseInt) {
		index = Math.max(0, index - parseInt);
    	return urls.get(index);
	}

	public String forward(int parseInt) {
		index = Math.min(lastIndex, index + parseInt);
    	return urls.get(index);
	}
}

// Using Stack - T(n) = O(1) , S(n) = O(n)
class BrowserStack {
    private Stack<String> history = new Stack<>();
    private Stack<String> future;
	 
	public BrowserStack(String homePage) {
		visit(homePage);
	}

	public void visit(String string) {
		history.push(string);
        future = new Stack<>();
	}

	public String back(int parseInt) {
		while (history.size() > 1 && parseInt-- > 0) {
            future.push(history.pop());
        }
        return history.peek();
	}

	public String forward(int parseInt) {
		while (!future.empty() && parseInt-- > 0){
            history.push(future.pop());
        }
        return history.peek();
	}
}

// Using ArrayList - T(n) = O(1) , S(n) = O(n)
class Node {
    public Node prev;
    public Node next;
    public final String url;
    public Node(final String url) {
      this.url = url;
    }
}
class BrowserDoublyLinkedList {
    private Node curr;
	 
	public BrowserDoublyLinkedList(String homePage) {
		curr = new Node(homePage);
	}

	public void visit(String string) {
		curr.next = new Node(string);
        curr.next.prev = curr;
        curr = curr.next;
	}

	public String back(int parseInt) {
		while (curr.prev != null && parseInt-- > 0) {
            curr = curr.prev;
        }
        return curr.url;
	}

	public String forward(int parseInt) {
		while (curr.next != null && parseInt-- > 0){
            curr = curr.next;
        }
        return curr.url;
	}
}


public class P010_Design_Browser_History {
    private static int t;
	private static String arr[];
	private static String arr1[][][];

	private static void takeInput() throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		t = Integer.parseInt(br.readLine().split(" ")[0]);

		arr = new String[t];
		arr1 = new String[t][][];
		for (int c = 0; c < t; c++) {
			String nk[] = br.readLine().split(" ");
			int q = Integer.parseInt(nk[0]);
			int i = 0;
			nk = br.readLine().split(" ");
			arr[c] = nk[0];
			arr1[c] = new String[q - 1][];

			while (i < q - 1) {
				nk = br.readLine().split(" ");
				arr1[c][i] = new String[2];
				arr1[c][i][0] = nk[0];
				arr1[c][i][1] = nk[1];
				i++;
			}

		}
	}

	private static void executeAndPrintOutput() {
		for (int i = 0; i < t; ++i) {
			Browser b = new Browser(arr[i]);
			for (int j = 0; j < arr1[i].length; j++) {
				if (arr1[i][j][0].equals("1")) {
					b.visit(arr1[i][j][1]);
				} else if (arr1[i][j][0].equals("2")) {
					System.out.print(b.back(Integer.parseInt(arr1[i][j][1])) + " ");
				} else if (arr1[i][j][0].equals("3")) {
					System.out.print(b.forward(Integer.parseInt(arr1[i][j][1])) + " ");
				}
			}
			System.out.println();
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		takeInput();
		executeAndPrintOutput();
	}
}
