//
//  main.cpp
//  CppPractice
//
//  Created by 김정원 on 3/13/26.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#define pii pair<int, int>

using namespace std;

const int INF = 2e9;

int N, K;
int isVisited[2][500001];

int getSum(int n) {
    return n * (n + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill(&isVisited[0][0], &isVisited[0][0] + 2 * 500001, INF);
    
    cin >> N >> K;
    
    queue<int> q;
    q.push(N);
    isVisited[0][N] = 0;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        int t0 = isVisited[0][x], t1 = isVisited[1][x];
        
        if (x - 1 >= 0) {
            if (t0 != INF && isVisited[1][x - 1] > t0 + 1) {
                isVisited[1][x - 1] = t0 + 1;
                q.push(x - 1);
            }
            if (t1 != INF && isVisited[0][x - 1] > t1 + 1) {
                isVisited[0][x - 1] = t1 + 1;
                q.push(x - 1);
            }
        }
        if (x + 1 <= 500000) {
            if (t0 != INF && isVisited[1][x + 1] > t0 + 1) {
                isVisited[1][x + 1] = t0 + 1;
                q.push(x + 1);
            }
            if (t1 != INF && isVisited[0][x + 1] > t1 + 1) {
                isVisited[0][x + 1] = t1 + 1;
                q.push(x + 1);
            }
        }
        if (2 * x <= 500000) {
            if (t0 != INF && isVisited[1][2 * x] > t0 + 1) {
                isVisited[1][2 * x] = t0 + 1;
                q.push(2 * x);
            }
            if (t1 != INF && isVisited[0][2 * x] > t1 + 1) {
                isVisited[0][2 * x] = t1 + 1;
                q.push(2 * x);
            }
        }
    }
    
    int t = 0, loc = K;
    while (loc <= 500000) {
        if (isVisited[t % 2][loc] <= t) {
            cout << t;
            return 0;
        }
        
        loc += ++t;
    }
    
    cout << -1;
}
