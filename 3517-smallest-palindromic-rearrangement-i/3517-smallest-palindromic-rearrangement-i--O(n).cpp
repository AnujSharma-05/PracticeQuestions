class Solution {
public:
    // -------------Classic Palindromic Section Division (but O(n) complexity)-----------------
    // Left + mid + right
    //Used hash array intead of map
    string smallestPalindrome(string s) {
        int n = s.size();
        string ans,left,right;
        // map<char, int> mp;
        // for(char c:s) mp[c]++;
        vector<int> arr(26,0);
        for(auto i: s) arr[i-'a']++;
        string mid = "";

        for(int i=0; i<26; i++){
            left.append(arr[i]/2, 'a'+i);
            if(arr[i] % 2) mid += ('a'+i);

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