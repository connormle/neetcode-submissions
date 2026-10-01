class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        vector<int> result(nums.size());
        prefix[0] = 1;
        suffix[nums.size() -1] = 1;
        for (int i{1}; i < nums.size(); ++i) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        for (int i{static_cast<int>(nums.size()) -2}; i >= 0; --i) {
            suffix[i] = suffix[i+1] * nums[i+1];
        }
        for (int i{}; i < nums.size(); ++i) {
            result[i] = (prefix[i] * suffix[i]);
        }
        return result;
    }
};
