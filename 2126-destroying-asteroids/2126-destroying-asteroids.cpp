class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long sumMass = mass;
        for(auto ele:asteroids){
            if(ele > sumMass){
                return false;
            }

            sumMass = sumMass + ele;
        }
        return true;
        
    }
};