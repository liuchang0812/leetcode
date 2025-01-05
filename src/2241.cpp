class ATM {
public:
    using ll = long long;
    ll data[5];
    ATM() {
        memset(data, 0, sizeof data);
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i=0; i<banknotesCount.size(); ++i)
            data[i] += banknotesCount[i];
    }
    inline int getv(int i) {
        static int v[5] = {20, 50, 100, 200, 500};
        return v[i];
    }
    vector<int> withdraw(int amount) {
        int get = 0;
        vector<int> res;
        res.resize(5);
        for (int i=4;i>=0; --i) {
            int v = getv(i);
            int want = amount - get;
            if (want >= v && data[i] > 0) {
                int cnt = min(1ll*want/v, data[i]);
                res[i] = cnt;
                get += cnt * v; 
            }
        }
        if (get == amount) {
            for (int i=0; i<5; ++i) {
                data[i] -= res[i];
            }
            return res;
        } else {
            return {-1};
        }
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */