class Solution {
public:
    inline const int minimumDeletions(
        vector<int>& __ns
    ) const noexcept {
        int __minI{};
        int __maxI{};
        int __max{__ns.front()};
        int __min{__ns.front()};

        for( int __i{}; __i < __ns.size(); ++__i ) {
            if( __ns[__i] > __max ) { __max = __ns[__i]; __maxI = __i; }
            if( __ns[__i] < __min ) { __min = __ns[__i]; __minI = __i; }

        }

        return
            __minI == __maxI ? __ns.size() :\
            __minI < __maxI ?\ 
            min( 
                {
                    (int)( ( __minI + 1 ) + ( __ns.size() - __maxI ) ), 
                    __maxI + 1,
                    (int)( __ns.size() - __minI )
                } 
            ) :\
            min( 
                {
                    (int)( ( __maxI + 1 ) + ( __ns.size() - __minI ) ), 
                    __minI + 1,
                    (int)( __ns.size() - __maxI )
                } 
            );
            // min(
            //     {
            //         (int)( ( __minI + 1 ) + ( __ns.size() - __maxI - 1 ) ),
            //         (int)( ( __maxI + 1 ) + ( __ns.size() - __minI - 1 ) ),
            //         (int)( __maxI + 1 ),
            //         (int)( __minI + 1 )
            //     }
            // );

    }

};