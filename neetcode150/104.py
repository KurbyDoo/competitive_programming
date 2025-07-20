# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        q = [[root, 1]]
        depth = 0

        while q:
            cur, count = q.pop(0)

            if cur.left:
                q.append([cur.left, count + 1])

            if cur.right:
                q.append([cur.right, count + 1])

            depth = max(count, depth)

        return depth
