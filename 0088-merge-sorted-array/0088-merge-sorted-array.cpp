class Solution {
public:
    // ------------Naive Approach Using extra vector Temp-------------
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int ptr1 = 0 , ptr2 = 0;
        for(int i=0; i<(m+n) ; i++){
            if(ptr2 < n && nums1[ptr1] <= nums2[ptr2] && ptr1<m){
                temp.push_back(nums1[ptr1]);
                ptr1++;
            }
            else if(ptr2 < n && nums1[ptr1]>nums2[ptr2]){
                temp.push_back(nums2[ptr2]);
                ptr2++;
            }
            else if(ptr1>=m && ptr2 < n){
                temp.push_back(nums2[ptr2]);
                ptr2++;
            }
            else{
                temp.push_back(nums1[ptr1]);
                ptr1++;
            }
        }
        nums1 = temp;
    }
};