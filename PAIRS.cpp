#include <iostream>
#include <vector>
#include <set>
#include<algorithm>


using namespace std;

vector<string> split_string(string);

// Complete the pairs function below.

int pairs(int k, vector<int> arr)
{
    int cnt = 0;
    std::sort(arr.begin(), arr.end());
    for (auto it = arr.begin(); it !=  arr.end(); ++it)
    {
        int cur = *it;
        bool b = std::binary_search(it, arr.end(), cur + k);
        if(b)
          ++cnt;
    }
    return cnt;

}


int main()
{



    int n, k;
    std::cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
    {
        std::cin >> arr[i];
    }

    int result = pairs(k, arr);

    cout << result << "\n";


    return 0;
}

