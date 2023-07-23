vector<int>lis;
for(int i = 0; i < n; ++i) {
    auto it = lower_bound(lis.begin(), lis.end(), v[i]);
    if(it == lis.end()) lis.push_back(v[i]); 
    else lis[it-lis.begin()] = v[i];
}