/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void doTheTrick(
        TreeNode* __root,
        int& __min,
        int& __max,
        int __posX,
        int __posY,
        unordered_map<int, vector<pair<int, int>>>& __um
    ) {
        if( !__root ) return;

        if( __posX < __min ) __min = __posX;
        else if( __posX > __max ) __max = __posX;

        if( !__um.contains(__posX) ) 
            __um.insert(
                make_pair(
                    __posX, 
                    vector<pair<int, int>>(
                        1, 
                        make_pair(
                            __root->val, 
                            __posY
                        )
                    )
                )
            );
        else __um[__posX].emplace_back(make_pair(__root->val, __posY));

        doTheTrick(
            __root->left,
            __min,
            __max,
            __posX - 1,
            __posY + 1,
            __um 
        );

        doTheTrick(
            __root->right,
            __min,
            __max,
            __posX + 1,
            __posY + 1,
            __um 
        );

    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int __min = 0;
        int __max = 0;
        unordered_map<int, vector<pair<int, int>>> __um;

        doTheTrick(
            root,
            __min,
            __max,
            0,
            0,
            __um
        );

        vector<vector<int>> __res;

        for( int __i{__min}; __i <= __max; ++__i ) {
            vector<int> __sorted;
            sort(
                __um[__i].begin(),
                __um[__i].end(),
                [&](
                    const pair<int, int>& __a,
                    const pair<int, int>& __b
                ) {
                    if( __a.second > __b.second )
                        return false;
                    else if( __a.second == __b.second )
                        return __a.first < __b.first; 
                    else return true;

                }
            );

            for( auto& n : __um[__i] )
                __sorted.emplace_back(n.first);

            __res.emplace_back( __sorted );

        }

        return __res;

    }
};