#include <iostream>
#include <string.h>

using namespace std;

int main(void) {
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    while(1){
        int n;
        cin >> n;
        if(n==0) break;
        int time[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                time[i][j] = i==j?  0 : 100;
            }
        }
        for(int i=0;i<n;i++){
            int pair;
            cin >> pair;
            for(int pair_tr=0; pair_tr<pair; pair_tr++){
                int contact, weight;
                cin >> contact >> weight;
                contact--;
                time[i][contact] = weight;
            }
        }
        for(int k=0; k<n; k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    time[i][j] = time[i][j]>time[i][k]+time[k][j] ? time[i][k]+time[k][j] : time[i][j];
                }
            }
        }
        int min = 100;
        int person = 0;
        for(int i=0; i<n; i++){
            int max = 0;
            for(int j=0;j<n;j++){
                max = max > time[i][j] ? max : time[i][j];
            }
            if(min > max){
                min = max;
                person = i;
            }
        }
        if(min==100) cout << "disjoint" << endl;
        else cout << person+1 << " " << min << endl;
    }

    return 0;
}