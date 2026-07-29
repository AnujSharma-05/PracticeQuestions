class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> arr;
        int flag = 0, i = 0, j = 0, maxlen = 0;
        while (j < n) {
            if (arr[nums[j]] == 0) flag++;
            arr[nums[j]]++;
            while (flag > 2) {
                arr[nums[i]]--;
                if (arr[nums[i]] == 0) flag--;
                i++;
            }
            maxlen = max(maxlen, j - i + 1);
            j++;
        }
        return maxlen;
    }
};