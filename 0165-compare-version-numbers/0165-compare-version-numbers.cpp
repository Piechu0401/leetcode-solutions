class Solution {
public:
    inline const int compareVersion(
        string& __v1, 
        string& __v2
    ) const noexcept {
        vector<int> __ns1;
        vector<int> __ns2;

        int __n{};

        for( auto& __c : __v1 )            
            if( 
                __c >= '0' &&
                __c <= '9'
            ) __n = __n * 10 + ( __c - 48 );
            else {
                __ns1.emplace_back( __n );
                __n = 0;

            }

        __ns1.emplace_back( __n );
        __n = 0;
        
        for( auto& __c : __v2 )            
            if( 
                __c >= '0' &&
                __c <= '9'
            ) __n = __n * 10 + ( __c - 48 );
            else {
                __ns2.emplace_back( __n );
                __n = 0;

            }

        __ns2.emplace_back( __n );

        for( int __i{}; __i < max( __ns1.size(), __ns2.size() ); ++__i ) {
            int __1{ ( __i < __ns1.size() ? __ns1[__i] : 0 ) };
            int __2{ ( __i < __ns2.size() ? __ns2[__i] : 0 ) };

            if( __1 < __2 ) return -1;
            else if( __1 > __2 ) return 1;

        }

        return 0;

    }
};