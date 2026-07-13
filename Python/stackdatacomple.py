class stack:
    def __init__(self, size):
        self.size=size
        self.arr = [None]*size
        self.top = -1
    def isEmpty(self):
        