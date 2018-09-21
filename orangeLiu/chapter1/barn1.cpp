/*
ID: liu_xia1
TASK: barn1
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    int m,s,c;
    cin >> m >> s >> c;
    vector<int> vi;
    for (int i = 0; i < c; i++)
    {
        int cow;
        cin >> cow;
        vi.push_back(cow);
    }
    sort(vi.begin(), vi.end());
    vector<int> space;
    for (int i = 1; i < c; i++)
    {
        space.push_back(vi[i] - vi[i-1] - 1);
    }
    sort(space.begin(), space.end());
    int ans = c;
    for (int i = 0; i < c - m; i++)
    {
        ans += space[i];
    }
    cout << ans << endl;
    return 0;
}
