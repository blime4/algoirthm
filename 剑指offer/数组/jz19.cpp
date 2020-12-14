class Solution {
public:
    void print(int lx, int ly, int rx, int ry, vector<vector<int>> &matrix, vector<int> &ret) {

        for (int j=ly; j<=ry; ++j) ret.push_back(matrix[lx][j]);
        for (int i=lx+1; i<=rx; ++i) ret.push_back(matrix[i][ry]);
        int h = rx - lx + 1;
        if (h > 1)
            for (int rj=ry-1; rj>=ly; --rj) ret.push_back(matrix[rx][rj]);
        int w = ry - ly + 1;
        if (w > 1)
            for (int ri = rx-1; ri>=lx+1; --ri) ret.push_back(matrix[ri][ly]);
    }
    vector<int> printMatrix(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (matrix.empty()) return ret;
        int lx = 0, ly = 0;
        int rx = matrix.size()-1, ry = matrix[0].size()-1;
        while (lx <= rx && ly <= ry) {
            print(lx++, ly++, rx--, ry--, matrix, ret);
        } 
        return ret;
    }

};