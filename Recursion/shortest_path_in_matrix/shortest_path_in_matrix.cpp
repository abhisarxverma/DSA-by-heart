#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
using namespace std;

// PROBLEM - Given a matrix, find the shortest path sum from the start to the end of the matrix i.e 0:0 to rows-1:cols-1 of the matrix.

// I solved this myself

// RECURSION IS THE WAY TO SOLVE THIS

// Helper function that will do recursion and return the answer
pair<int, vector<int>> recursion(vector<vector<int>> &matrix, pair<int, int> start, pair<int, int> end, int sum, vector<pair<int, int>> &path, vector<int> &path_values, int rows, int cols, int row, int col) {
    if (make_pair(row, col) == end) {
        return {sum, path_values};
    }

    vector<pair<int, int>> possible_moves;
    if (row+1 < rows && find(path.begin(), path.end(), make_pair(row+1, col)) == path.end()) possible_moves.push_back(make_pair(row+1, col));
    if (row-1 >= 0 && find(path.begin(), path.end(), make_pair(row-1, col)) == path.end()) possible_moves.push_back(make_pair(row-1, col));
    if (col+1 < cols && find(path.begin(), path.end(), make_pair(row, col+1)) == path.end()) possible_moves.push_back(make_pair(row, col+1));
    if (col-1 >= 0 && find(path.begin(), path.end(), make_pair(row, col-1)) == path.end()) possible_moves.push_back(make_pair(row, col-1));

    int shortest_sum = numeric_limits<int>::max();
    vector<int> shortest_path;

    for (auto move : possible_moves) {
        int i = move.first;
        int j = move.second;
        path.push_back(move);
        path_values.push_back(matrix[i][j]);
        pair<int, vector<int>> result = recursion(matrix, start, end, sum + matrix[i][j], path, path_values, rows, cols, i, j);
        path.pop_back();
        path_values.pop_back();

        if (result.first < shortest_sum) {
            shortest_sum = result.first;
            shortest_path = result.second;
        }
    }

    return {shortest_sum, shortest_path};
}

pair<int, vector<int>> find_shortest_route(vector<vector<int>> matrix, pair<int, int>start={-1, -1}, pair<int, int>end={-1, -1}) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    if (rows == 0 || cols == 0) return {0, {}};
    if (start.first == -1 || start.second == -1) start = {0, 0};
    if (end.first == -1 || end.second == -1) end = {rows - 1, cols - 1};

    vector<pair<int, int>> path = {start};
    vector<int> path_values = {matrix[0][0]};
    return recursion(matrix, start, end, matrix[0][0], path, path_values, rows, cols, 0, 0);
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 1},
        {1, 2, 3, 4, 5},
        {6, 9, 1, 0, 2},
        {7, 5, 6, 1, 8}
    };

    pair<int, vector<int>> ans = find_shortest_route(matrix);
    cout << "Shortest Path Sum: " << ans.first << "\nPath: ";
    for (int val : ans.second) cout << val << " ";
    cout << endl;
}
