class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        }

        int left = 0, right = 1;
        int answer = 0;
        while (right < prices.size()) {
            if (prices[right] > prices[left]) {
                answer = max(answer, prices[right] - prices[left]);
            } else {
                left = right;
            }
            right++;
        }
        return answer;
    }
};
