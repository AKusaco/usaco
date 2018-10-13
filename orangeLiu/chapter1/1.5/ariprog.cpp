/*
ID: liu_xia1
TASK: ariprog
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct point
{
    int a;
    int b;
};

bool comp(point x, point y)
{
    if (x.b == y.b)
    {
        return x.a < y.a;
    }
    return x.b < y.b;
}

int main()
{
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<bool> vb(2 * m * m + 1, false);
    vector<int> vi;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (!vb[i * i + j * j])
            {
                vb[i * i + j * j] = true;
                vi.push_back(i * i + j * j);
            }
        }
    }
    sort(vi.begin(), vi.end());
    vector<point> vp;
    for (int i = 0; i < vi.size(); i++)
    {
        for (int j = 1; j <= (2 * m * m)/(n - 1); j++)
        {
            point p;
            int sup = vi[i];
            bool flag = true;
            for (int k = 0; k < n; k++)
            {
                if (sup > 2 * m * m)
                {
                    flag = false;
                    break;
                }
                if (!vb[sup])
                {
                    flag = false;
                    break;
                }
                sup += j;
            }
            if (flag)
            {
                p.a = vi[i];
                p.b = j;
                vp.push_back(p);
            }
        }
    }
    sort(vp.begin(), vp.end(), comp);
    if (vp.empty())
    {
        cout << "NONE" << endl;
    }
    else
    {
        for (int i = 0; i < vp.size(); i++)
        {
            cout << vp[i].a << " " << vp[i].b << endl;
        }
    }
    return 0;
}
