class Solution {
public:
    inline const vector<int> twoOutOfThree(
        const vector<int>& __ns1, 
        const vector<int>& __ns2, 
        const vector<int>& __ns3
    ) const noexcept {
        vector<int> __res;
        char __is1[100]{};
        char __is2[100]{};
        char __is3[100]{};

        for( char __i{}; __i < max( { __ns1.size(), __ns2.size(), __ns3.size() } ); ++__i ) {
            if( __i < __ns1.size() ) __is1[__ns1[__i] - 1] = 1;
            if( __i < __ns2.size() ) __is2[__ns2[__i] - 1] = 1;
            if( __i < __ns3.size() ) __is3[__ns3[__i] - 1] = 1;

        }

        for( char __i{}; __i < 100; ++__i )
            if(
                __is1[__i] +
                __is2[__i] +
                __is3[__i] > 1
            ) __res.emplace_back( __i + 1 );

        return __res;
        
    }
};