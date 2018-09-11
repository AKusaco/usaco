/*
ID: suliang2
TASK: ride
LANG: C++
*/

#include <iostream>
#include <string>

using namespace std;

int getHash(string s)
{
    int hash = 1;
    for (int i = 0; i < s.length(); i++)
    {
        hash = ((s[i] - 'A' + 1) * hash) % 47;
    }
    return hash;
}

int main()
{
    // Redirect stdin and stdout, submit required.
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);

    string str1, str2;
    cin >> str1 >> str2;

    if (getHash(str1) == getHash(str2))
        puts("GO");
    else
        puts("STAY");
    return 0;
}
