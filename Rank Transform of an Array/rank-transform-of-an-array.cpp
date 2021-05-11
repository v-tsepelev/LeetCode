class Solution {
    public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        
        std::vector<int> sortedArr = arr;
        std::sort(sortedArr.begin(), sortedArr.end());
        
        std::map<int, int> hashMap{};
        for (auto elem : sortedArr)
        {
            if (hashMap.find(elem) == hashMap.end())
            {
                hashMap.insert(std::pair<int, int> (elem, hashMap.size() + 1));
            }
        }
        
        for (auto it{arr.begin()}; it != arr.end(); ++it)
        {
            *it = hashMap[*it];
        }
        
        return arr;
    }
};
