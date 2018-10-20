/*
ID: liu_xia1
TASK: milk3
LANG: C++
*/

#include <iostream>
#include <vector>

using namespace std;

bool flag[21][21];
bool milk[21];
int A, B, C;

void dfs(int a, int b, int c)
{
    if (flag[a][b])
    {
        return;
    }
    flag[a][b] = true;
    if (a == 0)
    {
        milk[c] = true;
    }
    // A->B
    if (a >= B - b)
    {
        dfs(a - B + b, B, c);
    }
    else
    {
        dfs(0, a + b, c);
    }
    // A->C
    if (a >= C - c)
    {
        dfs(a - C + c, b, C);
    }
    else
    {
        dfs(0, b, a + c);
    }
    // B->A
    if (b >= A - a)
    {
        dfs(A, b - A + a, c);
    }
    else
    {
        dfs(a + b, 0, c);
    }
    // B->C
    if (b >= C - c)
    {
        dfs(a, b - C + c, C);
    }
    else
    {
        dfs(a, 0, b + c);
    }
    // C->A
    if (c >= A - a)
    {
        dfs(A, b, c - A + a);
    }
    else
    {
        dfs(a + c, b, 0);
    }
    // C->B
    if (c >= B - b)
    {
        dfs(a, B, c - B + b);
    }
    else
    {
        dfs(a, b + c, 0);
    }
}

int main()
{
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    cin >> A >> B >> C;
    dfs(0, 0, C);
    for (int i = 0; i < C; i++)
    {
        if (milk[i])
        {
            cout << i << " ";
        }
    }
    cout << C << endl;
    return 0;
}
