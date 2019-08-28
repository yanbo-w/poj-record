#include <iostream>
#include <math.h>
#include <list>

using namespace std;

class island{
public:
    double x;
    double y;
    double radar_l;
    double radar_r;
    bool operator<(const island &a) const
    {
      return (radar_r < a.radar_r); 
    }
};

typedef list<island> RADAR; 

int one_solve(int n, double d){
    int n_tr;
    int i;
    RADAR radar;
    RADAR::iterator radar_tr;
    for(n_tr = 0;n_tr<n;n_tr++){
        island tmp;
        cin >> tmp.x >> tmp.y;
        if(tmp.y >d){
            for(n_tr=n_tr;n_tr<n;n_tr++) cin.ignore(100,'\n');
            return -1;
        }
        else{
            double half_l=sqrt((double)(d*d-tmp.y*tmp.y));
            tmp.radar_r=(double)tmp.x+half_l;
            tmp.radar_l=(double)tmp.x-half_l;
        }
        //radar_tr=radar.begin();
        //while(radar_tr->radar_r<tmp.radar_r&&radar_tr!=radar.end()) ++radar_tr;
        //radar.insert(radar_tr,tmp);
        radar.push_back(tmp);
    }
    radar.sort();
    // for (radar_tr = radar.begin(); radar_tr != radar.end(); ++radar_tr) 
    //     cout << radar_tr->r << " "; 
    // cout << endl; 

    int radar_num=0;
    while(!radar.empty()){
        radar_tr=radar.begin();
        double r_begin=radar_tr->radar_r;
        //cout << "now" << r_begin << endl;
        while(radar_tr != radar.end()&&radar_tr->radar_r<=r_begin+2*d){
            if(r_begin>=radar_tr->radar_l&&r_begin<=radar_tr->radar_r){
                //cout << radar_tr->x << endl;
                radar_tr=radar.erase(radar_tr);
            }
            else radar_tr++;
        }
        radar_num++;
    }
    return radar_num;
}
int main(){
    int n,problem=0;
    double d;
    cin >> n >> d;
    while(n!=0){
        problem++;
        int ans = one_solve(n,d);
        cout << "Case" << " " << problem << ": " << ans << endl;
        cin >> n >> d;
        //cout << n << d << endl;
    }
    return 0;
}