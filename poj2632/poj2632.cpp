#include <iostream>
#include <map>

using namespace std;

int * do_move_check(int *robo_x, int *robo_y, int *robo_dir, int robo_num, int repeat, char action, int length, int width, int robo_total_num){
    int *res = new int[3];
    switch(action){
                case 'L': robo_dir[robo_num] = ((robo_dir[robo_num]-repeat)%4+4)%4; break;
                case 'R': robo_dir[robo_num] = ((robo_dir[robo_num]+repeat)%4+4)%4; break;
                case 'F':{
                    switch(robo_dir[robo_num]){
                        case 0:{
                            int robo_y_prev = robo_y[robo_num];
                            robo_y[robo_num] = robo_y_prev + repeat;
                            int crash_distance = width+1;
                            for(int robo_num_tr =0; robo_num_tr<robo_total_num; robo_num_tr++){
                                if(robo_x[robo_num_tr]==robo_x[robo_num] && robo_num_tr!=robo_num){
                                    if(robo_y[robo_num_tr]<=robo_y[robo_num] && robo_y[robo_num_tr]>=robo_y_prev){
                                        if(robo_y[robo_num_tr]-robo_y_prev<crash_distance){
                                            crash_distance = robo_y[robo_num_tr]-robo_y_prev;
                                            res[2] = robo_num_tr;
                                        }
                                        // check_output << "Robot " << robo_num <<" crashes into robot " << robo_num_tr << endl;
                                        // std::string  str = check_output.str();
                                        // return str;
                                    }
                                }
                            }
                            if(crash_distance<width+1){
                                res[0] = 1;
                                res[1] = robo_num;
                                return res;
                            }
                            if(robo_y[robo_num] > width){
                                res[0] = 2;
                                res[1] = robo_num;
                                return res;
                                // check_output << "Robot " << robo_num << " crashes into the wall" << endl;
                                // std::string  str = check_output.str();
                                // return str;
                            }
                            break;
                        }
                        case 1:{
                            int robo_x_prev = robo_x[robo_num];
                            robo_x[robo_num] = robo_x_prev + repeat;
                            int crash_distance = length+1;
                            for(int robo_num_tr =0; robo_num_tr<robo_total_num; robo_num_tr++){
                                if(robo_y[robo_num_tr]==robo_y[robo_num] && robo_num_tr!=robo_num){
                                    if(robo_x[robo_num_tr]<=robo_x[robo_num] && robo_x[robo_num_tr]>=robo_x_prev){
                                        crash_distance = robo_x[robo_num_tr]-robo_x_prev;
                                        res[2] = robo_num_tr;
                                    }
                                }
                            }
                            if(crash_distance<length+1){
                                res[0] = 1;
                                res[1] = robo_num;
                                return res;
                            }
                            if(robo_x[robo_num] > length){
                                res[0] = 2;
                                res[1] = robo_num;
                                return res;
                            }
                            break;
                        }
                        case 2:{
                            int robo_y_prev = robo_y[robo_num];
                            robo_y[robo_num] = robo_y_prev - repeat;
                            int crash_distance = width+1;
                            for(int robo_num_tr =0; robo_num_tr<robo_total_num; robo_num_tr++){
                                if(robo_x[robo_num_tr]==robo_x[robo_num] && robo_num_tr!=robo_num){
                                    if(robo_y[robo_num_tr]>=robo_y[robo_num] && robo_y[robo_num_tr]<=robo_y_prev){
                                        crash_distance = robo_y_prev-robo_y[robo_num_tr];
                                        res[2] = robo_num_tr;
                                    }
                                }
                            }
                            if(crash_distance<width+1){
                                res[0] = 1;
                                res[1] = robo_num;
                                return res;
                            }
                            if(robo_y[robo_num] < 1){
                                res[0] = 2;
                                res[1] = robo_num;
                                return res;
                            }
                            break;
                        }
                        case 3:{
                            int robo_x_prev = robo_x[robo_num];
                            robo_x[robo_num] = robo_x_prev - repeat;
                            int crash_distance = length+1;
                            for(int robo_num_tr =0; robo_num_tr<robo_total_num; robo_num_tr++){
                                if(robo_y[robo_num_tr]==robo_y[robo_num] && robo_num_tr!=robo_num){
                                    if(robo_x[robo_num_tr]>=robo_x[robo_num] && robo_x[robo_num_tr]<=robo_x_prev){
                                        crash_distance = robo_x_prev-robo_x[robo_num_tr];
                                        res[2] = robo_num_tr;
                                    }
                                }
                            }
                            if(crash_distance<length+1){
                                res[0] = 1;
                                res[1] = robo_num;
                                return res;
                            }
                            if(robo_x[robo_num] < 1){
                                res[0] = 2;
                                res[1] = robo_num;
                                return res;
                            }
                            break;
                        }
                    }
                    break;
                }
            }
            return res;
}

map<char,int> create_map()
{
  map<char,int> m;
  m['N'] = 0;
  m['E'] = 1;
  m['S'] = 2;
  m['W'] = 3;
  return m;
}
// map<char,int> get_dir = {{'N',0},{'E',1},{'S',2},{'W',3}};
map<char,int> get_dir = create_map();

int main(void) {
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);  
    int lines;
    cin >> lines;
    for(int lines_tr=0; lines_tr<lines; lines_tr++) {
        int length, width;
        cin >> length >> width;
        int robo_num, instr_num;
        cin >> robo_num >> instr_num;
        int *robo_x = new int[robo_num];
        int *robo_y = new int[robo_num];
        int *robo_dir = new int[robo_num];
        for(int robo_num_tr =0; robo_num_tr<robo_num; robo_num_tr++){
            char robo_dir_t;
            cin >> robo_x[robo_num_tr] >> robo_y[robo_num_tr] >> robo_dir_t;
            robo_dir[robo_num_tr] = get_dir[robo_dir_t];
        }
        int flag = 0;
        for(int instr_num_tr =0; instr_num_tr<instr_num; instr_num_tr++){
            int robo_num_t, repeat_t;
            char action_t;
            cin >> robo_num_t >> action_t >> repeat_t;
            if(flag==0){
                robo_num_t--;
                int *result;
                result = do_move_check(robo_x, robo_y, robo_dir, robo_num_t, repeat_t, action_t, length, width, robo_num);
                int err1 = result[0];
                int err2 = result[1];
                if(result[0]==1){
                    cout << "Robot " << result[1]+1 <<" crashes into robot " << result[2]+1 << endl;
                    flag =1;
                }
                else if(result[0]==2){
                    cout << "Robot " << result[1]+1 << " crashes into the wall" << endl;
                    flag = 1;
                }
            }
        }
        if(flag==0) cout << "OK" << endl;
    }
    return 0;
}