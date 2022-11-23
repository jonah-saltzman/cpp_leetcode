#include <cstdio>
#include <cstdlib>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        std::vector<int> arr = std::vector<int>(n + 1, -1);
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        for (int i = 3; i <= n; ++i) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n];
    }
};

int main(int argc, char* argv[]) {
    if (argc <= 1)
        return 0;
    int n = strtol(argv[1], nullptr, 10);
    Solution sol;
    int r = sol.climbStairs(n);
    printf("%d combinations\n", r);
    return 0;
}