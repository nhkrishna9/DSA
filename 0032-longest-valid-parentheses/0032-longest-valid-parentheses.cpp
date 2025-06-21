class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0, ans = 0;

        // Left to right
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') open++;
            else close++;

            if (open == close) {
                ans = max(ans, 2 * close);
            } else if (close > open) {
                open = close = 0;
            }
        }

        open = close = 0;

        // Right to left
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') open++;
            else close++;

            if (open == close) {
                ans = max(ans, 2 * open);
            } else if (open > close) {
                open = close = 0;
            }
        }

        return ans;
    }
};
