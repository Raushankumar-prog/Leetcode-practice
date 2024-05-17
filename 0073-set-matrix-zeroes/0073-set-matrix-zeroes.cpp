class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<pair<int,int>> tempo;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0)
                {
                    tempo.push_back(make_pair(i,j));
                }
            }
        }
        for(int i=0; i<tempo.size();i++){
            int row=tempo[i].first;
            int col=tempo[i].second;
            for(int j=0;j<matrix.size();j++){
                for(int k=0;k<matrix[j].size();k++){
                    if(j==row)
                    matrix[j][k]=0;
                    if(k==col)
                    matrix[j][k]=0;
                }
            }
        }
    }
};