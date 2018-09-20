/*
ID: liu_xia1
TASK: namenum
LANG: C++
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    int letter[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
    string str;
    cin >> str;
    int n = str.length();
    freopen("dict.txt", "r", stdin);
    string dict;
    bool flag = false;
    while(cin >> dict)
    {
        if (dict.length() == n)
        {
            for (int i = 0; i < n; i++)
            {
                if (letter[dict[i] - 'A'] == str[i] - '0')
                {
                    if (i == n - 1)
                    {
                        flag = true;
                        cout << dict << endl;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
    if (!flag)
    {
        cout << "NONE" << endl;
    }
    return 0;
}
