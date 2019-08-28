#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    int lines;
    cin >> lines;
    for(int l=0; l<lines; l++){
        int parentheses;
        cin >> parentheses;
        int s[2*parentheses];
        int s_len = 0;
        int s_left_par = 0;
        for(int i=0; i<parentheses; i++){
            int pi;
            cin >> pi;
            for(int s_tr=s_len; s_tr<s_len+pi-s_left_par; s_tr++) s[s_tr] = 0;
            s_len += pi-s_left_par+1;
            s_left_par = pi;
            s[s_len-1] = 1;
        }
        //for(int i=0;i<s_len;i++) cout << s[i];
        stack<int> stk;
        for(int i=0; i<2*parentheses; i++){
            switch(s[i]){
                case 0:{
                    stk.push(0);
                    break;
                }
                case 1:{
                    int count = 0;
                    while(stk.top()!=0){
                        count += stk.top();
                        stk.pop();
                    }
                    stk.pop();
                    count +=1;
                    stk.push(count);
                    cout << count << ' ';
                    break;
                }
            }
        }
        cout << '\n';
    }

    return 0;
}