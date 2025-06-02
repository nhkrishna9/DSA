class Solution {
public:
    bool checkForAnagram(string s, string t){
        unordered_map<char, int> count;
        for(auto tmpChar:s){
            count[tmpChar]++;
        }

        for(auto tmpChar:t){
            count[tmpChar]--;
        }

        for(auto tmpCountOfChar:count){
            if(tmpCountOfChar.second != 0){
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> anagramGroups;

        for (const string& word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            anagramGroups[sortedWord].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& entry : anagramGroups) {
            result.push_back(entry.second);
        }

        return result;

    }
};