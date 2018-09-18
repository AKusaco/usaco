/*
 ID: suliang3
 TASK: friday
 LANG: C++
 */
// Time to complete the task:2018.9.18
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    int n, sum = 13, week[7] = {0};
    cin >> n;
    for (int i = 1900; i < 1900 + n; i++) {
        for (int j = 1; j < 13; j++) {
            week[sum % 7]++;
            if (j == 2) {
                (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))? sum += 29 : sum += 28;
            } else if (j == 4 || j == 6 || j == 9 || j == 11) {
                sum += 30;
            } else {
                sum += 31;
            }
        }
    }
    cout << week[6];
    for (int i = 0; i < 6; i++) {
            cout << " " << week[i];
    }
    putchar('\n');
    return 0;
}

