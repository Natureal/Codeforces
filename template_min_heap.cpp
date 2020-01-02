struct cmp{
    bool operator ()(pll a, pll b){
        return a.FI > b.FI;
    }
};

priority_queue<pll, vector<pll >, cmp> PQ;
