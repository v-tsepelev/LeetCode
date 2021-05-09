class Solution {
public:
  void sortColors(vector<int>& nums) {
    
    int zero = 0;
    int curr = 0;
    int two = nums.size() - 1;

    while (curr <= two) {
      if (nums[curr] == 0) {
	std::swap(nums[curr], nums[zero]);
	++zero;
	++curr;
      }
      else if (nums[curr] == 1)
	++curr;
      else {
	std::swap(nums[curr], nums[two]);
	--two;
      }
    }
  }
};
