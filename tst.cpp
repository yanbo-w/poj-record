# include <iostream>
# include <cstdlib>
# include <time.h>

using namespace std;

int main(){
    freopen("data.in","w",stdout);
    srand(time(0));
    int p = 3;
    int m = 50;
    cout << p << " " << m << endl;
    for(int i=0;i<m; i++){
        cout << rand() %10 << " ";
        for(int j=0;j<p; j++){
            if(rand()%p != 0) cout << 0 << " ";
            else cout << rand()%3 << " ";
        }
        for(int j=0;j<p; j++){
            if(rand()%p != 0) cout << 1 << " ";
            else cout << rand()%2 << " ";
        }
        cout << endl;
    }
}