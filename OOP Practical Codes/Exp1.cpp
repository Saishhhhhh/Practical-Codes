// Aim: Implement a class Complex which represents the Complex Number data type. 
// Implement the following:
// 1. Constructor (including a default constructor which creates the complex number 0+0i).
// 2. Overload operator+ to add two complex numbers.
// 3. Overload operator* to multiply two complex numbers.
// 4. Overload operators << and >> to print and read Complex Numbers.

#include<iostream>
using namespace std;

class complex{
    int real;
    int img;

    public:

    complex(){
        real = 0;
        img = 0;
    }

    complex(int real1, int img1){

        real = real1;
        img = img1;

    }

    void display(){
        cout << real << " + " << img << "i" << endl;
    }

    complex operator +(complex obj){
        complex obj3;

        obj3.real = real + obj.real;
        obj3.img = img + obj.img;

        return obj3;
    }

    //c1 = a+bi  c2 = c+di
    //(ac-bd) + (ad+bc)i

    complex operator *(complex obj){
        complex obj3;

        obj3.real = (real*obj.real) - (img*obj.img);
        obj3.img = (real * obj.img) + (obj.real * img);

        return obj3;
    }

    friend istream& operator>>(istream& input, complex& obj){
        
        cout << "Enter real part: ";
        input >> obj.real;
        cout << "Enter imaginary part: ";
        input >> obj.img;
        return input;
    }


    friend ostream& operator<<(ostream& output, complex& obj){
        output << obj.real << " + " << obj.img << "i";
        return output;
    }

};

int main(){

    complex c1(3,2);
    complex c2(2,6);
    
    // c1.display();
    // c2.display();

    complex c3;
    c3 = c1 + c2;

    c3.display();

    complex c4;
    c4 = c1*c2;

    c4.display();

    complex c5;
    cin >> c5;

    cout << "Entered complex number: " << c5 << endl;

    c5.display();

    return 0;
}