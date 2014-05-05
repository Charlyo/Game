#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef pair<int,int> P;

vector<int> s = {1, -1, 0, 0};
vector<int> r = {0, 0, 1, -1};

bool ok(int f, int c, const vector< vector<char> >& map) {
  return f >= 0 and f < map.size() and c >= 0 and c < map[0].size() and map[f][c] != 'X';
}

int distance(int f0, int c0, const vector<vector<char>>& g) {
    int n = g.size();
    int m = g[0].size();
    vector< vector<int > > dst(n, vector<int >(m, -1));
    queue<P> q;
    q.push(P(f0,c0));
    dst[f0][c0] = 0;
    while (not q.empty()) {
        int f = q.front().first;
        int c = q.front().second;
        q.pop();
        if (g[f][c] == 't') return dst[f][c];
        for (int k = 0; k < 4; ++k) {
            int ff = f + s[k];
            int cc = c + r[k];
            if (ok(ff,cc,g) and dst[ff][cc] == -1) {
                q.push(P(ff,cc));
                dst[ff][cc] = 1 + dst[f][c];
            }
        }
    }
    return -1;
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
  int dist = distance(m-1, n-1, g);
  if (dist != -1) cout << dist << endl;
  else cout << "no es pot arribar a cap tresor" << endl;
}
