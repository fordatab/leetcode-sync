class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            nums2 = nums[i+1:]
            for j in range(len(nums2)):
                if nums[i] + nums2[j] == target:
                    return([i,i+j+1])