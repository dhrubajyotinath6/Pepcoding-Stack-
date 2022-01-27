//https://leetcode.com/problems/validate-stack-sequences/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        int j = 0;
        
        for(int i : pushed){
            
            st.push(i);
            while(st.size() > 0 && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }
      return j == popped.size();  
    }
};