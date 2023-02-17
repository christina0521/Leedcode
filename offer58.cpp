//字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

//输入: s = "abcdefg", k = 2
//输出: "cdefgab"
#include<string>
class Solution {
public:
    std::string reverseLeftWords(std::string s, int n) {
        if(s.empty()) return " ";
        std::string up = s.substr(0,n);
        std::string down = s.substr(n);
        return down+up;
    }
};

int main(){
    std::string input = "abcdefg" ;
    int n = 2 ;
    Solution s ;
    s.reverseLeftWords(input, n);


}