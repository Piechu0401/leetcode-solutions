class Solution {
public:
    inline const vector<int> sortJumbled(
        const vector<int>& __ms, 
        vector<int>& __ns
    ) const noexcept {
        stable_sort(
            __ns.begin(),
            __ns.end(),
            [&](
                int __a,
                int __b
            ) -> bool {
                int __A{};
                int __B{};
                long __p{1L};

                if( __a )
                while( __a ) {
                    __A += __p * __ms[__a % 10];
                    __p *= 10L;
                    __a /= 10;

                }
                else __A = __ms[__a];

                __p = 1L;

                if( __b )
                while( __b ) {
                    __B += __p * __ms[__b % 10];
                    __p *= 10L;
                    __b /= 10;

                }
                else __B = __ms[__b];

                //if( __A == __B ) return __c1 < __c2;

                return __A < __B;

            }

        );

        return __ns;
        
    }
};