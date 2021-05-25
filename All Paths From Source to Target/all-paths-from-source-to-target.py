class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        target = len(graph) - 1
        path = deque([[0]])
        result = []
        while (path):
            currPath = path.popleft()
            currNode = currPath[-1]
            if currNode == target:
                result.append(currPath)
            else:
                for neighbor in graph[currNode]:
                    path.append(currPath + [neighbor])
        return result
