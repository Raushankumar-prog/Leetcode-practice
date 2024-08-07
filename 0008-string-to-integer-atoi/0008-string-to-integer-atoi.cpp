class Solution {
public:
    int myAtoi(string s) {
  
    queue<char> q;
    int i = 0;
    int n = s.length();

    
    while (i < n && s[i] == ' ') {
        i++;
    }


    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    
    while (i < n && isdigit(s[i])) {
        q.push(s[i]);
        i++;
    }

    
    long long num = 0;
    while (!q.empty()) {
        num = num * 10 + (q.front() - '0');
        q.pop();

        if (num * sign > INT_MAX) {
            return INT_MAX;
        }
        if (num * sign < INT_MIN) {
            return INT_MIN;
        }
    }

    return num * sign;




    }
};