class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) {
            return s.size();
        }
        int left = 0, right = 1;
        unordered_map<char, bool> exist;
        exist[s[left]] = true;
        int answer = 1;

        while (right < s.size()) {
            while (exist[s[right]] and left < right) {
                exist[s[left]] = false;
                left++;
            }
            exist[s[right]] = true;
            answer = max(answer, right - left + 1);
            right++;
        }
        return answer;
    }
};
