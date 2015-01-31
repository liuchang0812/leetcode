class Solution:
    # @param version1, a string
    # @param version2, a string
    # @return an integer

    def compareVersion(self, version1, version2):
        nums1 = version1.split(".")
        nums2 = version2.split(".")
        diff = abs(len(nums1) - len(nums2))
        if len(nums1) > len(nums2):
            for i in range(diff):
                nums2.append("0")
        elif len(nums1) < len(nums2):
            for i in range(diff):
                nums1.append("0")
                
        for i in range(min(len(nums1), len(nums2))):
            if int(nums1[i]) != int(nums2[i]):
                return 1 if int(nums1[i]) > int(nums2[i]) else -1
        
        if len(nums1) != len(nums2):
            return 1 if len(nums1) > len(nums2) else -1
        return 0
