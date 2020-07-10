#define ll long long
string Solution::minWindow(string str, string pat) {
    ll hash_pat[256]={0};
        ll hash_str[256]={0};
        for(int i=0;i<pat.size();i++)
            hash_pat[pat[i]]++;
        ll start = 0ll;
        ll start_index = -1;
        ll min_len = INT_MAX;
        ll count = 0ll;
        for(int j=0;j<str.size();j++)
        {
            hash_str[str[j]]++;
            if(hash_pat[str[j]] !=0 && hash_pat[str[j]] >= hash_str[str[j]])
                count++;
            if(count == pat.size())
            {
                while(hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0) 
                {
                    if(hash_str[str[start]] > hash_pat[str[start]]) 
                        hash_str[str[start]]--; 
                    start++; 
                }
                if(min_len > j - start + 1) 
                { 
                    min_len = j - start + 1; 
                    start_index = start; 
                } 
            }
        }
        if(start_index == -1)
            return "";
    return str.substr(start_index,min_len);
}
