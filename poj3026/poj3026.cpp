# include <iostream>
# include <queue>

using namespace std;

int adj[51*51][51*51];
int maze[51][51];
int maze_tr[51][51];
int node[51*51][2];
int dis[51*51];
bool tr[51*51];

void bfs(int from_node){
    queue<int> q_x;
    queue<int> q_y;

    q_x.push(node[from_node][0]);
    q_y.push(node[from_node][1]);

    while(!q_x.empty()){
        if(maze[q_x.front()][q_y.front()] >= 0 && maze[q_x.front()][q_y.front()] !=from_node) adj[from_node][maze[q_x.front()][q_y.front()]] = maze_tr[q_x.front()][q_y.front()];
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};
        for(int i=0;i<4;i++){
            int x_tmp = q_x.front() + x[i];
            int y_tmp = q_y.front() + y[i];
            if(maze_tr[x_tmp][y_tmp] == 0 && maze[x_tmp][y_tmp] != -2){
                maze_tr[x_tmp][y_tmp] = maze_tr[q_x.front()][q_y.front()] + 1;
                q_x.push(x_tmp);
                q_y.push(y_tmp);
            }
        }
        q_x.pop();
        q_y.pop();
    }
}

void clear_tr(){
    for(int i=0;i<51;i++){
        for(int j=0;j<51;j++){
            maze_tr[i][j] = 0;
        }
    }
}

void get_adj(int N){
    for(int i=0;i<N;i++){
        clear_tr();
        bfs(i);
        adj[i][i] = 0;
    }
}

void prim(int N){
    for(int i=0;i<N;i++){
        dis[i] = adj[0][i];
        tr[i] = false;
    }
    tr[0] = true;
    int dis_sum = 0;

    while(1){
        int min_dis = 51*51;
        int min_node = -1;
        for(int i=0;i<N;i++){
            if(!tr[i]){
                if(min_dis > dis[i]){
                    min_dis = dis[i]; 
                    min_node = i;
                }
            }
        }
        if(min_node != -1){
            tr[min_node] = true;
            dis_sum += min_dis;
            for(int i=0;i<N;i++){
                if(!tr[i]&& adj[min_node][i] < dis[i]){
                    dis[i] = adj[min_node][i];
                }
            }
        }
        else break;
    }
    cout << dis_sum << endl;
}

int main(){
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int N;
    cin >> N;
    for(int N_tr=0;N_tr<N;N_tr++){
        int x, y;
        cin >> y >> x;
        string wast;
        getline(cin, wast);
        int obj_num = 0;
        for(int x_tr=0;x_tr<x;x_tr++){
            char tmp[51];
            cin.getline(tmp, 51);
            // cout << tmp << endl;
            for(int y_tr=0;y_tr<y;y_tr++){
                switch(tmp[y_tr]){
                    case '#': maze[x_tr][y_tr] = -2; break;
                    case ' ': maze[x_tr][y_tr] = -1; break;
                    case 'A': node[obj_num][0] = x_tr; node[obj_num][1] = y_tr; maze[x_tr][y_tr] = obj_num++; break;
                    case 'S': node[obj_num][0] = x_tr; node[obj_num][1] = y_tr; maze[x_tr][y_tr] = obj_num++; break;
                }
            }
        }
        get_adj(obj_num);

        // for(int i=0;i<obj_num;i++){
        //     for(int j=0;j<obj_num;j++){
        //         cout << adj[i][j] << '\t';
        //     }
        //     cout << endl;
        // }
        prim(obj_num);
        // cout << "----------" << endl;
    }
}