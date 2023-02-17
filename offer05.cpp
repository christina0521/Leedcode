//替换空格： 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
#include <string>
class Solution {
public:
    std::string replaceSpace(std::string s) {
        std::string result ;
        for(auto c : s){

            if(c == ' '){
                result += "%20";
            }
            else result += c;
        }
        return result ;
    }
};

int main(){
    std::string  input = " we are family";
    Solution s;
    s.replaceSpace(input);
}