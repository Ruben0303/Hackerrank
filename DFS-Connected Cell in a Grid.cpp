#include<vector>
#include<iostream>
using namespace std;
void DFS(const vector<vector<int>>& grid, size_t i, size_t j, int& count, std::vector<std::vector<bool>>& is_visited)
{
    is_visited[i][j] = true;
    if (grid[i][j] == 1)
    {
        ++count;
        if (j + 1 < grid[i].size() && !is_visited[i][j + 1]) // aj
            DFS(grid, i, j + 1, count, is_visited);
        if (j >= 1 && !is_visited[i][j - 1]) // dzax
            DFS(grid, i, j - 1, count, is_visited);
        if (i >= 1)
        {
            if (!is_visited[i - 1][j]) // verev
                DFS(grid, i - 1, j, count, is_visited);
            if (j + 1 < grid[i - 1].size() && !is_visited[i - 1][j + 1]) // verev aj ugl
                DFS(grid, i - 1, j + 1, count, is_visited);
            if (j >= 1 && !is_visited[i - 1][j - 1]) // verev dzax ugl
                DFS(grid, i - 1, j - 1, count, is_visited);
        }
        if (i + 1 < grid.size())
        {
            if (!is_visited[i + 1][j])//nerqev
                DFS(grid, i + 1, j, count, is_visited);
            if (j + 1 < grid[i + 1].size() && !is_visited[i + 1][j + 1])//nerqev aj ugl
                DFS(grid, i + 1, j, count, is_visited);
            if (j >= 1 && !is_visited[i + 1][j - 1]) //nerqev dzax ugl
                DFS(grid, i + 1, j - 1, count, is_visited);
        }
    }
}
// Complete the maxRegion function below.
int maxRegion(const vector<vector<int>>& grid)
{
    int max = 0;

    int m = (grid.size() > 0) ? grid[0].size() : 0;

    std::vector<std::vector<bool>> is_visited(grid.size(), std::vector<bool>(m));
    for (size_t i = 0; i < grid.size(); ++i)
    {
        for (size_t j = 0; j < grid[i].size(); ++j)
        {
            int cur = 0;
            if (!is_visited[i][j])
                DFS(grid, i, j, cur, is_visited);
            if (cur > max)
                max = cur;
        }
    }
    return max;
}
int main()
{

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);

    cout << res << "\n";

    return 0;
}