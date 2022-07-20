/*问题描述：
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:

    MinStack() 初始化堆栈对象。
    void push(int val) 将元素val推入堆栈。
    void pop() 删除堆栈顶部的元素。
    int top() 获取堆栈顶部的元素。
    int getMin() 获取堆栈中的最小元素

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/queue-stack/g5l7d/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
//解法一：（手撕）栈同时存储（最小值+数据值）
#define MaxSize 20000
typedef struct{
    int data[MaxSize];      //存放栈中元素
    int top;                //栈顶指针
    int min[MaxSize];       //最小值
}MyMinStack;
MyMinStack minStack;          //全局变量

class MinStack {
public:
    MinStack() {
        minStack.top = -1;
    }
    
    void push(int val) {
        if(minStack.top > MaxSize-2)            //初始化为top = -1
            return;
        if(minStack.top == -1){
            minStack.data[++minStack.top] = val;
            minStack.min[minStack.top] = val;
        }else{
            minStack.data[++minStack.top] = val;
            minStack.min[minStack.top] = val < minStack.min[minStack.top-1] ? val : minStack.min[minStack.top-1];
        }
    }
    
    void pop() {
        if(minStack.top == -1)
            return;
        minStack.top--;
    }
    
    int top() {
        if(minStack.top == -1)
            return NULL;
        return minStack.data[minStack.top];
    }
    
    int getMin() {
        if(minStack.top == -1)
            return NULL;
        return minStack.min[minStack.top];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//解法二：双栈（数据栈 + 辅助栈）
class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int val) {
        x_stack.push(val);
        min_stack.push(min(min_stack.top(), val));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
