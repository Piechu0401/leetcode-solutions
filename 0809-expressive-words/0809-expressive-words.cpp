class Solution {
public:
    inline const int expressiveWords(
        const string __s, 
        const vector<string>& __ws
    ) const noexcept {
        vector<pair<char, int>> __freqs;
        int __res{};

        for( auto& __c : __s )
            if( 
                __freqs.size() &&
                __freqs.back().first == __c
            ) ++__freqs.back().second;
            else if(
                __freqs.size() &&
                __freqs.back().first != __c    
            ) __freqs.push_back( { __c, 1 } );
            else __freqs.push_back( { __c, 1 } );

        // for( auto& __p : __freqs )
        //     cout << __p.first << " " << __p.second << "\n";

        for( auto& __w : __ws ) {
            vector<pair<char, int>> __freqs2;

            for( auto& __c : __w )
                if( 
                    __freqs2.size() &&
                    __freqs2.back().first == __c
                ) ++__freqs2.back().second;
                else if(
                    __freqs2.size() &&
                    __freqs2.back().first != __c    
                ) __freqs2.push_back( { __c, 1 } );
                else __freqs2.push_back( { __c, 1 } );

            if( __freqs.size() != __freqs2.size() ) continue;

            bool __fuckNo{0};

            for( int __i{}; __i < __freqs.size(); ++__i )
                if( 
                    __freqs[__i].first != __freqs2[__i].first ||
                    (__freqs[__i].second < 3 &&
                    __freqs[__i].second != __freqs2[__i].second) ||
                    (__freqs[__i].second >= 3 &&
                    __freqs[__i].second < __freqs2[__i].second)
                ) {
                    __fuckNo = 1;
                    break;

                }

            if( !__fuckNo ) ++__res;

        }

        return __res;

    }
};