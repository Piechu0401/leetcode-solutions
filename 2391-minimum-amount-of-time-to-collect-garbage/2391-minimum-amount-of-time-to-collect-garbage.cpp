class Solution {
public:
    inline const int garbageCollection(
        const vector<string>& __g, 
        vector<int>& __t
    ) const noexcept {
        // trust me.
        // https://www.youtube.com/watch?v=ZEvi_wY53Zo

        int __res{};
        char __G{};
        char __P{};
        char __M{};
        int __i{};

        for( auto& __s : __g )
            __res += __s.length();

        for( __i = 1; __i < __t.size(); ++__i )
            __t[__i] += __t[__i - 1];

        __i = __g.size() - 1; 

        while( __i ) {
            if(
                __G &&
                __P &&
                __M
            ) break;

            for( int __j = __g[__i].length() - 1lu; __j >= 0; --__j  ) 
                if(
                    !__G &&
                    __g[__i][__j] == 'G'
                ) {
                    __G = 1;
                    __res += __t[__i - 1];

                }
                else if(
                    !__P &&
                    __g[__i][__j] == 'P'
                ) {
                    __P = 1;
                    __res += __t[__i - 1];

                }
                else if(
                    !__M &&
                    __g[__i][__j] == 'M'
                ) {
                    __M = 1;
                    __res += __t[__i - 1];

                }

            --__i;

        }

        return __res;

    }
};