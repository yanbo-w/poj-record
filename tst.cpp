# include <iostream>
# include <cstdlib>
# include <time.h>

using namespace std;

int main(){
    freopen("data.in","w",stdout);
    srand((int)time(0));
    int n = 10;
    cout << n << endl;
    while(n--){
        int h,w;
        h= rand()%40;
        w= rand()%10;
        cout << h << " " << w << endl;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(rand()%2) cout << 'o';
                else cout << '*';
            }
            cout << endl;
        }
    }
}