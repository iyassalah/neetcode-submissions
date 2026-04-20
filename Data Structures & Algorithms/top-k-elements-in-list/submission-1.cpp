class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for (int i = 0; i < nums.size(); ++i) {
            ++freq[nums[i]];
        }
        priority_queue<pair<int, int>> pq;
        for (auto element : freq) {
            pq.push({element.second, element.first});
        } 
        vector<int> res(k, 0);
        while (k--) {
            int top = pq.top().second;
            pq.pop();
            res[k] = top;
        }
        return res;
    }
};
