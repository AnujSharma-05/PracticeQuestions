class Solution {
public:
    // Input Checking Was The Game! 

    bool check(string &s, int i, int j) {
        if (i >= j) return true;
        if (s[i] != s[j]) return false;
        return check(s, i+1,j-1);
    }
    bool isPalindrome(string s) {
        string s1;
        for(char i:s){
            if (!isalnum(i)) continue;
            s1.push_back(tolower(i));
        }
        return check(s1,0, s1.size()-1);
    }
};