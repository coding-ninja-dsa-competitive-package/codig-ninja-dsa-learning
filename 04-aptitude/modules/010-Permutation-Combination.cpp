/**
 *  -   Three categories :
 *      1.  Selection
 *      2.  Distribution
 *      3.  Arrangements & circular arrangements
 * 
 *  Selection Formulae
 *  -   n 'distinct' objects and select 'r' from these objects
 *          nCr = n! / r!(n-r)!
 *  -   select any number (include 0)
 *      -   select 0 + select 1 + select 2 + select 3
 *              3C0 + 3C1 + 3C2 + 3C3 = 2^3
 *              2^n (if n numbers)
 *  -   slect any number (exclude 0)
 *          nC1 + nC2 + ... + nCn = 2^n - 1
 * 
 *  Distribution:
 *  -   can happen of identical or distinct objects.
 *  -   n identical objects - distribute them in r people or groups.
 *              (n+r-1)C(r-1)
 * 
 *  Arrangements:
 *  -   m*n*p rule of counting 
 *  -   r distinct objects in r places 
 *          r!
 *  -   r! modified for arrangement of identical objects
 *          r! / (no. of identical objects)!
 *      -   for ABCDDD => 6! / 3! 
 *  
 */


/**
 *  Value Of Factorial
 *  -   What is the value of 6!?
 *      a) 120  b) 240  c) 720  d) 5760
 *  Ans:    720 
 *      -   6!= 6×5×4×3×2×1=720
 */

/**
 *  Find value?
 *  -   What is the value of 10C3 ?
 *      a) 120  b) 60   c) 720  d) None of these
 *  Ans:    120
 */

/**
 *  Number Of Ways
 *  -   There are 10 boys and 8 girls in a group. Two boys are to be selected 
 *      and two girls are to be selected for the play. In how many ways can 
 *      they be selected?
 *      a) 18   b) 73   c) 80   d) 1260
 *  Ans:    1260
 *      -   Number of ways of selecting boys = 10C2 ×8C2 = 45 × 28 = 1260.
 */

/**
 *  Number Of Handshakes
 *  -   10 people at a party shake hands once with everyone else in the room. 
 *      How many handshakes took place?
 *      a) 32   b) 36   c) 35   d) 45   
 *  Ans:    45  
 *      -   Total number of handshakes= 10C2= 45. Hence, option (d) is correct
 */

/**
 *  Select Men?
 *  -   Find the number of ways in which we can select 2 men out of 11 men?
 *      a) 18   b) 55   c) 65   d) 80
 *  Ans:    55
 *      -   Number of ways in which we select 2 men out of 11 men= 11C2= 55.
 */

/**
 *  Ways To Answer?
 *  -   A student is to answer 10 out of 13 questions. In how many ways he can 
 *      do this:
 *      a) 286  b) 296  c) 196  d) 346
 *  Ans:    286
 *      -   Required number of ways= 13C10= 13!/(10! X 3!)= (13x12x11)/6= 286
 */

/**
 *  Pick Balls?
 *  -   In how many ways can we pick any number of balls from a pack of three 
 *      different balls?
 *      a) 2    b) 7    c) 8    d) None of these
 *  Ans:    8
 *      -   Required number of ways= 2^3=8
 */

/**
 *  Pick Coins?
 *  -   In how many different ways can we pick any number of coins from five 
 *      different coins?
 *      a) 20   b) 30   c) 32   d) 16
 *  Ans:    32
 *      -    required number of ways= 2^5=32.
 */

/**
 *  Captain And VC
 *  -   If captain and vice-captain are in the team then in how many ways can 
 *      we select a team of 10 players from a group of 15 players?
 *      a) 13C10    b) 13C8     c) 15C8     d) 15C10
 *  Ans:    13C8
 *      -   If captain and vice-captain are already in the team then we need 
 *          to select 8 players out of 13 players.
 *      -   Required number of ways= 13C8
 *          Hence, option (b) is correct.
 */

/**
 *  Committee
 *  -   A committee of five members is to be formed out of 3 trainees, 
 *      4 professors and 6 research associates. In how many different ways 
 *      this can be done if the committee should have all the 4 professors 
 *      and 1 research associate or all 3 trainee and 2 professors?
 *      a) 15   b) 18  C) 25    d) 12
 *  Ans:    12
 *      -   Total number of ways to select 4 professors and 1 research 
 *          associate= 4C4x6C1=1×6=6.
 *      -   Total number of ways to select 3 trainee and 2 professors= 3C3x4C2=6
 *          Required answer= 6+ 6= 12.
 */

/**
 *  Number Of Solutions
 *  -   Find the number of non-negative integer solutions of x+ y+ z= 10?
 *      a) 12   b)  66  c) 81   d) None
 *  Ans:    66
 *      -   Number of non-negative integer solutions= (10+3-1)C(3-1)= 12C2= 66. 
 *          Hence, option b is correct.
 */

