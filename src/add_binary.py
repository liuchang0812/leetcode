class Solution:
    # @param a, a string
    # @param b, a string
    # @return a string
    def addBinary(self, a, b):
        vala = int(a, 2)
        valb = int(b, 2)
        return str(bin(vala + valb))[2:]
