# Competitive Programming

>   Once you enter in programming you just don’t learn how to code but you also learn the **“art of thinking”**, by breaking your code into smaller chunks and then using your logic-based creativity to solve a problem from different angles.

---

### Why Competitive Programming

-   Publicly Demonstrate Your Skills. You are making your profile by participating in different platforms like CodeChef, Codeforces etc.
-   Prepare You well for **Technical Interviews**.
-   Makes your desirable candidate for **Major Companies**.
-   Makes you **Faster** and **Focused**.
-   Helps you solve **Complicated Problems**.
-   Guarenteed **Brain Exercise**. Always keeps you motivated.

---

### Time Complexity v/s Number of Operations 
>
            N       |       Time Complexity
        -----------------------------------
        10^18       |       O(logN)
        10^8        |       O(N)
        10^4        |       O(N^2)
        10^7        |       O(logN)
        5*10^2      |       O(N^3)
        0<=N<=9*10  |       O(N^4)
        0<=N<=20    |       O(2^n)
        0<=N<=11    |       O(N!)

---

### Types of Error:

#### **Verdict**
-   **Accepted**
-   **TLE (Time Limit Exceeded)**
-   **Compilation Error**
-   **Runtime Error**:
    -   Dividing by Zero.
    -   Segmentation Fault:
        -   Indices is out of bound i.e. maybe negative or greater than size of array.
        -   Array size is greater than 10^8.
#### **Functions**:
-   Max memory for function - 4MB.
-   Array size can be of atmost 10^6. It will be created in stack memory.
#### **Wrong Answer**
-   **Un-initialized** variables.
-   **int** : we should check the limit and assign the result proper data type. if result can be greater than 10^8 , we should use **long long**
-   **float** : we might need to use **double** as per the constraints.

## Modules:

-   [001 - Pre-Requisite](./modules/001-prerequisite)<br>
-   [002 - Pointers](./modules/002-pointers)<br>