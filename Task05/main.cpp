#include <iostream>
#include <string>
using namespace std;

class Time
{
    int seconds;

public:
    Time(int s = 0)
    {
        seconds = s;
    }

    // Prefix increment
    Time& operator++()
    {
        seconds++;
        return *this;
    }

    // Postfix increment
    Time operator++(int)
    {
        Time old = *this;
        seconds++;
        return old;
    }

    bool operator==(const Time& t) const
    {
        return seconds == t.seconds;
    }

    bool operator<(const Time& t) const
    {
        return seconds < t.seconds;
    }

    void display()
    {
        int h = seconds / 3600;
        int m = (seconds % 3600) / 60;
        int s = seconds % 60;

        cout << h << ":"
             << m << ":"
             << s << endl;
    }
};

class Playlist
{
    string tracks[3];
    int size;

public:
    Playlist()
    {
        tracks[0] = "Song A";
        tracks[1] = "Song B";
        tracks[2] = "Song C";

        size = 3;
    }

    string& operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Invalid playlist index");
        }

        return tracks[index];
    }

    const string& operator[](int index) const
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Invalid playlist index");
        }

        return tracks[index];
    }
};

int main()
{
    Time t(3599);

    cout << "Initial time: ";
    t.display();

    Time a = t++;

    cout << "After postfix, old value: ";
    a.display();

    cout << "Current time: ";
    t.display();

    Time b = ++t;

    cout << "After prefix: ";
    b.display();

    cout << boolalpha;
    cout << "a < b: " << (a < b) << endl;

    Playlist p;

    cout << "Track 1: " << p[0] << endl;
    cout << "Track 2: " << p[1] << endl;

    try
    {
        cout << p[3] << endl;
    }
    catch (const out_of_range& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
