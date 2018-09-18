/*
ID: liu_xia1
TASK: beads
LANG: C++
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    int n;
    cin >> n;
    string str;
    cin >> str;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int leftLength = 1;
        int leftIndex;
        if (i == n - 1)
        {
            leftIndex = 0;
        }
        else
        {
            leftIndex = i + 1;
        }
        char leftChar = str[i];
        for (int j = leftIndex; j != i; j++)
        {
            if (j == n)
            {
                j = 0;
            }
            if (leftLength > n)
            {
                break;
            }
            if (leftChar == 'w')
            {
                if (str[j] == 'w')
                {
                    leftLength++;
                }
                else
                {
                    if (str[j] == 'b')
                    {
                        leftLength++;
                        leftChar = 'b';
                    }
                    else
                    {
                        leftLength++;
                        leftChar = 'r';
                    }
                }
            }
            else
            {
                if (str[j] == leftChar || str[j] == 'w')
                {
                    leftLength++;
                }
                else
                {
                    break;
                }
            }
        }
        int rightLength = 1;
        int rightIndex;
        if (i == 0)
        {
            rightIndex = n - 1;
        }
        else
        {
            rightIndex = i - 1;
        }
        char rightChar = str[rightIndex];
        for (int j = rightIndex - 1; j != rightIndex; j--)
        {
            if (j < 0)
            {
                j = n - 1;
            }
            if (rightLength > n)
            {
                break;
            }
            if ( rightChar == 'w')
            {
                if (str[j] == 'w')
                {
                    rightLength++;
                }
                else
                {
                    if (str[j] == 'b')
                    {
                        rightChar = 'b';
                        rightLength++;
                    }
                    else
                    {
                        rightChar = 'r';
                        rightLength++;
                    }
                }
            }
            else
            {
                if (str[j] == rightChar || str[j] == 'w')
                {
                    rightLength++;
                }
                else
                {
                    break;
                }
            }
        }
        if (leftLength + rightLength >= n)
        {
            cout << n << endl;
            return 0;
        }
        else if (leftLength + rightLength > max)
        {
            max = leftLength + rightLength;
        }
    }
    cout << max << endl;
    return 0;
}
