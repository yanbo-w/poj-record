#include <iostream>
#include <math.h>

using namespace std;

int main(){
    double n,p;
    while(cin >> n){
        cin >> p;
        cout << pow(p,1.0/n) << '\n';
    }
    return 0;
}