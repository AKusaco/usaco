/*
ID: liu_xai1
TASK: milk2
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int begin;
    int end;
};

bool comp(const node x, const node y)
{
    if (x.begin != y.begin)
    {
        return x.begin < y.begin;
    }
    return x.end > y.end;
}

using namespace std;

int main()
{
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    int N;
    cin >> N;
    vector<node> vn;
    for (int i = 0; i < N; i++)
    {
        node a;
        cin >> a.begin >> a.end;
        vn.push_back(a);
    }
    sort(vn.begin(), vn.end(), comp);
    int b = vn[0].begin;
    int e = vn[0].end;
    int milk = e - b;
    int unmilk = 0;
    for (int i = 1; i < N; i++)
    {
        if (vn[i].begin <= e)
        {
            if (vn[i].end > e)
            {
                e = vn[i].end;
            }
        }
        else
        {
            if (vn[i].begin - e > unmilk)
            {
                unmilk = vn[i].begin - e;
            }
            b = vn[i].begin;
            e = vn[i].end;
        }
        if (e - b > milk)
        {
            milk = e - b;
        }
    }
    cout << milk << " " << unmilk << endl;
    return 0;
}
