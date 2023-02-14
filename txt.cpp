#include <vector>
#include <string>
#include<algorithm> // 头文件 
using namespace std;
/*
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result ;
    for(int i = 0 ; i < nums.size(); ++i){
        int wantToFind = target - nums[i];
        vector<int>::iterator t;
        t = find(nums.begin(),nums.end(),wantToFind);
        int index = distance(nums.begin(),t);
        if(index == 0) continue;
        if(t != nums.end()){
            result.push_back(i);
            result.push_back(index);
            break;
        }
    }
    return result;
}
*/


int romanToInt(string s) {
    int result =0 ;
    for(int i = 0 ; i < s.length() ; ++i){
        if(s[i] == 'I'){
            if(i + 1 < s.length() && s[i+1] == 'V') {
                result += 4 ;
                i++;
            }
            else if(i + 1 < s.length() && s[i+1] == 'X') {
                result += 9;
                i++;
            }
            else result += 1;
        }
        else if(s[i] == 'X'){
            if(i + 1 < s.length() && s[i+1] == 'L') {
                result += 40 ;i++;
            }
            else if(i + 1 < s.length() && s[i+1] == 'C'){
                result += 90;i++;
            } 
            else result += 10;
        }
        else if(s[i] == 'C' ){
            if(i + 1 < s.length() && s[i+1] == 'D'){ result += 400 ; i++;}
            else if(i + 1 < s.length() && s[i+1] == 'M'){ result += 900;i++;}
            else result += 100;
        }
        else if(s[i]=='V') result += 5;
        else if(s[i]=='L') result += 50;
        else if(s[i]=='C') result += 100;
        else if(s[i]=='D') result += 500;
        else if(s[i]=='M') result += 1000;
        
    }
    return result ;
}


string publicPart(string s1, string s2){
    string publicResult="" ;
    int length1 = s1.length();
    int length2 = s2.length();
    if(length1 < length2){
        for(int i = 0 ; i < length1; ++i){
            if(s1[i] == s2[i]) publicResult += s1[i];
        }
    }else{
        for(int i = 0 ; i < length2; ++i){
            if(s1[i] == s2[i]) publicResult += s1[i];
        }
    }
    
    return publicResult;
}
string longestCommonPrefix(vector<string>& strs) {
//特殊情况处理
    //1、只有一个字符串，直接返回空
    if(strs.size() == 1) return "";
    //如果前两个首字母不一样直接返回空
    if(strs[0][0] != strs[1][0]) return "";

    string publicResult = publicPart(strs[0], strs[1]);
    if(publicResult == "") return "";
    else {
        for(int i = 1 ; i < strs.size() ; ++i){
            publicResult = publicPart(strs[i], publicResult);
        }
    }
    return publicResult;
}
// 26 删除有序数组中的重复项
// 方法一 用时12ms，内存消耗18M
/*int removeDuplicates(vector<int>& nums) {
    int result = 1 ;
    vector<int> numsNoRepeat;
    int index = 1 ;
    int lastNum = nums[0] ;
    numsNoRepeat.push_back(nums[0]);

    for( ; index < nums.size(); ++index){
        if(nums[index] != lastNum) {
            numsNoRepeat.push_back(nums[index]);
            lastNum = nums[index] ;
            result++;
        }
    }
    nums.clear();
    for(auto c : numsNoRepeat) nums.push_back(c);
    return result;
}
*/

int removeDuplicates(vector<int>& nums) {
    int result = 1 ;
    int index = 1 ;
    int lastNum = nums[0] ;

    vector<int>::iterator numsIterator = nums.begin()+1;
    while(numsIterator != nums.end()){
        if(*numsIterator != lastNum) {
            lastNum = *numsIterator ;
            result++;
            numsIterator++;
        }
        else{
            nums.erase(numsIterator);
        }
    }
}
// 66 加一
vector<int> plusOne(vector<int>& digits) {
    if(digits.size() == 1 && digits[0] == 9) return {1,0};
    vector<int>  result ;
    for(auto c : digits) result.push_back(c);
    
    int index = 0;
    int lastNumAddOne = digits[digits.size()-1]+1;
    index = lastNumAddOne / 10 ;
    int digitsIAddOne = lastNumAddOne % 10 ;
    result[digits.size()-1] = digitsIAddOne;
    if(index == 0) return result ;
    else{
    for(int i = digits.size()-2; i >=0 ; --i){
            int numAddOne = digits[i]+index;
            index = numAddOne / 10 ;
            int digitsIAddOne = numAddOne % 10 ;
            result[i] = digitsIAddOne;
            if(index == 0 ) return result ;
            if(i == 0 && index != 0){
                vector<int>  resultAfter ;
                resultAfter.push_back(index);
                for(auto c : result) resultAfter.push_back(c);
                return resultAfter;
            }
        }
    }
    return result ;
}

int main(){
    //vector<int> nums = {3,2,4};
    //twoSum(nums, 6);
    // ListNode head;
	// head=(ListNode)malloc(sizeof(ListNode));
	// //创建了一个单链表，设置头结点head 
	// head->next=NULL; 
    // ListNode L1 , q;
    // q= head ;
    // L1.val = 9 ;
    // L1->next.val = 9 ;
    vector<int> plusOneInput={9,9};
    vector<int> output = plusOne(plusOneInput);
    vector<int> removeDuplicatesinput={1,1,1,2,2,2,2,3,3,3,3,3} ;
    removeDuplicates(removeDuplicatesinput);

    romanToInt("MCMXCIV");
    vector<string>input ;
    input.push_back("flower");
    input.push_back("flow");
    input.push_back("flight");

    longestCommonPrefix(input);

}
