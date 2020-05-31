
morris遍历是二叉树遍历算法的至强算法，不同于递归，非递归（栈实现）的空间复杂度，morris遍历可以将非递归遍历中的树的深度的空间开销，降为O(1)。从而实现时间复杂度为O(n)，而空间复杂度为O(1)的精妙算法。

morris遍历利用的是树的叶节点左右孩子为空，这一特性来实现空间开销的极度缩减。
morris遍历的实现原则

来到当前节点，记为cur（引用）
1、如果cur无左孩子，cur向右移动（cur = cur.right）
2、如果cur有左孩子，找到cur左子树上最右的节点，记为mostright
    （1）如果mostright的right指针指向空，让其指向cur，cur向左移动（cur = cur.left）
    （2）如果mostright的right指针指向cur，让其指向空，cur向右移动（cur = cur.right）
