# include <iostream>

using namespace std;

int N;
void print(){
    cout << "-------------" << endl;
    cout << N << endl;
}
int main(){
    int N, m;
    while(cin >> N){
        print();
        cout << N << endl;
    }
}