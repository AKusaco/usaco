/*
ID: liu_xia1
TASK: sprime
LANG: C++
*/

#include <cmath>
#include <iostream>

using namespace std;

int a[4] = {1,3,7,9};
int n;

bool is_prime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }
    int s = sqrt(n);
    for (int i = 2; i < s; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void fun(int x, int y)
{
    if (y == n)
    {
        cout << x << endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (is_prime(x * 10 + a[i]))
        {
            fun(x * 10 + a[i], y + 1);
        }
    }
}

int main()
{
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    cin >> n;
    fun(2, 1);
    fun(3, 1);
    fun(5, 1);
    fun(7, 1);
    return 0;
}
