class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currnt_sum = nums[0];
        int max_sum = nums[0];

        for (int i = 1; i < nums.size(); ++i)
         {
            if (currnt_sum < 0)
                currnt_sum = 0;
            currnt_sum = currnt_sum + nums[i];
            max_sum = max(max_sum, currnt_sum);
        }
        return max_sum;
    }
};