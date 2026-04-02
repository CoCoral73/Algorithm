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

string password;
bool isDouble[20];

bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while (true) {
        cin >> password;
        if (password == "end") { return 0; }
        
        bool flag = false;
        fill(isDouble, isDouble + 20, false);
        
        for (int i = 0; i < password.size(); i++) {
            if (isVowel(password[i])) {
                flag = true;
            }
            if (i > 0) {
                if (password[i-1] == password[i] && (password[i] != 'e' && password[i] != 'o')) {
                    flag = false;
                    break;
                }
                if (isVowel(password[i-1]) == isVowel(password[i])) {
                    isDouble[i] = true;
                }
                if (isDouble[i-1] && isVowel(password[i-1]) == isVowel(password[i])) {
                    flag = false;
                    break;
                }
            }
        }
        
        if (flag) {
            cout << '<' << password << '>' << " is acceptable.\n";
        } else {
            cout << '<' << password << '>' << " is not acceptable.\n";
        }
    }
}
