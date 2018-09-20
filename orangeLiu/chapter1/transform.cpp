/*
ID: liu_xai1
TASK: transform
LANG: C++
*/

#include <iostream>
#include <vector>

using namespace std;

bool compRotate90(vector<vector<char>>& before,
        vector<vector<char>>& after, int i, int j, int N)
{
    return before[i][j] == after[j][N - i - 1];
}

bool compRotate180(vector<vector<char>>& before,
        vector<vector<char>>& after, int i, int j, int N)
{
    return before[i][j] == after[N - i - 1][N - j - 1];
}

bool compRotate270(vector<vector<char>>& before,
        vector<vector<char>>& after, int i, int j, int N)
{
    return before[i][j] == after[N - j - 1][i];
}

bool compMirror(vector<vector<char>>& before,
        vector<vector<char>>& after, int i, int j, int N)
{
    return before[i][j] == after[i][N - j - 1];
}

bool compMirrorRotate90(vector<vector<char>>& before,
        vector<vector<char>>& after, int i, int j, int N)
{
    return before[i][j] == after[N - j - 1][N - i - 1];
}

bool compMirrorRotate180(vector<vector<char>>& before,
        vector<vector<char>>& after, int i, int j, int N)
{
    return before[i][j] == after[N - i - 1][j];
}

bool compMirrorRotate270(vector<vector<char>>& before,
        vector<vector<char>>& after, int i, int j, int N)
{
    return before[i][j] == after[j][i];
}

bool compNoChange(vector<vector<char>>& before,
        vector<vector<char>>& after, int i, int j, int N)
{
    return before[i][j] == after[i][j];
}

int main()
{
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    int N;
    cin >> N;
    vector<vector<char>> before;
    for (int i = 0; i < N; i++)
    {
        vector<char> vc;
        for (int j = 0; j < N; j++)
        {
            char c;
            cin >> c;
            vc.push_back(c);
        }
        before.push_back(vc);
    }
    vector<vector<char>> after;
    for (int i = 0; i < N; i++)
    {
        vector<char> vc;
        for (int j = 0; j < N; j ++)
        {
            char c;
            cin >> c;
            vc.push_back(c);
        }
        after.push_back(vc);
    }
    vector<int> ans(8, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (compRotate90(before, after, i, j, N))
            {
                ans[0]++;
            }
            if (compRotate180(before, after, i, j, N))
            {
                ans[1]++;
            }
            if (compRotate270(before, after, i, j, N))
            {
                ans[2]++;
            }
            if (compMirror(before, after, i, j, N))
            {
                ans[3]++;
            }
            if (compMirrorRotate90(before, after, i, j, N))
            {
                ans[4]++;
            }
            if (compMirrorRotate180(before, after, i, j, N))
            {
                ans[5]++;
            }
            if (compMirrorRotate270(before, after, i, j, N))
            {
                ans[6]++;
            }
            if (compNoChange(before, after, i, j, N))
            {
                ans[7]++;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (ans[i] == N * N)
        {
            if (i == 4 || i == 5 || i == 6)
            {
                cout << 5 << endl;
                return 0;
            }
            else if (i == 7)
            {
                cout << 6 << endl;
                return 0;
            }
            else
            {
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    cout << 7 << endl;
    return 0;
}
