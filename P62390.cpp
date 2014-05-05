#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

void escriu(int n) {
    stack <int> s;
    s.push(n);
    while (not s.empty()) {
        int m = s.top();
        s.pop();
        if (m > 0)  {
            cout << " " << m;
            s.push(m-1);
            s.push(m-1);
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
