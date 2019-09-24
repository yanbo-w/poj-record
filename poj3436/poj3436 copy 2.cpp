# include <iostream>
# include <string.h>
# include <queue>

using namespace std;

int map[50][2][10];
int p,n;
int q[50];
int g[52][52];
int f[52][52];
int all;
int connection;


bool find_aug(){

    int color[52];
    int father[52];
    for(int t=0;t<52;t++) father[t] = -1;
    memset(color,0,sizeof(color));
    queue<int> bq;

    bq.push(50);
    color[50] = 1;
    while(!bq.empty()){
        for(int tr=0;tr<n;tr++){
            if(g[bq.front()][tr] == 1 && q[tr] != 0 && color[tr] == 0){
                bq.push(tr);
                color[tr] = 1;
                father[tr] = bq.front();
            }
        }
        if(g[bq.front()][51] != 0){
            int min = q[bq.front()];
            int rec = bq.front();
            while(rec!=50){
                min = min > q[rec] ? q[rec] : min;
                rec = father[rec];
            }
            all = all + min;
            rec = bq.front();
            while(rec!=50){
                q[rec] = q[rec] - min;
                if(f[father[rec]][rec] == 0 && father[rec]!=50) connection++;
                f[father[rec]][rec] += min;
                rec = father[rec];
            }
            return true;
        }
        color[bq.front()] = 2;
        bq.pop();
    }
    return false;
}

void ek(){
    while(find_aug()){
    }
}

int main(){
    freopen("data.in","r",stdin);
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
            if(flag_s) g[50][i] = 1;
            if(flag_c) g[i][51] = 1;
            for(int j=0;j<n;j++){
                bool flag_1 = true;
                if(i == j) flag_1 = false;
                for(int p_tr=0;p_tr<p;p_tr++){
                    if((map[i][1][p_tr] == 0 && map[j][0][p_tr] == 1) || (map[i][1][p_tr] == 1 && map[j][0][p_tr] == 0)) flag_1 = false;
                }
                if(flag_1) g[i][j] = 1;
            }
        }

        // cout << "read_data" << endl;
        
        ek();

        cout << all <<" " << connection<< endl;
        for(int i = 0; i <n;i++){
            for(int j = 0; j <n;j++){
                if(f[i][j] !=0){
                    cout << i+1 << " " << j+1 << " "<< f[i][j] << endl;
                }
            }
        }
    }
    return 0;
}