class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros = 0, product = 1;
        vector<int> res(nums.size(), 0); 
        for (auto ele : nums) {
            if (ele == 0) {
                if (zeros)
                    return res;
                zeros++;
            } else {
                product *= ele;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (zeros) {
                if (nums[i] == 0)
                    res[i] = product;
                else 
                    res[i] = 0;
            } else {
                res[i] = product / nums[i];
            }
        }
        return res;
    }
};
