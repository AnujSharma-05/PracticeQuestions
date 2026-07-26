class Solution {
public:
    // ------------Dutch National Flag Algorithm------------
    // Intuition is simple: how can we swap 3 diff entities in order in place? idea is SWAP!

    //there are three regions
        // region 1: 0->p1-1 to be containing 0s (this is known region from p2 pov)
        // region 2: p1->p2-1 to be containing something (this is unknown region from p2 pov)
        // region 2: p2->p3-1 to be containing 2s fs! (this is known region from p2 pov)

        // hence whenever making changes from that unknown region, ie swapping with p3, we gotta check the incoming element as well. therefore we are not incrementing p2 in that case! (reason of while is that after p2 corss p3, everything is known region)

    void sortColors(vector<int>& nums) {
      int n = nums.size();  
      int p1=0, p2=0, p3=n-1;
      while(p2<=p3){
        if(nums[p2] == 0 ) {
            swap(nums[p1], nums[p2]);
            p1++;
            p2++;
        }
        else if(nums[p2] == 1) p2++;
        else if( nums[p2] == 2) {
            swap(nums[p2], nums[p3]);
            p3--;
        }
      }
    }
};