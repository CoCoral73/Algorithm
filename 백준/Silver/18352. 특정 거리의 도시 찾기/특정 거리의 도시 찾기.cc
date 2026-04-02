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
#include <functional>
#define pii pair<int, int>

using namespace std;

const int INF = 2e9;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int N, M, K, X;
vector<vector<int>> graph(300001);
int dist[300001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K >> X;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    fill(dist, dist + 300001, INF);
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, X});
    dist[X] = 0;
    
    while (!pq.empty()) {
        int w, x;
        tie(w, x) = pq.top();
        pq.pop();
        
        if (w > dist[x]) continue;
        
        for (int y : graph[x]) {
            if (w + 1 < dist[y]) {
                dist[y] = w + 1;
                pq.push({w + 1, y});
            }
        }
    }
    
    bool flag = false;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == K) {
            cout << i << '\n';
            flag = true;
        }
    }
    
    if (!flag) {
        cout << -1;
    }
}
