#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

char path[] = "//Users//vsevolodshatalov//documents//texts//file.txt";
char path0[] = "//Users//vsevolodshatalov//documents//texts//file0.txt";
class Bus
{
private:
    char* Surname;
    int BusNumber;
    int Age;
    int RouteNumber;
public:
    //Bus():BusNumber(0), Age(0), RouteNumber(0), Surname(nullptr) {};
    Bus(int a = 0, int b = 0, int c = 0, char* d = nullptr):BusNumber(a), Age(b), RouteNumber(c), Surname(d) {
        if (d == nullptr)
            d = "\0";
        try {
            Surname = new char[strlen(d)+1];
        }
        catch (...)
        {
            cout << "Error" << endl;
        }
        strcpy(Surname, d);
    };
    Bus(const Bus &other):BusNumber(other.BusNumber), Age(other.Age), RouteNumber(other.RouteNumber), Surname(nullptr) {
        try {
            Surname = new char[strlen(other.Surname)+1];
        }
        catch (...)
        {
            cout << "Error" << endl;
        }
        strcpy(Surname, other.Surname);
    };
    friend ostream& operator << (ostream &out, Bus &tmp) {
        out << tmp.BusNumber << " " << tmp.Age << " " << tmp.RouteNumber << " " << tmp.Surname << endl;
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
    };
    int getRouteNumbers()
    {
        return RouteNumber;
    };
    int getAge()
    {
        return Age;
    };
    char* getSurname()
    {
        return Surname;
    };
    void setBusNumbers(int num)
    {
        BusNumber = num;
    };
    void setRouteNumbers(int num)
    {
        RouteNumber = num;
    };
    void setAge(int num)
    {
        Age = num;
    };
    void setSurname(char* str)
    {
        delete []Surname;
        try
        {
            Surname = new char[strlen(str) + 1];
        }
        catch(...)
        {
            cout << "Error" << endl;
        }
    };
    void save(ofstream& fout)
    {
        int a = getBusNumbers();
        int b = getBusNumbers();
        int c = getAge();
        char* d = getSurname();
        fout.write((char*)&a, sizeof(a));
        fout.write((char*)&b, sizeof(b));
        fout.write((char*)&c, sizeof(c));
        fout.write(d, strlen(d) + 1);
    };
    void load(ifstream& fin)
    {
        int a = getBusNumbers();
        int b = getRouteNumbers();
        int c = getAge();
        char* d = getSurname();
        fin.read((char*)&a, sizeof(a));
        fin.read((char*)&b, sizeof(b));
        fin.read((char*)&c, sizeof(c));
        fin.read(d, strlen(d) + 1);
    }
    /*void save(ofstream& fout)
    {
        fout.write((char*)&BusNumber, sizeof(BusNumber));
        fout.write((char*)&RouteNumber, sizeof(RouteNumber));
        fout.write((char*)&Age, sizeof(Age));
        fout.write(Surname, strlen(Surname) + 1);
    };
    void load(ifstream& fin)
    {
        fin.read((char*)&BusNumber, 100);
        fin.read((char*)&RouteNumber, 100);
        fin.read((char*)&Age, 10);
        fin.read(Surname, strlen(Surname) + 1);
    }*/
};

unsigned int writetofile(Bus *bus[])
{
    ofstream fout(path, ios::out | ios::binary);
    for (unsigned int i = 0; i < 3; i++)
    {
        (*bus[i]).save(fout);
    }
    fout.close();
    return 0;
}

unsigned int writetootherfile(Bus *bus[])
{
    ofstream fout(path0, ios::out | ios::binary);
    for (unsigned int i = 0; i < 3; i++)
    {
        (*bus[i]).save(fout);
    }
    fout.close();
    return 0;
}
unsigned int readfromfile(Bus *bus[])
{
    ifstream fin(path, ios::in | ios::binary);
    //ofstream fout("//Users//vsevolodshatalov//documents//texts//file0.txt", ios::out | ios::binary);
    for (unsigned int i = 0; i < 3; i++)
    {
        (*bus[i]).load(fin);
        //(*bus[i]).save(fout);
    }
    //fout.close();
    fin.close();
    return 0;
}

