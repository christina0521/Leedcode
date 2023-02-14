#include <stack>
#include <iostream>
class MinStack {
public:
    /** initialize your data structure here. */
    std::stack<int> data;
    std::stack<int> minStack;
    std::stack<int> tmp;
    int minData = 9999 ;
    MinStack() {

    }
    
    void push(int x) {
        data.push(x);
        if(data.size() == 1) minStack.push(x);
        else{
            int minStackSize = minStack.size();
            if(x > minStack.top()){
                for(int i = 0 ; i < minStackSize; ++i) {
                    if(minStack.top() < x){
                        tmp.push(minStack.top());
                        minStack.pop();
                    }   
                }
                int tmpSize = tmp.size();
                minStack.push(x);
                for(int i = 0 ; i < tmpSize; ++i) {
                    minStack.push(tmp.top());
                    tmp.pop();
                }
            }
            else minStack.push(x);
        }
        minData = minStack.top();
    }
    
    void pop() {
        int top = data.top();
        if(top == minData){
            minStack.pop();
        }
        data.pop();

    }
    
    int top() {
        int top = data.top();
        return top;
    }
    
    int min() {
        minData = minStack.top();
        return minData;
    }
};

int main(){
    MinStack* obj = new MinStack();
    obj->push(395);
    int param_1 = obj->min();
    int param_2 = obj->top();
    int param_3 = obj->min();
    obj->push(276);
    obj->push(29);
    int param_4 = obj->min();
    obj->push(-482);
    int param_5 = obj->min();
    obj->pop();
    obj->push(-108);
    obj->push(-251);
    int param_7 = obj->min();
    obj->push(-439);
    int param_8 = obj->top();
    obj->push(370);
    obj->pop();
    obj->pop();
    int param_11 = obj->min();
    obj->pop();
    int param_13= obj->min();
    int param_14= obj->min();
    obj->pop();
    int param_16 = obj->min();
    obj->push(-158);
    obj->push(82);
    obj->pop();
    obj->push(-176);
    int param_17= obj->min();
    int param_18= obj->min();
    obj->push(-90);
    int param_19= obj->min();
    int param_20= obj->min();
        obj->push(411);
    int param_21= obj->min();
    int param_22= obj->min();    
    int param_23= obj->min();
        obj->push(-494);


}
//"push","min","pop","top","push","top","push","min","min","push","pop","min","min","pop","pop","min","push","min","min","push","min","top","min","push","min","push","top","min","push","min","top","min","push","min","min","push","pop","push","push","min","push","push","push","top","min","push","min","push","push","push","min","push","push","push","pop","push","min","top","min","min","push","top","push","push","top","push","min","push","top","min","min","min","min","min","push","min","push","push","min","min","min","top","min","push","pop","min","min","push","min","min","min","min","push","top","top","push","push","push","top","top","push","min","push","push","push","min","min","push","push","push","push","min","min","min","push","top","pop","min","push","top","pop","push","min","pop","min","pop","min","push","top","push","min","min","top","pop","top","min","min","push","push","push","pop","push","min","min","push","push","push","top","min","top","min","min","top","top","pop","pop","min","min","push","min","push","min","push","push","push","min","pop","pop","push","pop","top","push","top","top","pop","top","push","push","top","top","min","min","min","push","min","min","push","min","pop","top","push","push","push","push","push","min","min","push","min","min","min","push","min","min","min","top","min","min","push","top","min","push","min","push","min","min","min","push","pop","push","pop","push","top","min","min","push","min","min","min","push","push","push","min","push","top","push","min","push","top","min","min","min","pop","min","top","min","push","min","min","min","min","min","pop","min","min","push","min","pop","push","top","push","push","min","pop","pop","push","pop","min","push","push","min","min","pop","pop","pop","push","pop","push","push","push","push","min","top","min","min","min","top","push","min","push","push","min","pop","min","push","pop","pop","push","push","push","pop","min","min","pop","push","push","min","top","min","pop","push","push","push","min","min","push","push","push","min","pop","min","push","push","min","min","min","push","min","min","min","min","min","min","push","min","pop","min","min","push","pop","pop","pop","push","top","push","push","min","min","min","min","min","push","push","top","push","top","push","top","pop","push","min","push","push","min","min","min","min","pop","min","push","top","pop","push","min","push","push","push","push","pop","min","push","push","top","min","min","top","min","min","push","min","push","min","top","min","min","push","push","min","push","push","push","push","min","min","pop","push","top","push","pop","min","push","push","min","min","push","min","push","push","min","min","min","top","min","min","push","top","push","top","pop","push","push","min","push","pop","pop","push","min","push","min","min","min","top","top","pop","pop","pop","min","push","top","push","min","min","min","push","min","top","min","push","push","min","pop","min"]

//,[-494],[],[],[],[155],[],[-370],[],[],[273],[],[],[],[],[],[],[173],[],[],[0],[],[],[],[-266],[],[-359],[],[],[189],[],[],[],[375],[],[],[-188],[],[-275],[-223],[],[294],[380],[-42],[],[],[33],[],[457],[422],[-352],[],[326],[-378],[231],[],[416],[],[],[],[],[277],[],[472],[205],[],[-443],[],[-5],[],[],[],[],[],[],[-312],[],[-249],[-209],[],[],[],[],[],[196],[],[],[],[-347],[],[],[],[],[400],[],[],[269],[434],[-213],[],[],[-58],[],[-353],[-426],[-335],[],[],[-188],[-388],[369],[319],[],[],[],[121],[],[],[],[155],[],[],[155],[],[],[],[],[],[495],[],[-53],[],[],[],[],[],[],[],[465],[162],[-334],[],[282],[],[],[432],[-418],[195],[],[],[],[],[],[],[],[],[],[],[],[374],[],[202],[],[181],[173],[-323],[],[],[],[-430],[],[],[346],[],[],[],[],[244],[-467],[],[],[],[],[],[279],[],[],[-30],[],[],[],[264],[-217],[-418],[12],[-439],[],[],[7],[],[],[],[-189],[],[],[],[],[],[],[303],[],[],[-297],[],[-21],[],[],[],[461],[],[-303],[],[-338],[],[],[],[-42],[],[],[],[85],[132],[57],[],[-17],[],[-10],[],[-500],[],[],[],[],[],[],[],[],[-7],[],[],[],[],[],[],[],[],[346],[],[],[16],[],[472],[-211],[],[],[],[-381],[],[],[214],[169],[],[],[],[],[],[33],[],[115],[-346],[-309],[130],[],[],[],[],[],[],[335],[],[-92],[-16],[],[],[],[-470],[],[],[250],[327],[144],[],[],[],[],[359],[138],[],[],[],[],[272],[-241],[-362],[],[],[-83],[195],[-208],[],[],[],[-500],[5],[],[],[],[284],[],[],[],[],[],[],[477],[],[],[],[],[30],[],[],[],[-269],[],[-413],[-323],[],[],[],[],[],[217],[-408],[],[-353],[],[-142],[],[],[-321],[],[-33],[382],[],[],[],[],[],[],[298],[],[],[495],[],[195],[-147],[-85],[195],[],[],[154],[-311],[],[],[],[],[],[],[-390],[],[323],[],[],[],[],[338],[263],[],[160],[148],[142],[427],[],[],[],[-153],[],[-384],[],[],[159],[419],[],[],[-385],[],[461],[-346],[],[],[],[],[],[],[343],[],[-269],[],[],[-401],[81],[],[130],[],[],[-428],[],[454],[],[],[],[],[],[],[],[],[],[59],[],[143],[],[],[],[-154],[],[],[],[114],[-346],[],[],[]]
