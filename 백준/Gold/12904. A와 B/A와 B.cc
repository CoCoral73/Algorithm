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
    
    int start = 0, end = T.size() - 1;
    bool isReversed = false;
    
    while (end - start + 1 > S.size()) {
        if (!isReversed) {
            if (T[end] == 'B') {
                isReversed = true;
            }
            end--;
        } else {
            if (T[start] == 'B') {
                isReversed = false;
            }
            start++;
        }
    }
    
    string result = T.substr(start, S.size());
    if (isReversed) reverse(result.begin(), result.end());
    
    cout << (result.compare(S) == 0);
}
