#include <iostream> // includes cin to read from stdin and cout to write to stdout
#include <vector>

using namespace std; // since cin and cout are both in namespace std, this saves some text



int main() {

    freopen("kickstart/ks3.in", "r", stdin);

    int t;
    cin >> t; 
    vector<int> num(9);
    int n;
    for (int i = 1; i <= t; ++i) {
        n = 0;
        for(int j = 0; j < 9; j++){
            cin >> num[j];
            n += num[j];
        }

    }
    
    return 0;
}