#include <iostream>
#include <cstring>
using namespace std;

class Text
{
    char* data;

public:
    // Constructor
    Text(const char* s = "")
    {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    // Copy constructor
    Text(const Text& t)
    {
        data = new char[strlen(t.data) + 1];
        strcpy(data, t.data);
    }

    // Copy assignment
    Text& operator=(const Text& t)
    {
        if (this != &t)
        {
            char* temp = new char[strlen(t.data) + 1];

            strcpy(temp, t.data);

            delete[] data;

            data = temp;
        }

        return *this;
    }

    // Concatenation
    Text operator+(const Text& t) const
    {
        int length = strlen(data) + strlen(t.data);

        char* temp = new char[length + 1];

        strcpy(temp, data);
        strcat(temp, t.data);

        Text result(temp);

        delete[] temp;

        return result;
    }

    // Equality
    bool operator==(const Text& t) const
    {
        return strcmp(data, t.data) == 0;
    }

    // Inequality
    bool operator!=(const Text& t) const
    {
        return !(*this == t);
    }

    // Output operator
    friend ostream& operator<<(ostream& out, const Text& t)
    {
        out << t.data;
        return out;
    }

    // Destructor
    ~Text()
    {
        delete[] data;
    }
};

int main()
{
    Text a("Hello ");
    Text b("World");
    Text c("!");

    Text result = a + b + c;

    cout << "Message: " << result << endl;

    cout << boolalpha;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;

    Text empty("");

    cout << "Empty message: [" << empty << "]" << endl;

    // Self-assignment test
    a = a;

    cout << "After self-assignment: " << a << endl;

    // Long message test
    Text longMessage(
        "This is a longer SMS message used to test dynamic memory."
    );

    cout << "Long message: " << longMessage << endl;

    return 0;
}
