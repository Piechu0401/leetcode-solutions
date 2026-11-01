class Solution {
public:
    inline const vector<int> sortArrayByParityII(
        vector<int>& __ns
    ) const noexcept {
        short __even{};
        short __odd{1};

        while(
            __odd < __ns.size() && 
            __even < __ns.size()
        ) {
            while(
                __even < __ns.size() &&
                !( __ns[__even] & 1 )
            ) __even += 2;

            while(
                __odd < __ns.size() &&
                ( __ns[__odd] & 1 )
            ) __odd += 2;

            if(
                __odd < __ns.size() && 
                __even < __ns.size()
            ) {
                int __temp{ __ns[__odd] };
                __ns[__odd] = __ns[__even];
                __ns[__even] = __temp;

            }

        }

        return __ns;
        
    }
};