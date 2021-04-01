int luckBalance(int k, vector<vector<int>> contests) 
{

    int sum = 0;
    std::vector<int> importants;
    for(int i = 0; i < contests.size(); ++i)
    {
        if(contests[i][1] > 0)
          importants.push_back((contests[i][0]));
        sum += contests[i][0];
    }
    if(k < importants.size())
    {
        int dif = importants.size() - k;
        std::sort(importants.begin(),importants.end());
        for(int i = 0; i < dif; ++i)
            sum -=  2 *importants[i];
    }    
    return sum;
}
