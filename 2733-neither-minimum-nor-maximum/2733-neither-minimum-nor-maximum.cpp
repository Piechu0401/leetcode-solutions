class Solution {
public:
    inline const int findNonMinOrMax(
        const vector<int>& __ns
    ) const noexcept {
        char __res[100]{};
        char __count{};
        char __ret{};

        for( auto& __n : __ns ) {
            if( !*( __res + (char)__n - 1 ) ) ++__count;
            
            ++*( __res + (char)__n - 1 );

        }

        if( __count < 3 ) return -1;

        for( char __i{}; __i < 100; ++__i ) {
            if(
                !__ret &&
                *( __res + __i )
            ) __ret = 1;
            else if(
                __ret &&
                *( __res + __i )
            ) return __i + 1;

            // cout << __i + 1 << " " << (int)*( __res + __i ) << "\n";

        }


        return -1;

    }
};