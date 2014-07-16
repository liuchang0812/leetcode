class Solution:
    # @param path, a string
    # @return a string
    def simplifyPath(self, path):
        items = path.split('/')
        path_items = []
        for item in items:
            if item == ".":
                continue
            if item == "":
                continue
            if item == "..":
                if len(path_items):
                    path_items.pop()
                continue
            path_items.append(item)
        ans = ''
        for i in path_items:
            ans = ans + '/' + i
        if ans=="":
            ans = '/'
        return ans


