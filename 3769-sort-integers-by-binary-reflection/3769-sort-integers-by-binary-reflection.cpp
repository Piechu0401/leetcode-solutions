class Solution {
public:
    inline const vector<int> sortByReflection(
        vector<int>& __ns
    ) const noexcept {
        sort(
            __ns.begin(),
            __ns.end(),
            [](
                const int& __a,
                const int& __b
            ) -> const bool {
                int __A{__a};
                int __B{__b};
                int __refA{};
                int __refB{};

                while( __A ) {
                    __refA = ( __refA << 1 ) | ( __A & 1 );
                    __A >>= 1;

                }

                while( __B ) {
                    __refB = ( __refB << 1 ) | ( __B & 1 );
                    __B >>= 1;

                }

                if( __refA == __refB ) return __a < __b;

                return __refA < __refB;

            }
        );

        return __ns;
        
    }
};