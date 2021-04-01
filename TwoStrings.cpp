#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;
class Hash
{
private:
    std::vector<std::vector<char>> hash;

public:
    Hash()
    {
        hash.resize(255);
    }
    void insert(const char c)
    {
        hash[c % 255].push_back(c);
    }
    bool find(const char c)
    {
        int ind = c % 255;
        if (hash[ind].empty())
            return false;  
        return true;
    }

};
// Complete the twoStrings function below.
string twoStrings(string s1, string s2)
{
    Hash hash;
    string& b = (s1.size() > s2.size()) ? s1 : s2;
    string& s = (s2.size() < s1.size()) ? s2 : s1;
    for (size_t i = 0; i < b.size(); ++i)
        hash.insert(b[i]);
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (hash.find(s[i]))
            return "YES";
    }
    return "NO";
}
int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s1, s2;
        std::cin >> s1 >> s2;
        std::cout << twoStrings(s1, s2);
    }
}