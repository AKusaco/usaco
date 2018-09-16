/*
 ID: suliang3
 TASK: ride
 LANG: C++
 */
// Time to complete the task: 2018.09.14
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    char group[7] = {0};
    char comet[7] = {0};
    int numG, numC;
    numG = numC = 1;
    cin >> group;
    getchar();
    cin >> comet;
    for(int i = 0; i < strlen(group); i++) {
        numG *= (group[i] - 'A' + 1) % 47;
    }
    for(int i = 0; i < strlen(comet); i++) {
        numC *= (comet[i] - 'A' + 1) % 47;
    }
    if(numG % 47 == numC % 47) {
        cout << "GO" << endl;
    } else {
        cout << "STAY" << endl;
    }
    return 0;
}

