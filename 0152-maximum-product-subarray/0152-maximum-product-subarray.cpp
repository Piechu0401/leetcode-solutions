class Solution {
public:
    inline const int maxProduct(
        const vector<int>& __ns
    ) const noexcept {
        int __max{ __ns.front() };
        int __min{ __ns.front() };
        int __res{ __ns.front() };

        for( unsigned short __i{1}; __i < __ns.size(); ++__i ) {
            int __tmax{__max};
            int __tmin{__min};
            
            __max = max(
                {
                    __ns[__i],
                    __ns[__i] * __tmax,
                    __ns[__i] * __tmin
                }
            );

            __min = min(
                {
                    __ns[__i],
                    __ns[__i] * __tmax,
                    __ns[__i] * __tmin
                }
            );

            __res = __res < __max ? __max : __res;

        }

        return __res;

    }   
};