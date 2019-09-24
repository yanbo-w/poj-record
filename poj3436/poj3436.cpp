# include <iostream>
# include <string.h>
# include <queue>

using namespace std;

#define inf 0x3f3f3f3f

int map[50][2][10];
int q[50];
int p,n;
int g[200][200];
int gf[200][200];
int f[200][200];
int val[200];
int pre[200];
int all;
int connection;

inline int min(int a,int b)
{
	return a>b?b:a;
}


bool bfs(int s,int t)//0到2*n+1的最大流
{
	memset(val,0,sizeof(val));
	queue <int> q;
	q.push(s);
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(int i=0;i<=t;i++)
		{
			if(g[p][i]>0&&!val[i])
			{
				pre[i]=p;
				q.push(i);
				val[i]=1;
				if(i==t)
				{
					return true;
				}
			}
		}
	}
	return false;
}
int EK(int s,int t)
{
	int flow=0;
	while(bfs(s,t))
	{
		int d=inf;
		for(int i=t;i!=s;i=pre[i])
		{
			d=min(d,g[pre[i]][i]);
		}
		flow+=d;
		for(int i=t;i!=s;i=pre[i])
		{
			g[pre[i]][i]-=d;
            f[pre[i]][i]+=d;
			g[i][pre[i]]+=d;
            f[i][pre[i]]-=d;
            
		}
	}
	return flow;
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


        cout << EK(2*n, 2*n+1) <<" ";
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