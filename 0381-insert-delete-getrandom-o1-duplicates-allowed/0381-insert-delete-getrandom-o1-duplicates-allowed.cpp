class RandomizedCollection {
public:
    explicit RandomizedCollection() noexcept {}
    
    inline const bool insert(
        const int& __v
    ) noexcept {
        __vs.emplace_back( __v );
        __um[__v].insert( __vs.size() - 1 );

        return __um[__v].size() == 1;

    }
    
    inline const bool remove(
        const int& __v
    ) noexcept {
        if( !__um.count( __v ) ) return 0;

        if( __v == __vs.back() ) {
            __um[__v].erase( __vs.size() - 1 );
            __vs.pop_back();

            if( !__um[__v].size() ) __um.erase( __v );

            return 1;

        }
        
        __um[__vs.back()].erase( __vs.size() - 1 );
        __um[__vs.back()].insert( *__um[__v].begin() );
        __vs[*__um[__v].begin()] = __vs.back();
        __um[__v].erase( *__um[__v].begin() );
        __vs.pop_back();

        if( !__um[__v].size() ) __um.erase( __v );

        return 1;

    }
    
    inline const int getRandom() const noexcept { return __vs[rand() % __vs.size()]; }

    unordered_map<int, unordered_set<int>> __um;
    vector<int> __vs;

};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */