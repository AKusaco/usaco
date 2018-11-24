/*
ID: liu_xia1
TASK: preface
LANG: C++
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int a[7] = {0};

string op[5][10] =
{
    {},
    {"","I","II","III","IV","V","VI","VII","VIII","IX"},
    {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
    {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
    {"","M","MM","MMM"}
};

void fun(string& str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'I')
        {
            a[0]++;
        }
        else if (str[i] == 'V')
        {
            a[1]++;
        }
        else if (str[i] == 'X')
        {
            a[2]++;
        }
        else if (str[i] == 'L')
        {
            a[3]++;
        }
        else if (str[i] == 'C')
        {
            a[4]++;
        }
        else if (str[i] == 'D')
        {
            a[5]++;
        }
        else
        {
            a[6]++;
        }
    }
}

int main()
{
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp_1 = i % 10;
        string temp = op[1][temp_1];
        fun(temp);
        if (i < 10)
        {
            continue;
        }
        int temp_2 = (i / 10) % 10;
        temp = op[2][temp_2];
        fun(temp);
        if (i < 100)
        {
            continue;
        }
        int temp_3 = (i / 100) % 10;
        temp = op[3][temp_3];
        fun(temp);
        if (i < 1000)
        {
            continue;
        }
        int temp_4 = i / 1000;
        temp = op[4][temp_4];
        fun(temp);
    }
    for (int i = 0; i < 7; i++)
    {
        if (a[i] == 0)
        {
            continue;
        }
        if (i == 0)
        {
            cout << "I" << " " << a[i] << endl;
        }
        else if (i == 1)
        {
            cout << "V" << " " << a[i] << endl;
        }
        else if (i == 2)
        {
            cout << "X" << " " << a[i] << endl;
        }
        else if (i == 3)
        {
            cout << "L" << " " << a[i] << endl;
        }
        else if (i == 4)
        {
            cout << "C" << " " << a[i] << endl;
        }
        else if (i == 5)
        {
            cout << "D" << " " << a[i] << endl;
        }
        else
        {
            cout << "M" << " " << a[i] << endl;
        }
    }
    return 0;
}
