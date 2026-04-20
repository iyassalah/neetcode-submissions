class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (string s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            anagrams[temp].push_back(s);
        }    
        vector<vector<string>> groupAnagrams;
        for (auto element : anagrams) {
            vector<string> temp;
            for (int i = 0; i < element.second.size(); ++i) {
                temp.push_back(element.second[i]);
            }
            groupAnagrams.push_back(temp);
        }
        return groupAnagrams;
    }
};
