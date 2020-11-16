# 数据结构与算法学习笔记
## 课程：算法原理与实践
### 第一课
####  C语言的陷阱：
- 内存重叠的处理
- 临时变量太多或者没安全释放
- 没有测试内存越界
- 指针操作不熟悉

```C++
//有问题代码
void *memmove(void *dest , const void *src, size_t n)
{
  char *p1 = dest;
  char *p2 = src;
  while(*p2 != \0)
  {
    *p1++ = *p2++;
  }
  return p1;
}

//正确写法
void *memmove(void *dest, const void *src, size_t n)
{
  char *p1 = dest;
  const char *p2 = src;
  if(p2 < p1){
    p2 += n;
    p1 += n;
    while(n-- != 0)
    {
      *--p1 = *--p2;
    }
   }
   else{
    while(n-- != 0){
      *p1++ = *p2++;
    }
   }
   return p1;
}
```
反转二叉树
Invert a Binary Tree 
```C++
/**
  Definition for a binary tree node.
  struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
  };
*/

class Solution{
  public:
    TreeNode* invertTree(TreeNode* root){
      if(root == NULL)
        return NULL;
        
        TreeNode* tmpNode = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmpNode);
        return root;
    }
}

```
