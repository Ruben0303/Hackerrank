#include<iostream>
#include<string>
#include <algorithm>
#include<vector>
using namespace std;
class Hash
{
    
    std::vector<std::vector<string>> hash;
public:
    Hash(int size)
    {
        hash.resize(size + 1);
    }
    void insert(std::string & s)
    {
        int ind = s.size();
        std::sort(s.begin(), s.end());
        hash[ind].push_back(s);
    }
    int find_anagram(std::string & s) const
    {
        int cnt = 0;
        int ind = s.size();
        if((hash[ind].empty()))
            return cnt;
        std::sort(s.begin(), s.end());
        for(size_t i = 0; i < hash[ind].size(); ++i)
        {
            if(hash[ind][i] == s)
                ++cnt;
        }
        return cnt;
    }
};

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) 
{
    Hash hash(s.size());
    int cnt = 0;
    for(size_t i = 0; i < s.size(); ++i)
    {
        std::string suf;
        suf.push_back(s[i]);
        for(size_t j = i + 1; j < s.size(); ++j)
        {
            suf.push_back(s[j]);
            if(s[i] == s[j])
                ++cnt;
            cnt += hash.find_anagram(suf);
            hash.insert(suf);
        }
    }
    return cnt;
}

int main()
{

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        cout << result << "\n";
    }


    return 0;
}
