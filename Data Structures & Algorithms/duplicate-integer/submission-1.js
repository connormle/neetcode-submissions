class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums) {
        const hashMap = new Map();
        for (const num of nums) {
            if (hashMap.has(num)) return true;
            hashMap.set(num)
        }
        return false;
    }
}
