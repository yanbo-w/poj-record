# include <iostream>
# include <vector>
# include <queue>
# include <cmath>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) return res;   
        qsort(nums, 0, nums.size()-1);
        for(int i = 0; i < nums.size(); i++){
            if(i == 0 || nums[i] != nums[i-1]){
                int lo = i+1;
                int hi = nums.size()-1;
                while(lo < hi){
                    if(nums[lo] + nums[hi] < -nums[i]) lo++;
                    else if(nums[lo] + nums[hi] > -nums[i]) hi--;
                    else if(nums[lo] + nums[hi] == -nums[i]){
                        vector<int> now;
                        now.push_back(nums[i]);
                        now.push_back(nums[lo]);
                        now.push_back(nums[hi]);
                        res.push_back(now);
                        lo++;
                        hi--;
                        while(lo < hi && nums[lo] == nums[lo-1]) lo++;
                        while(lo < hi && nums[hi] == nums[hi+1]) hi--;
                    }
                }    
            }
        }
        return res;
    }
private:
    void qsort(vector<int> &nums, int lo, int hi){
        if(nums.size() > 0 && lo < hi){
            int lo_init = lo;
            int hi_init = hi;
            int partion = nums[lo];
            while(lo < hi){
                while(lo < hi && nums[hi] >= partion) hi--;
                nums[lo] = nums[hi];
                while(lo < hi && nums[lo] <= partion) lo++;
                nums[hi] = nums[lo];
            }
            nums[lo] = partion;
            qsort(nums, lo_init, lo-1);
            qsort(nums, lo+1, hi_init);
        }
    }
};

int main(){

    Solution t;

    vector<int> nums{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};

    vector<vector<int>> res =  t.threeSum(nums);

    // cout << "----" <<(getnum() < getnum() ? getnum() : getnum()) << "----" << endl;

    return 0;
}