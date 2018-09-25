/*
ID: liu_xia1
TASK: combo
LANG: C++
*/

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool check(int number1, int number2, int n)
{
    if (abs(number1 - number2) <= 2)
    {
        return true;
    }
    if (abs(number1 - number2) >= n - 2)
    {
        return true;
    }
    return false;
}

int main()
{
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> farmer;
    for (int i = 0; i < 3; i++)
    {
        int num;
        cin >> num;
        farmer.push_back(num);
    }
    vector<int> worker;
    for (int i = 0; i < 3; i++)
    {
        int num;
        cin >> num;
        worker.push_back(num);
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if ((check(i, farmer[0], n) && check(j, farmer[1], n) 
                && check(k, farmer[2], n)) || (check(i, worker[0], n) 
                && check(j, worker[1], n) && check(k, worker[2], n)))
                {
                    count++;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}
