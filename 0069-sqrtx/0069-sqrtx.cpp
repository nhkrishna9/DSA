class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1){ // To avoid devide by zero issues
            return x;
        }
        int low = 0/*To avoid integer overflow issues*/, high=x, ans;
        while(low<=high){
            int mid = (low+high) / 2;
            if(mid <= x/mid){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
        
    }
};