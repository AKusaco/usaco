/*
ID: liu_xia1
TASK: crypt1
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool checkIn(int number, vector<int>& vi)
{
    while(number)
    {
        int sup = number % 10;
        if (find(vi.begin(), vi.end(), sup) == vi.end())
        {
            return false;
        }
        number /= 10;
    }
    return true;
}

bool check(int number1, int number2, vector<int>& vi)
{
   if (!checkIn(number1, vi))
   {
       return false;
   }

   if (!checkIn(number2, vi))
   {
       return false;
   }
   int sup1 = number1 * (number2 % 10);
   if (!checkIn(sup1, vi) || sup1 < 111 || sup1 > 999)
   {
       return false;
   }
   int sup2 = number1 * (number2 / 10);
   if (!checkIn(sup2, vi) || sup2 < 111 || sup2 > 999)
   {
       return false;
   }
   int ans = sup2 * 10 + sup1;
   if (!checkIn(ans, vi))
   {
       return false;
   }
   return true;
}

int main()
{
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> vi;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vi.push_back(num);
    }
    int count = 0;
    for (int i = 111; i <= 999; i++)
    {
        for (int j = 11; j <= 99; j++)
        {
            bool ans = check(i, j, vi);
            if (ans)
            {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
