int Solution::isValidSudoku(const vector<string> &ar) {
    for(int i=0;i<9;i++)
    {
        unordered_map<char,int> ump;
        unordered_map<char,int> ump2;
        for(int j=0;j<9;j++)
        {
            if(ump.find(ar[i][j])!=ump.end())
                    return 0;
            else if(ar[i][j] != '.')
            {
                ump[ar[i][j]] = 1;
            }
            if(ump2.find(ar[j][i])!=ump2.end())
                return 0;
            else if(ar[j][i]!='.')
                ump2[ar[j][i]] = 1;
        }
    }
   // cout << 11;
    int dx[] = {0,0,0,3,3,3,6,6,6};
    int dy[] = {0,3,6,0,3,6,0,3,6};
    for(int i=0;i<9;i++)
    {
        int x = dx[i];
        int y = dy[i];
        unordered_map<char,int> ump;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(ump.find(ar[i+x][j+y])!=ump.end())
                {
                    return 0;
                }
                else if(ar[i+x][j+y]!='.')
                {
                    ump[ar[i+x][j+y]] = 1;
                }
            }
        }
    }
    return 1;
}
