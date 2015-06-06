class Solution {
public:
    string convert(string s, int numRows){
        if(numRows == 1) return s;
        string mat[numRows];
        int i = 0, j, gap = numRows - 2;
        while(i < s.size()){
            for(j = 0; i < s.size() && j < numRows; ++j) 
                mat[j] += s[i++];
            for(j = gap; i < s.size() && j > 0; --j) 
                mat[j] += s[i++];
        }
        string ans = "";
        for(i = 0; i < numRows; ++i)
            ans += mat[i];
        return ans;
    }
};
