class Solution {
public:
    inline const vector<int> vowelStrings(
        const vector<string>&           __ws, 
        const vector<vector<int>>&      __qs
    ) const noexcept {
        int __count{};
        vector<int> __ps;

        for( auto& __w : __ws ) {
            if(
                (__w.front() == 'a' ||
                __w.front() == 'e' ||
                __w.front() == 'i' ||
                __w.front() == 'o' ||
                __w.front() == 'u') &&
                (__w.back() == 'a' ||
                __w.back() == 'e' ||
                __w.back() == 'i' ||
                __w.back() == 'o' ||
                __w.back() == 'u')
            ) ++__count;

            __ps.emplace_back( __count );

        }

        vector<int> __res;

        for( auto& __q : __qs )
            if( !__q.front() ) __res.emplace_back( __ps[__q.back()] );
            else if( __q.front() == __q.back() ) 
                __res.emplace_back( 
                    (__ws[__q.back()].front() == 'a' ||
                    __ws[__q.back()].front() == 'e' ||
                    __ws[__q.back()].front() == 'i' ||
                    __ws[__q.back()].front() == 'o' ||
                    __ws[__q.back()].front() == 'u') &&
                    (__ws[__q.back()].back() == 'a' ||
                    __ws[__q.back()].back() == 'e' ||
                    __ws[__q.back()].back() == 'i' ||
                    __ws[__q.back()].back() == 'o' ||
                    __ws[__q.back()].back() == 'u') 
                );
            else  __res.emplace_back( __ps[__q.back()] - __ps[__q.front() - 1] );

        return __res;
        
    }
};