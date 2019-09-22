# include <iostream>
# include <string.h>
# include <stdio.h>

using namespace std;
int h,w;
int map[41][11];
int g[200][200];
int found[200];
int used[200];
int ln, rn;
int all;
int star_num;

bool find(int r){
    for(int i = 0; i <rn; i++){
        if(g[r][i] == 1 && used[i] == 0){
            used[i] = 1;
            if(found[i] == -1 || find(found[i])){
                found[i] = r;
                return true;
            }
        }
    }
    return false;
}

int min_edge(){
    memset(g, 0, sizeof(g));
    ln = (h*w+1)/2;
    rn = h*w/2;
    for(int x=0; x<h; x++){
        for(int y=0; y<w; y++){
            if((x+y)%2 == 0 && map[x+1][y+1]){
                if(map[x+2][y+1]) g[(x*w+y)/2][((x+1)*w+y)/2] = 1;
                if(map[x][y+1]) g[(x*w+y)/2][((x-1)*w+y)/2] = 1;
                if(map[x+1][y+2]) g[(x*w+y)/2][(x*w+y+1)/2] = 1;
                if(map[x+1][y]) g[(x*w+y)/2][(x*w+y-1)/2] = 1;
            }
        }
    }
    for(int i=0; i<rn; i++) found[i] = -1; 
    all = 0;
    for(int i=0; i<ln; i++){
        memset(used, 0, sizeof(used));
        if(find(i)) all++;
    }
    return all;
}


int main(){

    // freopen("data.in","r",stdin);

    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        star_num = 0;
        memset(map,0,sizeof(map));
        cin >> h >> w;
        for(int h_tr=1; h_tr <= h; h_tr ++){
            for(int w_tr=1; w_tr <= w; w_tr++){
                char tmp;
                cin >> tmp;
                if(tmp=='*'){
                    star_num++;
                    map[h_tr][w_tr] = star_num;
                }
            }
        }
        cout << star_num-min_edge() << endl;
    }
    
}