class Node:
    def __init__(self):
        self.data = 0
        self.left = None
        self.right = None

    def __init__(self, d):
        self.data = d
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, d):
        if(self.root == None):
            self.root = Node(d)
        else:
            self._insert(d, self.root)

    def _insert(self, d, node):
        if(d < node.data):
            if(node.left != None):
                self._insert(d, node.left)
            else:
                node.left = Node(d)
        else:
            if(node.right != None):
                self._insert(d, node.right)
            else:
                node.right = Node(d)

    def printTree(self):
        self._printTree(self.root)
        print("\n")

    def _printTree(self, node):
        if(node == None):
            return;
        else:
            self._printTree(node.left)
            print("%d->" % node.data)
            self._printTree(node.right)

tree = BinaryTree()
tree.insert(5)
tree.insert(2)
tree.insert(1)
tree.insert(3)
tree.insert(7)
tree.insert(6)

tree.printTree()
