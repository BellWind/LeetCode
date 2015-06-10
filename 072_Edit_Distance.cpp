class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() < word2.size())
            swap(word1, word2);
        word1 = word1.insert(0, "0");
        word2 = word2.insert(0, "0");
        int len = max(word1.size(), word2.size());
        p = new int[len];
        n = new int[len];
        for(int i = 0; i < word2.size(); i++)
            p[i] = i;
        for(int i = 1; i < word1.size(); i++) {
            for(int j = 0; j < word2.size(); j++) {
                if(j == 0)
                    n[j] = i;
                else {
                    if(word1[i] == word2[j])
                        n[j] = p[j - 1];
                    else
                        n[j] = min(min(p[j - 1], n[j - 1]), p[j]) + 1;
                }
            }
            for(int j = 0; j < word2.size(); j++)
                p[j] = n[j];
        }
        return n[word2.size() - 1];
    }
private:
    int *p, *n;
};
