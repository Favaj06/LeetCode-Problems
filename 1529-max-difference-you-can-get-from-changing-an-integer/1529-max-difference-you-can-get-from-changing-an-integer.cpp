class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string a = s, b = s;

        // Maximize a: replace first non-9 digit with 9
        for (char c : s) {
            if (c != '9') {
                for (char& ch : a) {
                    if (ch == c) ch = '9';
                }
                break;
            }
        }

        // Minimize b: if first digit not 1, replace it with 1
        if (s[0] != '1') {
            char target = s[0];
            for (char& ch : b) {
                if (ch == target) ch = '1';
            }
        } else {
            // Replace first digit (not 0 or 1) with 0 (starting from second digit)
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    char target = s[i];
                    for (char& ch : b) {
                        if (ch == target) ch = '0';
                    }
                    break;
                }
            }
        }

        return stoi(a) - stoi(b);
    }
};