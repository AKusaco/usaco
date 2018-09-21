/*
ID: liu_xia1
TASK: ride
LANG: C++
*/

#include <iostream>
#include <string>

using namespace std;

int convert(string& s)
{
    int ans = 1;
    for (int i = 0; i < s.length(); i++)
    {
        ans = (s[i] - 'A' + 1) * ans;
        ans %=47;
    }
    return ans;
}

int main()
{
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    string s1,s2;
    cin >> s1 >> s2;
    if (convert(s1) == convert(s2))
    {
        cout << "GO" << endl;
    }
    else
    {
        cout << "STAY" << endl;
    }
    return 0;
}
