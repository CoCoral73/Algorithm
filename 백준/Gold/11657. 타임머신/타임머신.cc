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
#define int long long

using namespace std;

const int INF = 2e9;

int N, M;
vector<pair<int, pii>> graph;
vector<int> dist(501, INF);

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph.push_back({C, {A, B}});
    }
    
    dist[1] = 0;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int w = graph[j].first;
            int s, e;
            tie(s, e) = graph[j].second;
            
            if (dist[s] != INF && w + dist[s] < dist[e]) {
                dist[e] = w + dist[s];
                if (i == N-1) {
                    flag = true;
                }
            }
        }
    }
    
    if (flag) {
        cout << -1;
    } else {
        for (int i = 2; i <= N; i++) {
            cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
        }
    }
}
