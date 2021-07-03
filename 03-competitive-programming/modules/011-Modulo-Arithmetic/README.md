# Modulo Arithmetic (%)

>   In short, **Modulo Operator(%)** is used in **CP** when we are having the answers going out of range from **datatype limit**.

>   Generally, in questions, ask is to convert the answer to **10^9 + 7**.<br><br> Reason to choose this number:<br>
    1.  Number is very large like 2^100.<br>
    2.  Number is prime - 10^9+7.

---

### Modulo Properties

1.  (a+b) % c   =>  ((a%c) + (b%c)) % c
2.  (a*b) % c   =>  ((a%c) * (b%c)) % c
3.  (a-b) % c   =>  ((a%c) - (b%c)) % c
4.  (a/b) % c   =>  ((a%c) / (b%c)) % c

---

### Modulo Operation
-   Answer with modulo should be in the range - **(0 to n-1)**
-   If our ans is coming as negative then the formulae is changed a bit :<br>
-   Example : -5 % 3 = -2<br>
    So, formulae will be changed in this case : **(a%m + m) % m** <br>
    i.e ((-5 % 3) + 3 ) % 3 = 1

---

## Problems

[001 - Number of Balanced Trees](./code/001-Number-Of-Balanced-Trees.cpp)<br>

---