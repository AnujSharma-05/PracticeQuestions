class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = 0, slargest = 0;
        int n = nums.size();
        for(int i=0; i < n ; i++){
            if(nums[i] > largest){
                slargest = largest;
                largest = nums[i];
            }
            else if( nums[i] > slargest && slargest != largest){
                slargest = nums[i];
            }
        }
        return ((largest-1)*(slargest-1));
    }
};