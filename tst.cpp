# include <iostream>
# include <vector>
# include <queue>
# include <cmath>

using namespace std;


class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(rows == 0 || cols == 0 || threshold < 0) return 0;
        vector<vector<int> > map(rows);
        for(int i = 0; i < rows; i++) map[i].resize(cols);
        queue<int> x;
        queue<int> y;
        x.push(0);
        y.push(0);
        int res = 1;
        map[0][0] = 1;
        while(!x.empty()){
            if(move(x.front()+1, y.front(), rows, cols, map, threshold)){
                map[x.front()+1][y.front()] = 1;
                x.push(x.front()+1);
                y.push(y.front());
                res++;
            }
            if(move(x.front()-1, y.front(), rows, cols, map, threshold)){
                map[x.front()-1][y.front()] = 1;
                x.push(x.front()-1);
                y.push(y.front());
                res++;
            }
            if(move(x.front(), y.front()+1, rows, cols, map, threshold)){
                map[x.front()][y.front()+1] = 1;
                x.push(x.front());
                y.push(y.front()+1);
                res++;
            }
            if(move(x.front(), y.front()-1, rows, cols, map, threshold)){
                map[x.front()][y.front()-1] = 1;
                x.push(x.front());
                y.push(y.front()-1);
                res++;
            }
            x.pop();
            y.pop();
        }
        return res;
    }
private:
    bool move(int x, int y, int rows, int cols, vector<vector<int> > &map, int threshold){
        if(x >= 0 && y >= 0 && x < rows && y < cols && map[x][y] == 0 && threshlimit(x, y, threshold)) return true;
        else return false;
    }
    bool threshlimit(int i, int j, int threshold){
        int sum = 0;
        while(i > 0){
            sum += i%10;
            i /= 10;
        }
        while(j > 0){
            sum += j%10;
            j /= 10;
        }
        if(sum <= threshold) return true;
        else return false;
    }
};

int main(){

    Solution t;

    cout << t.movingCount(15,1,1) << endl;
    // cout << "----" <<(getnum() < getnum() ? getnum() : getnum()) << "----" << endl;

    return 0;
}