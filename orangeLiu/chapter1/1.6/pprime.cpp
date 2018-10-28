/*
ID: liu_xia1
TASK: pprime
LANG: C++
*/

#include <cmath>
#include <iostream>

using namespace std;

bool is_prime(int x)
{
    if (x <= 1)
    {
        return false;
    }
    if (x == 2)
    {
        return true;
    }
    int s = sqrt(x);
    for (int i = 2; i <= s; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int fun(int x)
{
    int res = x / 10;
    while (x)
    {
        res *= 10;
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    int a, b;
    cin >> a >> b;
    if (a < 12)
    {
        for (int i = a; i < 12; i++)
        {
            if (is_prime(i))
            {
                cout << i << endl;
            }
        }
    }
    for (int i = 10; i <= 10000; i++)
    {
        int sup = fun(i);
        if (sup < a)
        {
            continue;
        }
        if (sup > b)
        {
            break;
        }
        if (is_prime(sup))
        {
            cout << sup << endl;
        }
    }
    return 0;
}
