#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (auto& e : nums) {
        cin >> e;
    }

    sort(nums.begin(), nums.end());
    long long res = 0;
    for (int i = 0; i < (k - 1); i++) {
        res += nums[i];
    }

    long double sum = 0;
    for (int i = 0; i < (n - k + 1); i++) {
        sum += (long double)(nums[i + k - 1]);
    }
    sum /= (n - k + 1);
    sum += (long double)(res);

    printf("%.7llf", sum);
    return 0;
}