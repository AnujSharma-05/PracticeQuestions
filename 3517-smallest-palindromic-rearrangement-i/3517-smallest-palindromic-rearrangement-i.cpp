class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string ans,left,right;
        map<char, int> mp;
        for(char c:s) mp[c]++;
        string mid = "";
        for(auto &i: mp){
            int freq = i.second;
            if(freq %2 !=0) mid+=i.first;
            left.append(freq / 2, i.first);

        }
        for(int i=left.size()-1 ; i>=0 ; i--){
            right += left[i];
        }
        ans+=left;
        ans+=mid;
        ans+=right;
        return ans;
    }
};