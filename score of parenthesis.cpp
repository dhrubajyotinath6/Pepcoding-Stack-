/*
https://leetcode.com/problems/score-of-parentheses/solution/
*/
class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int> st;
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '(') st.push(-1);
            
            else{
                if(st.top() == -1){
                    st.pop();
                    st.push(1);
                }else{
                    int val = 0;
                    while(st.top() != - 1){                       
                        val += st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2*val);
                }
                
            }                
        }
        int val = 0;
        while(st.size() > 0){
            val += st.top();
            st.pop();
        }
        return val;
    }
};


   ///////////////////////////////////////////////////////////////////////

class Solution {
public:
    int scoreOfParentheses(string s) {
        
         int ans = 0, bal = 0;
        
        for (int i = 0; i < s.size(); i++) {
            
            if (s[i] == '(') {
                bal++;
            } else {
                bal--;
                if (s[i-1] == '(')
                    ans += 1 << bal;
            }
        }

        return ans;
    }
};