class Solution {
public:
    // ------------Approach without Using extra vector Temp-------------
    //We are using 3 pointers and comparisng the 2 vectors backwards hence storing the extra pieces in the unused space of the nums1 taking the advantage of the sorted property
    // time complexity is O(n+m) and space complexity is 0;

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = m-1 , ptr2 = n-1;
        for(int p = m+n-1; p>=0 ; p--){
            if(ptr2<0) break; //cause then the nums1 is already in order
            if(ptr1>=0 && nums1[ptr1]>nums2[ptr2]){
                nums1[p] = nums1[ptr1];
                ptr1--;
            }
            else{
                nums1[p] = nums2[ptr2];
                ptr2--;
            }
        }
        
    }
};