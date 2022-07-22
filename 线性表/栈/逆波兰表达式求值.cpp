/*根据 逆波兰表示法，求表达式的值。

有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

注意 两个整数之间的除法只保留整数部分。

可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。


逆波兰表达式：

逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。

    平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
    该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。

逆波兰表达式主要有以下两个优点：

    去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
    适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中

作者：力扣 (LeetCode)
链接：https://leetcode.cn/leetbook/read/queue-stack/gomvm/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/




class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            string& token = tokens[i];
            if (isNumber(token)) {
                stk.push(atoi(token.c_str()));      //atoi(n) 将 n 进制的字符串转化为十进制。C 库函数 int atoi(const char *str) 把参数 str 所指向的字符串转换为一个整数（类型为 int 型）。
                //标准库的string类提供了三个成员函数来从一个string得到c类型的字符数组，这里主要介绍c_str
                ////c_str()：生成一个const char*指针，指向以空字符终止的数组。
                //c_str()函数返回一个指向正规C字符串（字符数组）的指针, 内容与本string串相同.
                //这是为了与c语言兼容，在c语言中没有string类型，故必须通过string类对象的成员函数c_str()把string 对象转换成c中的字符串（即字符数组）样式。
                //注意：一定要使用strcpy()函数 等来操作方法c_str()返回的指针 
            } else {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                switch (token[0]) {//c++中switch是不支持string，float等的，只支持整形类（int，char等）
                    //在C++中，string有两种，一种是字符串char[]，另外一种是封装好的字符串类，要区别理解。例如'a'是char, "a"是char string，这两者都是普通的字符和字符串，和C语言中没什么不同值得注意的是后者包含两个字符，末尾有一个隐身的'\0'
                    //而 string str = "a" 是C++ 封装好的string。C++中的char string和string不是一回事。当用到了"string"这个关键词，就不是普通的字符串，而是用到了封装后的类。 
                    case '+':
                        stk.push(num1 + num2);
                        break;
                    case '-':
                        stk.push(num1 - num2);
                        break;
                    case '*':
                        stk.push(num1 * num2);
                        break;
                    case '/':
                        stk.push(num1 / num2);
                        break;
                }
            }
        }
        return stk.top();
    }

    bool isNumber(string& token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
};
