#include <bits/stdc++.h>
using namespace std;

struct cross {
    long long w;
    long long l;
    long long r;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    vector<cross> all_c(n);
    for (auto &[w, l , r] : all_c) {
        cin >> w >> l >> r;
    }

    ranges::sort(all_c, ranges::greater{}, &cross::w);

    auto sum_l = accumulate(begin(all_c), end(all_c), 0ll, [](long long s, cross &c) {
        return s + c.l;
    });

    auto sum_least = accumulate(begin(all_c), end(all_c), 0ll, [](long long s, cross &c) {
        return s + c.l * c.w;
    });

    long long max_result = 0;
    auto remain_time = m - sum_l;

    // 额外收获前缀和
    vector<long long> max_av(n);
    long long prev_ps = 0;
    for (int i=0; i<n; ++i) {
        max_av[i] = prev_ps + (all_c[i].r - all_c[i].l) * all_c[i].w;
        prev_ps = max_av[i];
    }
    // 额外收获的累计时间
    vector<long long> ps_time(n);
    prev_ps = 0;
    for (int i=0; i<n; ++i) {
        ps_time[i] = prev_ps + (all_c[i].r - all_c[i].l);
        prev_ps = ps_time[i];
    }

    
    for (int i=0; i<n; ++i) {
        auto current_reamin_time = remain_time + all_c[i].l;
        auto current_sum_least = sum_least - all_c[i].l * all_c[i].w;
        auto add_i = ranges::upper_bound(ps_time, current_reamin_time) - begin(ps_time);

        auto floor_i = min<int>(i, add_i);
        auto current_result = current_sum_least ;
        if (floor_i > 0) current_result += max_av[floor_i - 1];
        auto floor_time = current_reamin_time - (floor_i > 0 ? ps_time[floor_i - 1] : 0);
        current_result += floor_time * all_c[i].w;

        max_result = max(max_result, current_result);
    }
    cout << max_result << endl;
}