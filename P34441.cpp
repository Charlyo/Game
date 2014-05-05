#include <iostream>
#include <stack>
using namespace std;

typedef pair<int,bool> P;

void escriu(int n) {
    stack <P> s;
    s.push(make_pair(n,false));
    while (not s.empty()) {
        int m = s.top().first;
        bool b = s.top().second;
        s.pop();
        if (m > 0) {
            if (b) {
                cout << ' ' << m;
            }
            else {
               s.push(make_pair(m-1, false));
               s.push(make_pair(m, true));
               s.push(make_pair(m-1, false));
           }
        }
    }
}


int main() {
    int n;
    while (cin >> n) {
        escriu(n);
        cout << endl;
    }
}
