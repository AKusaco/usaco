/*
ID: liu_xia1
TASK: milk
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int price;
    int number;
};

bool comp(node x, node y)
{
    return x.price < y.price;
}

int main()
{
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    int count,farmer;
    cin >> count >> farmer;
    vector<node> vn;
    for (int i = 0; i < farmer; i++)
    {
        node n;
        cin >> n.price >> n.number;
        vn.push_back(n);
    }
    sort(vn.begin(), vn.end(), comp);
    int money = 0;
    for (int i = 0; i < vn.size(); i++)
    {
        if (vn[i].number >= count)
        {
            money += count * vn[i].price;
            break;
        }
        else
        {
            money += vn[i].number * vn[i].price;
            count -= vn[i].number;
        }
    }
    cout << money << endl;
    return 0;
}
