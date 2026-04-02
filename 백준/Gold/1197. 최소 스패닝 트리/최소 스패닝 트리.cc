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

int V, E;
int parent[10001];
bool isMST[10001];
vector<pair<int, pii>> edge;

bool compare(pair<int, pii> x, pair<int, pii> y) {
    return x.first < y.first;
}

int findParent(int x) {
    if (x != parent[x]) {
        parent[x] = findParent(parent[x]);
    }
    return parent[x];
}

void unionParent(int x, int y) {
    int px = findParent(x), py = findParent(y);
    if (px == py) return;
    
    if (px < py) {
        parent[py] = px;
    } else {
        parent[px] = py;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> V >> E;
    
    for (int i = 1; i <= V; i++)
        parent[i] = i;
    
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
    }
    
    sort(edge.begin(), edge.end(), compare);
    
    int count = 0, weight = 0;
    for (int i = 0; i < edge.size(); i++) {
        if (count == V - 1) break;
        
        int w, a, b;
        w = edge[i].first;
        tie(a, b) = edge[i].second;
        if (findParent(a) != findParent(b)) {
            weight += w;
            unionParent(a, b);
            isMST[a] = true;
            isMST[b] = true;
        }
    }
    
    cout << weight;
}
