/*
ID: liu_xia1
TASK: hamming
LANG: C++
*/

#include <iostream>

using namespace std;

int a[65];
int n, b, d;

bool check(int x, int k, int d)
{
    for (int i = 0; i <= k; i++)
    {
        int tmp = x ^ a[i];
        int count = 0;
        while (tmp)
        {
            count++;
            tmp = tmp & (tmp - 1);
        }
        if (count < d)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    cin >> n >> b >> d;
    a[0] = 0;
    int k = 0;
    for (int i =1; i < 256 && k != n; i++)
    {
        if (check(i, k, d))
        {
            a[++k] = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if ((i + 1) % 10 == 0 || i == n-1)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }
    return 0;
}
