class Solution {
public:
    void Helper(vector<string>& ans, int open, int close,int n, string tmp){
        if(open == close && tmp.size()==n*2){
            ans.push_back(tmp); 
        }
        if(open<n){
            Helper(ans, open+1, close, n, tmp+'(');
        }
        if(open>close){
            Helper(ans, open, close+1, n, tmp+')');
        }

    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        Helper(ans, 0, 0, n, "");

        return ans;

        
    }
};