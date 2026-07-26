class Solution {
public:
    // --------------Most Intuitive Non Kadane Solution ------------

    // Two observations in multiplication flow:
        // 1) When there are odd number of -ves then we must ommit one;
        // 2) when there is a 0 then we need to start the substring calc again


    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pre=1, best=INT_MIN, suff=1;
        for(int i=0;i<n; i++){
            if(pre==0) pre=1; //Whenever the product is 0 we need to start again to calculate the subarray hence made the pre and suff to 1;

            if(suff==0) suff=1;
            pre *= nums[i];
            suff *= nums[n-i-1]; //We are iterating from both the ends and then we would encounter the best break point (in terms of number of negative signs are concerned) ie, even number of negatives = take all, odd number of negatives = omit one negative (for that we calc the pre and suff so that that ommition can be done)
            best = max(best, max(pre, suff));
        }
        return best;

    }
};