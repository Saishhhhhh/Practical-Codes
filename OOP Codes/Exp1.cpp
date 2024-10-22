// Aim: Implement a class Complex which represents the Complex Number data type. 
// Implement the following:
// 1. Constructor (including a default constructor which creates the complex number 0+0i).
// 2. Overload operator+ to add two complex numbers.
// 3. Overload operator* to multiply two complex numbers.
// 4. Overload operators << and >> to print and read Complex Numbers.

#include<iostream> 
using namespace std;

class Complex {
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    friend ostream& operator<<(ostream &out, const Complex &obj);
    friend istream& operator>>(istream &in, Complex &obj);

    Complex operator+(const Complex &obj) {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }

    Complex operator*(const Complex &obj) {
        Complex res;
        res.real = (real * obj.real) - (imag * obj.imag);
        res.imag = (real * obj.imag) + (imag * obj.real);
        return res;
    }
};

ostream& operator<<(ostream &out, const Complex &obj) {
    out << obj.real << "+i" << obj.imag;
    return out;
}

istream& operator>>(istream &in, Complex &obj) {
    cout << "\n Enter Real part: ";
    in >> obj.real;
    cout << "\n Enter Imaginary part: ";
    in >> obj.imag;
    return in;
}

int main() {
    Complex c1, c2, c3, c4;
    
    cout << "\n Enter First Number:";
    cin >> c1;
    
    cout << "\n Enter Second Number:";
    cin >> c2;
    
    c3 = c1 + c2;
    cout << "\n The Addition = " << c3;
    
    c4 = c1 * c2;
    cout << "\n The Multiplication = " << c4;
    
    cout << "\n\n";
    return 0;
}

/* 
Input Required:

Enter First Number:
Enter Real part: 3
Enter Imaginary part: 4

Enter Second Number:
Enter Real part: 1
Enter Imaginary part: 2

*/
