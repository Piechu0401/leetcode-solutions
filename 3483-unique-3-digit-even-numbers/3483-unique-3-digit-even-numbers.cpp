class Solution {
public:
    inline const int totalNumbers(
        vector<int>& __ds
    ) const noexcept {
        unordered_set<int> __us;

        for( int __i{}; __i < __ds.size(); ++__i )
            for( int __j{}; __j < __ds.size(); ++__j )
                if( __i != __j )
                    for( int __k{}; __k < __ds.size(); ++__k )
                        if( 
                            __k != __j && 
                            __i != __k &&
                            !( __ds[__k] & 1 ) &&
                            __ds[__i] * 100 + __ds[__j] * 10 + __ds[__k] >= 100  &&
                            !__us.count( __ds[__i] * 100 + __ds[__j] * 10 + __ds[__k] )  
                        ) __us.insert( __ds[__i] * 100 + __ds[__j] * 10 + __ds[__k] );

        return __us.size();

    }
};