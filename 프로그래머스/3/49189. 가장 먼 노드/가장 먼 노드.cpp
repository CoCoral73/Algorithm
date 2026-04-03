#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> graph(n + 1);
    for (auto e : edge) {
        int a = e[0], b = e[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    
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
    
    int max_value = *max_element(dist.begin() + 1, dist.end());
    for (int i = 1; i <= n; i++) {
        answer += (max_value == dist[i]);
    }
    
    return answer;
}