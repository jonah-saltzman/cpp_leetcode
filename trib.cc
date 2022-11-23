#include <cstdio>
#include <cstdlib>
#include <vector>

class Solution {
public:
    int begin = 0;
    int end = 2;
    int arr[3] = {0, 1, 1};
    inline int arr_i(int i) {
        return (begin + i) % 3;
    }
    inline void push(int n) {
        arr[begin] = n;
        end += 1;
        end = end == 3 ? 0 : end;
        begin += 1;
        begin = begin == 3 ? 0 : begin;
    }
    int tribonacci(int n) {
        if (n < 3)
            return arr[n];
        for (int i = 3; i <= n; ++i) {
            push(arr[arr_i(0)] + arr[arr_i(1)] + arr[arr_i(2)]);
        }
        return arr[end];
    }
};

int main(int argc, char* argv[]) {
    if (argc <= 1)
        return 0;
    int n = strtol(argv[1], nullptr, 10);
    Solution sol;
    int r = sol.tribonacci(n);
    printf("F(%d) = %d\n", n, r);
    return 0;
}