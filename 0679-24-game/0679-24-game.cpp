class Solution { 
public:
    inline const double operation(
        const double&   __a,
        const double&   __b,
        char&           __op
    ) const noexcept { // 313
        if( __op == 0 ) return __a + __b;
        else if( __op == 1 ) return __a - __b;
        else if( __op == 2 ) return __a * __b;

        return __b == 0.0 ? DBL_MAX : __a / __b;

    }

    inline const double doTheTrick(
        vector<double>&     __ds,
        vector<char>&        __os
    ) const noexcept {
        double __chunk1{
            operation(
                    __ds[0],
                    __ds[1],
                    __os[0]                
            )
        };

        double __chunk2{
            operation(
                    __ds[1],
                    __ds[2],
                    __os[1]                
            )
        };

        double __chunk3{
            operation(
                    __ds[2],
                    __ds[3],
                    __os[2]                
            )
        };

        double __res1{
            operation(
                __chunk1,
                __chunk3,
                __os[1]
            )
        };
            
        double __res2{ 
            operation(
                operation(
                    __chunk1,
                    __ds[2],
                    __os[1]
                ),
                __ds[3],
                __os[2]
            )
        };

        double __res3{
            operation(
                operation(
                    __ds[0],
                    __chunk2,
                    __os[0]
                ),
                __ds[3],
                __os[2]
            )
        };

        double __res4{
            operation(
                __ds[0],
                operation(
                    __ds[1],
                    __chunk3,
                    __os[1]
                ),
                __os[0]
            )
        };

        // if( 
        //     __os[0] == 3 && __os[1] == 1 && __os[2] == 3 &&
        //     __ds[0] == 8 && __ds[1] == 3 && __ds[2] == 8 && __ds[3] == 3
        // ) {
        //     cout << __chunk1 << " " << __chunk3 << " " << __res4 << "\n";
        //     cout << __res1 << " " << __res2 << " " << __res3 << " " << __res4 << "\n";
        // 
        // }

        return 
            abs( __res1 - 24.0 ) < 1e-9 ? 24.0 :\
            abs( __res2 - 24.0 ) < 1e-9 ? 24.0 :\
            abs( __res3 - 24.0 ) < 1e-9 ? 24.0 :\
            abs( __res4 - 24.0 ) < 1e-9 ? 24.0 : 0.0;

    }

    inline const bool judgePoint24(
        vector<int>& __cs
    ) const noexcept { // looks ugly, but I dont give a fuck
                            // yeah thanks for not mentioning that you don't need to use all of the
                            // numbers you fucking retard, go fuck yourself you discord mod
                            // yeah I said that, go cry you motherfucker
                            // UPDATE: Im deeply sorry Im the fucking idiot here, you need to use all shit...
        // if(
        //     (
        //         (
        //             __cs[0] == 4 ||
        //             __cs[1] == 4 ||
        //             __cs[2] == 4 ||
        //             __cs[3] == 4
        //         ) &&
        //         (
        //             __cs[0] == 6 ||
        //             __cs[1] == 6 ||
        //             __cs[2] == 6 ||
        //             __cs[3] == 6
        //         )
        //     ) ||
        //     (
        //         (
        //             __cs[0] == 2 ||
        //             __cs[1] == 2 ||
        //             __cs[2] == 2 ||
        //             __cs[3] == 2
        //         ) &&
        //         (
        //             __cs[0] == 3 ||
        //             __cs[1] == 3 ||
        //             __cs[2] == 3 ||
        //             __cs[3] == 3
        //         ) &&
        //         (
        //             __cs[0] == 4 ||
        //             __cs[1] == 4 ||
        //             __cs[2] == 4 ||
        //             __cs[3] == 4
        //         )
        //     )
        // ) return 1;

        for( char __i{}; __i < 4; ++__i ) 
            for( char __j{}; __j < 4; ++__j ) {
                if( __i == __j ) continue;
                
                for( char __k{}; __k < 4; ++__k ) {
                    if( __k == __j || __k == __i ) continue;

                    for( char __l{}; __l < 4; ++__l ) {
                        if( __l == __j || __l == __i || __l == __k ) continue;

                        // vector<int> __digits = { __cs[__i], __cs[__j], __cs[__k], __cs[__l] };
                        vector<double> __ds = {
                            (double)( __cs[__i] ), 
                            (double)( __cs[__j] ), 
                            (double)( __cs[__k] ), 
                            (double)( __cs[__l] )
                        };

                        for( char __a{}; __a < 4; ++__a )
                            for( char __b{}; __b < 4; ++__b ) {
                                for( char __c{}; __c < 4; ++__c ) {
                                    vector<char> __os = { __a, __b, __c };

                                    // cout << (int)__a << " " << (int)__b << " " << (int)__c << "\n";

                                    double __res{ doTheTrick( __ds, __os ) };
                                    // cout << __res << "\n";

                                    if( __res == 24.000000 ) {
                                        // cout 
                                        //     << __ds[0] << " " << (int)__os[0] << " "
                                        //     << __ds[1] << " " << (int)__os[1] << " "
                                        //     << __ds[2] << " " << (int)__os[2] << " "
                                        //     << __ds[3];
                                        
                                        return 1;

                                    }

                                }

                            }

                    }

                }

            }

        return 0;

    }

};

// operators combs:
// 4 * 4 * 4 = 64
// possible orders of operations ... [op1] ... [op2] ... [op3] ...
// [op1] [op2] [op3]
// [op1] [op3] [op2]
// [op3] [op2] [op1]
// [op3] [op1] [op2]
// [op2] [op1] [op3]
// [op2] [op3] [op1] --> 6
// [op] = { -, +, *, / }
// A [op] B [op] C [op] D
// parenthesis ways: 
// ( ( A [op] B [op] C ) [op] D )
// ( A [op] B [op] C [op] D )
// ( ( A [op] B ) [op] ( C [op] D ) )
// ( ( A [op] ( B [op] C ) ) [op] D )
// ( A [op] ( ( B [op] C ) [op] D ) )
// # ## #   ### #   # ###
// ## # #   ## ##   ### #   
// # # ##   ## ##   # ###   