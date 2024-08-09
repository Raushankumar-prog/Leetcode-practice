class Solution {
public:
  
    long long power(long long n, long long x, const int MOD) {
        long long result = 1;
        while (x > 0) {
            if (x % 2 == 1) {
                result = (result * n) % MOD;
            }
            n = (n * n) % MOD; 
            x /= 2; 
        }
        return result;
    }
    
    int countGoodNumbers(long long n) {
        const int MOD = 1e9 + 7;
        if (n == 0) return 1;
        
        long long powerOf5 = power(5, (n + 1) / 2, MOD);
        long long powerOf4 = power(4, n / 2, MOD);
        
        return (1LL * powerOf5 * powerOf4) % MOD;
    }
};
