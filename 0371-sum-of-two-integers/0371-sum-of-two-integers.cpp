class Solution {
public:
    int getSum(int a, int b) {

        while(b!=0){
            int partialSum = a^b; //This will the solution if there is no carry.
            int carrayBits = a&b;

        // Now, Start adding carry to the initial sum 2nd bit and update the carry and use the third bit carry and add it to third bit sum and so on.
            int shiftedCarry = carrayBits<<1;


            a = partialSum;
            b = shiftedCarry;
        }
        return a;
        
    }
};