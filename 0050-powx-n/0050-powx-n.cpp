class Solution {
public:
    double myPow(double x, int n) {
          ios_base::sync_with_stdio(false);
            cin.tie(NULL);

         long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        double current_product = x;

        while (N > 0) {
            if (N % 2 == 1) {
                result *= current_product;
            }
            current_product *= current_product;
            N /= 2;
        }

        return result;
    }
};