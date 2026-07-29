class Solution {
    static constexpr long long LIM = 1000001LL; // > max k

    long long combCap(int n, int r) {
        r = min(r, n - r);
        __int128 ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans >= LIM) return LIM;
        }
        return (long long)ans;
    }

    long long countWays(const vector<int>& cnt) {
        long long res = 1;
        int used = 0;

        for (int c : cnt) {
            if (!c) continue;

            long long add = combCap(used + c, c);

            __int128 cur = (__int128)res * add;
            if (cur >= LIM) return LIM;

            res = (long long)cur;
            used += c;
        }
        return min(res, LIM);
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> half(26, 0);
        char mid = 0;

        for (char ch : s) half[ch - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (half[i] & 1) mid = char('a' + i);
            half[i] /= 2;
        }

        if (countWays(half) < k) return "";

        int m = 0;
        for (int x : half) m += x;

        string left;
        left.reserve(m);

        for (int pos = 0; pos < m; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= (int)ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid) return left + string(1, mid) + right;
        return left + right;
    }
};