#include <iostream>
#include <vector>
using namespace std;

int bs (double& x, const vector<double> & v, int esq, int dre) {
    if (dre < esq) return -1;
    if (dre == esq) {
        if (v[dre] == x) return dre;
        else return -1;
    }
    int mig = (esq+dre)/2;
    if (v[mig] < x) return bs(x, v, mig+1, dre);
    else if (v[mig] > x) return bs(x, v, esq, mig);
    else {
        if (v[mig-1] == x) return bs(x, v, esq, mig-1);
        else return mig;
    }
}

int first_occurrence (double x, const vector<double> & v) {
    return bs(x, v, 0, (v.size()-1));
}


int main() {
    int x;
    cin >> x;
    vector <double> v (x);
    for (int i = 0; i < x; ++i) {
        cin >> v[i];
    }
    double z;
    cin >> z;
    int k = first_occurrence(z, v);
    cout << k << endl;
}