/**
 *  Number Of Positive Solutions
 *  -   Find the number of positive integer solutions of x+ y+ z= 10?
 *      a) 12   b) 66   c) 36   d) None
 *  Ans:    36
 *      -   Number of positive integer solutions= (7+3-1)C(3-1)= 9C2= 36. Hence,    
 *          option c is correct.
 */

/**
 *  Ways To Arrange
 *  -   In how many different ways can the letter of the word ‘ARMOUR’ be 
 *      arranged?
 *      a) 360  b) 300  c) 640  d) 350
 *  Ans:    360
 *      -   There are 6 letters in ‘ARMOUR’. And two R's are  same. Hence 
 *          this can be arranged in 6!/2 ways or 720 ways.
 */

/**
 *  Arrange Words
 *  -   In how many different ways can the letter of the word ‘ARROW’ be arranged?
 *      a) 60   b) 40   c) 50   d) None of these
 *  Ans:    60
 *      -   Required number of letters= 5!/2!=60
 *          Hence, option (a) is correct.
 */

/**
 *  Arrange Prizes
 *  -   How many ways can 4 prizes be given away to 3 boys, if each boy is 
 *      eligible for all the prizes?
 *      a) 12   b) 64   c) 81   d) None 
 *  Ans:    84  
 *      -   Any one prize can be given to any one of the 3 boys and hence 
 *          there are 3 ways of distributing each prize.
 *      -   Hence, the 4 prizes can be distributed in 3^4 = 81 ways.
 */ 

/**
 *  Arrange Rings
 *  -   Find out the number of ways in which 6 rings of different types can be 
 *      worn in 3 fingers?
 *      a) 120  b) 720  c) 729  d) 125
 *  Ans:    729
 *      -   Required number of ways= 3^6=729
 */

/**
 *  Arrange Letters
 *  -   In how many ways can the letters of the word HIPPOPOTAMUS be arranged?
 *      a) 12!  b) 12!/2!   c) 12!/3!   d) 12!/(2!*3!)
 *  Ans:    12!/(2!*3!)
 *      -   The words can be arranged in 12! Ways. There are 3 P’s and 2 O’s.
 *          So, number of arrangements = 12!/(2! x 3!)
 */

/**
 *  Letter Arranged
 *  -   In how many different ways can the letter of the word SOFTWARE be 
 *      arranged in such a way that the vowels always come together?
 *      a) 13440    b) 4320     c) 1440     d) 720
 *  Ans:    4320
 *      -   There are total 3 vowels (O, A, E) in SOFTWARE.
 *      -   These three vowels can be considered as a single letter. Now we 
 *          have 6 letter which can be arranged in 6! Different ways and 
 *          the 3 vowels can be arranged in 3! Ways.
 *      -   Hence the required number of combinations= 3!×6!= 4320.
 */

/**
 *  Form Integers
 *  -   How many three digit integers can be formed using the digits 
 *      0, 1, 2, 5, 8 and 9 (repetition of digits not allowed).
 *      a) 60   b) 100  c) 160  d) 720
 *  Ans:    100
 *      -   Forming numbers without including zero
 *          Total numbers formed = 5 × 4 × 3 = 60
 *          Forming numbers including zero
 *          Total numbers formed = 5 × 5 × 4 = 100
 *          Required number of integers = 100 + 60 = 160
 */

/**
 *  Number Of Integers
 *  -   What will be the number of integers formed in the previous question 
 *      if repetition of digits is allowed?
 *      a) 305   b) 180     c) 125  d) None
 *  Ans:    180
 */

/**
 *  Person Sit
 *  -   10 persons we invited to a party. In how many ways can they be seated 
 *      in a round table such that two particular persons sit on either side 
 *      of the host?
 *      a) 9!*2 b) 9!   c) 8!*2     d) 8!
 *  Ans:    8!*2
 *      -   After fixing the places of three persons (1 host + 2 persons) and 
 *          treating them as 1 unit we can arrange the total (10 - 2 + 1) = 9 
 *          units in 8! ways. Again these particular persons can sit on either 
 *          side of the host in 2 ways. Hence the total number of ways is 8!×2.
 */

/**
 *  Different Ways To Sit
 *  -   If 7 people are going to sitting at a round table, but Kriti will not 
 *      sit next to Heena, how many different ways can the group of 6 sit?
 *      a) 240  b) 480  c) 720  d) None
 *  Ans:    480 
 *      -   Total circular permutations = (7-1)! = 6! = 720. 
 *          Ways in which Kriti and Heena sit together = 2! × 5! = 2 × 120 = 240 
 *          Required ways = 720 - 240 = 480. 
 */