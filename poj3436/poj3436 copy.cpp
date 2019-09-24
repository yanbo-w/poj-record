# include <iostream>
# include <string.h>
# include <queue>
# include <stack>

using namespace std;

int map[50][2][10];
int p,n;
int q[50];
int status[50];
int g[50][50];
int f[50][50];
int all;

int connection;

bool bfs(int i){
    int color[50];
    int father[50];
    for(int t=0;t<50;t++) father[t] = -1;
    memset(color,0,sizeof(color));
    queue<int> bq;
    if(q[i] == 0) return false;
    else{
        bq.push(i);
        color[i] = 1;
        while(!bq.empty()){
            for(int tr=0;tr<n;tr++){
                if(g[bq.front()][tr] == 1 && q[tr] != 0 && color[tr] == 0){
                    bq.push(tr);
                    color[tr] = 1;
                    father[tr] = bq.front();
                    if(status[tr] == 2){
                        int min = q[tr];
                        int rec = tr;
                        while(rec!=-1){
                            min = min > q[rec] ? q[rec] : min;
                            rec = father[rec];
                        }
                        all = all + min;
                        rec = tr;
                        while(father[rec]!=-1){
                            q[rec] = q[rec] - min;
                            
                            f[father[rec]][rec] += min;
                            rec = father[rec];
                        }
                        q[i] -= min;
                        return true;
                    }
                }
            }
            bq.pop();
        }
    }
    return false;
}

bool find_aug(){
    for(int i=0;i<n;i++){
        if(status[i] == 1 && bfs(i)) return true;
    }
    return false;
}

void ek(){
    while(find_aug()){
    }
}

int main(){
    // freopen("data.in","r",stdin);
    cin >> p >> n;
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
    memset(status,0,sizeof(status));
    for(int i=0;i<n;i++){
        bool flag_s = true;
        bool flag_c = true;
        for(int p_tr=0;p_tr<p;p_tr++){
            if(map[i][0][p_tr] == 1) flag_s = false;
            if(map[i][1][p_tr] != 1) flag_c = false;
        }
        if(flag_s) status[i] = 1;
        if(flag_c) status[i] = 2;
        for(int j=0;j<n;j++){
            bool flag_1 = true;
            for(int p_tr=0;p_tr<p;p_tr++){
                if((map[i][1][p_tr] == 0 && map[j][0][p_tr] == 1) || (map[i][1][p_tr] == 1 && map[j][0][p_tr] == 0)) flag_1 = false;
            }
            if(flag_1) g[i][j] = 1;
        }
    }

    cout << "read_data" << endl;
    
    ek();

    cout << all <<" " ;
        for(int i = 0; i <n;i++){
            for(int j = 0; j <n;j++){
                if(f[i][j] >0){
                    connection++;
                }
            }
        }
        cout << connection<< endl;
    for(int i = 0; i <n;i++){
        for(int j = 0; j <n;j++){
            if(f[i][j] !=0){
                cout << i+1 << " " << j+1 << " "<< f[i][j] << endl;
            }
        }
    }

    return 0;
}