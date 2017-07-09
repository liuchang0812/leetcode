
class LogSystem {
public:
    typedef struct entry {
        int year, month, day, hour, min, sec, id;
	bool operator<(const entry& b)
	{
		return year < b.year ||
		       year == b.year && month < b.month ||
		       year == b.year && month == b.month && day < b.day ||
		       year == b.year && month == b.month && day == b.day && hour < b.hour ||
		       year == b.year && month == b.month && day == b.day && hour == b.hour && min < b.min ||
		       year == b.year && month == b.month && day == b.day && hour == b.hour && min == b.min && sec < b.sec ||
            year == b.year && month == b.month && day == b.day && hour == b.hour && min == b.min && sec == b.sec && id < b.id;
	}
    } entry_t;
    
    vector<entry_t> items;
    
    int str2int(const string& str)
    {
        int ret = 0;
        for (auto c:str)
        {
            ret = ret * 10 + (c -'0');
        }
        return ret;
    }
    
    bool dayu(const entry_t& a, const entry_t& b)
    {
        
        return a.year > b.year || (a.year == b.year && a.month > b.month) || (a.year == b.year && a.month == b.month && a.day > b.day) ||
               (a.year == b.year && a.month == b.month && a.day == b.day && a.hour > b.hour) ||
               (a.year == b.year && a.month == b.month && a.day == b.day && a.hour == b.hour && a.min > b.min) ||
               (a.year == b.year && a.month == b.month && a.day == b.day && a.hour == b.hour && a.min == b.min && a.sec >= b.sec);
    }
    
    bool dayu2(const entry_t& a, const entry_t& b)
    {
        return a.year > b.year || (a.year == b.year && a.month > b.month) || (a.year == b.year && a.month == b.month && a.day > b.day) ||
               (a.year == b.year && a.month == b.month && a.day == b.day && a.hour > b.hour) ||
               (a.year == b.year && a.month == b.month && a.day == b.day && a.hour == b.hour && a.min > b.min) ||
               (a.year == b.year && a.month == b.month && a.day == b.day && a.hour == b.hour && a.min == b.min && a.sec > b.sec);
    }
    entry_t str2ent(int id, const string& str)
    {
            return entry_t{str2int(str.substr(0, 4)), str2int(str.substr(5, 2)), str2int(str.substr(8, 2)), str2int(str.substr(11, 2)), str2int(str.substr(14, 2)), str2int(str.substr(17)), id};
    }
    
    LogSystem() {
        items.clear();    
    }
    
    void put(int id, string timestamp) {
        //cout << "put " << id << ' '  << timestamp << endl;
        items.push_back(str2ent(id, timestamp));
        
        sort(items.begin(), items.end());
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        entry_t se, ee;
        se = str2ent(-1, s);
        ee = str2ent(-1, e);
        
        if (gra == "Year") 
        {
            se = entry_t{se.year, 0, 0, 0, 0, 0, 0};
            ee = entry_t{ee.year+1, 0, 0, 0, 0, 0, 0};
        }
        else if (gra == "Month")
        {
            se = entry_t{se.year, se.month, 0, 0, 0, 0, 0};
            ee = entry_t{ee.year, ee.month+1, 0, 0, 0, 0, 0};
        }
        else if (gra == "Day")
        {
            se = entry_t{se.year, se.month, se.day, 0, 0, 0, 0};
            ee = entry_t{ee.year, ee.month, ee.day+1, 0, 0, 0, 0};
        }
        else if (gra == "Hour")
        {
            se = entry_t{se.year, se.month, se.day, se.hour, 0, 0, 0};
            ee = entry_t{ee.year, ee.month, ee.day, ee.hour+1, 0, 0, 0};
        }
        else if (gra == "Minute")
        {
            se = entry_t{se.year, se.month, se.day, se.hour, se.min, 0, 0};
            ee = entry_t{ee.year, ee.month, ee.day, ee.hour, ee.min+1, 0, 0};
        }
        else
        {
            ee.sec = ee.sec + 1;
        }
        
        //cout << " retrieve " << s << ' ' << e << ' ' << gra << endl; 
        vector<int> ans;
        for (const auto& i: items)
        {
            if (dayu(i, se) && dayu2(ee,i))
                ans.push_back(i.id);
        }
        
        return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
