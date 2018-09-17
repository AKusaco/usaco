/*
 ID: suliang3
 TASK: gift1
 LANG: C++
 */
// Time to complete the task:2018.9.17
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main() {
    //freopen("gift1.in", "r", stdin);
    //freopen("gift1.out", "w", stdout);
    char name[10][14], giver[14], mushroom[14], people[14] = {0};
    int headcount, sendMoney, sendNumber, income[10] = {0};
    cin >> headcount;
    for (int i = 0; i < headcount; i++) {
        cin >> name[i];
        getchar();
    }
    for (int i = 0; i < headcount; i++) {
        cin >> giver;
        getchar();
        cin >> sendMoney >> sendNumber;
        // the giver's balance（送礼者的余额）
        for (int i = 0; i < headcount; i++) {
            int hash = 0;
            // copy the giver's name
            for (int k = 0; k < 14; k++) {
                people[k] = name[i][k];
            }
            for (int j = 0; j < strlen(giver); j++) {
                if (people[j] != giver[j]) {
                    hash = 1;
                    break;
                }
            }
            if (hash == 0 && sendNumber != 0) {
                income[i] -= sendMoney;
                income[i] += (sendMoney % sendNumber);
                break;
            }
        }
        for (int i = 0; i < sendNumber; i++) {
            cin >> mushroom;
            getchar();
            // the recipient's balance （收礼者的余额）
            for (int i = 0; i < headcount; i++) {
                int flag = 0;
                // copy the recipient's name
                for (int k = 0; k < 14; k++) {
                    people[k] = name[i][k];
                }
                for (int j = 0; j < strlen(mushroom); j++) {
                    if (people[j] != mushroom[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0 && sendNumber != 0) {
                    income[i] += sendMoney / sendNumber;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < headcount; i++) {
        cout << name[i] << " " << income[i] << endl;
    }
    return 0;
}

