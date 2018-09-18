/*
ID: liu_xia1
TASK: friday
LANG: C++
*/

#include <iostream>
#include <vector>

using namespace std;

int days[2][12] = {{31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}};

int main()
{
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    vector<int> ans(7,0);
    int n;
    cin >> n;
    int week = 1;
    for (int i = 1900; i < 1900 + n; i++)
    {
        int x;
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
        {
            x = 1;
        }
        else
        {
            x = 0;
        }
        int date = 1;
        for (int j = 0; j < 12; j++)
        {
            for (int k = 1; k <= days[x][j]; k++)
            {
                date++;
                date %= days[x][j];
                week++;
                week %= 7;
                if (date == 13)
                {
                    ans[week]++;
                }
            }
        }
    }
    cout << ans[6] << " " << ans[0] << " " << ans[1] << " "
        << ans[2] << " " << ans[3] << " " << ans[4] << " "
        << ans[5] << endl;
    return 0;
}
