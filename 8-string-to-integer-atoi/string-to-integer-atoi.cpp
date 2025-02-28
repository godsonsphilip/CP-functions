 // 1.) Simple loop implementation:
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


 // 2.) Resursive Implementation:
class Solution {
public:
    int myAtoi(string s, int t = 0, long ans = 0, int sign = 1) {
        if (t == 0) { // Initial handling (leading spaces & sign detection)
            while (t < s.size() && s[t] == ' ') t++;
            if (s[t] == '-' || s[t] == '+') sign = (s[t++] == '-') ? -1 : 1;
            while (t < s.size() && s[t] == '0') t++; // Skip leading zeros
        }
        
        if (t >= s.size() || !isdigit(s[t])) return ans * sign; // Base case
        
        ans = ans * 10 + (s[t] - '0');
        
        if (ans * sign >= INT_MAX) return INT_MAX; // Overflow handling
        if (ans * sign <= INT_MIN) return INT_MIN;
        
        return myAtoi(s, t + 1, ans, sign); // Recursive call
    }
};
