#include <iomanip>
#include <iostream>
using namespace std;

class Money
{
    long long paise;

public:
    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p)
    {
    }

    // TODO 1: Addition
    Money operator+(const Money& m) const
    {
        Money result;
        result.paise = paise + m.paise;
        return result;
    }

    Money operator-(const Money& m) const
    {
        Money result;
        result.paise = paise - m.paise;
        return result;
    }

    Money& operator+=(const Money& m)
    {
        paise += m.paise;
        return *this;
    }

    // TODO 2: Equality
    bool operator==(const Money& m) const
    {
        return paise == m.paise;
    }

    bool operator<(const Money& m) const
    {
        return paise < m.paise;
    }

    friend ostream& operator<<(ostream& out, const Money& m)
    {
        long long amount = m.paise;

        if (amount < 0)
        {
            out << "-Rs ";
            amount = -amount;
        }
        else
        {
            out << "Rs ";
        }

        out << amount / 100 << "."
            << setw(2) << setfill('0') << amount % 100;

        return out;
    }

    friend istream& operator>>(istream& in, Money& m)
    {
        long long rupees;
        int p;

        in >> rupees >> p;

        if (in)
        {
            m.paise = rupees * 100 + p;
        }

        return in;
    }
};

int main()
{
    Money a(120, 75);
    Money b(79, 25);

    Money c = a + b;

    cout << c << endl;
    cout << boolalpha << (c == Money(200)) << endl;

    Money x(0, 75);
    Money y(0, 50);

    cout << x + y << endl;

    Money z(5, 0);
    Money w(10, 0);

    cout << z - w << endl;

    return 0;
}
