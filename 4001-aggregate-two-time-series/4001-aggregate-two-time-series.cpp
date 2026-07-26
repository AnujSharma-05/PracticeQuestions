class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
        int ptr1=0, ptr2=0;
        vector<vector<int>> ans;
        int maxSize = s1.size() + s2.size();
        for(int i=0; i < maxSize; i++){
            if(ptr2 < s2.size() && ptr1<s1.size()
                && s1[ptr1][0] == s2[ptr2][0]){
                    ans.push_back({s1[ptr1][0], s1[ptr1][1] + s2[ptr2][1] });
                    ptr1++;
                    ptr2++;
                }
            else if( ptr2 < s2.size() && ptr1<s1.size()
                && s1[ptr1][0] < s2[ptr2][0] ){
                ans.push_back({s1[ptr1][0], s1[ptr1][1] + s2[ptr2][1] });
                ptr1++;
            }
            else if( ptr2 < s2.size() && ptr1<s1.size()
                && s1[ptr1][0] > s2[ptr2][0]){
                ans.push_back({s2[ptr2][0], s1[ptr1][1] + s2[ptr2][1] });
                ptr2++;
            }
            else if(ptr2 < s2.size() && ptr1>=s1.size()){
                ans.push_back({s2[ptr2][0], s2[ptr2][1] });
                ptr2++;
            }
            else if(ptr2 >= s2.size() && ptr1<s1.size()){
                ans.push_back({s1[ptr1][0], s1[ptr1][1] });
                ptr1++;
            }
        }
        return ans;
    }
};