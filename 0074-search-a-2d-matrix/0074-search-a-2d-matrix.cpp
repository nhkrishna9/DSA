class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();

        int top = 0, bottom = r-1;
        while(top <= bottom){
            int vMid = top+ ((bottom-top)/2);
            if(matrix[vMid][0] == target){
                return true;
            }
            else if(matrix[vMid][0] < target) {
                top = vMid+1;
            }
            else{
                bottom = vMid-1;
            }
        }
        if (bottom < 0) return false;
        int left = 0, right = c-1;
        while(left <= right) {
            int hMid = left+((right-left)/2);
            if(matrix[bottom][hMid] == target){
                return true;
            }
            else if(matrix[bottom][hMid] < target){
                left = hMid+1;
            }
            else{
                right = hMid-1;
            }
        }
        
        return false;
    }
};