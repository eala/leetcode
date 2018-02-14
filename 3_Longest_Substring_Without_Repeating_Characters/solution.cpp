class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        int temp = 0;
        const int ASCII_CODE_COUNT = 127;
        int codeMap[ASCII_CODE_COUNT] = {};
        int i = 0, j = s.length();
        
        while (j > 0){
            
            if (codeMap[s[i]]){
                memset(codeMap, 0, sizeof(int) * ASCII_CODE_COUNT);
                i = i - temp + 1;
                j = s.length() - i;
                temp = 0;
                continue;
            }
            temp++;
            codeMap[s[i]] = 1;
            i++;
            j--;
            if (temp > length)
                length = temp;
        }
        return length;
    }
};
