#include <iostream>
using namespace std;

enum DayTime {Morning, Day, Evening, Night};

class Time
{
private:
    int Seconds;
    int Minutes;
    int Hours;
public:
    Time(int a = 0, int b = 0, int c = 0):Hours(a), Minutes(b), Seconds(c) {};//неверный список инициализации. Не в том порядке!!!
    Time(const Time &other) {
        this->Seconds = other.Seconds;
        this->Minutes = other.Minutes;
        this->Hours = other.Hours;
    };
    Time(const Time &&other) {//бессмысленный move он совпадает с copy
        this->Seconds = other.Seconds;
        this->Minutes = other.Minutes;
        this->Hours = other.Hours;
    };
    friend istream& operator >> (istream &in, Time &num) {
        cin >> num.Hours >> num.Minutes >> num.Seconds;
        if (num.Hours > 24 || num.Minutes > 60 || num.Seconds > 60)
        {
            cout << "Wrong time" << endl;
            exit(1);
        }
        return in;
    };
    void operator = (const Time &other) {// почему void???
        this->Seconds = other.Seconds;
        this->Minutes = other.Minutes;
        this->Hours = other.Hours;
    };
    Time& operator = (Time &&other) {
        swap(Seconds, other.Seconds);
        swap(Minutes, other.Minutes);
        swap(Hours, other.Hours);
        cout << "Move" << endl;
        return (*this);
    };
    friend ostream& operator << (ostream &out, Time &tmp) {
        out << tmp.Hours << ":" << tmp.Minutes << ":" << tmp.Seconds;
        return out;
        
    };
    Time operator + (const Time &plus) {
        Time res;
        res.Seconds = this->Seconds + plus.Seconds;
        res.Minutes = this->Minutes + plus.Minutes;
        res.Hours = this->Hours + plus.Hours;
        if (res.Seconds >= 60)
        {
            res.Seconds = res.Seconds - 60;
            res.Minutes++;
        }
        if (res.Minutes >= 60)
        {
            res.Minutes = res.Minutes - 60;
            res.Hours++;
        }
        if (res.Hours >= 24)
        {
            cout << "Can't handle that much... Please, don't exceed 24 hours" << endl;
        }
        return res;
    };
    Time operator - (Time &minus) {
        Time res;
        res.Seconds = this->Seconds - minus.Seconds;
        res.Minutes = this->Minutes - minus.Minutes;
        res.Hours = this->Hours - minus.Hours;
        if (res.Seconds >= 60)
        {
            res.Seconds = res.Seconds - 60;
            res.Minutes++;
        }
        if (res.Minutes >= 60)
        {
            res.Minutes = res.Minutes - 60;
            res.Hours++;
        }
        if (res.Hours >= 24)
        {
            cout << "Can't handle that much... Please, don't exceed 24 hours" << endl;
        }
        return res;
    };
    bool operator < (const Time &num) { //что за странное имя num ???
        if (Hours < num.Hours) 
        {
            return true;
        }
        else if (Hours > num.Hours)
            return false; //этот кусок кода (6 строк) можно сократить до return(Hours < num.Hours)
        else
        {
            if (Minutes < num.Minutes)
            {
                return true;
            }
            else if (Minutes > num.Minutes)
                return false;
            else //этот кусок кода (6 строк) можно сократить до return(Minutes < num.Minutes)
            {
                if (Seconds < num.Seconds)
                {
                    return true;
                }
                else if (Seconds > num.Seconds)
                    return false;
                else return false;
            }
        }
    };
    bool operator <= (const Time &num) {  //плохо. Надо использовать уже сделанные operator < и >
        if (Hours <= num.Hours)
        {
            return true;
        }
        else if (Hours > num.Hours)
            return false;
        else
        {
            if (Minutes <= num.Minutes)
            {
                return true;
            }
            else if (Minutes > num.Minutes)
                return false;
            else
            {
                if (Seconds <= num.Seconds)
                {
                    return true;
                }
                else if (Seconds > num.Seconds)
                    return false;
                else return false;
            }
        }
    };
    bool operator > (const Time &num) { //плохо. Надо использовать уже сделанный operator <
        if (Hours < num.Hours)
        {
            return false;
        }
        else if (Hours > num.Hours)
            return true;
        else
        {
            if (Minutes < num.Minutes)
            {
                return false;
            }
            else if (Minutes > num.Minutes)
                return true;
            else
            {
                if (Seconds < num.Seconds)
                {
                    return false;
                }
                else if (Seconds > num.Seconds)
                    return true;
                else return false;
            }
        }
    };
    bool operator >= (const Time &num) { //плохо. Надо использовать уже сделанные operator < и >
        if (Hours < num.Hours)
        {
            return false;
        }
        else if (Hours >= num.Hours)
            return true;
        else
        {
            if (Minutes < num.Minutes)
            {
                return false;
            }
            else if (Minutes >= num.Minutes)
                return true;
            else
            {
                if (Seconds < num.Seconds)
                {
                    return false;
                }
                else if (Seconds >= num.Seconds)
                    return true;
                else return false;
            }
        }
    };
    ~Time() {};
    DayTime getDayTime()
    {
        DayTime Time;
        if (Hours >= 6 && Hours < 12)
            Time = Morning;
        if (Hours >= 12 && Hours < 18)
            Time = Day;
        if (Hours >= 18 && Hours < 24)
            Time = Evening;
        if (Hours >= 0 && Hours < 6)
            Time = Night;
        return Time;
    }
};

void printTime(Time t)
{
    if (t.getDayTime() == 0)
        cout << "Morning" << endl;
    if (t.getDayTime() == 1)
        cout << "Day" << endl;
    if (t.getDayTime() == 2)
        cout << "Evening" << endl;
    if (t.getDayTime() == 3)
        cout << "Night" << endl;
}

int main(int argc, const char * argv[]) {
    Time a(4,13,35);
    Time b(4,13,35);
    Time c(5,5,5);
    Time d = c;
    Time tmp;
    tmp = a + b;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << tmp << endl;
    printTime(a);
    if (a <= b)
        cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}
