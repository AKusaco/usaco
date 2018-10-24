/*
 ID: suliang3
 TASK: namenum
 LANG: C++
 */
// Time to complete the task: 2018.10.24
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

const char num[26] = {'2','2','2','3','3','3','4','4','4','5','5','5',
    				'6','6','6','7','0','7','7','8','8','8','9','9','9','0'};
char a[13], b[13];

int main() {
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    freopen("dict.txt", "r", stderr);
    cin >> a;
    bool flag1, flag2 = false;
    while (fscanf(stderr, "%s", b) != EOF) {
    	flag1 = true;
    	if (strlen(a) != strlen(b)) continue;
    	for (int i = 0; flag1 && b[i]; i++) {
    		if (a[i] != num[b[i] - 'A'])
    			flag1 = false;
    	}
    	if (flag1) {
    		flag2 = true;
    		cout << b << endl;
    	}
    }
    if (!flag2)
    	cout << "NONE" << endl;
    return 0;
}
