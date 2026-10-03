class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet{};
        for (auto num: nums) {
            numSet.insert(num);
        }
        int maxConsecutiveLength{};
        for (auto num: numSet) {
            if (numSet.contains(num - 1)) continue;
            int consecutiveLength{1};
            while(numSet.contains(num + 1)) {
                ++num;
                ++consecutiveLength;
            }
            if (consecutiveLength > maxConsecutiveLength) maxConsecutiveLength = consecutiveLength;
        }
        return maxConsecutiveLength;
    }
};
