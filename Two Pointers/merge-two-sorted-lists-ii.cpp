void Solution::merge(vector<int> &ar1, vector<int> &ar2) {
    for(int i=0;i<ar2.size();i++)
        ar1.push_back(ar2[i]);
    sort(ar1.begin(),ar1.end());
}
