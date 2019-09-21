# include <iostream>
# include <string.h>
using namespace std;

int line_tr[500];
int line_mc[500];
int g[500][500];
int N,K;

bool find(int r){

    for(int i=0; i<N; i++){
        if(g[r][i] == 1 && line_tr[i] == 0){
            line_tr[i] = 1;
            if(line_mc[i] == -1||find(line_mc[i])){
                line_mc[i] = r;
                return true;
            }
        }
    }

    return false;
}
int main(){
    
    // freopen("data.in","r",stdin);

    memset(g,0,sizeof(g));
    cin >> N >> K;
    for(int i=0; i<N; i++) line_mc[i] = -1;
    for(int i = 0; i < K; i++){
        int row, line;
        cin >> row >> line;
        row--;
        line--;
        g[row][line] = true;
    }
    int all = 0;
    for(int i=0; i<N; i++){
        memset(line_tr,0,sizeof(line_tr));
        if(find(i)) all++;
    }

    cout << all << endl;
}