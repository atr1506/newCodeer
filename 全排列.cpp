// result = []
// def backtrack(路径, 选择列表):
//     if 满足结束条件:
//         result.add(路径)
//         return

//     for 选择 in 选择列表:
//         做选择
//         backtrack(路径, 选择列表)
//         撤销选择


class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};

// 1234的全排列
// --首先遍历元素,然后把遍历到的每一个元素都和第一个元素交换
// 那么就形成了 1234  2134  3214 4231 这样的4组

// --检查每一组除了第一个之外的剩余元素， 如1234剩余的是234，发现是3个元素
// 那么问题就转换为求234的全排列了
// 接下来也是一样 问题转换为求134， 214， 231的全排列

// 像这样 总是对除了第一个之外的元素全排列， 每次元素的个数都在减少一个，
// 求N个元素全排列最终就变成求2的元素的全排列了 

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。