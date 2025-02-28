class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int t = 0;
        long ans = 0;
        bool key = true;
        int sign = 1;
        // Just to remove the leading white spaces:
        while (t < n && s[t] == ' ') {
            t++;
        }

        //Checking thr signs:
        if (s[t] == '-' || s[t]=='+') {
            sign = (s[t]=='-') ? -1 : 1;
            t++; 
        }

        // Skipping the leading zeroes:
        while (t < n and s[t] == '0') {
            t++;
        }

        // Checking whether the character is a non-integer or not?
        while (t < n and isdigit(s[t])) {
            ans = ans * 10 + (s[t] - '0');
            if (ans * sign >= INT_MAX)
                return INT_MAX;
            if (ans * sign <= INT_MIN)
                return INT_MIN;

            t++;
        }

        return ans * sign;
    }
};