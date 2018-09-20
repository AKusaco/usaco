/*
ID: liu_xia1
TASK: palsquare
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

char c[] = {'0','1','2','3','4','5','6','7','8','9',
    'A','B','C','D','E','F','G','H','I','J'};

string convert10ToBase(int num, int base)
{
    string ans;
    while (num)
    {
        int sup = num % base;
        ans += c[sup];
        num /= base;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool palindromic(string str)
{
    for (int i = 0, j = str.length() - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int base;
    cin >> base;
    for (int i = 1; i <= 300; i++)
    {
        string numBase1 = convert10ToBase(i, base);
        string numBase2 = convert10ToBase(i * i, base);
        if (palindromic(numBase2))
        {
            cout << numBase1 << " " << numBase2 << endl;
        }
    }
    return 0;
}
