class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < nums.size(); i++) {
            if (positions.count(target - nums[i])) {
                return {positions[target - nums[i]][0], i};
            }
            positions[nums[i]].push_back(i);
        }    
        return {0, 0};
    }
};
