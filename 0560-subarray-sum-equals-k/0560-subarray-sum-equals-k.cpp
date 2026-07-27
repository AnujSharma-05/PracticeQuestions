class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0, cnt = 0, n = nums.size();
        int i = 0, j = 0;
        while(i<n){
            sum = 0;
            for(j=i; j<n; j++){
                sum+=nums[j];
                if(sum == k){
                    cnt++;
                }
            }
            i++;
        }
        return cnt;
    }
};