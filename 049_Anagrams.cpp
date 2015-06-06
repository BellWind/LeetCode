class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        string tmp;
        vector<string> ans;
        map<string, vector<string>> mp;
        for(int i = 0; i < strs.size(); i++) {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(strs[i]);
        }
        for(map<string, vector<string>>::iterator it = mp.begin(); it != mp.end(); it++) {
            if(it->second.size() > 1) {
                ans.insert(ans.end(), it->second.begin(), it->second.end());
            }
        }
        return ans;
    }
};
