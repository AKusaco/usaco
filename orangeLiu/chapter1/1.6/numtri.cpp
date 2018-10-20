/*
ID: liu_xia1
TASK: numtri
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int>> vvi;
    for (int i = 1; i <= n; i++)
    {
        vector<int> vi;
        for (int j = 0; j < i; j++)
        {
            int num;
            cin >> num;
            vi.push_back(num);
        }
        vvi.push_back(vi);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            vvi[i][j] += max(vvi[i + 1][j], vvi[i + 1][j + 1]);
        }
    }
    cout << vvi[0][0] << endl;
    return 0;
}
