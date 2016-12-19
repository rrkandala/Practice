import sys

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

    def getRoot(self):
        return self.root

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
            sys.stdout.write("%d->" % node.data)
            self._printTree(node.right)

    def IsSubTree(self, T, S):
        if(S == None):
            return True

        if(T == None):
            return False
        
        if(self.AreIdentical(T, S) == True):
            return True
        
        return self.AreIdentical(T.left, S) or self.AreIdentical(T.right, S)

    def AreIdentical(self, s1, s2):
        if(s1 == None and s2 == None):
            return True
        elif(s1 == None or s2 == None):
            return False

        return (s1.data == s2.data and self.AreIdentical(s1.left, s2.left) and self.AreIdentical(s1.right, s2.right))

tree1 = BinaryTree()
tree1.insert(5)
tree1.insert(2)
tree1.insert(1)
tree1.insert(3)
tree1.insert(7)
tree1.insert(6)
print("Tree 1: ")
tree1.printTree()

tree2 = BinaryTree();
tree2.insert(2)
tree2.insert(1)
tree2.insert(3)
print("Tree 1: ")
tree2.printTree()

tree = BinaryTree();
print("Tree2 is subtree of Tree1: %s" % str(tree.IsSubTree(tree1.getRoot(), tree2.getRoot())))