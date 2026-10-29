class Solution {
public:
    inline const string reformatNumber(
        string& __n
    ) const noexcept {
        string __res{};
        char __ds{};

        for( auto& __c : __n )
            if( 
                __c != ' ' &&
                __c != '-'
            ) {
                __res += __c;

                if( !( ++__ds % 3 ) ) __res += '-';

            }

        if( !( __ds % 3 ) ) __res.pop_back();
        else if( ( __ds % 3 ) == 1 ) {
            __res[__res.length() - 2] = __res[__res.length() - 3];
            __res[__res.length() - 3] = '-';

        }

        return __res;
        
    }
};