#include <iostream>
#include <cstring>
using namespace std;

class Bus
{
private:
    char* Surname;
    int BusNumber;
    int Age;
    int RouteNumber;
public:
    Bus():BusNumber(0), Age(0), RouteNumber(0), Surname(nullptr) {};
    Bus(int a = 0, int b = 0, int c = 0, char* d = nullptr):BusNumber(a), Age(b), RouteNumber(c), Surname(nullptr) {
        if (d == nullptr)
            d = "\0"; //ОЙ  и куда именно оно попытается записать этот ноль????
        Surname = new (nothrow) char[strlen(d)+1];
        strcpy(Surname, d);
    };
    Bus(const Bus &other):BusNumber(other.BusNumber), Age(other.Age), RouteNumber(other.RouteNumber), Surname(nullptr) {
        Surname = new char[strlen(other.Surname)+1];
        strcpy(Surname, other.Surname);
    };
    friend ostream& operator << (ostream &out, Bus &tmp) {
        out << tmp.BusNumber << endl << tmp.Age << endl << tmp.RouteNumber << endl << tmp.Surname << endl;
        return out;
    };
    friend istream& operator >> (istream &in, Bus &num) {
        in >> num.BusNumber >> num.Age >> num.RouteNumber >> num.Surname;
        return in;
    };
    bool operator < (const Bus &other) {
        if (other.BusNumber < BusNumber)
            return true;
        else return false;
    };
    bool operator > (const Bus &other) {
        if (other.BusNumber > BusNumber)
            return true;
        else return false;
    };
    ~Bus() {
        delete []Surname;
    };
    
    int getBusNumbers()
    {
        return BusNumber;
    }
    int getRouteNumbers()
    {
        return RouteNumber;
    }
    int getAge()
    {
        return Age;
    }
};

void printBusNumbers(Bus *arr[], int n)
{
    cout << "Bus numbers: ";
    for (int i = 0; i < n; i++)
    {
        cout << (*arr[i]).getRouteNumbers();
    }
    cout << endl;
}

void sortByRouteNumber(Bus *arr[], int n)
{
    int a[n];
    for (int t = 0; t < n; t++)
        a[t] = (*arr[t]).getRouteNumbers();
    for (int i = n-1; i>=0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        }
    }
    cout << "Bus routes: ";
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
    cout << endl;
}

void avgAge(Bus *arr[], int n)
{
    int a[n];
    int s = 0;
    for (int t = 0; t < n; t++)
        a[t] = (*arr[t]).getAge();
    for (int k = 0; k < n; k++)
    {
        s = s + a[k];
    }
    s = s / n;
    cout << "Average Age: " << s << endl;
}

void oldAndYoung(Bus *arr[], int n)
{
    int a[n];
    for (int t = 0; t < n; t++)
        a[t] = (*arr[t]).getAge();
    for (int i = n-1; i>=0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        }
    }
    cout << "Age of youngest: " << a[0] << endl;
    cout << "Age of oldest: " << a[n-1] << endl;
}

int main(int argc, const char * argv[]) {
    const int N = 3;
    Bus *arr[N];
    Bus a(9335, 40, 154, "Vladimir");
    Bus b(4363, 42, 536, "Kirill");
    Bus c(2642, 56, 243, "Dmitry");
    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;
    printBusNumbers(arr, N);
    sortByRouteNumber(arr, N);
    avgAge(arr, N);
    oldAndYoung(arr, N);
    //cout << a;
    //cin >> a;
    //cout << a;
}
