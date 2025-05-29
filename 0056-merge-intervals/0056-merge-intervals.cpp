class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        vector<vector<int>> intervals_sorted;
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& a, const std::vector<int>& b) {
                return a[0] < b[0];
            }
        );

        vector<int> tmp = intervals[0];
        for(int i=1;i<n;i++){
            if(intervals[i][0] <= tmp[1]){
                tmp[1] = max(intervals[i][1] , tmp[1]);
            }
            else{
                ans.push_back(tmp);
                tmp = intervals[i];
            }
            


        }
        ans.push_back(tmp);

        return ans;
        
    }
};