/*
ID: liu_xia1
TASK: gift1
LANG: C++
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    unordered_map<string, int> ans;
    vector<string> vs;
    int n;
    string name;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        ans[name] = 0;
        vs.push_back(name);
    }
    while (cin >> name)
    {
        int money,number;
        cin >> money >> number;
        ans[name] -= money;
        if (number != 0)
        {
            ans[name] += money % number;
        }
        for (int i = 0; i < number; i++)
        {
            string recieve;
            cin >> recieve;
            ans[recieve] += (money / number);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << vs[i] << " " << ans[vs[i]] << endl;
    }
    return 0;
}
