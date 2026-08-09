class Solution {
public:
    inline const bool doesValidArrayExist(
        const vector<int>&      __dd // diddy   : D
    ) const noexcept {
        char __res{};

        for( auto& __d : __dd ) __res ^= __d;

        return !__res;
        
    }
};