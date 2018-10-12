/*
 ID: suliang3
 TASK: transform
 LANG: C++
 */
// Time to complete the task:2018.10.12

#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

char tile1[11][11], tile2[11][11], c[105];
int N, a[11][11];
int x, y, p, tot, flag, res;

void solve() {
    // #4 #6
    if (p == 1)
        flag = 2;
    else
        flag = 1;
    memset(a, 0, sizeof(a));
    tot = a[x=0][y=0] = 1;
    while (tot < N*N) {
        while(y<N-1 && !a[x][y+1] && flag) {
            if (tile2[x][++y] == c[tot])
                a[x][y] = ++tot;
            else
                flag = 0;
        }
        while(x<N-1 && !a[x+1][y] && flag) {
            if (tile2[++x][y] == c[tot]){
                a[x][y] = ++tot;
            } else {
                flag = 0;
            }
        }
        while(y>=1 && !a[x][y-1] && flag) {
            if (tile2[x][--y] == c[tot]) {
                a[x][y] = ++tot;
            }
            else
                flag = 0;
        }
        while(x>=1 && !a[x-1][y] && flag) {
            if (tile2[--x][y] == c[tot])
                a[x][y] = ++tot;
            else
                flag = 0;
        }
        if (flag == 0) break;
    }
    if (flag == 1 && res > 6)
        res = 6;
    else if (flag == 2 && res > 4)
        res = 4;
    // #1 #5
    if (p == 1)
        flag = 2;
    else
        flag = 1;
    memset(a, 0, sizeof(a));
    tot = a[x=0][y=N-1] = 1;
    while (tot < N*N) {
        while(x<N-1 && !a[x+1][y] && flag) {
            if (tile2[++x][y] == c[tot])
                a[x][y] = ++tot;
            else
                flag = 0;
        }
        while(y>=1 && !a[x][y-1] && flag) {
            if (tile2[x][--y] == c[tot])
                a[x][y] = ++tot;
            else
                flag = 0;
        }
        while(x>=1 && !a[x-1][y] && flag) {
            if (tile2[--x][y] == c[tot])
                a[x][y] = ++tot;
            else
                flag = 0;
        }
        while(y<N-1 && !a[x][y+1] && flag) {
            if (tile2[x][++y] == c[tot])
                a[x][y] = ++tot;
            else
                flag = 0;
        }
        if (flag == 0) break;
    }
    if (flag == 1 && res > 1)
        res = 1;
    else if (flag == 2 && res > 5)
        res = 5;
    // #2 #5
    if (p == 1)
        flag = 2;
    else
        flag = 1;
    memset(a, 0, sizeof(a));
    tot = a[x=N-1][y=N-1] = 1;
    while (tot < N*N) {
        while(y>=1 && !a[x][y-1] && flag) {
            if (tile2[x][--y] == c[tot])
                a[x][y] = ++tot;
            else
                flag = 0;
        }
        while(x>=1 && !a[x-1][y] && flag) {
            if (tile2[--x][y] == c[tot])
                a[x][y] = ++tot;
            else
                flag = 0;
        }
        while(y<N-1 && !a[x][y+1] && flag) {
            if (tile2[x][++y] == c[tot])
                a[x][y] = ++tot;
            else
                flag = 0;
        }
        while(x<N-1 && !a[x+1][y] && flag) {
            if (tile2[++x][y] == c[tot])
                a[x][y] = ++tot;
            else
                flag = 0;
        }
        if (flag == 0) break;
    }
    if (flag == 1 && res > 2)
        res = 2;
    else if (flag == 2 && res > 5)
        res = 5;
    // #3 #5
    if (p == 1)
        flag = 2;
    else
        flag = 1;
    memset(a, 0, sizeof(a));
    tot = a[x=N-1][y=0] = 1;
    while (tot < N*N) {
        while(x>=1 && !a[x-1][y] && flag) {
            if (tile2[--x][y] == c[tot])
                a[x][y] = ++tot;
            else
                flag = 0;
        }
        while(y<N-1 && !a[x][y+1] && flag) {
            if (tile2[x][++y] == c[tot])
                a[x][y] = ++tot;
            else
                flag = 0;
        }
        while(x<N-1 && !a[x+1][y] && flag) {
            if (tile2[++x][y] == c[tot])
                a[x][y] = ++tot;
            else
                flag = 0;
        }
        while(y>=1 && !a[x][y-1] && flag) {
            if (tile2[x][--y] == c[tot])
                a[x][y] = ++tot;
            else
                flag = 0;
        }
        if (flag == 0) break;
    }
    if (flag == 1 && res > 3)
        res = 3;
    else if (flag == 2 && res > 5)
        res = 5;
    // output result
    if (p == 1) {
        if (res == 7)
            puts("7");
        else
            cout << res << endl;
    }
}

int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    cin >> N;
    char c1[10], c2[10];
    for (int i = 0; i < N; i++) {
        cin >> c1;
        for (int j = 0; j < N; j++) {
            tile1[i][j] = c1[j];
        }
    }
    for (int i = 0; i < N; i++) {
        cin >> c2;
        for (int j = 0; j < N; j++) {
            tile2[i][j] = c2[j];
        }
    }
    memset(a, 0, sizeof(a));
    tot = a[x=0][y=0] = 1;
    c[0] = tile1[x][y];
    while(tot < N*N) {
        while(y<N-1 && !a[x][y+1]) {
            c[tot] = tile1[x][++y];
            a[x][y] = ++tot;
        }
        while(x<N-1 && !a[x+1][y]) {
            c[tot] = tile1[++x][y];
            a[x][y] = ++tot;
        }
        while(y>=1 && !a[x][y-1]) {
            c[tot] = tile1[x][--y];
            a[x][y] = ++tot;
        }
        while(x>=1 && !a[x-1][y]) {
            c[tot] = tile1[--x][y];
            a[x][y] = ++tot;
        }
    }
    p = 0; res = 7;
    solve();
    // reflex
    memset(a, 0, sizeof(a));
    tot = a[x=0][y=N-1] = 1;
    tile1[x][y] = c[0];
    while (tot < N*N) {
        while(y>=1 && !a[x][y-1]) {
            tile1[x][--y] = c[tot];
            a[x][y] = ++tot;
        }
        while(x<N-1 && !a[x+1][y]) {
            tile1[++x][y] = c[tot];
            a[x][y] = ++tot;
        }
        while(y<N-1 && !a[x][y+1]) {
            tile1[x][++y] = c[tot];
            a[x][y] = ++tot;
        }
        while(x>=1 && !a[x-1][y]) {
            tile1[--x][y] = c[tot];
            a[x][y] = ++tot;
        }
    }
    memset(a, 0, sizeof(a));
    tot = a[x=0][y=0] = 1;
    c[0] = tile1[x][y];
    while(tot < N*N) {
        while(y<N-1 && !a[x][y+1]) {
            c[tot] = tile1[x][++y];
            a[x][y] = ++tot;
        }
        while(x<N-1 && !a[x+1][y]) {
            c[tot] = tile1[++x][y];
            a[x][y] = ++tot;
        }
        while(y>=1 && !a[x][y-1]) {
            c[tot] = tile1[x][--y];
            a[x][y] = ++tot;
        }
        while(x>=1 && !a[x-1][y]) {
            c[tot] = tile1[--x][y];
            a[x][y] = ++tot;
        }
    }
    p = 1;
    solve();
    return 0;
}

