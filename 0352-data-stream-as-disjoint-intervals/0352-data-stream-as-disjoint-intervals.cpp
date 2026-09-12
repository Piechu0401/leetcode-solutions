class SummaryRanges {
public:
    explicit SummaryRanges() noexcept {}
    
    inline void addNum(
        const int& __v
    ) noexcept { 
        if( !__is.size() || __is.back() < __v ) { __is.emplace_back( __v ); return; }
        else if( __is.front() > __v ) { __is.insert( __is.begin(), __v ); return; }

        int __beg{};
        int __end{ (int)__is.size() - 1 };        
        int __idx{};

        while( __beg <= __end ) {
            int __mid{ __beg + ( ( __end - __beg ) >> 1 ) };

            if( __is[__mid] < __v ) { __idx = __mid; __beg = ++__mid; }
            else if( __is[__mid] > __v ) { __end = --__mid; }
            else return;

        }

        __is.insert( __is.begin() + ++__idx, __v );

        // for( auto& __i : __is ) cout << __i << " ";
        // cout << '\n';
        
    }
    
    inline const vector<vector<int>> getIntervals() {
        vector<vector<int>> __res;
        int __i{};

        while( __i < __is.size() ) {
            int __beg{ __i };
            int __end{ (int)__is.size() - 1 };
            int __idx{};

            while( __beg <= __end ) {
                int __mid{ __beg + ( ( __end - __beg ) >> 1 ) };

                if( __is[__i] - __i != __is[__mid] - __mid ) __end = --__mid;
                else { __idx = __mid; __beg = ++__mid; }

            }

            __res.push_back( { __is[__i], __is[__idx] } );

            __i = __idx + 1;

        }

        return __res;

    }

    vector<int> __is;

};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

 // 0 1 2 3 4  5  6  7
 // 1 2 3 8 9 10 11 12
 // 0 2   3 7
 // 1 3   8 12