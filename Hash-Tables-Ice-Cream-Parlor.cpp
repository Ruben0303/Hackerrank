#include <bits/stdc++.h>
#include <algorithm>
#include <utility>

class Hash{
    std::vector<std::vector<std::pair<int,int>>> hash;
    int n;
    
    public:
        Hash(int n) : n(n) {hash.resize(n);}
        void insert(int val, int ind)
        {
            int i = val %  n;
            hash[i].push_back(std::pair<int,int>(val,ind));
        }
        int find_ind(int val, int ind,int money)
        {
            int cur_val = money - val;
            int i = cur_val %  n;
            for(int j = 0; j < hash[i].size(); ++j)
            {
                if(hash[i][j].first == cur_val && hash[i][j].second != ind)
                    return hash[i][j].second;
            }
            return -1;
        }
        
};


using namespace std;

vector<string> split_string(string);

// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money)
{
    Hash hash(cost.size());
    for(int i = 0; i < cost.size(); ++i)
        hash.insert(cost[i],i);
    for(int i = 0; i < cost.size(); ++i)
    {
        int ind = hash.find_ind(cost[i],i,money);
        if(ind != -1)
        {
            std::cout << i + 1 <<" " << ind + 1 <<'\n';
            return;
        }     
    }

}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
