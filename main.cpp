#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

constexpr auto kMod = 1'000'000'009;

ll t, n;
vl dp1, dp2, dp3;

tuple<ll, ll, ll> solve(ll x) {
  if (dp1[x] < 0 || dp2[x] < 0 || dp3[x] < 0) {
    const auto &[a1, a2, a3] = solve(x - 1);
    const auto &[b1, b2, b3] = solve(x - 2);
    const auto &[c1, c2, c3] = solve(x - 3);

    dp1[x] = (a2 + a3) % kMod;
    dp2[x] = (b1 + b3) % kMod;
    dp3[x] = (c1 + c2) % kMod;
  }

  return {dp1[x], dp2[x], dp3[x]};
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  dp1 = vl(100'000 + 1, -1);
  dp1[1] = 1;  // 1 = 1
  dp1[2] = 0;  // 2 = 2
  dp1[3] = 1;  // 3 = 3 = 1 + 2 = 2 + 1
  dp1[4] = 2;  // 4 = 3 + 1 = 1 + 3 = 1 + 2 + 1
  dp2 = vl(100'000 + 1, -1);
  dp2[1] = 0;  // 1 = 1
  dp2[2] = 1;  // 2 = 2
  dp2[3] = 1;  // 3 = 3 = 1 + 2 = 2 + 1
  dp2[4] = 0;  // 4 = 3 + 1 = 1 + 3 = 1 + 2 + 1
  dp3 = vl(100'000 + 1, -1);
  dp3[1] = 0;  // 1 = 1
  dp3[2] = 0;  // 2 = 2
  dp3[3] = 1;  // 3 = 3 = 1 + 2 = 2 + 1
  dp3[4] = 1;  // 4 = 3 + 1 = 1 + 3 = 1 + 2 + 1

  cin >> t;
  while (0 < (t--)) {
    cin >> n;

    const auto &[a1, a2, a3] = solve(n);
    cout << (a1 + a2 + a3) % kMod << '\n';
  }

  return 0;
}