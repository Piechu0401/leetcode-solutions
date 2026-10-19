class AllOne {
public:
    // from DJ Piechu0401,
    // give it a try homeboy!
    // https://www.youtube.com/watch?v=YJ4bIyti6q0

    explicit AllOne() noexcept {}
    
    inline void inc(
        const string& __k
    ) noexcept {
        if( !__vals.count( __k ) ) {
            __vals[__k] = 1;
            __order.insert( { __k, 1 } );
            // cout << "INC: ";
            // for( auto& __e : __order )
            //     cout << __e.first << " " << __e.second << " ";
            // cout << "\n";
            return;

        }

        __order.erase( { __k, __vals[__k] } );
        __order.insert( { __k, ++__vals[__k] } );

        // cout << "INC: ";
        // for( auto& __e : __order )
        //     cout << __e.first << " " << __e.second << " ";
        // cout << "\n";

    }
    
    inline void dec(
        const string& __k
    ) noexcept {
        if( __vals[__k] == 1 ) {
            __vals.erase( __k );
            __order.erase( { __k, 1 } );
            return;

        }

        __order.erase( { __k, __vals[__k] } );
        __order.insert( { __k, --__vals[__k] } );

        // cout << "DEC: ";
        // for( auto& __e : __order )
        //     cout << __e.first << " " << __e.second << " ";
        // cout << "\n";
        
    }
    
    inline const string getMaxKey() noexcept {
        if( !__order.size() ) return "";

        // cout << "MAX: ";
        // for( auto& __e : __order )
        //     cout << __e.first << " " << __e.second << " ";
        // cout << "\n";

        return __order.rbegin()->first;

    }
    
    inline const string getMinKey() noexcept {
        if( !__order.size() ) return "";

        // cout << "MIN: ";
        // for( auto& __e : __order )
        //     cout << __e.first << " " << __e.second << " ";
        // cout << "\n";

        return __order.begin()->first;
   
    }

    struct __orderBy {
        inline const bool operator()(
            const pair<string, int>& __a,
            const pair<string, int>& __b 
        ) const noexcept { 
            if( __a.second == __b.second ) return __a.first < __b.first;
            return __a.second < __b.second; 
            
        }

    };

    unordered_map<string, int>                      __vals;
    set<pair<string, int>, __orderBy>               __order;

};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */