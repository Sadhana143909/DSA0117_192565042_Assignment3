#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Complex
{
    double real;
    double imag;

public:
    // Default constructor
    Complex() : real(0), imag(0)
    {
    }

    // Constructor with real part
    Complex(double r) : real(r), imag(0)
    {
    }

    // Constructor with real and imaginary parts
    Complex(double r, double i) : real(r), imag(i)
    {
    }

    // Addition
    Complex operator+(const Complex& c) const
    {
        return Complex(real + c.real,
                       imag + c.imag);
    }

    // Subtraction
    Complex operator-(const Complex& c) const
    {
        return Complex(real - c.real,
                       imag - c.imag);
    }

    // Multiplication
    Complex operator*(const Complex& c) const
    {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    // Division
    Complex operator/(const Complex& c) const
    {
        double denominator =
            c.real * c.real + c.imag * c.imag;

        if (denominator == 0)
        {
            throw runtime_error("Division by zero impedance");
        }

        return Complex(
            (real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator
        );
    }

    // Equality
    bool operator==(const Complex& c) const
    {
        return real == c.real && imag == c.imag;
    }

    // Magnitude
    double magnitude() const
    {
        return sqrt(real * real + imag * imag);
    }

    // Output operator
    friend ostream& operator<<(ostream& out, const Complex& c)
    {
        out << c.real;

        if (c.imag >= 0)
        {
            out << " + j" << c.imag;
        }
        else
        {
            out << " - j" << -c.imag;
        }

        return out;
    }
};

int main()
{
    double R = 10;
    double L = 0.05;
    double C = 0.002;
    double omega = 100;

    // Resistor impedance
    Complex ZR(R, 0);

    // Inductor impedance
    Complex ZL(0, omega * L);

    // Capacitor impedance
    Complex ZC(0, -1.0 / (omega * C));

    cout << "Resistor impedance: " << ZR << endl;
    cout << "Inductor impedance: " << ZL << endl;
    cout << "Capacitor impedance: " << ZC << endl;

    // Series circuit
    Complex series = ZR + ZL + ZC;

    cout << "Series impedance: " << series << endl;
    cout << "Series magnitude: "
         << series.magnitude() << endl;

    // Parallel circuit
    try
    {
        Complex parallel1 = (ZR * ZL) / (ZR + ZL);

        Complex parallel =
            (parallel1 * ZC) / (parallel1 + ZC);

        cout << "Parallel impedance: "
             << parallel << endl;

        cout << "Parallel magnitude: "
             << parallel.magnitude() << endl;
    }
    catch (const runtime_error& e)
    {
        cout << e.what() << endl;
    }

    // Test division by zero
    try
    {
        Complex a(10, 5);
        Complex zero(0, 0);

        Complex result = a / zero;

        cout << result << endl;
    }
    catch (const runtime_error& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
