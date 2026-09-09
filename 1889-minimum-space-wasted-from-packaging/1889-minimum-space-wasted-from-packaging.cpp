class Solution {
public:
    inline const int minWastedSpace(
        vector<int>& __ps, 
        vector<vector<int>>& __bs
    ) const noexcept {
        long long __res{LLONG_MAX};

        sort( __ps.begin(), __ps.end() );
        vector<long long> __pref( 1, *__ps.begin() );

        for( int __i{1}; __i < __ps.size(); ++__i )
            __pref.emplace_back( __pref.back() + __ps[__i] );

        // for( auto& __p : __ps ) cout << __p << " ";
        // cout << "\n";

        for( auto& __b : __bs ) {
            sort( __b.begin(), __b.end() );

            if( __b.back() < __ps.back() ) { cout << "lol\n"; continue; }
            
            long long __total{};
            int __prev{-1};

            for( auto& __box : __b ) {
                int __beg{ ( __prev == -1 ? 0 : __prev ) };
                int __end{(int)__ps.size() - 1};
                int __idx{-1};

                // cout << __b.size() << " " << __beg << " " << __end << "\n";
                while( __beg <= __end ) {
                    int __mid{ __beg + ( ( __end - __beg ) >> 1 ) };

                    // cout << __mid << " ";

                    if( __ps[__mid] > __box ) __end = --__mid;
                    else { __idx = __mid; __beg = ++__mid; }

                }
                // cout << '\n';

                if( __idx == -1 ) continue;

                // cout << __prev << " " << __idx << " ";

                if( __prev != -1 ) __total += (long long)( __idx - __prev ) * (long long)__box - ( __pref[__idx] - __pref[__prev] );
                else __total += ( __idx + 1LL ) * __box - __pref[__idx];

                __prev = __idx;

                // cout << "\n";

            }

            __res = ( __total < __res ? __total : __res );

        }

        return __res == LLONG_MAX ? -1 : __res % 1000000007;
        
    }
};