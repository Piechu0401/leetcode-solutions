class Solution {
public:
    inline const string sortVowels(
        string& __s
    ) const noexcept {
        unordered_map<char, pair<char, pair<int, int>>> __vs;

        for( int __idx{}; __idx < __s.length(); ++__idx )
            if(
                __s[__idx] == 'a' ||
                __s[__idx] == 'e' ||
                __s[__idx] == 'i' ||
                __s[__idx] == 'o' ||
                __s[__idx] == 'u'
            ) if( !__vs.count( __s[__idx] ) )
                __vs[__s[__idx]] = { __s[__idx], { __idx, 1 } };
            else ++__vs[__s[__idx]].second.second;

        vector<pair<char, pair<int, int>>> __vwls;

        for( auto& __p : __vs ) 
            __vwls.emplace_back( __p.second );

        sort(
            __vwls.begin(),
            __vwls.end(),
            [](
                const pair<char, pair<int, int>>& __a,
                const pair<char, pair<int, int>>& __b
            ) -> bool {
                if( __a.second.second == __b.second.second )
                    return __a.second.first < __b.second.first;

                return __a.second.second > __b.second.second;

            }
        );

        // for( auto& __v : __vwls )
        //     cout << __v.first << " ";

        int __i{};

        for( auto& __c : __s ) {
            if( __i == __vwls.size() ) break;

            if( 
                __c == 'a' ||
                __c == 'e' ||
                __c == 'i' ||
                __c == 'o' ||
                __c == 'u' 
            ) {
                __c = __vwls[__i].first;
                if( !--__vwls[__i].second.second ) ++__i;

            }

        }

        return __s;
        
    }
};