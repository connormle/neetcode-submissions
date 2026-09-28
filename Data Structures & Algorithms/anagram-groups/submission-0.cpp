class Solution {
public:
    std::string getAnagramKey(const std::string& str) {
        array<int, 26> charCounts{};
        for (int i {}; i < str.size(); ++i) {
            charCounts[static_cast<int>(str[i] - 'a')] += 1;
        }
        std::string key{};
        for (int i{}; i < 26; ++i) {
            key += (to_string(charCounts[i]) + '|');
        }
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap{};
        for (const auto& str: strs) {
            std::string key {getAnagramKey(str)};
            anagramMap[key].push_back(str);
        }
        vector<vector<string>> result{};
        for (auto& [key, value]: anagramMap) {
            result.push_back(value);
        }
        return result;
    }
};
