class Solution {
public:
    inline const vector<int> decrypt(
        vector<int>&    __code, 
        int&            __k
    ) const noexcept {
        if( !__k ) return vector<int>( __code.size(), 0 );

        vector<int> __res = __code;

        if( __k > 0 ) 
            for( char __i{}; __i < __code.size(); ++__i ) {
                int __rep{};
                char __idx{__i};
                char __times{};

                while( __times < __k ) {
                    __idx = ( ++__idx ) % __code.size();
                    __rep += __code[__idx]; 
                    ++__times;

                }

                __res[__i] = __rep;

            }
        else
            for( char __i{}; __i < __code.size(); ++__i ) {
                int __rep{};
                char __idx{__i};
                char __times{};

                while( __times < -__k ) {
                    __idx = ( __idx - 1 == -1 ? __code.size() - 1 : --__idx );
                    __rep += __code[__idx]; 
                    ++__times;

                }

                __res[__i] = __rep;

            }

        return __res;

    }
};