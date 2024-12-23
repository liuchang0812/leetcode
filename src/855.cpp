class ExamRoom {
public:
    int cnt;
    int used;
    set<int> pp;

    ExamRoom(int n) {
        cnt = n;
        used = 0;    
    }
    
    int seat() {
        if (used == 0) {
            pp.insert(0);
            ++ used;
            return 0;
        }

        int res = 0;
        int diff = -1;
        if (pp.find(0) == pp.end()) {
            res = 0;
            diff =  *pp.begin() - 1;
        }

        auto p = pp.begin();
        auto pre = *p;
        ++p;
        for (; p!=pp.end(); ++p)
        {
            
            if (*p - pre > 1 && (*p - pre - 2) / 2 > diff) {
                //cout << "pre diff " << diff << ' ' << *p << ' ' << pre << ' ' << (*p-pre) / 2 << endl;
                diff = (*p - pre - 2) / 2;
                res = (*p - pre) / 2 + pre;
                //cout << *p << ' ' << res << endl;

            }
            pre = *p;
        }

        
        if (pp.find(cnt-1) == pp.end() && cnt-2- *pp.rbegin() > diff) {
            res = cnt-1;
            diff = cnt - 2 - *pp.rbegin() ;
        }


        pp.insert(res);
        used++;
        return res;
    }
    
    void leave(int p) {
        pp.erase(p);
        --used;
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */