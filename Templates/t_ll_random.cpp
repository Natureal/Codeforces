mt19937_64 rng_ll(chrono::steady_clock::now().time_since_epoch().count());

ll rand_ll(ll l, ll r){
    return uniform_int_distribution<ll>(l, r)(rng_ll);
}
