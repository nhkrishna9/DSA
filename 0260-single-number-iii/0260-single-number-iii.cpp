class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xorOfAllNums = 0;
        for(const int& num:nums){
            xorOfAllNums = xorOfAllNums ^ num;
        }
        //Final output of xorOfAllNums contains xor of two distinct values.

        // Fact is that xor of two distinct values contains diffenrent bit at any place.
        // If we and, "xor of two distinct values" with "last bit set value of 'xor of two distinct values'"
        // we end up with either zero or 1. 
        // Do this for all the elements then we will have two buckets with "last bit set 1"  and "last bit set 0"
        // In each set, Do the XOR then we will get the unique element.
        //int lastBitSet = (xorOfAllNums) & (~(xorOfAllNums-1));
        //Line 15: Char 58: runtime error: signed integer overflow: -2147483648 - 1 cannot be represented in type 'int' //(solution.cpp)
        int lastBitSet = (xorOfAllNums) & (~(xorOfAllNums-1));
        int x=0, y=0;
        for(const int& num:nums){
            int tmp;
            tmp = lastBitSet & num;
            if(tmp == 0){
                x = x ^ num; 
            }
            else{
                y = y ^ num; 
            }
        }

        return {x,y};
    }

   
};