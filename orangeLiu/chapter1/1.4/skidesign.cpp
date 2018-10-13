/*
ID: liu_xia1
TASK: skidesign
LANG: C++
*/

#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int main()
{
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> vi;
    int l = INT_MAX;
    int r = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num > r)
        {
            r = num;
        }
        if (num < l)
        {
            l = num;
        }
        vi.push_back(num);
    }
    int res = INT_MAX;
    for (int i = l; i <= r; i++)
    {
        int ans = 0;
        int left = i;
        int right = i + 17;
        for (int j = 0; j < n; j++)
        {
            if (vi[j] > right)
            {
                ans += (vi[j] - right) * (vi[j] - right);
            }
            else if (vi[j] < left)
            {
                ans += (left - vi[j]) * (left - vi[j]);
            }
            else
            {
                continue;
            }
        }
        if (ans < res)
        {
            res = ans;
        }
    }
    cout << res << endl;
    return 0;
}
