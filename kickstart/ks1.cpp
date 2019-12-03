#include <iostream> 
#include <vector>

using namespace std; 

int main() {

    // freopen("kickstart/ks1.in", "r", stdin);

    int t, n, a, res;
    cin >> t; 

    for (int i = 1; i <= t; ++i) {
        cin >> n;
        cout << "Case #" << i << ":";
        vector<int> count(n+1);
        res = 0;
        for(int j = 0; j < n; j++){
            cin >> a;
            if(a > n) a = n; 
            for(int k = 1; k <= a; k++) count[k]++;
            if(count[res+1] >= res+1) res++;
            cout << " " << res;
        }
        cout << endl;

    }

    return 0;
}