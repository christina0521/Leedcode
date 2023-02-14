// 2023/02/14 by christina
// 执行用时：536 ms, 在所有 C++ 提交中击败了5.36%的用户
// 内存消耗：209.3 MB, 在所有 C++ 提交中击败了5.15%的用户

// 我滴娘，我就是个智障，我怎么能想的这么复杂，笑死了

// 正确答案是 一个当输入栈，一个当输出栈，不就好了吗。看我的代码，来回倒腾，哈哈哈

// 我离正确答案也不远了，嘻嘻，就是多了一个倒腾的功能

#include <stack>
#include <iostream>
// myself 
// class CQueue {
// public:
//     std::stack<int> input;

//     CQueue() {
//         //创建队列
//     }
    
//     void appendTail(int value) {
//         input.push(value);
//     }
    
//     int deleteHead() {
//         std::stack<int> tmp;
//         int inputSize = input.size();
//         if(inputSize == 0) return -1;
//         if(inputSize == 1) {
//             int top = input.top();
//             input.pop();
//             return top;
//         }
        
//         for(int i = 0 ; i< inputSize; ++i){
//             int top = input.top();
//             tmp.push(top);
//             input.pop();
//         }

//         int result = tmp.top();
//         tmp.pop();
//         int tmpSize = tmp.size();    // 这里注意细节

//         for(int i = 0 ; i< tmpSize; ++i){   // 这里不能写成 tmp.size() 因为tmp的大小是变化的
//             int top = tmp.top();
//             input.push(top);
//             tmp.pop();   // 这里记得pop
//         }       
//         return result ;
//     }
// };


// 正确答案
// 执行用时：260 ms, 在所有 C++ 提交中击败了53.26%的用户
// 内存消耗：101.1 MB, 在所有 C++ 提交中击败了32.74%的用户
class CQueue {
public:
    std::stack<int> input;
    std::stack<int> output;

    int in2out(){
        int inputSize = input.size();
        for(int i = 0 ; i< inputSize; ++i){
            int top = input.top();
            output.push(top);
            input.pop();
        }
    }

    CQueue() {
        //创建队列
    }
    
    void appendTail(int value) {
        input.push(value);
    }
    
    int deleteHead() {
        if(output.empty()){
            if(input.empty()) return -1;
            in2out();
        }
        
        int result = output.top();
        output.pop();
              
        return result ;
    }
};


 //Your CQueue object will be instantiated and called as such:
int main(){
    CQueue* obj = new CQueue();
    int param_1 = obj->deleteHead();
    obj->appendTail(12);
    int param_2 = obj->deleteHead();
    obj->appendTail(10);
    obj->appendTail(9);
    int param_3 = obj->deleteHead();
    int param_4 = obj->deleteHead();
    int param_5 = obj->deleteHead();
    obj->appendTail(20);
    int param_6 = obj->deleteHead();
    obj->appendTail(1);
    obj->appendTail(8);    
    obj->appendTail(20);
    obj->appendTail(1);    
    obj->appendTail(11);
    obj->appendTail(2);
    int param_7 = obj->deleteHead();
    int param_8 = obj->deleteHead();
    int param_9 = obj->deleteHead();
    int param_10 = obj->deleteHead();
    std::cout<<"param "<<param_1<<" "<<param_2<<" "<<param_3<<" "<<param_4<<" "<<param_5<<" "<<
    param_6<<" "<<param_7<<" "<<param_8<<" "<<param_9<<" "<<param_10<<" "<<std::endl;
}
