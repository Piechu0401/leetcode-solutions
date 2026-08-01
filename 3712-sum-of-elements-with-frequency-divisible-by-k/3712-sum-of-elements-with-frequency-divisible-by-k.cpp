class Solution {
public:
    inline const int sumDivisibleByK(
        const vector<int>& __ns, 
        const int& __k
    ) const noexcept {
        char __fs[100]{};
        short __res{};

        for( auto& __n : __ns ) ++*( __fs + __n - 1 );
        
        for( char __i{}; __i < 100; ++__i )
            if( !( *( __fs + __i ) % __k ) ) __res += *( __fs + __i ) * (__i + 1);

        return __res;

    }
};