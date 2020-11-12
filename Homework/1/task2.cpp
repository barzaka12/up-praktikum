#include<iostream>

using namespace std;


bool powerOf2(int num)
{
    for(int i = 1; i <= num; i*=2 )
    {
        if (i == num)return true;
    }
    return false;
}

int closestPowerOf3(int num)
{
    int power = 0;
    int lowerThanNum = 1, higherThanNum;
    for(int i = 0; i < 1000000; i++)
    {
        higherThanNum = lowerThanNum * 3;
        power++;
        if (higherThanNum >= num)
        {
            int lowDiff = num - lowerThanNum;
            int highDiff = higherThanNum - num;
            if( lowDiff <= highDiff) return power - 1;
            return power;
        }
        lowerThanNum = higherThanNum;
    }
    return -1;
}

int closestPowerOf5(int num)
{
    int power = 0;
    int lowerThanNum = 1, higherThanNum;
    for(int i = 0; i < 1000000; i++)
    {
        higherThanNum = lowerThanNum * 5;
        power++;
        if (higherThanNum >= num)
        {
            int lowDiff = num - lowerThanNum;
            int highDiff = higherThanNum - num;
            if( lowDiff <= highDiff) return power - 1;
            return power;
        }
        lowerThanNum = higherThanNum;
    }
    return -1;
}

int main()
{
    int num;
    cin >> num;

    if (num < 1)return 74;

    if (num % 2)
    {
        cout << closestPowerOf5(num) << endl;
        return 0;
    }

    if(!powerOf2(num))
    {
        cout << closestPowerOf5(num) << endl;
        return 0;
    }

    cout << closestPowerOf3(num) << endl;
    return 0;
}
