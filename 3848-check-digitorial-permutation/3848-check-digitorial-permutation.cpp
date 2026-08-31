class Solution {
public:
    inline const bool isDigitorialPermutation(
        const int& __n
    ) const noexcept {
        int __d{};
        int __t{__n};
        char __dsn[10]{};
        char __dsd[10]{};

        while( __t ) {
            __d +=
                ( 
                    ( __t % 10 ) == 1 ? 1 :\
                    ( __t % 10 ) == 2 ? 2 :\
                    ( __t % 10 ) == 3 ? 6 :\
                    ( __t % 10 ) == 4 ? 24 :\
                    ( __t % 10 ) == 5 ? 120 :\
                    ( __t % 10 ) == 6 ? 720 :\
                    ( __t % 10 ) == 7 ? 5040 :\
                    ( __t % 10 ) == 8 ? 40320 :\
                    ( __t % 10 ) == 9 ? 362880 : 1
                );

            ++__dsn[__t % 10];
            __t /= 10;

        }

        while( __d ) { ++__dsd[__d % 10]; __d /= 10; }

        return (
            __dsd[0] == __dsn[0] &&
            __dsd[1] == __dsn[1] &&
            __dsd[2] == __dsn[2] &&
            __dsd[3] == __dsn[3] &&
            __dsd[4] == __dsn[4] &&
            __dsd[5] == __dsn[5] &&
            __dsd[6] == __dsn[6] &&
            __dsd[7] == __dsn[7] &&
            __dsd[8] == __dsn[8] &&
            __dsd[9] == __dsn[9]
        );

    }
};