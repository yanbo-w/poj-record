# include <iostream>
# include <queue>
# include <stdio.h>

using namespace std;
int n, np, nc, m;

int g[100][100];
int gf[100][100];
int f[100][100];

int p[100];
int c[100];

int p_num[100];
int c_num[100];

queue<int> aug_route;
int aug_flow;
int total_flow;

void init(){
    for(int i=0; i<n; i++){
        p[i] = 0;
        c[i] = 0;
        p_num[i] = -1;
        c_num[i] = -1;
        for(int j=0; j<n; j++){
            g[i][j] = 0;
            gf[i][j] = 0;
            f[i][j] = 0;
        }
    }
}

bool bfs(int s){
    int color[100];
    int parent[100];
    for(int i=0; i<100; i++){
        color[i] = 0;
        parent[i] = -1;
    }
    queue<int> Q;
    Q.push(s);
    color[Q.front()] = 1;
    while(!Q.empty()){     
        for(int i=0; i<n; i++){
            if(color[i] == 0 && gf[Q.front()][i] != 0){
                Q.push(i);
                color[i] = 1;
                parent[i] = Q.front();
                if(c[i] != 0){
                    aug_flow = c[i];
                    int tr = i;
                    while(parent[tr] != -1){
                        aug_route.push(tr);
                        if(gf[parent[tr]][tr] < aug_flow) aug_flow = gf[parent[tr]][tr];
                        tr = parent[tr];
                    }
                    aug_route.push(tr);
                    if(p[s] < aug_flow) aug_flow = p[s];
                    p[s] = p[s] - aug_flow;
                    c[i] = c[i] - aug_flow;
                    total_flow += aug_flow;
                    return true;
                }
            }
        }
        color[Q.front()] = 2;
        Q.pop();
    }
    return false;
}

bool find_aug(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            gf[i][j] = g[i][j] - f[i][j];
        }
    }

    for(int i=0; i<np; i++){
        if(p[p_num[i]]>0){
            if(bfs(p_num[i])){
                return true;
            }
        }
    }

    return false;
}

int maxflow(){
    total_flow = 0;
    while(find_aug()){
        int u;
        while(1){
            u = aug_route.front();
            aug_route.pop();
            if(aug_route.empty()) break;
            // cout << u << "--->" << aug_route.front() << "--->";
            f[aug_route.front()][u] += aug_flow;
            f[u][aug_route.front()] = -f[aug_route.front()][u];
        }
        // cout << endl;
    }
    return total_flow;
}

int main(){

    // freopen("data.in", "r", stdin);
    while(cin >> n){
        init();
        cin >> np >> nc >> m;
        for(int i=0;i<m;i++){
            int a, b, w;
            scanf(" (%d,%d)%d ", &a, &b, &w);
            g[a][b] = w;
        }
        for(int i=0;i<np;i++){
            int a, w;
            scanf(" (%d)%d ", &a, &w);
            p[a] = w;
            p_num[i] = a;
        }
        for(int i=0;i<nc;i++){
            int a, w;
            scanf(" (%d)%d", &a, &w);
            c[a] = w;
            c_num[i] = a;
        }

        cout << maxflow() << endl;
    }
}