class Solution {
public:
    bool isPalindrome(string s) {
        erase_if(s, [](unsigned char c) {
            return !isalnum(c);
        });
        ranges::transform(s, s.begin(), [](unsigned char c) {
            return tolower(c);
        });
        int left{};
        int right = (s.size() - 1);
        while (left < right) {  
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
