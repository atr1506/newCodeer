class KthNumbers {
public:
    vector<int> findKthNumbers(vector<int> A, int n, int k) {
        //默认大顶堆，加第二个和第三个参数greater<>变为小顶堆
        priority_queue<pair<int,int>,vector<pair<int, int> >, greater<pair<int,int> > > p;
        vector<int> index; //存储前k个小元素的下标，方便输出时恢复到原来的相对顺序
        //建堆
        for(int i = 0; i < n; ++i)
            p.push(make_pair(A[i], i));
        //弹出k个较小元素
        for(int i = 0; i < k; ++i)
        {
            index.push_back(p.top().second);
            p.pop();
        }
         
        vector<int> result;
        sort(index.begin(), index.end()); //对k个小的元素下标排序，方便获得正确的相对位置
        for(int i = 0; i < k; ++i)
            result.push_back(A[index[i]]);
        return result;
    }
};