/*
https://leetcode.com/problems/remove-outermost-parentheses/
https://leetcode.com/problems/remove-outermost-parentheses/discuss/270022/JavaC%2B%2BPython-Count-Opened-Parenthesis
*/
/*
a) USING STACK 
TC -> O(N)
SC -> O(2N) -> O(N)approx [ 2N IF WE COMSIDER STACK + STRING STR, WHICH IS ANS]
*/
class Solution {
public:
    string removeOuterParentheses(string s) {
        
        stack<int> st;
        string str = "";
        for(int i = 0; i < s.size(); i++){
            
            char ch = s[i];
            
            if(ch == '('){
                
                if(st.size() > 0)   str+=ch;
                st.push(ch);
            }
            else{
                st.pop();
                if(st.size() > 0)   str+=ch;
            }
        }
        return str;
    }
};

/*
b) 2ND APPROACH
TC -> O(N)
SC -> O(N)
*/
class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string res;
        int open = 0;
        
        for(char c : s){
            if(c == '(' && open++ > 0) res += c;
            if(c == ')' && open-- > 1) res += c;
        }
        return res;
    }
};