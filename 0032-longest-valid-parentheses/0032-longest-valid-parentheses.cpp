class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0, ans = 0;

        // Left to right traversal
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') open++;
            else close++;

            if (open == close) {
                ans = max(ans, open + close);
            } else if (close > open) {
                open = 0;
                close = 0;
            }
        }

        open = close = 0;

        // Right to left traversal
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '('){
                 open++;
            }
            else{
                close++;
            }

            if (open == close) {
                ans = max(ans, open + close);
            } else if (open > close) {
                open = 0;
                close = 0;
            }
        }

        return ans;
    }
};
