/*
ID: liu_xai1
TASK: frac1
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct point
{
    int x;
    int y;
};

bool comp(point a, point b)
{
    return ((a.x * 1.0) / (a.y * 1.0)) < ((b.x * 1.0) / (b.y * 1.0));
}

bool sup(int s, int l) // small  large
{
    for (int i = 2; i < s; i++)
    {
        if (s % i == 0 && l % i == 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    int n;
    cin >> n;
    vector<point> vp;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (j == 1 || (j != 1 && i % j != 0))
            {
                if (sup(j, i))
                {
                    continue;
                }
                point p;
                p.x = j;
                p.y = i;
                vp.push_back(p);
            }
        }
    }
    sort(vp.begin(), vp.end(), comp);
    cout << 0 << "/" << 1 << endl;
    for (int i = 0; i < vp.size(); i++)
    {
        cout << vp[i].x << "/" << vp[i].y << endl;
    }
    cout << 1 << "/" << 1 << endl;
}
