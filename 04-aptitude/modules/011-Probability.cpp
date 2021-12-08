/**
 *  Probability Of Head
 *  -   Three coins are tossed, find the probability that two heads are obtained.
 *      a) 1/4  b) 3/8  c) 1/2  d) 5/8
 *  Ans:    3/8
 *      -   Total outcomes (S) = 2^3 = 8		
 *          Favorable outcomes (E) = 3C2 = 3 (HHT, HTH, THH)    
 *          P (E) = E/S= 3/8
 *          Hence, option (b) is correct.
 */ 

/**
 *  Probability Of Tail
 *  -   Three unbiased coins are tossed. What is the probability of getting 
 *      at most two tails?
 *      a) 5/8  b) 3/4  c) 7/8  d) None 
 *  Ans:    7/8
 *      -   Here S = {TTT, TTH, THT, HTT, THH, HTH, HHT, HHH}
 *          Let E = event of getting at most two heads.\
 *          Then E = {TTT, TTH, THT, HTT, THH, HTH, HHT}.
 *          Required probability = 7/8
 */

/**
 *  Die And Prime Number
 *  -   A die is rolled, find the probability that a prime number is obtained
 *      a) 1/2  b) 1/3  c) 1/4  d) 2/3
 *  Ans:    1/2
 *      -   S = {1, 2, 3, 4, 5, 6}	E = {2, 3, 5}
 *          P (E) = 1/2
 *          Hence, option (a) is correct.
 */

/**
 *  Probability Of Sum
 *  -   Two dice are rolled, find the probability that the sum is 4
 *      a) 1/6  b) 1/9  c) 1/12     d) 1/18
 *  Ans:    1/12  
 *      -   S = 6 × 6 = 36
 *          E = [{(1,3), (2,2), (3,1)} 
 *          P (E) = 3/36 = 1/12
 *          Hence, option (c) is correct.
 */

/**
 *  Probability Of Even
 *  -   Two dice are thrown simultaneously. What is the probability of getting 
 *      two numbers whose product is even?
 *      a) 5/8  b) 3/4  c) 7/8  d) None of these
 *  Ans:    3/4
 *      -   In a simultaneous throw of two dice, we have n(S) = (6 x 6) = 36.
 *          Then, E	= {(1, 2), (1, 4), (1, 6), (2, 1), (2, 2), (2, 3), (2, 4), 
 *          (2, 5), (2, 6), (3, 2), (3, 4),(3, 6), (4, 1), (4, 2), (4, 3), 
 *          (4, 4), (4, 5), (4, 6), (5, 2), (5, 4), (5, 6), (6, 1), (6, 2), 
 *          (6, 3), (6, 4), (6, 5), (6, 6)}
 *              n(E) = 27
 *              Required probability = 27/36 = ¾
 *              Hence, option (b) is correct.
 */ 

/**
 *  Probability Of King
 *  -   A card is drawn at random from a deck of cards. Find the probability 
 *      of getting a king or a spade.
 *      a) 1/13     b) 17/52    c) 3/13     d) 4/13
 *  Ans:    4/13
 *      -   Number of kings = 4 
 *          Number of spades = 13
 *          There is 1 card of king in spade. So, required number of    
 *          possibilities = 13+4-1 = 16
 *          Probability = 16/52 = 4/13 
 *          Hence, option (d) is correct.
 */

/**
 *  Probability Of Cards
 *  -   Three cards are drawn from a deck of cards. Find the probability such 
 *      that one of them is a spade, one is a diamond and one is a heart.
 *      a) 3/13 b) 1/(13^3) c) (13^3)*3!/52*51*50   d) 10/(13^3)
 *  Ans:    (13^3)*3!/52*51*50
 */

/**
 *  Probability Of Bags
 *  -   A bag contains 3 white, 4 red and 5 blue balls. Two balls are drawn at 
 *      random from the bag. The probability that both of them are blue is_______
 *      a) 6/21     b) 4/21     c) 1/7  d) 5/33
 *  Ans:    5/33
 *      -    Let S be the sample space.
 *          Then, n(S) = number of ways of drawing 2 balls out of 12 = 12C2 = 66
 *          Let E = event of getting both the balls blue.
 *              n(E) = 5C2 = 10
 *          Probability = 10/66 = 5/33. Hence, option (d) is correct.
 */

/**
 *  Probability Of Balls
 *  -   A bag contains 5 black and 6 white balls. James takes a ball out and 
 *      places it in the bag again. He again takes out a ball. What is the 
 *      probability that both the balls are white?
 *      a) 25/121   b) 36/121   c) 3/11     d) 49/121
 *  Ans:    36/121
 *      -   Required probability = (6/11) x (6/11) = 36/121
 *          Hence, option (b) is correct.
 */

