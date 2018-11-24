/*
ID: liu_xia1
TASK: subset
LANG: C++
*/

#include <cstring>
#include <iostream>

using namespace std;

long long dp[40][800];

int main()
{
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    int n;
    cin >> n;
    int sum;
    sum = (n + 1) * n / 2;
    if (sum % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        sum /= 2;
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1;
        dp[1][0] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (j - i >= 0)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        cout << dp[n][sum] / 2 << endl;
        return 0;
    }
}
