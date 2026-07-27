class Solution {
public:
    // ------------Sliding Window Approach-------------

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        long long prod = 1;
        int left = 0;
        int cnt = 0;
        for(int right = 0; right < nums.size(); right++) {
            prod *= nums[right];

            while(prod >= k) { //Shrinking Step! (always place it first)
                prod /= nums[left];
                left++;
            }

            cnt += (right - left + 1); //Adding all the subarrays possible
        }

        return cnt;
    }
};