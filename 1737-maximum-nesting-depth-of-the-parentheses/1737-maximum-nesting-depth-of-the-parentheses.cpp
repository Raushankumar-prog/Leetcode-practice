class Solution {
public:
    int maxDepth(string s) {
        int count=0,maxi=0;
        for(char c :s){
            if(c=='('){
                count++;
                maxi=max(count,maxi);
            }
            else if( c==')'){
                
                count--;
            }
        }
        return maxi;
    }
};