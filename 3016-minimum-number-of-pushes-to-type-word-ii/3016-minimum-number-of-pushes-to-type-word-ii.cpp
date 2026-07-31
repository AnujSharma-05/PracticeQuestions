class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int temp = 1;
        int cnt = 0;

        vector<int> arr(27, 0);
        for(auto i: word) arr[i - 'a' +1]++;
        sort(arr.rbegin(), arr.rend());

        for(int i = 0; i < 26; i++) {
            while(arr[i] != 0) {
                cnt += temp;
                arr[i]--;
            }
            if((i +1)%8==0) temp++;
        }


        return cnt;
    }
};