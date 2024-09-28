class Search:
    def __init__(self, arr: list[int], num: int):
        self.arr = arr
        self.num = num
        self.idx_b = self.binary()
        self.idx_l = self.linear()

    def linear(self):
        for idx in range(len(self.arr)):
            if self.arr[idx] == self.num:
                return idx

        return False

    def binary(self):
        l = 0
        r = len(self.arr) - 1

        if self.arr[l] == self.num:
            return l
        elif self.arr[r] == self.num:
            return r 

        while l <= r:
            k = (l + r) // 2
            # [l, k]
            if self.arr[k] < self.num:
                l = k + 1
            # [k+1, r]
            elif self.arr[k] > self.num:
                r = k - 1
            else:
                return k
        
        return False



