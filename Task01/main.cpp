#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title;
    string author;
    int copies;

public:
    Book() : Book("Unknown", "Unknown", 0)
    {
    }

    Book(string t) : Book(t, "Unknown", 1)
    {
    }

    Book(string t, string a, int c)
        : title(t), author(a), copies(c)
    {
        if (copies < 0)
        {
            copies = 0;
        }
    }

    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Copies: " << copies << endl;
        cout << "------------------" << endl;
    }
};

int main()
{
    Book b1;
    Book b2("C++ Basics");
    Book b3("Python", "James", 5);
    Book b4("Java", "John", -3);

    b1.display();
    b2.display();
    b3.display();
    b4.display();

    return 0;
}
