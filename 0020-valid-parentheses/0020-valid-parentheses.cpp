class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch:s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else if((ch == ')' && st.top() != '(') ||
                        (ch == '}' && st.top() != '{') ||
                        (ch == ']' && st.top() != '[')){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;

        
    }
};