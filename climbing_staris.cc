#include <cstdio>
#include <cstdlib>
#include <vector>

int climbing_stairs(int n, std::vector<int>& arr) {
    int r;
    if (n > 2) {
        if (arr[n] != -1) {
            return arr[n];
        }
        r = climbing_stairs(n - 1, arr) + climbing_stairs(n - 2, arr);
        arr[n] = r;
        return r;
    }
    switch (n) {
        case 2:
           return 2;
        case 1:
            return 1;
        default:
            return 0;
    }
}

int main(int argc, char* argv[]) {
    if (argc <= 1)
        return 0;
    int n = strtol(argv[1], nullptr, 10);
    std::vector<int> arr = std::vector<int>(n + 1, -1);
    int r = climbing_stairs(n, arr);
    printf("%d combinations\n", r);
    return 0;
}