/*
ID: liu_xia1
TASK: sort3
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    int n;
    cin >> n;
    int num1 = 0, num2 =0, num3 = 0;
    vector<int> vi;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num == 1)
        {
            num1++;
        }
        else if (num == 2)
        {
            num2++;
        }
        else
        {
            num3++;
        }
        vi.push_back(num);
    }
    int num12 = 0,num13 = 0,num21 = 0,num23 = 0,num31 = 0,num32 = 0;
    for (int i = 0; i < num1; i++)
    {
        if (vi[i] == 2)
        {
            num12++;
        }
        else if(vi[i] == 3)
        {
            num13++;
        }
    }
    for (int i = 0; i < num2; i++)
    {
        if (vi[i + num1] == 1)
        {
            num21++;
        }
        else if (vi[i + num1] == 3)
        {
            num23++;
        }
    }
    for (int i = 0; i < num3; i++)
    {
        if (vi[i + num1 + num2] == 1)
        {
            num31++;
        }
        else if (vi[i + num1 + num2] == 2)
        {
            num32++;
        }
    }
    int ans = 0;
    ans += min(num12, num21);
    num12 -= min(num12, num21);
    num21 -= min(num12, num21);
    ans += min(num13, num31);
    num13 -= min(num13, num31);
    num31 -= min(num13, num31);
    ans += min(num23, num32);
    num23 -= min(num23, num32);
    num32 -= min(num23, num32);
    ans += ((num12 + num13) * 2);
    cout << ans << endl;
    return 0;
}
