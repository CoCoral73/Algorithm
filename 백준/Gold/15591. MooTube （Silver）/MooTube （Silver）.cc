#include <bits/stdc++.h>

using namespace std;

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  int N, Q;
  cin >> N >> Q;
  
  vector<vector<pair<long long, int>>> graph(N + 1);
  
  for (int i = 0; i < N - 1; i++) {
    int p, q;
    long long r;
    cin >> p >> q >> r;
    graph[p].push_back({r, q});
    graph[q].push_back({r, p});
  }
  
  for (int i = 0; i < Q; i++) {
    long long k;
    int v;
    cin >> k >> v;
    
    queue<int> q({v});
    vector<bool> isVisited(N + 1);
    isVisited[v] = true;
    int count = -1;
    
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      
      count++;
      
      for (auto next : graph[x]) {
        long long next_u = next.first;
        int y = next.second;
        
        if (next_u < k || isVisited[y]) continue;
        isVisited[y] = true;
        q.push(y);
      }
    }
    cout << count << '\n';
  }
  
    
}