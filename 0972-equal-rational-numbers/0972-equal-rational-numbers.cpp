class Solution {
public:
    inline const bool isRationalEqual(
        string& __s, 
        string& __t
    ) const noexcept {
        // solved it listening to this mad shit
        // https://www.youtube.com/watch?v=y-Rf1qMbExg&list=LL&index=1
        
        if( __s == __t ) return 1;

        char __sdot{};

        for( auto& __c : __s ) __sdot = ( __sdot || __c == '.' );

        if(
            !__sdot &&
            __s.back() >= '0' &&
            __s.back() <= '9' 
        ) __s += ".0";

        char __tdot{};

        for( auto& __c : __t ) __tdot = ( __tdot || __c == '.' );

        if(
            !__tdot &&
            __t.back() >= '0' &&
            __t.back() <= '9' 
        ) __t += ".0";

        if( __s.back() == '.' ) __s += '0';
        if( __t.back() == '.' ) __t += '0';
        
        if( __s == __t ) return 1;

        // remove ) hoe from both

        string __srep{""};
        string __trep{""};

        if( __sdot && __s.back() == ')' ) {
            __s.pop_back();

            while( __s.back() != '(' ) {
                __srep = __s.back() + __srep;
                __s.pop_back();

            }

            __s.pop_back();

        }

        if( __tdot && __t.back() == ')' ) {
            __t.pop_back();

            while( __t.back() != '(' ) {
                __trep = __t.back() + __trep;
                __t.pop_back();

            }

            __t.pop_back();

        }

        for( int __i{}; __i < 9; ++__i ) {
            __t += __trep;
            __s += __srep;

        }

        long double __a = stold( __s );
        long double __b = stold( __t );

        return abs( __a - __b ) < 1e-8;

    }
};