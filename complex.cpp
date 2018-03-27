#include <iostream>
using namespace std;

class Complex
{
public:
    double re;
    double im;
    Complex():re(0),im(0) {};
    ~Complex() {};
    void operator = (const Complex &other) {};
    Complex(const Complex &other) {this->re = other.re; this->im = other.im;};
    Complex(double a, double b):re(a), im(b) {};
    friend istream& operator >> (istream &anstream, Complex &num) {cin >> num.re >> num.im; return anstream;};
    friend ostream& operator << (ostream &stream, Complex &tmp) {stream << "Real is: " << tmp.re << " Imaginary part: " << tmp.im << "i" << endl; cout << tmp.re << "+" << tmp.im << "i" << endl; return stream;};
    Complex operator + (const Complex &c) {Complex res; res.re = this->re + c.re; res.im = this->im + c.im; return res;};
    Complex operator - (const Complex &d) {Complex res; res.re = this->re - d.re; res.im = this->im - d.im; return res;};
    Complex operator * (const Complex &e) {Complex res; res.re = (this->re * e.re) - (this->im * e.im); res.im = (this->im * e.re) + (this->re * e.im); return res;};
    Complex operator / (const Complex &f) {Complex res; res.re = ((this->re * f.re) + (this->im * f.im)) / ((f.re * f.re) + (f.im * f.im)); res.im = ((f.re * this->im) - (f.im * this->re)) / ((f.re * f.re) + (f.im * f.im)); return res;};
    
};

int main(int argc, const char * argv[]) {
    {
        Complex a;
        Complex b;
        cin >> a;
        cin >> b;
        Complex d = a + b;
        cout << d;
        Complex e = a - b;
        cout << e;
        Complex f = a * b;
        cout << f;
        Complex g = a / b;
        cout << g;
        Complex c(1,2);
        //cout << a;
    }
}
