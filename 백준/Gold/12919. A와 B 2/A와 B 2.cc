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

string S, T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> S >> T;
    
    queue<pair<bool, pii>> q;
    q.push({false, {0, T.size() - 1}});

    while (!q.empty()) {
        int isReversed = q.front().first;
        int start, end;
        tie(start, end) = q.front().second;
        q.pop();
        
        if (end - start + 1 == S.size()) {
            string result = T.substr(start, S.size());
            if (isReversed) reverse(result.begin(), result.end());
            
            if (result.compare(S) == 0) {
                cout << 1;
                return 0;
            }
            else { continue; }
        }
        
        if (!isReversed) {
            if (T[end] == 'A') {
                q.push({false, {start, end - 1}});
            }
            if (T[start] == 'B') {
                q.push({true, {start + 1, end}});
            }
        } else {
            if (T[start] == 'A') {
                q.push({true, {start + 1, end}});
            }
            if (T[end] == 'B') {
                q.push({false, {start, end - 1}});
            }
        }
    }

    cout << 0;
}
