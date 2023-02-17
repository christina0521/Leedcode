//剑指 Offer 53 - I. 在排序数组中查找数字 I
// 统计一个数字在排序数组中出现的次数。

// 示例 1:

// 输入: nums = [5,7,7,8,8,10], target = 8
// 输出: 2
// 示例 2:

// 输入: nums = [5,7,7,8,8,10], target = 6
// 输出: 0
#include<vector>

// 二分查找的主要方法：1、找最左边相同的数  2、找最右边相同的数 3、二者相减即可
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int numsSize = nums.size();
        if(numsSize == 0 ) return 0;
        if(numsSize == 1 && nums[0] == target) return 1;
        if(numsSize == 1 && target < nums[0]) return 0 ;
        if(numsSize > 1  && target > nums[numsSize-1]) return 0 ;

        int frist = 0;
        int end = numsSize-1;
        int repeatNums = 0 ;
        while(frist < end){
            int centerIndex = (frist + end ) / 2 ;
            int center = nums[centerIndex];
            if(target < center)  frist = centerIndex + 1;
            else if(target > center)  end = center -1;
            else if(target == center) {
                repeatNums++;
                frist++;
            }
        }
        return repeatNums;
    }
};

int main(){
    Solution example ;
    std::vector<int> nums={5,6,7,8,8,9,10};
    example.search(nums, 8);
}