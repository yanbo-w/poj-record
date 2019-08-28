#include <iostream>

using namespace std;

int main(void) {
    long int s, d;
    while(cin >> s >> d)
    {
        long int n = 5*d/(d+s);
        long int res;
        if(n<2) res = res = 2*n*s-2*d*(5-n)+n*s-(2-n)*d;
        else res = (2*n+2)*s-2*d*(5-n);
        if(res >= 0)
            cout << res << '\n';
        else cout << "Deficit" << '\n';
    }

    return 0;
}