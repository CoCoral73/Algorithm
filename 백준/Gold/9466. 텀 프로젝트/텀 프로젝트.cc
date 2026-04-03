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

const int INF = 1e9;

int n, answer;
vector<int> v;
vector<int> isVisited;

void dfs(int x) {
    isVisited[x] = 1;
    
    int y = v[x];
    if (isVisited[y] == 1) {
        for (int next = v[y]; next != y; next = v[next])
            answer--;
        answer--;
    } else if (isVisited[y] == 0) {
        dfs(y);
    }
    
    isVisited[x] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        
        v.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        
        isVisited.assign(n + 1, 0);
        answer = n;
        for (int i = 1; i <= n; i++) {
            if (!isVisited[i]) {
                dfs(i);
            }
        }
        cout << answer << '\n';
    }
}

