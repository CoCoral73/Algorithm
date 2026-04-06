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
#include <sstream>
#define int long long
#define pii pair<int, int>


using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> p(M);
    queue<int> q;
    vector<int> isVisited(N+1, -1);
    
    for (int i = 0; i < M; i++) {
      cin >> p[i];
      q.push(p[i]);
      isVisited[p[i]] = 0;
    }
    
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      
      for (int i = 0; i < 20; i++) {
        int next = x ^ (1 << i);
        
        if (next > N || isVisited[next] != -1) continue;
        
        isVisited[next] = isVisited[x] + 1;
        q.push(next);
      }
    }
    cout << *max_element(isVisited.begin(), isVisited.end());
}

