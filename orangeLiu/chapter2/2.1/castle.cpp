/*
ID: liu_xia1
TASK: castle
LANG: C++
*/

#include <iostream>

using namespace std;

int M, N, m, n, curNum = 2, curArea = 0;
int arr[150][150];
int record[2600];
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void dfs(int i, int j)
{
    int r, c;
    arr[i][j] = curNum;
    if (i % 2 != 0 && j % 2 != 0)
    {
        curArea++;
    }
    for (int k = 0; k < 4; k++)
    {
        r = i + dir[k][0];
        c = j + dir[k][1];
        if (r >= 0 && r < n && c >= 0 && c < m && arr[r][c] == 0)
        {
            dfs(r, c);
        }
    }
}

int main()
{
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    cin >> M >> N;
    m = 2 * M;
    n = 2 * N;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if ((i % 2 == 0 || j % 2 == 0) && i != 0 && j != 0
                    && i != n && j != m)
            {
                arr[i][j] = 0;
            }
            if (i % 2 != 0 && j % 2 != 0)
            {
                arr[i][j] = 0;
                int num;
                cin >> num;
                if (num == 1)
                {
                    arr[i-1][j-1]=arr[i][j-1]=arr[i+1][j-1] = 1; 
                }
                else if (num == 2)
                {
                    arr[i-1][j-1]=arr[i-1][j]=arr[i-1][j+1] = 1;
                }
                else if (num == 3)
                {
                    arr[i-1][j-1]=arr[i][j-1]=arr[i+1][j-1]=arr[i-1][j]=arr[i-1][j+1]=1;
                }
                else if (num == 4)
                {
                    arr[i-1][j+1]=arr[i][j+1]=arr[i+1][j+1]=1;
                }
                else if (num == 5)
                {
                    arr[i-1][j-1]=arr[i][j-1]=arr[i+1][j-1]=arr[i-1][j+1]=arr[i][j+1]=arr[i+1][j+1]=1;
                }
                else if (num == 6)
                {
                    arr[i-1][j-1]=arr[i-1][j]=arr[i-1][j+1]=arr[i][j+1]=arr[i+1][j+1]=1;
                }
                else if (num == 7)
                {
                    arr[i-1][j-1]=arr[i][j-1]=arr[i+1][j-1]=arr[i-1][j+1]=arr[i][j+1]=arr[i+1][j+1]=arr[i-1][j]=1;
                }
                else if (num == 8)
                {
                    arr[i+1][j-1]=arr[i+1][j]=arr[i+1][j+1]=1;
                }
                else if (num == 9)
                {
                    arr[i-1][j-1]=arr[i][j-1]=arr[i+1][j-1]=arr[i+1][j]=arr[i+1][j+1]=1;
                }
                else if (num == 10)
                {
                    arr[i-1][j-1]=arr[i-1][j]=arr[i-1][j+1]=arr[i+1][j-1]=arr[i+1][j]=arr[i+1][j+1]=1;
                }
                else if (num == 11)
                {
                    arr[i-1][j-1]=arr[i-1][j]=arr[i-1][j+1]=arr[i+1][j-1]=arr[i+1][j]=arr[i+1][j+1]=arr[i][j-1]=1;
                }
                else if (num == 12)
                {
                    arr[i-1][j+1]=arr[i][j+1]=arr[i+1][j+1]=arr[i+1][j-1]=arr[i+1][j]=1;
                }
                else if (num == 13)
                {
                    arr[i-1][j-1]=arr[i][j-1]=arr[i+1][j-1]=arr[i-1][j+1]=arr[i][j+1]=arr[i+1][j+1]=arr[i+1][j]=1;
                }
                else if (num == 14)
                {
                    arr[i-1][j-1]=arr[i-1][j]=arr[i-1][j+1]=arr[i+1][j-1]=arr[i+1][j]=arr[i+1][j+1]=arr[i][j+1]=1;
                }
                else if (num == 15)
                {
                    arr[i][j-1]=arr[i-1][j-1]=arr[i-1][j]=arr[i-1][j+1]=arr[i+1][j-1]=arr[i+1][j]=arr[i+1][j+1]=arr[i][j+1]=1;
                }
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                dfs(i, j);
                if (curArea > max)
                {
                    max = curArea;
                }
                record[curNum] = curArea;
                curNum++;
                curArea = 0;
            }
        }
    }
    cout << curNum - 2 << endl;
    cout << max << endl;
    max = 0;
    int tmp, col, row;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                if (arr[i][j - 1] != arr[i][j + 1])
                {
                    tmp = record[arr[i][j - 1]] + record[arr[i][j + 1]];
                    if (tmp > max)
                    {
                        max = tmp;
                        row = i;
                        col = j;
                    }
                    else if (tmp == max)
                    {
                        if (j < col)
                        {
                            row = i;
                            col = j;
                        }
                        if (j == col && i > row)
                        {
                            row = i;
                            col = j;
                        }
                    }
                }
                if (arr[i - 1][j] != arr[i + 1][j])
                {
                    tmp = record[arr[i - 1][j]] + record[arr[i + 1][j]];
                    if (tmp > max)
                    {
                        max = tmp;
                        row = i;
                        col = j;
                    }
                    else if (tmp == max)
                    {
                        if (j < col)
                        {
                            row = i;
                            col = j;
                        }
                        if (j == col && i > row)
                        {
                            row = i;
                            col = j;
                        }
                    }
                }
            }
        }
    }
    cout << max << endl;
    if (row % 2 == 0)
    {
        cout << row / 2 + 1 << " ";
    }
    else
    {
        cout << (row - 1) / 2 + 1 << " ";
    }
    if (col % 2 != 0)
    {
        cout << col / 2 + 1 << " ";
    }
    else
    {
        cout << col / 2 << " ";
    }
    if (row % 2 != 0 && col % 2 == 0)
    {
        cout << "E" << endl;;
    }
    else if (row % 2 == 0 && col % 2 != 0)
    {
        cout << "N" << endl;
    }
    return 0;
}
