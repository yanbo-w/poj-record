# include <iostream>
# include <cstdlib>
# include <time.h>
# include <string.h>

using namespace std;

void tst(char *str){
    cout << "...." << int(&str) << endl;
    cout << "...." << str[0] << endl;
}

int main(){
    char tmp1[5] = "abcd";
    char tmp2[] = "abcd";
    char *tmp3;
    tmp3 = tmp1;
    char *tmp4;
    strcpy(tmp1, tmp4);

    tst(tmp1);
    tst(tmp2);
    tst(tmp3);
    tst(tmp4);

    cout << cin.getline(tmp1, 5) << endl;
}