#include<iostream>

using namespace std;

//isLeap() returns:
//  true for leap years
//  false for non-leap years
bool isLeap(int year)
{
    if (!(year % 400))return true;
    if (year % 4)return false;
    if (!(year % 100))return false;
    return true;
}

//getInput() returns:
//  true for expected input
//  false for not expected input
bool getInput(int &day, int &month, int &year)
{
    std::cin >> day >> month >> year;
    if (year < 1900 || year > 2100) return false;
    if (month <= 0 || month > 12) return false;
    if (day <= 0) return false;
    if (day > 28)
    {
        if (month != 2 && day < 31) return true;
        if (month == 2 && day < 30)
        {
            return isLeap(year);
        }
        return !(month == 2 || month == 4 || month == 6 || month == 9 || month == 11);
        
    }
    return true;
}

//nextDay() returns:
//  100 when only day should be increased
//  110 when day should become 1 and month should be increased 
//  111 when day and month should be increased and year should be increased
int nextDay(int day, int month, int year)
{
    if (day < 28)return 100;
    if (month != 2 && day <30)return 100;
    if (month == 2 && day ==29) return 110; 
    if (month == 2 && day == 28)
    {
        if(isLeap(year))return 100;
        return 110;
    }
    if (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11)) return 110;
    if (day == 30 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))return 100;
    if (day == 31 && month != 12) return 110;
    if (day == 31 && month == 12) return 111;

    return -1;
}

//nextDayIncreaser() returns:
//  true if everything ran smoothly
//  false if nextDay() broke
bool nextDayIncreaser(int &day, int &month, int &year)
{
    int response = nextDay(day, month, year);
    if(response == -1)
    {
        cout << "DEBUG: An error has occured in nextDay()\n";
        return false;
    }
    if ((response%1000)/100)day++;
    if ((response%100)/10)
    {
        day = 1;
        month++;
    }
    if(response%10)
    {
        day = 1;
        month = 1;
        year++;
    }
    return true;
}

//dayOfWeek() returns:
//  1 for Monday
//  2 for Tuesday
//  3 for Wednesday
//  4 for Thursday
//  5 for Friday
//  6 for Saturday
//  7 for Sunday
//  -22 if nextDayIncreaser() returns false
int dayOfWeek(const int finalday, const int finalmonth, const int finalyear)
{
    int unixDays = 0;
    int day = 1, month = 1, year = 1900;
    for(int i = 0; i < 1000000 ; i++)
    {
        if(day == finalday  &&  month == finalmonth  &&  year == finalyear)return (unixDays%7)+1;
        if(!nextDayIncreaser(day, month, year))return -22;
        unixDays++;
    }
    return -1;
}

bool output(int day, int month, int year, int dayOfWeek)
{
    switch (dayOfWeek)
    {
        case -22:
            return false;
        
        case 1:
            cout << "Monday";
            break;

        case 2:
            cout << "Tuesday";
            break;

        case 3:
            cout << "wednesday";
            break;

        case 4:
            cout << "Thursday";
            break;

        case 5:
            cout << "Friday";
            break;

        case 6:
            cout << "Saturday";
            break;

        case 7:
            cout << "Sunday";
            break;

        case -1:
            cout << "Unexpected error in dayOfWeek()\n";
            return false;
    }

    cout << ", " << day << ", ";

    switch (month)
    {
        case 1:
            cout << "January";
            break;

        case 2:
            cout << "February";
            break;

        case 3:
            cout << "March";
            break;

        case 4:
            cout << "April";
            break; 

        case 5:
            cout << "May";
            break;

        case 6:
            cout << "June";
            break;

        case 7:
            cout << "July";
            break;

        case 8:
            cout << "August";
            break;

        case 9:
            cout << "September";
            break;

        case 10:
            cout << "Octeber";
            break;

        case 11:
            cout << "November";
            break;

        case 12:
            cout << "December";
            break;

        default:
            return false;
    }

    cout << ", " << year << endl;
    return true;
}

int main()
{
    int day, month, year;
    if(!getInput(day, month, year))return 74;
    if(!nextDayIncreaser(day,month,year))return 22;
    if(output(day, month, year, dayOfWeek(day, month, year)))return 0;
    return 22;
}
