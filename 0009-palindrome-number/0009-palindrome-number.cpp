class Solution {
public:
    bool isPalindrome(int x) {
       long long int reverse=0;
       long long  int number=x;
        if(x<0){return false;}
       if(x/10==0){
        return true;
       }
       while(x>0){
        reverse=reverse*10+x%10;
        x=x/10;
       }
       
          if(number==reverse){return true;}
          else{
            return false;
          }
       

    }
};