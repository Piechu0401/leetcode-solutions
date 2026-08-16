class Solution {
public:
    inline const vector<vector<int>> queensAttacktheKing(
        const vector<vector<int>>& __qs, 
        const vector<int>& __k
    ) const noexcept {
        vector<vector<int>> __res;
        vector<char> __bd( 64, 0 );

        __bd[__k[0] * 8 + __k[1]] = 2;

        for( auto& __q : __qs ) __bd[__q[0] * 8 + __q[1]] = 1;

        for( auto& __q : __qs ) {
            int __dst{1};
            char __le{1};
            char __ri{1};
            char __do{1};
            char __up{1};
            char __lt{1};
            char __lb{1};
            char __rt{1};
            char __rb{1};

            while(
                __q[0] - __dst > -1 ||
                __q[1] - __dst > -1 ||
                __q[0] + __dst < 8 ||
                __q[1] + __dst < 8
            ) {
                if(
                    __le &&
                    __q[1] - __dst > -1 &&
                    __bd[__q[0] * 8 + __q[1] - __dst] == 2
                ) { __res.emplace_back( __q ); }
                else if(
                    __le &&
                    __q[1] - __dst > -1 &&
                    __bd[__q[0] * 8 + __q[1] - __dst] == 1
                ) __le = 0;

                if(
                    __ri &&
                    __q[1] + __dst < 8 &&
                    __bd[__q[0] * 8 + __q[1] + __dst] == 2
                ) { __res.emplace_back( __q ); }
                else if(
                    __ri &&
                    __q[1] + __dst < 8 &&
                    __bd[__q[0] * 8 + __q[1] + __dst] == 1
                ) __ri = 0;

                if(
                    __up &&
                    __q[0] - __dst > -1 &&
                    __bd[( __q[0] - __dst) * 8 + __q[1]] == 2
                ) { __res.emplace_back( __q ); }
                else if(
                    __up &&
                    __q[0] - __dst > -1 &&
                    __bd[( __q[0] - __dst) * 8 + __q[1]] == 1
                ) __up = 0;

                if(
                    __do &&
                    __q[0] + __dst < 8 &&
                    __bd[( __q[0] + __dst) * 8 + __q[1]] == 2
                ) { __res.emplace_back( __q ); }
                else if(
                    __do &&
                    __q[0] + __dst < 8 &&
                    __bd[( __q[0] + __dst) * 8 + __q[1]] == 1
                ) __do = 0;

                if(
                    __lt &&
                    __q[0] - __dst > -1 &&
                    __q[1] - __dst > -1 &&
                    __bd[( __q[0] - __dst) * 8 + __q[1] - __dst] == 2
                ) { __res.emplace_back( __q ); }
                else if(
                    __lt &&
                    __q[0] - __dst > -1 &&
                    __q[1] - __dst > -1 &&
                    __bd[( __q[0] - __dst) * 8 + __q[1] - __dst] == 1
                ) __lt = 0;

                if(
                    __rt &&
                    __q[0] - __dst > -1 &&
                    __q[1] + __dst < 8 &&
                    __bd[( __q[0] - __dst) * 8 + __q[1] + __dst] == 2
                ) { __res.emplace_back( __q ); }
                else if(
                    __rt &&
                    __q[0] - __dst > -1 &&
                    __q[1] + __dst < 8 &&
                    __bd[( __q[0] - __dst) * 8 + __q[1] + __dst] == 1
                ) __rt = 0;

                if(
                    __lb &&
                    __q[0] + __dst < 8 &&
                    __q[1] - __dst > -1 &&
                    __bd[( __q[0] + __dst) * 8 + __q[1] - __dst] == 2
                ) { __res.emplace_back( __q ); }
                else if(
                    __lb &&
                    __q[0] + __dst < 8 &&
                    __q[1] - __dst > -1 &&
                    __bd[( __q[0] + __dst) * 8 + __q[1] - __dst] == 1
                ) __lb = 0;

                if(
                    __rb &&
                    __q[0] + __dst < 8 &&
                    __q[1] + __dst < 8 &&
                    __bd[( __q[0] + __dst) * 8 + __q[1] + __dst] == 2
                ) { __res.emplace_back( __q ); }
                else if(
                    __rb &&
                    __q[0] + __dst < 8 &&
                    __q[1] + __dst < 8 &&
                    __bd[( __q[0] + __dst) * 8 + __q[1] + __dst] == 1
                ) __rb = 0;

                ++__dst;

            }

        }

        return __res;
        
    }
};