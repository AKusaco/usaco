/*
 ID: suliang3
 TASK: milk2
 LANG: C++
 */
// Time to complete the task:2018.9.30
// This question refers to other people's code.
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    int N;
    int start[5000], end[5000];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> start[i] >> end[i];
    }
    for (int i = 0; i < N; ++i) {
        int n1 = 0, n2 = 0;
        for (int j = i; j < N; ++j) {
            if(start[i] > start[j]) {
                n1 = start[i];
                n2 = end[i];
                start[i] = start[j];
                end[i] = end[j];
                start[j] = n1;
                end[j] = n2;
            } else if (start[j] == start[i]) {
                if (end[i] < end[j]) {
                    n2 = end[i];
                    end[i] = end[j];
                    end[j] = n2;
                }
            }
        }
    }
    int s = start[0], e = end[0];
    int maxa = e - s, maxb = 0;
    for (int i = 1; i < N; i++) {
        if (start[i] <= e) {
            if (end[i] > e)
                e = end[i];
        } else {
            if (start[i] - e > maxb) {
                maxb = start[i] - e;
            }
            s = start[i];
            e = end[i];
        }
        if (e - s > maxa) {
            maxa = e - s;
        }
    }
    cout << maxa << " " << maxb << endl;
    return 0;
}

