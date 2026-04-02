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

int N;
int tower[500000];
int result[500000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tower[i];
    }
    
    vector<int> stack;
    stack.push_back(0);
    result[0] = 0;
    
    for (int i = 1; i < N; i++) {
        while (!stack.empty()) {
            int h = tower[stack.back()];
            if (h < tower[i]) {
                stack.pop_back();
            } else {
                result[i] = stack.back() + 1;
                stack.push_back(i);
                break;
            }
        }
        
        if (stack.empty()) {
            result[i] = 0;
            stack.push_back(i);
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << result[i] << ' ';
    }
}
