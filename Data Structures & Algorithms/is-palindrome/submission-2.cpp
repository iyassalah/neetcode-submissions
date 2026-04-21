class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            while (left < right && !(isdigit(s[left]) or isalpha(s[left]))) left++;
            while (right > left && !(isdigit(s[right]) or isalpha(s[right]))) right--;
            
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++, right--;
        }
        return true;
    }
};
