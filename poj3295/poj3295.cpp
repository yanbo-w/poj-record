#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    string input;
    cin >> input;
    while(input!="0")
    {
        stack<int> stk;
        for(int i=1; i<33; i++){
            int p = (i&16) >> 4;
            int q = (i&8) >> 3;
            int r = (i&4) >> 2;
            int s = (i&2) >> 1;
            int t = (i&1);
            //cout << p << ' ' << q << ' ' << r << ' ' << s << ' ' << t << '\n' ;
            for(int j=input.length()-1;j>=0;j--){
                char tr = input[j];
                //cout << tr;
                switch(tr)
                {
                    case 'p':{
                        stk.push(p);
                        break;
                    }
                    case 'q':{
                        stk.push(q);
                        break;
                    }
                    case 'r':{
                        stk.push(r);
                        break;
                    }
                    case 's':{
                        stk.push(s);
                        break;
                    }
                    case 't':{
                        stk.push(t);
                        break;
                    }
                    case 'K':{
                        int x = stk.top();
                        stk.pop();
                        int w = stk.top();
                        stk.pop();
                        if(w==1 && x==1) stk.push(1);
                        else stk.push(0);
                        break;
                    }
                    case 'A':{
                        int x = stk.top();
                        stk.pop();
                        int w = stk.top();
                        stk.pop();
                        if(w==0 && x==0) stk.push(0);
                        else stk.push(1);
                        break;
                    }
                    case 'N':{
                        int w = stk.top();
                        stk.pop();
                        if(w==1) stk.push(0);
                        else stk.push(1);
                        break;
                    }
                    case 'C':{
                        int x = stk.top();
                        stk.pop();
                        int w = stk.top();
                        stk.pop();
                        if(w==1 && x==0) stk.push(0);
                        else stk.push(1);
                        break;
                    }
                    case 'E':{
                        int x = stk.top();
                        stk.pop();
                        int w = stk.top();
                        stk.pop();
                        if(w==x) stk.push(1);
                        else stk.push(0);
                        break;
                    }
                }
            }
        }
        int res_sum = 0;
        for(int tr_input=0;tr_input<32;tr_input++){
            res_sum += stk.top();
            stk.pop();
        }
        if(res_sum == 32) cout << "tautology" << '\n';
        else cout << "not" << '\n';
        cin >> input;
    }

    return 0;
}