/**
 *  -   Nth term of an AP:
 *          T(n) = a + (n-1)d
 *  -   Sum of n terms in AP:
 *          S(n) = n/2(2*a + (n-1)d)
 *  -   Nth term of GP:
 *          T(n) = a*r^(n-1)
 *  -   Sum of n terms in GP:
 *          S(n) = a(r^n - 1) / (r-1)   when r>=1
 */

/**
 *  Sum of the numbers
 *  -   The sum of squares of 3 consecutive positive numbers is 365. The sum of the numbers:
 *      a) 30 b) 33 c) 36  d) 50
 *  Ans: 33
 */

/**
 *  How many numbers?
 *  -   The sum of a two digit number and the number obtained by reversing its digits is 
 *      a square number. How many such numbers are there?
 *      a)  5   b) 6    c) 7    d) 8
 *  Ans:    8
 */

/**
 *  What's the remainder?   
 *  -   When a number is divided by 357 the remainder is 39. If that number is divided 
 *      by 17, the remainder will be:
 *      a) 0    b) 3    c) 5    d) 11
 *  Ans:    5
 */

/**
 *  Ratio Of Boys To Girl
 *  -   In a school 1/10 of the boys are the same in number as ¼ of the girls. The ratio 
 *      of the boys to girls in that school is:
 *      a) 2:1  b) 5:2 c) 4:3   d) 3:2
 *  Ans:    5:2
 */

/**
 *  Final Fraction
 *  -   The numerator of a fraction is four less than its denominator. If the numerator 
 *      is decreased by 2 and the denominator is increased by 1, then the denominator 
 *      becomes eight times the numerator. Find the fraction:
 *      a)  3/8     b) 3/7  c) 4/8  d) 2/7
 *  Ans:    3/7
 */

/**
 *  Term Of Ap
 *  -   Which term of the AP: 3, 15, 27, 39, … will be 132 more than its 54th term?
 *      a)  65  b) 66   c) 63   d) 76
 *  Ans:    65
 *      -   common difference d = 12,
 *              132/12 = 11
 *          So, 54 + 11 = 65th term will be 132 more than the 54th term. Hence, option 
 *              a is correct.
 */

/**
 *  Divisible by 7
 *  -   How many three digit numbers are divisible by 7?
 *      a)  128     b) 166  c) 193  d) 156
 *  Ans:    128
 *      -   Smallest three digit number divisible by 7 is 105.
 *          Greatest three digit number divisible by 7 is 994.
 *          Required number of terms
 *              = {(last term – first term)/common difference}+1
 *              = {(994-105)/7}+1
 *              = (889/7)+1=127+1=128. Hence, option (a) is correct.
 */

/**
 *  Find the term?
 *  -   An AP consists of 50 terms of which 3rd term is 12 and the last term is 106. 
 *      Find the 29th term.
 *      a)  73  b) 64 c) 34     d) 96
 *  Ans:    12 = a + 2d
 *          106 = a + 49d
 *          So, 106-12 = 47d
 *          Or, 94 = 47d
 *          Or, d = 2
 *          Hence, a = 8
 *          29th term= 8 + 28x2 = 64. Hence, option b is correct.
 */

/**
 *  Find the 20th term
 *  -   Find the 20th term from the last term of the AP: 3, 8, 13, ……, 253.
 *      a)  187     b) 158  c) 169  d) 189
 *  Ans:    158 
 *      -   a = 3, d = 5
 *          253 = 3 + 5(n-1)
 *          Or, 5(n-1) = 250
 *          Or, n-1 = 50
 *          Or, n = 51          
 *          So, the 20th term from the last term = 51 – 19 = 32nd term
 *          Now, 32nd term = 3 + 5x31 = 158. Hence, option b is correct.
 */

/**
 *  Sum of numbers
 *  -   What is the sum of all 3 digit numbers that leave a remainder of '2' when 
 *      divided by 3?
 *      a)  897     b) 164850   c) 164749   d) 149700
 *  Ans:    164850
 *      -   The smallest number that will leave a remainder of 2 when divided by 3 is 101
 *          The largest 3 digit number that will leave a remainder of 2 when divided 
 *          by 3 is 998.
 *          So, it is an AP with the first term being 101 and the last term being 998 
 *          and common difference being 3.
 *          Therefore 998 = 101 + (n - 1)* 3
 *          897 = (n - 1) * 3
 *          n - 1 = 299 
 *          n = 300.
 *          Required sum= 300/2*(101+998)=164850. Hence, option b is correct.
 */

