class TreeNode: #Class for creating each node of the tree
    def __init__(self, data):
        self.data = data #This gives the node an integer value
        self.left = None #This gives the node a left child if needed
        self.center = None #This gives the node a center child if needed
        self.right = None #This gives the node a right child if needed

class Tree: #Class for creating the actual tree
    def create_tree_node(data): #This takes a interger value and creates a node with that value for the tree
        return TreeNode(data)

    def fill_tree_node(root): #This function is used to fill the treenodes with the values needed to create the tree
        #creating the left side of the tree
        root.left = Tree.create_tree_node(2)
        root.left.left = Tree.create_tree_node(5)
        root.left.right = Tree.create_tree_node(6)
        root.left.left.left = Tree.create_tree_node(11)
        root.left.left.right = Tree.create_tree_node(12)
        root.left.left.right.left = Tree.create_tree_node(17)

        #creating the center of the tree
        root.center = Tree.create_tree_node(3)
        root.center.left = Tree.create_tree_node(7)
        root.center.right = Tree.create_tree_node(8)

        #creating the right side of the tree
        root.right = Tree.create_tree_node(4)
        root.right.left = Tree.create_tree_node(9)
        root.right.right = Tree.create_tree_node(10)
        root.right.left.left = Tree.create_tree_node(13)
        root.right.left.right = Tree.create_tree_node(14)
        root.right.right.left = Tree.create_tree_node(15)
        root.right.right.right = Tree.create_tree_node(16)
    
    def print_given_level(root, level): #This function is used in the breadth first traversal to find and move up the tree's level
        if root is not None and level == 1: #When the root level of the tree is not empty and the level is 1, it prints just the root value
            print(f"{root.data} ", end="")
        elif root is not None and level > 1: #When the tree has more then just one level it recursively calls itself with the level -1. Then it prints the tree's height 
            Tree.print_given_level(root.left, level - 1)
            Tree.print_given_level(root.center, level - 1) 
            Tree.print_given_level(root.right, level - 1)
        else:
            return 0 #If the tree is empty it returns 0 because the tree is empty
        
    def tree_height(root): #This function is used to find the height of the tree
        if root is None: # If the root is empty then exit since the tree is empty
            return 0
        else: #If the tree is not empty then it recursively calls itself to find the height of the tree
            left_height = Tree.tree_height(root.left)
            center_height = Tree.tree_height(root.center)
            right_height = Tree.tree_height(root.right)

            if left_height > center_height and left_height > right_height: #This is used to find the height of the left side of the tree
                return left_height + 1
            elif center_height > right_height and center_height > left_height: #This is used to find the height of the center of the tree
                return center_height + 1
            else:
                return right_height + 1 #This is used to find the height of the right side of the tree
        
    def bredth_first_traversal(root):
        height = Tree.tree_height(root)
        for i in range(1, height + 1):
            Tree.print_given_level(root, i)

    def depth_first_traversal(root):
        if root is not None:
            Tree.depth_first_traversal(root.left)
            Tree.depth_first_traversal(root.center)
            Tree.depth_first_traversal(root.right)
            print(f"{root.data} ", end="")
            
            
        else:
            return 0


def main(): #This is the main function that is used to run the program. This will create the tree and print the tree's height and the breadth first traversal of the tree
    root = Tree.create_tree_node(1)
    Tree.fill_tree_node(root)
    print("Tree Height: ", Tree.tree_height(root))
    print("\nThe breath first traversal of the tree is: ")
    Tree.bredth_first_traversal(root)
    print("\nThe depth first traversal of the tree is: ")
    Tree.depth_first_traversal(root)

if __name__ == "__main__":
    main()