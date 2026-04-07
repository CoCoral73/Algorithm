#include <bits/stdc++.h>

using namespace std;

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  int N;
  char game;
  
  cin >> N >> game;
  
  set<string> names;
  while (N--) {
    string name;
    cin >> name;
    names.insert(name);
  }
  
  int x;
  switch (game) {
    case 'Y':
      x = 1;
      break;
    case 'F':
      x = 2;
      break;
    default:
      x = 3;
      break;
  }
  
  cout << names.size() / x;
}