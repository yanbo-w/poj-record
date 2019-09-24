# include <iostream>
# include <string.h>
# include <queue>

using namespace std;

#define INF 0x3f3f3f3f

int map[50][2][10];
int q[50];
int p,n;
int g[200][200];
int gf[200][200];
int f[200][200];
int all;
int connection;


bool find_aug(){

    int color[2*n+2];
    int father[2*n+2];
    for(int t=0;t<2*n+2;t++) father[t] = -1;
    memset(color,0,sizeof(color));

    queue<int> bq;
    bq.push(2*n);
    color[2*n] = 1;
    while(!bq.empty()){
        for(int tr=0;tr<2*n+2;tr++){
            if(gf[bq.front()][tr] != 0 && color[tr] == 0){
                bq.push(tr);
                color[tr] = 1;
                father[tr] = bq.front();
                if(tr == 2*n+1){
                    int min = gf[father[tr]][tr];
                    int rec = tr;
                    while(rec!=2*n){
                        min = min > gf[father[rec]][rec] ? gf[father[rec]][rec] : min;
                        rec = father[rec];
                    }
                    // cout << "-------min------" << endl;
                    // cout << min << endl;
                    all = all + min;
                    rec = tr;
                    while(rec!=2*n){
                        // cout << rec/2+1 << "<--";
                        
                        f[father[rec]][rec] += min;
                        f[rec][father[rec]] -= min;
                        rec = father[rec];
                    }
                    // cout << "s" << endl;
                    return true;
                }
            }
        }
        color[bq.front()] = 2;
        bq.pop();
    }
    return false;
}

void ek(){
    do{
        for(int i=0; i<2*n+2; i++){
            for(int j=0; j<2*n+2; j++){
                gf[i][j] = g[i][j] -f[i][j];
            }
        }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout << f[2*i][2*j+1] << "\t";
        //     }
        //     cout << endl;
        // }
        // cout << "--------------------" << endl;
    }while(find_aug());
}

int main(){
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    while(cin >> p >> n){

        for(int i=0;i<n;i++){
            cin >> q[i];
            for(int j=0;j<p;j++){
                cin >> map[i][0][j];
            }
            for(int j=0;j<p;j++){
                cin >> map[i][1][j];
            }
        }
        all = 0;
        connection = 0;
        memset(g,0,sizeof(g));
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++){
            bool flag_s = true;
            bool flag_c = true;
            for(int p_tr=0;p_tr<p;p_tr++){
                if(map[i][0][p_tr] == 1) flag_s = false;
                if(map[i][1][p_tr] != 1) flag_c = false;
            }
            if(flag_s) g[n*2][2*i] = q[i];
            if(flag_c) g[2*i+1][n*2+1] = q[i];
            g[2*i][2*i+1] = q[i];
            for(int j=0;j<n;j++){
                bool flag_1 = true;
                if(i == j) flag_1 = false;
                for(int p_tr=0;p_tr<p;p_tr++){
                    if((map[i][1][p_tr] == 0 && map[j][0][p_tr] == 1) || (map[i][1][p_tr] == 1 && map[j][0][p_tr] == 0)) flag_1 = false;
                }
                if(flag_1) g[2*i+1][2*j] = q[i];
            }
        }

        ek();

        cout << all <<" ";
        for(int i = 0; i <n;i++){
            for(int j = 0; j <n;j++){
                if(f[2*i+1][2*j] >0){
                    connection++;
                }
            }
        }
        cout << connection<< endl;
        for(int i = 0; i <n;i++){
            for(int j = 0; j <n;j++){
                if(f[2*i+1][2*j] >0){
                    cout << i+1 << " " << j+1 << " "<< f[2*i+1][2*j] << endl;
                }
            }
        }
    }
    return 0;
}