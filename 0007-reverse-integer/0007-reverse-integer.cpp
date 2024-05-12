class Solution {
public:
    int reverse(int x) {
       
        long long  int reverse=0;
          if(x/10==0){
                 return x;
        }
          while(x){
   
    
         reverse=reverse*10+x%10;
                  x=x/10;
          }

         
    return (reverse<INT_MIN || reverse>INT_MAX)?0:reverse;
    }
};