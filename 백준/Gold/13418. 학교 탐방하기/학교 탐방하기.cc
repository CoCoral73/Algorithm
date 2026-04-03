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

int N, M;
vector<pair<int, pii>> graph;
int parent[1001];

int findParent(int x) {
    if (x != parent[x]) {
        parent[x] = findParent(parent[x]);
    }
    return parent[x];
}

void unionParent(int x, int y) {
    x = findParent(x);
    y = findParent(y);
    
    if (x < y) {
        parent[y] = x;
    } else {
        parent[x] = y;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for (int i = 0; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({c, {a, b}});
    }
    
    sort(graph.begin(), graph.end());
    for (int i = 0; i <= N; i++)
        parent[i] = i;
    
    int count = 0, result1 = 0, result2 = 0;
    for (int i = 0; i <= M; i++) {
        if (count == N) break;
        
        int w, a, b;
        w = graph[i].first;
        tie(a, b) = graph[i].second;
        if (findParent(a) != findParent(b)) {
            unionParent(a, b);
            result1 += (w == 0);
            count++;
        }
    }
    
    sort(graph.begin(), graph.end(), greater<>());
    for (int i = 0; i <= N; i++)
        parent[i] = i;
    
    count = 0;
    for (int i = 0; i <= M; i++) {
        if (count == N) break;
        
        int w, a, b;
        w = graph[i].first;
        tie(a, b) = graph[i].second;
        if (findParent(a) != findParent(b)) {
            unionParent(a, b);
            result2 += (w == 0);
            count++;
        }
    }
    
    cout << abs(result1*result1 - result2*result2);
}
