/*有效的括号

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/queue-stack/g9d0h/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/


解法一：map匹配
class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2)      //如果个数是奇数
            return false;
        unordered_map<char, char> pairs = {
            {'}', '{'},
            {')', '('},
            {']', '['}
        };

        stack<char> stk;
        for(char ch:s){
            if(pairs.count(ch)){
                if(stk.empty() || stk.top()!=pairs[ch]){    //不能交换顺序，因为empty的时候top会报错，必须先判断empty
                    return false;
                }
                stk.pop();
            }
            else{
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};

解法二switch：
bool BracketsCheck(char * str){
    InitStack(S);
    int i=0;
    while(str[i]!='\0'){
        switch(str[i]){
            //左括号入栈
            case '(': Push(S,'(');  break;
            case '[': Push(S,'[');  break;
            case '{': Push(S,'{');  break;
            //遇到右括号，检测栈顶
            case ')': Pop(S,e);
                if(e!='(')  return false;
            break;
            case ']': Pop(S,e);
                if(e!='[')  return false;
            break;
            case '}': Pop(S,e);
                if(e!='{')  return false;
            break;
            default:
            break;
        }//switch
        i++;
    }//while
    if(!IsEmpty(S)){
        printf("括号不匹配\n");
        return false;
    }
    else{
        printf("括号匹配\n");
        return true;
    }
}
