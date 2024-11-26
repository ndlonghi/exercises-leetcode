/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
 

Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

unordered_map<int, int> getOcurrancies(vector<int>& nums) {
  unordered_map<int, int> res {};
    
  for (auto x:nums) {
    res[x]++;
  }
  
  return res;
}

vector<int> intersectMaps(unordered_map<int, int>& shorter, unordered_map<int, int>& longer) {
  vector<int> res;

  for (auto el:shorter) {
    if (longer.count(el.first) > 0) {
      for (auto i = 0; i < min(el.second, longer[el.first]); i++) {
        res.push_back(el.first);
      }
    }
  }
  
  return res;
}

class Solution {
  public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    auto nums1Map = getOcurrancies(nums1);
    auto nums2Map = getOcurrancies(nums2);
    
    if (nums1Map.size() > nums2Map.size()) {
      return intersectMaps(nums2Map, nums1Map);
    } else {
      return intersectMaps(nums1Map, nums2Map);
    }
  }
};
