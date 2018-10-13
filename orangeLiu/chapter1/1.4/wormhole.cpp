/*
ID: liu_xia1
TASK: wormhole
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 15;

struct point
{
    int x;
    int y;
}p[N];

int right_next[N], pairs[N];
int n;

bool cmp(point a, point b)
{
    return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}

bool isOK()
{
    for (int i = 1; i <= n; i++)
    {
        int t = i;
        for (int j = 0; j < n; j++)
        {
            t = right_next[pairs[t]];
        }
        if (t)
        {
            return true;
        }
    }
    return false;
}
int fun()
{
    int i, ans = 0;
    for (i = 1; i <= n; i++)
    {
        if (!pairs[i])
        {
            break;
        }
    }
    if (i > n)
    {
        if (isOK())
        {
            return 1;
        }
        return 0;
    }
    for (int j = i+1; j <= n; j++)
    {
        if (!pairs[j])
        {
            pairs[i] = j;
            pairs[j] = i;
            ans += fun();
            pairs[i] = pairs[j] = 0;
        }
    }
    return ans;
}

int main()
{
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 2; i <= n; i++)
    {
        if (p[i].y == p[i - 1].y)
        {
            right_next[i - 1] = i;
        }
    }
    int ans = fun();
    cout << ans << endl;
    return 0;
}
