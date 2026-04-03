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

const int INF = 2e9 / 3;

int N, E;
int v1, v2;
vector<vector<pii>> graph(801);
int dist1[801], dist2[801];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    cin >> v1 >> v2;
    
    //1 -> v1 -> v2 -> N
    fill(dist1, dist1 + 801, INF);
    fill(dist2, dist2 + 801, INF);
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, v1});
    dist1[v1] = 0;
    
    while (!pq.empty()) {
        int w, x;
        tie(w, x) = pq.top();
        pq.pop();
        
        if (w > dist1[x]) continue;
        
        for (pii next : graph[x]) {
            if (w + next.first < dist1[next.second]) {
                dist1[next.second] = w + next.first;
                pq.push({w + next.first, next.second});
            }
        }
    }
    
    pq.push({0, v2});
    dist2[v2] = 0;
    
    while (!pq.empty()) {
        int w, x;
        tie(w, x) = pq.top();
        pq.pop();
        
        if (w > dist2[x]) continue;
        
        for (pii next : graph[x]) {
            if (w + next.first < dist2[next.second]) {
                dist2[next.second] = w + next.first;
                pq.push({w + next.first, next.second});
            }
        }
    }
    
    int answer1 = dist1[1] + dist1[v2] + dist2[N];
    int answer2 = dist2[1] + dist2[v1] + dist1[N];
    int answer = min(answer1, answer2);
    if (answer >= INF) {
        cout << -1;
    } else {
        cout << answer;
    }
}
