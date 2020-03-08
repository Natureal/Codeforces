mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand_int(int l, int r){
    // produces a random integer, uniformly distributed on [l, r]
    return uniform_int_distribution<int>(l, r)(rng);
}
