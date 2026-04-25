class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> toWarmerDay(n);
        stack<pair<int, int>> needHigherTemp;

        for (int i = 0; i < n; ++i) {
            while (!needHigherTemp.empty() and temperatures[i] > needHigherTemp.top().first) {
                int index = needHigherTemp.top().second;
                needHigherTemp.pop();
                toWarmerDay[index] = i - index;
            }
            needHigherTemp.push({temperatures[i], i});
        }
        while (!needHigherTemp.empty()) {
            auto [temp, index] = needHigherTemp.top();
            needHigherTemp.pop();
            toWarmerDay[index] = 0;
        }

        return toWarmerDay;
    }
};
