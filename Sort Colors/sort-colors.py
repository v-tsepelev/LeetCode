# This problem is also known as the Dutch national flag problem.

from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> List[int]:

        zero = 0 # all elements before nums[zero] are 0's
        curr = 0 # pointer to a current element of array
        two = len(nums) - 1 # all elements after nums[two] are 2's

        while curr <= two:
            if nums[curr] == 0:
                nums[curr], nums[zero] = nums[zero], nums[curr]
                zero += 1
                curr += 1
            elif nums[curr] == 1:
                curr += 1
            else:
                nums[curr], nums[two] = nums[two], nums[curr]
                two -= 1

        return nums
