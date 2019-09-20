# include <iostream>

using namespace std;

int g[27][27];
int color[27];
// int start_t[27];
// int stop_t[27];
int time;
int N;
int indegree[27];
// int outdegree[27];
int circle;
int zero_indegree;
int out[27];
int stack_pointer;

void dfs(int t){
    color[t] = 0;
    time = time + 1;
    // start_t[t] = time;
    for(int i=0;i<N;i++){
        if(g[t][i] == 1 && color[i] == -1){
            // outdegree[t]++;
            dfs(i);
        }
        else if(g[t][i] == 1 && color[i] == 0) circle = 1;
    }
    color[t] = 1;
    time = time + 1;
    out[stack_pointer] = t;
    stack_pointer--;
    // stop_t[t] = time;
}

int check(){
    zero_indegree = 0;
    for(int i=0;i<N;i++){
        color[i] = -1;
        // start_t[i] = 0;
        // stop_t[i] = 0;
        // outdegree[i] = 0;
        stack_pointer =  N-1;
        if(indegree[i] == 0) zero_indegree++;
    }
    time = 0;
    circle = 0;
    for(int i=0;i<N;i++){
        if(color[i] == -1) dfs(i);
    }
    if(circle == 1) return 2;
    if(zero_indegree == 1){
        for(int i=0; i<N-1; i++){
            // if(outdegree[i] > 1) return 0;
            if(g[out[i]][out[i+1]] != 1) return 0;
        }
        return 1;
    }
    else return 0;
}


int main(){
    // freopen("data.in","r",stdin);
    int m;
    while(cin >> N){
        if(N == 0) break;
        cin >> m;
        for(int i=0;i<27;i++){
            for(int j=0;j<27;j++){
                g[i][j] = 0;
            }
            indegree[i] = 0;
        }
        bool flag = true;
        for(int m_tr=0;m_tr<m;m_tr++){
            char a, b;
            cin >> a;
            cin.get();
            cin >> b;
            g[a-'A'][b-'A'] = 1;
            indegree[b-'A']++;
            if(flag){
                switch(check()){
                    case 0:break;
                    case 1:{
                        flag = false;
                        cout << "Sorted sequence determined after "<< m_tr+1  << " relations: ";
                        for(int i=0; i<N; i++) cout << char('A'+out[i]);
                        cout <<  "."<< endl;
                        break;
                    }
                    case 2:{
                        flag = false;
                        cout << "Inconsistency found after "<< m_tr+1  << " relations." << endl;
                        break;
                    }
                }
            }
        }
        if(flag) cout << "Sorted sequence cannot be determined." << endl;
    }
}
