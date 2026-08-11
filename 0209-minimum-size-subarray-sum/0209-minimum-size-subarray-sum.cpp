class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long sum = 0;
        int len1=INT_MAX;
        int n = nums.size();

        // while(j<nums.size()){
            
        //     cout<<i<<" "<<j-i+1<<" "<<sum<<endl;
        //     if(sum>=target){
        //         cout<<"Hi "<<i<<" "<<j-i+1<<" "<<sum<<endl;
        //         len1 = min(len1,j-i+1);
        //         sum-=nums[i];
        //         if(i==j) i++,j++,sum+=nums[j];
        //         else i++;
        //     }
        //     else j++,sum+=nums[j]; 
            
        // }

        int ptr = 0;

        for(int i = 0 ; i < n ; i++){
            while(ptr<n&&sum<target){
                sum+=nums[ptr];
                ptr++;
            }
            if(sum>=target){
                len1 = min(len1,ptr-i);
                sum-=nums[i];
            }
            else break;
        }


        if(len1==INT_MAX) return 0;
        else return len1;
    }
};