/**
 *  Find numbers?
 *  -   The sum of the three numbers in A.P is 21 and the product of their extremes 
 *      is 45. Find the numbers.
 *      a)  5,7 and 9 b) 9,7 and 5 c) Both a and b  d) None Of These
 *  Ans:    Both a and b
 *      -   Let the numbers be a - d, a, a + d.
 *          Then a - d + a + a + d = 21
 *          3a = 21
 *          a = 7
 *          According to the question:  (a - d)(a + d) = 45
 *              a^2 - d^2 = 45
 *              d&2 = 4
 *              d = +2
 *          Hence, the numbers are 5, 7 and 9 when d = 2 and 9, 7 and 5 when d = -2. 
 *          In both the cases numbers are the same. Hence, option c is correct.
 */

/**
 *  Find the 11th term?
 *  -   Find the 11th term of the series 1, 4, 16, …..
 *      a)  4^10    b) 4^9  c) 4^11     d) None
 *  Ans; 4^10
 *      -   The nth term of the G.P. = ar^(n-1) (a is the 1st term and r is the common 
 *          ratio)
 *          First term of the series =1 common ratio =4.
 *          11th term of the series = 1.4^(11-1)= 4^10. Hence, option a is correct.
 */

/**
 *  Find sum of series?
 *  -   Find sum of the series 4, 2, 1, 0.5, 0.25, ……
 *      a) 4    b) 8    c) 1    d) None
 *  Ans:    8
 */

/**
 *  What will be first term?
 *  -   The seventh term of a GP is 16 times the 3rd term. What will be the 1st term 
 *      when it's 4th term is 24?
 *      a) 2    b) 3    c) 4    d) 5
 *  Ans:    3
 */

/**
 *  Find the remainder?
 *  -   Find the remainder of (80×81×84)/85?
 *      a) 20   b) 45   c) 65   d) 39
 *  Ans:    65
 *      -    (80*81*84)/85 ⇒ (-5*-4*-1)/85 = -20 / 85 
 *          The remainder is -20 which is equal to -20+ 85 = 65.  
 *          Hence, option c is correct.
 */

/**
 *  Again find remainder?
 *  -   Find the remainder of (20^127)/7 
 *      a) 1    b) 2    c) 3    d) 6
 *  Ans:    6
 *      -   Remainder of (ax-1)^n/a always gives a remainder -1 or a-1 (if n is odd .) 
 *          It gives a remainder of -1 or -1+7=6. Hence, option d is correct.
 */ 

/**
 *  Whats the remainder?
 *  -   (20×23×24×26)/ 100 will give a remainder =?
 *      a)  20  b) 15   c) 10   d) 40
 *  Ans:    40
 */

/**
 *  Find again remainder?
 *  -   Find the remainder when 66^105 is divided by 17.
 *      a)  15  b) 7    c) 6    d) 8
 *  Ans:    15  
 */

/**
 *  Sum of single digit
 *  -   What is the sum of the single digit numbers which cannot be the unit (last) 
 *      digit of any perfect square?
 *      a)  18  b) 9    c) 20   d) 12
 *  Ans:    20
 *      -   The digits which cannot be the last digit of any perfect square are 2, 3, 7 
 *          and 8. The required sum = 2 + 3 + 7 + 8 = 20
 *          ⇒ option (c )
 */

/**
 *  What is unit digit?
 *  -   What is the unit’s digit of the number 23^34× 34^57× 57^61?
 *      a)  9    b) 8   c) 2    d) 6
 *  Ans:    2
 *      -   The unit’s digit of 23^34 = 9
 *          The unit’s digit of 34^57 = 4
 *          The unit’s digit of 57^61 = 7
 *          The unit digit of the number 23^34× 34^57× 57^61 = Unit’s digit 
 *          of (9 × 4 × 7) =2
 */

/**
 *  What will be last digit?
 *  -   What will be the last two digits of the following expression 67 × 54 × 29 × 28 × 47?
 *      a) 25   b) 13   c) 52   d) 26
 *  Ans:    52
 */

