#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

int tetradecimalToDecimal(char *tetra)
{
    int len = strlen(tetra);
    int result = 0, power = len - 1;
    int num;
    for(int i = 0;i<len;i++)
    {
        switch (tetra[i])
        {
        case '0':
            num = 0;
            break;
        
        case 'a':
            num = 1;
            break;
        
        case 'b':
            num = 2;
            break;
        
        case 'c':
            num = 3;
            break;
        
        case 'd':
            num = 4;
            break;
        
        case 'e':
            num = 5;
            break;
        
        case 'f':
            num = 6;
            break;
        
        case 'g':
            num = 7;
            break;
        
        case 'h':
            num = 8;
            break;
        
        case 'i':
            num = 9;
            break;
        
        case 'j':
            num = 10;
            break;
        
        case 'k':
            num = 11;
            break;
        
        case 'l':
            num = 12;
            break;
        
        case 'm':
            num = 13;
            break;
        }
        result += num*pow(14,power);
        power--;

    }
    return result;
}

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

void decToTetra(int num, char *ageInTetra)
{
    char result[8]="0000000";
    int single;
    for(int i = 6; i >= 0; i--)
    {
        if(!num)break;
        single = num % 14;
        switch (single)
        {
        case 0:
            result[i] = '0';
            break;
        
        case 1:
            result[i] = 'a';
            break;
        
        case 2:
            result[i] = 'b';
            break;
        
        case 3:
            result[i] = 'c';
            break;
        
        case 4:
            result[i] = 'd';
            break;
        
        case 5:
            result[i] = 'e';
            break;
        
        case 6:
            result[i] = 'f';
            break;
        
        case 7:
            result[i] = 'g';
            break;
        
        case 8:
            result[i] = 'h';
            break;
        
        case 9:
            result[i] = 'i';
            break;
        
        case 10:
            result[i] = 'j';
            break;
        
        case 11:
            result[i] = 'k';
            break;
        
        case 12:
            result[i] = 'l';
            break;
        
        case 13:
            result[i] = 'm';
            break;
        }
        num /= 14;
    }
    int i = 0, j = 0;
    for(; j < 7; j++)
    {
        if(result[j]!='0')
        {
            ageInTetra[i] = result[j];
            i++;
        }
    }
    ageInTetra[i] = 0;
}

int main()
{
    char dateInTetra[16], dayInTetra[4], monthInTetra[2], yearInTetra[16] = "000000000", ageInTetra[8] = "0000000";
    int age, day, month, year, weekDay, i;
    cin >> dateInTetra >> age;
    for(i = 0; true; i++)
    {
        if(dateInTetra[i] == '.')
        {
            monthInTetra[0] = dateInTetra[i+1];
            dateInTetra[i] = '0';
            dateInTetra[i+1] = '0';
            dateInTetra[i+2] = '0';
            dayInTetra[i+1] = 0;
            break;
        }

        dayInTetra[i] = dateInTetra[i];
    }
    i+=3;
    for(int j = 0; true; i++, j++)
    {
        if(dateInTetra[i] == 0)
        {
            
            yearInTetra[j] = 0;
            break;
        }

        yearInTetra[j] = dateInTetra[i];
    }

    day = tetradecimalToDecimal(dayInTetra);
    month = tetradecimalToDecimal(monthInTetra);
    year = tetradecimalToDecimal(yearInTetra);

    weekDay = dayOfWeek(day,month,year);
    if(weekDay == 6 || weekDay == 7) cout << "Yes, " << day << '.' << month << '.' << year << " isn't a working day. " << age << " -> ";
    cout << "No, " << day << '.' << month << '.' << year << " is a working day. " << age << " -> ";
    decToTetra(age,ageInTetra);
    cout << ageInTetra << endl;
    return 0;
}
