# include <iostream>

using namespace std;

int dp[20][15001];
int Hook[20];
int Mass[20];
int C,G;

int main(){

    // freopen("data.in", "r", stdin);

    cin >> C >> G;
    for(int Ctr=0;Ctr<C;Ctr++) cin >> Hook[Ctr];
    for(int Gtr=0;Gtr<G;Gtr++) cin >> Mass[Gtr];

    for(int i=0;i<C;i++) dp[0][7500+Hook[i]*Mass[0]] = 1;
    for(int j=0;j<G-1;j++){
        for(int v=0;v<15001;v++){
            if(dp[j][v]!=0){
                for(int i=0;i<C;i++){
                    dp[j+1][v+Mass[j+1]*Hook[i]] += dp[j][v];
                }
            }
        }
    }
    cout << dp[G-1][7500];

}