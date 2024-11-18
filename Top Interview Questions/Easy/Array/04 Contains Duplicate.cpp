class Solution {
  public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> numbers = {};
    for (auto i = 0; i < nums.size(); i++) {
      if (numbers.contains(nums[i])) {
        return true;
      } else {
        numbers.insert(nums[i]);
      }
    }
    return false;
  }
};
