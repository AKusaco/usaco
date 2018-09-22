/*
ID: liu_xia1
TASK: dualpal
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

char c[] = {'0','1','2','3','4','5','6','7','8','9'};

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
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    int n, s;
    cin >> n >> s;
    int m = 0;
    for (int i = s + 1; ; i++)
    {
        int count = 0;
        for (int j = 2; j < 11; j++)
        {
            string str = convert10ToBase(i, j);
            if (palindromic(str))
            {
                count++;
                if (count == 2)
                {
                    m++;
                    cout << i << endl;
                    if (m == n)
                    {
                        return 0;
                    }
                }
            }
        }
    }
}
