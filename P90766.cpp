#include <vector>
#include <iostream>
using namespace std;


vector<int> s = {1, -1, 0, 0};
vector<int> r = {0, 0, 1, -1};

bool ok(int f, int c, const vector< vector<char> >& map) {
  return f >= 0 and f < map.size() and c >= 0 and c < map[0].size() and map[f][c] != 'X';
}


int reachable(int f, int c, const vector< vector<char> >& map, vector< vector<bool> >& vis) {
  int cont = 0;
  if (not vis[f][c]) {
    vis[f][c] = true;
    if (map[f][c] == 't') ++cont;
    for (int k = 0; k < 4; ++k) {
      int f0 = f-s[k];
      int c0 = c-r[k];
      if (ok(f0, c0, map)){
         cont += reachable(f0, c0, map, vis);
      }
    }
  }
  return cont;
}

int reachable(int f, int c, const vector< vector<char> >& map) {
  int n = map.size();
  int m = map[0].size();
  vector< vector<bool> >vis(n, vector<bool>(m, false));
  return reachable(f, c, map, vis);
}



int main(){
  int x, y;
  cin >> x >> y;
  vector< vector<char> > g(x,vector<char>(y));
  for (int i = 0; i < x; ++i)
    for(int j = 0; j < y; ++j)
      cin >> g[i][j];
  int m, n;
  cin >> m >> n;
  cout << reachable(m-1, n-1, g) << endl;
}
