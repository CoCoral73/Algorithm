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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int n, m, t;
        cin >> n >> m >> t;
        
        int s, g, h;
        cin >> s >> g >> h;
        
        vector<vector<pii>> graph(n+1);
        for (int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].push_back({d, b});
            graph[b].push_back({d, a});
        }
        
        vector<int> dest;
        for (int i = 0; i < t; i++) {
            int x;
            cin >> x;
            dest.push_back(x);
        }
        sort(dest.begin(), dest.end());
        
        vector<int> dist1(n + 1, INF), dist2(n + 1, INF), dist3(n + 1, INF);
        dist1[s] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, s});
        while (!pq.empty()) {
            int cost, x;
            tie(cost, x) = pq.top();
            pq.pop();
            
            if (cost > dist1[x]) continue;
            
            for (pii next : graph[x]) {
                if (cost + next.first < dist1[next.second]) {
                    dist1[next.second] = cost + next.first;
                    pq.push({cost + next.first, next.second});
                }
            }
        }
        
        dist2[g] = 0;
        pq.push({0, g});
        while (!pq.empty()) {
            int cost, x;
            tie(cost, x) = pq.top();
            pq.pop();
            
            if (cost > dist2[x]) continue;
            
            for (pii next : graph[x]) {
                if (cost + next.first < dist2[next.second]) {
                    dist2[next.second] = cost + next.first;
                    pq.push({cost + next.first, next.second});
                }
            }
        }
        
        dist3[h] = 0;
        pq.push({0, h});
        while (!pq.empty()) {
            int cost, x;
            tie(cost, x) = pq.top();
            pq.pop();
            
            if (cost > dist3[x]) continue;
            
            for (pii next : graph[x]) {
                if (cost + next.first < dist3[next.second]) {
                    dist3[next.second] = cost + next.first;
                    pq.push({cost + next.first, next.second});
                }
            }
        }
        
        //s -> g -> h
        int result1 = dist1[g] + dist2[h];
        //s -> h -> g
        int result2 = dist1[h] + dist3[g];
        
        for (int d : dest) {
            if (dist1[d] == result1 + dist3[d] || dist1[d] == result2 + dist2[d]) {
                cout << d << ' ';
            }
        }
        cout << '\n';
    }
}
