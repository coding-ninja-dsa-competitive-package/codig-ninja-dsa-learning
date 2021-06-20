#include <bits/stdc++.h>

using namespace std;

/**
 *  Tell the positions
 *  -   In a class there are ‘n’ number of students. They have three different 
 *      subjects: Data Structures, Algorithm Design & Analysis and Operating 
 *      Systems. total_marks for each subject of all the students are provided to 
 *      you. You have to tell the position of each student in the class. Print 
 *      the names of each student according to their position in class. Tie is 
 *      broken on the basis of their roll_number numbers. Between two students having 
 *      same total_marks, the one with less roll_number number will have higher rank. The 
 *      input is provided in order of roll_number number.
 *  Input Format:
 *      First line will have a single integer ‘n’, denoting the number of students 
 *      in the class.
 *      Next ‘n’ lines each will have one string denoting the name of student 
 *      and three space separated integers ds, algo, os denoting the total_marks in three 
 *      subjects.
 *  Output Format:
 *      Print ‘n’ lines having two values: First, the position of student in the 
 *      class and second his name.
 *  Constraints:
 *      1 <= n <= 10^5
 *      0 <= ds, algo, os <= 100
 *  
 *  Sample Input:
 *      3
 *      Mohit 94 85 97  
 *      Shubham 93 91 94    
 *      Rishabh 95 81 99
 *  Sample Output:
 *      1 Shubham
 *      2 Mohit
 *      3 Rishabh
 */

class student{
    public:
        int roll_number;
        string name;
        int total_marks;
};
bool compare(student s1, student s2){
    if (s1.total_marks > s2.total_marks){
        return 1;
    } else if (s1.total_marks < s2.total_marks){
        return 0;
    } else if (s1.total_marks == s2.total_marks){
        if (s1.roll_number < s2.roll_number){
            return 1;
        }
    }
    return 0;
}
int main(){
    int n;
    cin >> n;
    student *students = new student[n];
    int roll_number = 1;
    for (int i = 0; i < n; i++){
        string name;
        cin >> name;
        int ds, algo, os;
        cin >> ds >> algo >> os;
        int total_total_marks = ds + algo + os;
        students[i].roll_number = roll_number;
        students[i].name = name;
        students[i].total_marks = total_total_marks;
        roll_number += 1;
    }
    sort(students, students + n, compare);
    roll_number = 1;
    for (int i = 0; i < n; i++){
        cout << roll_number << " " << students[i].name << endl;
        roll_number += 1;
    }
}