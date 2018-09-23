/*
 ID: suliang3
 TASK: beads
 LANG: C++
 */
// Time to complete the task:2018.9.23
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    char c1, c2, beads[350] = {0};
    int N, left = 0, right = 0, sum[350] = {0};
    cin >> N >> beads;
    for (int i = 0; i < N; i++) {
        c1 = beads[i];
        if (i == 0)
            c2 = beads[N - 1];
        else
            c2 = beads[i - 1];
        // start with statistics on the right side.
        for (int j = i; right < N; j++) {
            if (j == N)
                j = 0;
            if (c1 == 'w' && beads[j] == 'w') {
                right++;
                continue;
            } else if (c1 == 'w' && beads[j] != 'w') {
                c1 = beads[j];
            }
            if (beads[j] == c1 || beads[j] == 'w')
                right++;
            else
                break;
        }
        // start with statistics on the left side.
        for (int k = i - 1; left < N; k--) {
            if (k == -1)
                k = N - 1;
            if (c2 == 'w' && beads[k] == 'w') {
                left++;
                continue;
            } else if (c2 == 'w' && beads[k] != 'w') {
                c2 = beads[k];
            }
            if (beads[k] == c2 || beads[k] == 'w')
                left++;
            else
                break;
        }
        // record data
        if (left + right > N)
            sum[i] = N;
        else
            sum[i] = left + right;
        left = right = 0;
    }
    // find the maximum value
    int maxn = 0;
    for (int i = 0; i < N; i++) {
        if (maxn < sum[i])
            maxn = sum[i];
    }
    cout << maxn << endl;
    return 0;
}

