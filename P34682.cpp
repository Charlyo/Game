#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int cont, fx;
    cin >> cont;
    for (int j = 0; j < cont; ++j) {
        bool trobat = false;
        cin >> fx;
        for (int k = 0; k < n && not trobat; ++k) {
            if (fx+v[k] == k+1) {
                trobat = true;
                cout << k+1 << endl;
            }
        }
        if (not trobat) cout << "no existeix" << endl;
    }
}
