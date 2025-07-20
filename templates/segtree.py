import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 5)
class Node():
    def __init__(self, arr: list[int], a: int, b: int):
        self.l = a
        self.r = b
        if(a == b):
            self.minValue = arr[a]
            return
        
        mid = (a + b) // 2
        self.leftChild = Node(arr, a, mid)
        self.rightChild = Node(arr, mid + 1, b)
        self.minValue = min(self.leftChild.minValue, self.rightChild.minValue)


    def query(self, a: int, b: int) -> int:
        if (a <= self.l and self.r <= b):
            return self.minValue
        
        if (self.r < a or self.l > b):
            return float('inf')

        return min(
                self.leftChild.query(a, b),
                self.rightChild.query(a, b)
        )

    def update(self, x: int, v: int) -> None:
        if(x < self.l or x > self.r): return
        if(x == self.l and x == self.r):
            self.minValue = v
            return
        
        self.leftChild.update(x, v)
        self.rightChild.update(x, v)
        self.minValue = min(self.leftChild.minValue, self.rightChild.minValue)

def main():
    n, m = map(int, input().split())
    data = [0 for _ in range(n)]
    for i in range(n):
        data[i] = int(input())

    rootNode = Node(data, 0, n - 1)
    for i in range(m):
        op, a, b = input().split()
        a = int(a)
        b = int(b)
        if (op == 'M'): 
            rootNode.update(a, b)
        else:
            print(rootNode.query(a, b))

if __name__ == "__main__":
    main()