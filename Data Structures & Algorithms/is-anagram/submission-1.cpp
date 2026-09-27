#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
    std::unordered_map<char, int> sMap{};
    std::unordered_map<char, int> tMap{};

        for (char c: s) {
            sMap[c] = sMap[c] + 1;
        }
        for (char c: t) {
            tMap[c] = tMap[c] + 1;
        }

        for (const auto& [key, value]: sMap) {
            if (sMap[key] != tMap[key]) return false;
        }

        for (const auto& [key, value]: tMap) {
            if (sMap[key] != tMap[key]) return false;
        }

        return true;
    }
};
