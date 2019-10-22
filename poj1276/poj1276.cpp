#include <iostream>
#include <string.h>

using namespace std;

int res[10][100000];

int D[10];
int n[10];
int used[10][100000];

int cash, N;

int main(){
    // freopen("data.in","r",stdin);

    while(cin >> cash){
        cin >> N;
        for(int N_tr=0; N_tr<N; N_tr++){
            int n_local, D_local;
            cin >> n_local >> D_local;
            n[N_tr] = n_local;
            D[N_tr] = D_local;
        }

        for(int c=0; c<=cash; c++){
            for(int b=0; b<N; b++){
                int not_in, in;
                if(b-1 < 0) not_in = 0;
                else not_in = res[b-1][c];
                if(c-D[b] < 0) in = 0;
                else if(used[b][c-D[b]] < n[b]){
                    in = res[b][c-D[b]] + D[b];
                    used[b][c] = used[b][c-D[b]] + 1;
                }
                else{
                    in = res[b][c-D[b]];
                    used[b][c] = used[b][c-D[b]];
                }
                if(in > not_in){
                    res[b][c] = in;
                }
                else{
                    res[b][c] = not_in;
                    used[b][c] = 0;
                }
            }
        }
        if(N > 0) cout << res[N-1][cash] << endl;
        else cout << 0 << endl;
    }
}