class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int temp = 1;
        int cnt = 0;
        for(int i=1; i<=n; i++){
            cnt = cnt + temp;
            if((i%8==0)) temp++;
        }
        return cnt;
    }
};