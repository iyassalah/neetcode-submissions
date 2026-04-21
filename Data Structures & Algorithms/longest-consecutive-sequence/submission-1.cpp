class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }    
        int longest = 0;
        for (int num : nums) {
            if (s.find(num - 1) == s.end()) {
                int currentLong = 1, temp = num;
                while (s.find(temp + 1) != s.end()) {
                    currentLong++, temp++;
                }
                longest = max(longest, currentLong);
            }
        }
        return longest;
    }
};