void printBusNumbers(Bus *arr[], int n)
{
    cout << "Bus numbers: ";
    for (int i = 0; i < n; i++)
    {
        cout << (*arr[i]).getRouteNumbers() << " ";
    }
    cout << endl;
}

void sortByRouteNumber(Bus *arr[], const int n)
{
    //int a[n];
    //for (int t = 0; t < n; t++)
        //a[t] = (*arr[t]).getRouteNumbers();
    /*for (int i = n-1; i>=0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        }
    }*/
    for (int i = n-1; i>=0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    cout << "Bus routes(sorted): " << endl;
    for (int k = 0; k < n; k++)
    {
        cout << *arr[k] << endl;
    }
    cout << endl;
}

void avgAge(Bus *arr[], const int n)
{
    //int a[n];
    int s = 0;
    //for (int t = 0; t < n; t++)
        //a[t] = (*arr[t]).getAge();
    /*for (int k = 0; k < n; k++)
    {
        s = s + a[k];
    }*/
    for (int k = 0; k < n; k++)
    {
        s = s + (*arr[k]).getAge();
    }
    s = s / n;
    cout << "Average Age: " << s << endl;
}

void oldAndYoung(Bus *arr[], const int n)
{
    //int a[n];
    //for (int t = 0; t < n; t++)
        //a[t] = (*arr[t]).getAge();
    /*for (int i = n-1; i>=0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        }
    }*/
    for (int i = n-1; i>=0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    cout << "Age of youngest: " << *arr[n-1] << endl;
    cout << "Age of oldest: " << *arr[0] << endl;
}

/*void getObject(Bus o)
{
    fstream f;
    f.open("//Users//vsevolodshatalov//documents//texts//file.txt", ios::out | ios::app | ios::trunc);
    f << o;
    if (!f.is_open())
        cout << "File is not open" << endl;
    f.close();

}

void putObject(Bus buf)
{
    fstream f;
    fstream ff;
    f.open("//Users//vsevolodshatalov//documents//texts//file.txt", ios::in);
    ff.open("//Users//vsevolodshatalov//documents//texts//newfile.txt", ios::out);
    while(1)
    {
        f >> buf;
        if(f.eof()) {
            break;
        }
        ff << buf;
    }
    //f >> buf;
    //f >> buf >> buf >> buf;
    //f >> buffer;
    //cout << "buffer: " << buffer << endl;
    cout << buf << endl;
    //if (!ff.is_open())
    //cout << "File is not open" << endl;
    f.close();
    ff.close();
}*/

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
    ifstream of;
    //ofstream ofstr("//Users//vsevolodshatalov//documents//texts//file.txt", ios::binary | ios::out);
    fstream ff;
    Bus buf;
    Bus temp;
    const int M = 30;
    char* buffer = new char[M];
    writetofile(arr);
    cout << *arr[0] << endl;
    cout << *arr[1] << endl;
    cout << *arr[2] << endl;
    cout << "-----------------------------------------" << endl;
    readfromfile(arr);
    cout << *arr[0] << endl;
    cout << *arr[1] << endl;
    cout << *arr[2] << endl;
    writetootherfile(arr);
    //of.open("//Users//vsevolodshatalov//documents//texts//file.txt", ios::binary);
    //a.load(of);
    //of.write((char*)&a, sizeof(a));
    //of.close();
    //a.save(ofstr);
    //ofstr.close();
    //getObject(a);
    //getObject(b);
    //getObject(c);
    //putObject(buf);
    /*f.open("//Users//vsevolodshatalov//documents//texts//file.txt", ios::out);
    f << a;
    f << b;
    f << c;
    if (!f.is_open())
        cout << "File is not open" << endl;
    //f.seekg(0);
    f.close();
    f.open("//Users//vsevolodshatalov//documents//texts//file.txt", ios::in);
    ff.open("//Users//vsevolodshatalov//documents//texts//newfile.txt", ios::out);
    while(1)
    {
        f >> buf;
        if(f.eof()) {
            break;
        }
        ff << buf;
    }
    //f >> buf;
    //f >> buf >> buf >> buf;
    //f >> buffer;
    //cout << "buffer: " << buffer << endl;
    cout << buf << endl;
    //if (!ff.is_open())
        //cout << "File is not open" << endl;
    f.close();
    ff.close();*/
}

