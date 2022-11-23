#include <cstdio>
#include <cstdlib>
#include <vector>

class Solution {
public:
    int fib(int n) {
        if (n < 2)
            return n;
        int arr[2] = {0, 1};
        int t;
        for (int i = 2; i <= n; ++i) {
            t = arr[1];
            arr[1] = arr[0] + arr[1];
            arr[0] = t;
        }
        return arr[1];
    }
};

int main(int argc, char* argv[]) {
    if (argc <= 1)
        return 0;
    int n = strtol(argv[1], nullptr, 10);
    std::vector<int> arr = std::vector<int>(n + 1, -1);
    Solution sol;
    int r = sol.fib(n);
    printf("F(%d) = %d\n", n, r);
    return 0;
}