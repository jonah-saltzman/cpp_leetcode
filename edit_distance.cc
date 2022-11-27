#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using std::vector;

void print_table(vector<vector<int>> table) {
    printf("rows: %zu\ncols: %zu\n", table[0].size(), table.size());
    for (int i = 0; i < table.size(); ++i) {
        printf("[");
        int j = 0;
        for (; j < table[0].size() - 1; ++j) {
            if (false) {
                printf(" X");
            } else {
                printf("%*d,", 2, table[i][j]);
            }
        }
        printf("%*d]\n", 2, table[i][j]);
    }
}

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        vector<vector<int>> dp;
        dp.resize(word1.size() + 1, vector<int>(word2.size() + 1, -1));

        for (size_t j = 0; j < dp[0].size(); ++j) {
            dp[dp.size() - 1][j] = dp[0].size() - 1 - j;
        }
        for (size_t i = 0; i < dp.size(); ++i) {
            dp[i][dp[0].size() - 1] = dp.size() - 1 - i;
        }
        for (int i = word1.size() - 1; i >= 0; --i) {
            for (int j = word2.size() - 1; j >= 0; --j) {
                if (word1[i] == word2[j])
                    dp[i][j] = dp[i + 1][j + 1];
                else
                    dp[i][j] = 1 + std::min({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
            }
        }
        return dp[0][0];
    }
};

int main(int argc, char* argv[]) {
    if (argc <= 2)
        return 0;
    char* str1 = argv[1];
    char* str2 = argv[2];
    Solution sol;
    int distance = sol.minDistance(std::string(str1), std::string(str2));
    printf("distance: %d\n", distance);
    return 0;
}