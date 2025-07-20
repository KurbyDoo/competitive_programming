// Author: KurbyDoo
// Created: 2025-06-16 19:17:00
// Problem Name
// Problem Code
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll, ll> pll;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    // Hash for integers
    size_t operator()(int x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(static_cast<uint64_t>(x) + FIXED_RANDOM);
    }

    // Hash for long long
    size_t operator()(long long x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(static_cast<uint64_t>(x) + FIXED_RANDOM);
    }

    // Hash for pii
    // size_t operator()(pii p) const {
    //     static const uint64_t FIXED_RANDOM =
    //         chrono::steady_clock::now().time_since_epoch().count();
    //     uint64_t h1 = splitmix64(static_cast<uint64_t>(p.first) + FIXED_RANDOM);
    //     uint64_t h2 =
    //         splitmix64(static_cast<uint64_t>(p.second) + FIXED_RANDOM);
    //     return h1 ^ (h2 + 0x9e3779b97f4a7c15 + (h1 << 6) + (h1 >> 2));
    // }

    // Has for pll
    size_t operator()(pll p) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        uint64_t h1 = splitmix64(static_cast<uint64_t>(p.first) + FIXED_RANDOM);
        uint64_t h2 =
            splitmix64(static_cast<uint64_t>(p.second) + FIXED_RANDOM);
        return h1 ^ (h2 + 0x9e3779b97f4a7c15 + (h1 << 6) + (h1 >> 2));
    }
};

template <typename T, typename V>
using dict = gp_hash_table<T, V, custom_hash>;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    printf("Hello, World!");

    return 0;
}