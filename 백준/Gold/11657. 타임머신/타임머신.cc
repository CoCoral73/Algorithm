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
#define int long long
#define pii pair<int, int>


using namespace std;

const int INF = 1e9;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, pii>> graph;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({c, {a, b}});
    }
    
    vector<int> dist(501, INF);
    dist[1] = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int a, b, c;
            c = graph[j].first;
            tie(a, b) = graph[j].second;
            
            if (dist[a] != INF && dist[a] + c < dist[b]) {
                dist[b] = dist[a] + c;
                if (i == N-1) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    
    for (int i = 2; i <= N; i++) {
        cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
    }
}

