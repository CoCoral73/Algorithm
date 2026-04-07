#include <bits/stdc++.h>

using namespace std;

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  int N;
  vector<string> grid;
  pair<int, int> heart = {-1, -1};
  
  cin >> N;
  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    grid.push_back(str);
    for (int j = 0; j < N; j++) {
      if (heart == make_pair(-1, -1) && str[j] == '*') {
        heart = {i + 1, j};
      }
    }
  }
  
  vector<int> answer(5);
  for (int r = heart.first, c = heart.second - 1; c >= 0 && grid[r][c] == '*'; c--)
    answer[0]++;
  for (int r = heart.first, c = heart.second + 1; c < N && grid[r][c] == '*'; c++)
    answer[1]++;
  for (int r = heart.first + 1, c = heart.second; grid[r][c] == '*'; r++)
    answer[2]++;
  for (int r = heart.first + answer[2] + 1, c = heart.second - 1; r < N && grid[r][c] == '*'; r++)
    answer[3]++;
  for (int r = heart.first + answer[2] + 1, c = heart.second + 1; r < N && grid[r][c] == '*'; r++)
    answer[4]++;
  
  cout << heart.first + 1 << ' ' << heart.second + 1 << '\n';
  for (int x : answer)
    cout << x << ' ';
}