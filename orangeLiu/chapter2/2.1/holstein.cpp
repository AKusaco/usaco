/*
ID: liu_xia1
TASK: holstein
LANG: C++
*/

#include <iostream>
#include <vector>

using namespace std;

int v, g;
int need[26];
int number[16][26];
int res = 25;
int ans[16];
int output[16];
int a[26] = {0};
int t = 0;

bool check()
{
    for (int i = 0; i < v; i++)
    {
        if (a[i] < need[i])
        {
            return false;
        }
    }
    res = t;
    for (int i = 1; i <= t; i++)
    {
        output[i] = ans[i];
    }
    return true;
}

void dfs(int k)
{
    if (t >= res)
    {
        return;
    }
    if (check())
    {
        return;
    }
    if (k == g)
    {
        return;
    }
    for (int i = 0; i < v; i++)
    {
        a[i] += number[k][i];
    }
    ans[++t] = k;
    dfs(k + 1);
    --t;
    for (int i = 0; i < v; i++)
    {
        a[i] -= number[k][i];
    }
    dfs(k + 1);
}

int main()
{
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    cin >> v;
    for (int i = 0; i < v; i++)
    {
        int num;
        cin >> num;
        need[i] = num;
    }
    cin >> g;
    for (int i = 0; i < g; i++)
    {
        for (int j = 0; j < v; j++)
        {
            int num;
            cin >> num;
            number[i][j] = num;
        }
    }
    dfs(0);
    cout << res << " ";
    for (int i = 1; i < res; i++)
    {
        cout << output[i] + 1 << " ";
    }
    cout << output[res] + 1 << endl;
}
