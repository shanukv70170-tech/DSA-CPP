
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
      
        Set<Integer> set1 = new HashSet<>();
        for (int num : nums1) {
            set1.add(num);
        }


        Set<Integer> result = new HashSet<>();
        for (int num : nums2) {
            if (set1.contains(num)) {
                result.add(num);
            }
        }

        int[] resArr = new int[result.size()];
        int i = 0;
        for (int num : result) {
            resArr[i++] = num;
        }
        return resArr;
    }
}