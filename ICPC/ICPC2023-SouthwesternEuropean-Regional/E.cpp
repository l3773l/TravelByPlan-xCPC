//
// Created by LL06p on 2024/4/4.
//
#include <bits/stdc++.h>

using namespace std;

struct frac {
    long long F;
    long long D;
    frac(long long f = 0, long long d = 1): F(f), D(d) {}
    void toIr() {
        auto cd = gcd(F, D);
        F /= cd;
        D /= cd;
    }
    frac operator+ (const frac &rhs) const {
        auto LCM = lcm(rhs.D, D);
        return {F*(LCM/D) + rhs.F*(LCM/rhs.D) , LCM};
    }
    frac operator- (const frac &rhs) const {
        return *this + frac{-F, D};
    }
    frac operator* (const frac &rhs) const {
        frac rt = {F * rhs.F, D * rhs.D};
        rt.toIr();
        return rt;
    }
    frac operator/ (const frac &rhs) const {
        frac fact = {rhs.D, rhs.F};
        return *this * fact;
    }
};

struct point {
    frac pos;
    long long H;
};

struct line {
    point begPoint;
    point endPoint;
    long long lerp(frac pos) {
        auto distance = (endPoint.pos - begPoint.pos);

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


}