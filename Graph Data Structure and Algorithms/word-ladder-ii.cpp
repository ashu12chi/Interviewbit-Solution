vector<vector<string> > Solution::findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> s;
        unordered_set<string> visited;
        for(auto word: wordList)
            s.insert(word);
        if(beginWord==endWord){
       ans.push_back({beginWord});
       return ans;
   }
        if(s.find(endWord) == s.end())
            return ans;
        s.insert(beginWord);
        queue<vector<string>> q;
        q.push({beginWord});
        s.erase(s.find(beginWord));
        int level = 1;
        int min_level = INT_MAX;
        while(!q.empty())
        {
            vector<string> v = q.front();
            q.pop();
            if(v.size() > level)
            {
                for(string w : visited)
                    s.erase(w);
                //visited.clear();
                if(v.size() > min_level)
                    break;
                level = v.size();
            }
            string temp = v.back();
            for(int i=0;i<temp.size();i++)
            {
                for(int j=0;j<26;j++)
                {
                    string temp2 = temp;
                    temp2[i] = (char)('a'+j);
                    if(s.find(temp2) != s.end())
                    {
                        visited.insert(temp2);
                        v.emplace_back(temp2);
                        if(temp2 == endWord)
                        {
                            ans.emplace_back(v);
                            min_level = level;
                        }
                        else
                            q.push(v);
                        v.pop_back();
                    }
                }
            }
        }
        return ans;
    }
