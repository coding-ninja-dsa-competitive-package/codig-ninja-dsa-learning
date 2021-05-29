#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;

/**
 *  Fraction class for operator overloading test.
 */
class Fraction{
    private:
        int numerator;
        int denominator;
    public:
        Fraction(int num, int den){
            this->numerator = num;
            this->denominator = den;
        }

        void print(){
            cout << this->numerator << " / " << this->denominator << endl;
        }
        // overloading for + operator for addition
        Fraction operator+(const Fraction &f) const{
            int lcm = this->denominator * f.denominator;
            int x = lcm / this->denominator;
            int y = lcm / f.denominator;
            int num = x*this->numerator + y*f.numerator;
            Fraction newFraction(num, lcm);
            newFraction.simplify();
            return newFraction;
        }
        // overloading for * operator for multiplication
        Fraction operator*(Fraction const &f) const{
            int num = this->numerator*f.numerator;
            int den = this->denominator*f.denominator;
            Fraction fNew(num, den);
            fNew.simplify();
            return fNew;
        }
        // overloading for == operator for equality
        bool operator==(Fraction const &f) const {
            return (this->numerator == f.numerator) && (this->denominator == f.denominator);
        }

        //pre increment operator overloading
        // nesting is allowed ++(++f1)
        Fraction& operator++(){
            numerator = this->numerator + this->denominator;
            this->simplify();
            return (*this);
        }

        // post increment operator overloading
        // nesting is not allowed in post increment.
        Fraction& operator++(int){
            Fraction fNew(numerator,denominator);
            numerator = numerator + denominator;
            simplify();
            fNew.simplify();
            return fNew;
        }
        // increment and assignment 
        Fraction& operator+=(Fraction const &f){
            int lcm = this->denominator * f.denominator;
            int x = lcm / this->denominator;
            int y = lcm / f.denominator;
            int num = x*this->numerator + y*f.numerator;
            numerator = num;
            denominator = lcm;
            simplify();
            return *this;
        }

        void simplify(){
            int gcd = 1;
            int minimum = min(this->numerator, this->denominator);
            for(int i=1; i<=minimum; i++){
                if(this->numerator%i == 0 && this->denominator%i == 0){
                    gcd = i;
                }
            }
            this->numerator = this->numerator/gcd;
            this->denominator = this->denominator/gcd;
        }
};

int main() {
    Fraction f1(10, 3);
    Fraction f2(20, 6);
    Fraction f3 = f1+f2;
    cout << "Addition of 2 fractions : " ; 
    f3.print();

    Fraction f4 = f1*f2;
    cout << "Multiplication of 2 fractions : " ; 
    f3.print();

    bool isEqual = (f1==f2) ? true : false;
    cout << "Fractions are equal - " << isEqual << endl;

    Fraction f5 = ++(++f1);
    cout << "Pre increment operator overload : ";
    f5.print();

    return 0;
}