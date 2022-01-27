//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

There are two approaches for this problem :

(a)1st approach (Using stack)
    TC -> O(N)
    SC -> O(N)

class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            
            if(ch == '('){
                st.push(ch);
            }
            
            else{
                if(st.size() > 0 && st.top() == '('){
                    st.pop();
                }else{
                    st.push(ch);
                }
            }
        }
       return st.size(); 
    }
};

(b) 2nd approach using two variables
    TC -> O(N)
    SC -> O(1)

    We will declare two variables and initialise their values as 0;

    

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int bal = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            char ch = s[i];
            
            bal += ch == '(' ? 1 : -1;
            
            if(bal == -1){
                ans++;
                bal++;
            }
        }
        return ans + bal;   
            
    }
};

Lets dry run now
    TESTCASE 1:
        "())"

        for i = 0:
            ch = '(';
            bal = 1 [0 + 1 = 1];
            ans = 0;

        for i = 1:
            ch += ')';
            bal = 0  [1 - 1 = 0];
            ans = 0

        for i = 2:
            ch += ')';
            bal = -1; [0 - 1 = -1];
            ans = 0;

            since bal = -1;
            ans = 1 [ 0 + 1 = 1]
            bal = 0;

Ans: ans + bal = 1 + 0 = 0