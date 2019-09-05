#include <iostream>

using namespace std;

bool dfs(int graph[100][100], int *price, int*level, int N, int s, int M, int level_d, int level_u){
    if(level[s]<level_d || level[s]>level_u) return false;
    level_d = level[s]-M>level_d?level[s]-M:level_d;
    level_u = level[s]+M<level_u?level[s]+M:level_u;
    for(int N_tr=s+1; N_tr<N; N_tr++){
        if(graph[s][N_tr]!=0){
            if(dfs(graph, price, level, N, N_tr, M, level_d, level_u)&&price[N_tr]+graph[s][N_tr]<price[s]) price[s] = price[N_tr]+graph[s][N_tr];
        }
    }
    return true;
}

int main(void) {
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int M, N;
    cin >> M >> N;

    static int graph[100][100];
    static int price[100];
    static int level[100];
    
    for(int N_tr=0; N_tr<N;N_tr++){
        int P, L, X;
        cin >> P >> L >> X;
        price[N_tr] = P;
        level[N_tr] = L;
        for(int X_tr=0; X_tr<X; X_tr++){
            int T, V;
            cin >> T >> V;
            T --;
            graph[N_tr][T] = V;
        }
    }

    dfs(graph, price, level, N, 0, M, level[0]-M, level[0]+M);

    cout << price[0] << endl;

    return 0;
}