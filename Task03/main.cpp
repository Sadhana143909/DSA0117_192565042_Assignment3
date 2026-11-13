#include <iostream>
using namespace std;

class Event
{
    int rows;
    int seats;
    int booked;
    char** map;

public:
    Event(int r, int s)
        : rows(r), seats(s), booked(0), map(nullptr)
    {
        if (rows > 0 && seats > 0)
        {
            map = new char*[rows];

            for (int i = 0; i < rows; i++)
            {
                map[i] = new char[seats];

                for (int j = 0; j < seats; j++)
                {
                    map[i][j] = 'O';
                }
            }
        }

        cout << "Event created" << endl;
    }

    void bookSeat(int r, int s)
    {
        if (r >= 0 && r < rows &&
            s >= 0 && s < seats)
        {
            if (map[r][s] == 'O')
            {
                map[r][s] = 'X';
                booked++;
                cout << "Seat booked" << endl;
            }
            else
            {
                cout << "Seat already booked" << endl;
            }
        }
        else
        {
            cout << "Invalid seat" << endl;
        }
    }

    void cancelSeat(int r, int s)
    {
        if (r >= 0 && r < rows &&
            s >= 0 && s < seats)
        {
            if (map[r][s] == 'X')
            {
                map[r][s] = 'O';
                booked--;
                cout << "Booking cancelled" << endl;
            }
            else
            {
                cout << "Seat is not booked" << endl;
            }
        }
        else
        {
            cout << "Invalid seat" << endl;
        }
    }

    void display()
    {
        cout << "Seat Map:" << endl;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < seats; j++)
            {
                cout << map[i][j] << " ";
            }

            cout << endl;
        }

        cout << "Total booked: " << booked << endl;
    }

    ~Event()
    {
        if (map != nullptr)
        {
            for (int i = 0; i < rows; i++)
            {
                delete[] map[i];
            }

            delete[] map;
        }

        cout << "Event closed. Booked seats: "
             << booked << endl;
    }
};

int main()
{
    Event e1(2, 3);

    e1.bookSeat(0, 1);
    e1.bookSeat(1, 2);
    e1.display();

    e1.cancelSeat(0, 1);
    e1.display();

    {
        Event e2(1, 2);
        e2.bookSeat(0, 0);
    }

    Event* e3 = new Event(2, 2);
    e3->bookSeat(1, 1);
    delete e3;

    return 0;
}
