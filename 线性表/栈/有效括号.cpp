/*有效的括号

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/queue-stack/g9d0h/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/

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
