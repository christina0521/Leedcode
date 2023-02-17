//能够明显感觉到自己思路又在提升，知道要做二分查找了，但算法实现还是有待提高

#include<vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int size = nums.size();
        int left_index = 0;
        int right_index =  size -1;
        int mid_index;

        while(right_index - left_index >= 0){
            mid_index = (left_index + right_index)  >> 1;

            if(nums[mid_index] != mid_index){
                right_index = mid_index - 1;
            }else{
                left_index = mid_index + 1;
            }
        }
        return left_index ;

    }
};

int main(){
    Solution example ;
    std::vector<int> nums={1,2};
    int result = example.missingNumber(nums);
}