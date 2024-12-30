# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        

        @cache
        def dfs(list_node, tree_node) -> bool:

            if  list_node == None:
                return True
            
            if tree_node == None:
                print(f'{list_node.val=} False')
                return False
            
            res = False
            if tree_node.val == list_node.val:
                res = dfs(list_node.next, tree_node.left) or dfs(list_node.next, tree_node.right)
            
            if head != list_node:
                res = res or dfs(head, tree_node)
            
            res = res or dfs(head, tree_node.left) or dfs(head, tree_node.right)


            print(f'{list_node.val=} {tree_node.val=} {res=}')
            return res
        
        return dfs(head, root)