class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return true;

        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& a, const std::vector<int>& b) {
                return a[0] < b[0];
            }
        );

        vector<int> tmp = intervals[0];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < tmp[1]) {
                return false;
            }
            tmp = intervals[i];  // Move to the next interval
        }

        return true;
    }
};
