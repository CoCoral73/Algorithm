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

int V, E;
vector<vector<pii>> graph(10001);
priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
bool isMST[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> V >> E;
    
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    
    isMST[1] = true;
    for (pii x : graph[1]) {
        pq.push({x.first, {1, x.second}});
    }
    
    int count = 0, weight = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int a, b;
        tie(a, b) = pq.top().second;
        pq.pop();
        
        if (count == V - 1) break;
        
        if (!isMST[b]) {
            isMST[b] = true;
            weight += cost;
            count++;
            
            for (pii x : graph[b]) {
                pq.push({x.first, {b, x.second}});
            }
        }
    }
    
    cout << weight;
}
