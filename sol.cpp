class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int freq1[26], freq2[26];
        memset(freq1, 0, sizeof(freq1));
        for (char c : licensePlate) {
            if (!isalpha(c))
                continue;
            freq1[tolower(c)-'a']++;
        }
        string ans = "";
        int len = INT_MAX;
        for (string word : words) {
            memset(freq2, 0, sizeof(freq2));
            for (char c : word) {
                if (!isalpha(c))
                    continue;
                freq2[tolower(c)-'a']++;
            }
            bool ok = true;
            for (int i = 0; i < 26; i++)
                ok &= (freq2[i] >= freq1[i]);
            if (ok && (int) word.size() < len) {
                ans = word;
                len = (int) word.size();
            }
        }
        return ans;
    }
};
