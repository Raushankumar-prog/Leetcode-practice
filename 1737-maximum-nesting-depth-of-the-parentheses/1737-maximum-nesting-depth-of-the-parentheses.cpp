class Solution {
public:
    int maxDepth(string s) {
        int count=0,maxi=0;
        for(char c :s){
            if(c=='('){
                count++;
                
            }
            else if( c==')'){
                maxi=max(count,maxi);
                count--;
            }
        }
        return maxi;
    }
};