/**
 *  Probability Of Even 
 *  -   A bag contains 21 toys numbered 1 to 21. A toy is drawn and then 
 *      another toy is drawn without replacement. Find the probability that 
 *      both toys will show even numbers   
 *      a) 3/14     b) 3/7  c) 4/7  d) 5/14
 *  Ans:    3/14
 *      -   The probability that first toy shows the even number = 10/21
 *      -   Since, the toy is not replaced there are now 9 even numbered toys 
 *          and total 20 toys left.
 *      -   Hence, probability that second toy shows the even number = 9/20
 *      -   Required probability = (10/21) × (9/20) = 3/14
 *          Hence, option (a) is correct.
 */

/**
 *  Probability Of Events
 *  -   The odds against an event are 3:4 and the odds in favour of another 
 *      independent event are 3:5. Find the probability that at least one of 
 *      the two events will occur.
 *      a) 5/7  b) 11/14    c) 6/7  d) 41/56
 *  Ans:    41/56
 */

/**
 *  Probability Of Ticket
 *  -   In a charity show tickets numbered consecutively from 101 through 350 
 *      are placed in a box. What is the probability that a ticket selected at 
 *      random (blindly) will have a number with a hundredth digit of 2?
 *      a) 0.30     b) 0.35     c) 0.40     d) 0.45
 *  Ans:    0.40
 *      -   250 numbers between 101 and 350 i.e. n(S)=250
 *          n(E)=100th digits of 2 =299−199=100
 *          P(E) = 100/250 = 0.4
 *          Hence, option (c) is correct.
 */

/**
 *  Probability Of Students
 *  -   The probability of success of three students A, B and C in the one 
 *      examination are 1/3, 1/2 and 1/4 respectively. Find the probability of 
 *      all three students failing in the examination.
 *      a) 0.25     b) 0.35     c) 0.45     d) 0.55
 *  Ans:    0.25
 *      -   Required probability = [1 – 1/3] × [1 – 1/2] × [1 – 1/4] = 
 *          (2/3) * (1/2)*(3/4) = 1/4 = 0.25. Hence, option (a) is correct.
 */

/**
 *  Probability Of Selected Person
 *  -   Out of 13 applicants for a job, there are 5 women and 8 men. It is 
 *      desired to select 2 persons for the job. The probability that at least 
 *      one of the selected persons will be a woman is:
 *      a) 25/39    b) 14/39    c) 5/13     d) 10/13
 *  Ans:    25/39
 */

/**
 *  Probability Of Good
 *  -   A bag contains 10 mangoes out of which 4 are rotten. Two mangoes are 
 *      taken out together. If one of them is found to be good, then the 
 *      probability that other is also good is:
 *      a) 5/13     b) 8/15     c) 5/18 d) None of these
 *  Ans:    5/13
 *      -   #### We are given 4 rotten and 6 good mangoes.
 *          #### Let us consider 2 events A= 1st mango is good
 *          #### B= 2nd mango is good.
 *          #### P(B/A)=P(A intersection B)/P(A)
 *          #### P(A intersection B)= Both mangoes are good.
 *          #### Favorable cases= 6C2
 *          #### Total cases=10C2
 *          #### P(A intersection B)=6C2/10C2
 *          #### P(A)=1st good,2nd rotten +both good
 *          #### P(A)=(6C1*4C1)/10C2+(6C2/10C2)
 *          #### P(B/A)=P(A intersection B)/P(A)=(6C2/10C2)/((6C1*4C1)/10C2+
 *              (6C2/10C2))=5/13
 */

/**
 *  Probability Of Stand
 *  -   Four boys and three girls stand in queue for an interview. The 
 *      probability that they will stand in alternate position is:
 *      a) 1/34 b) 1/35     c) 1/17     d) 1/68
 *  Ans:    1/35
 */

/**
 *  Probability Of Win In Single Trial
 *  -   A and B play a game where each is asked to select a number from 1 to 5. 
 *      If two numbers match, both of them win a prize. The probability that    
 *      they will not win a prize in a single trail is
 *      a) 1/25     b) 24/25    c) 3/25     d) None of these
 *  Ans:    None of these
 */

/**
 *  Probability Of Rich Girl    
 *  -   A class consists of 100 students; 25 of them are girls and 75 boys; 20 
 *      are rich, and the remaining poor; 40 of them love to play basketball, 
 *      and the rest loves to play football. The probability of selecting a 
 *      basketball lover rich girl is
 *      a) 0.05     b) 0.04     c) 0.02     d) 0.08
 *  Ans:    0.02
 *      -   (25/100)*(20/100)*(40/100) = 1/50 = 0.02
 */

/**
 *  Probability Of Same Colour
 *  -   A box contains 5 brown and 4 white socks. A man takes out two socks. 
 *      The probability that they are of the same colour
 *      a) 5/18     b) 1/6  c) 5/108    d) 4/9
 *  Ans:    4/9
 *      -   (5/9)*(4*8) + (4/9)*(3*8) = 4/9
 */

/**
 *  Probability Of Club
 *  -   There are five clubs in Lucknow. If 3 singers check into clubs in a 
 *      day. What is the probability that each singer check into a different club?
 *      a)  12/25   b) 13/25    c) 12/15    d) 13/15
 *  Ans:    12/25
 */