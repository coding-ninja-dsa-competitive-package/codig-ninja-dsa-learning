#include<iostream>

using namespace std;

/**
 *  Fraction Class
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

        void add(const Fraction &f){
            int lcm = this->denominator * f.denominator;
            int x = lcm / this->denominator;
            int y = lcm / f.denominator;
            int num = x*this->numerator + y*f.numerator;
            this->numerator = num;
            this->denominator = lcm;
            simplify();
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

int main(){
    Fraction f1(12, 13);
    Fraction f2(21, 17);
    f1.add(f1);
    f1.print();
}