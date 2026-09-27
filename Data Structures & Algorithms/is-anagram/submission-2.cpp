#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
    std::unordered_map<char, int> sMap{};
    std::unordered_map<char, int> tMap{};

        for (char c: s) {
            sMap[c] = sMap[c] + 1;
        }
        for (char c: t) {
            tMap[c] = tMap[c] + 1;
        }

        return sMap == tMap;
    }
};
