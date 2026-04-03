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

int TC, N, M, W;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> TC;
    while (TC--) {
        cin >> N >> M >> W;
        vector<pair<int, pii>> graph;
        vector<int> dist(N+1, INF);
        
        int S, E, T;
        for (int i = 0; i < M; i++) {
            cin >> S >> E >> T;
            graph.push_back({T, {S, E}});
            graph.push_back({T, {E, S}});
        }
        
        for (int i = 0; i < W; i++) {
            cin >> S >> E >> T;
            graph.push_back({-T, {S, E}});
        }
        
        dist[1] = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < graph.size(); j++) {
                int w = graph[j].first;
                int s, e;
                tie(s, e) = graph[j].second;
                
                if (w + dist[s] < dist[e]) {
                    dist[e] = w + dist[s];
                    if (i == N-1) {
                        cout << "YES";
                        goto nextRound;
                    }
                }
            }
        }
        cout << "NO";
        nextRound:
        cout << "\n";
    }
}
