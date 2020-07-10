vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    if(B.size() == 0 || A.size() < B[0].size())
        return {};
    map<string,int> m;
    for(int i=0;i<B.size();i++)
        m[B[i]]++;
    vector<int> ans;
    for(int i=0;i<A.size();i++)
    {
        if(m.find(A.substr(i,B[0].size())) != m.end())
        {
            auto copy = m;
            int count = B.size();
            int j = i;
            while(count--)
            {
                string temp = A.substr(j,B[0].size());
                j += B[0].size();
                if(copy.find(temp) != copy.end())
                {
                    break;
                }
                else
                {
                    if(copy[temp] == 1)
                        copy.erase(temp);
                    else
                        copy[temp]--;
                }
            }
            if(copy.size() == 0)
            {
                ans.push_back(i);
            }
        }
    }
    return ans;
}
