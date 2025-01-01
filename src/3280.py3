class Solution:
    def bin(self, v) -> str:
        return bin(int(v))[2:]
    def convertDateToBinary(self, date: str) -> str:
        items = date.split('-')
        return '-'.join(map(lambda v: self.bin(v), items))