
# LeetCode 

## 环境:
- Clion 
- WSL2(Ubuntu20)
- G++ 9.4(C++11)
- CMake 3.6


## 题目

### 1. [两数之和](https://leetcode.cn/problems/two-sum/)
双重循环暴力解法，注意内层循环的范围

```c++
for (int i = 0; i < nums.size(); ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      //...
    }
}
```

### 2. [两数相加](https://leetcode.cn/problems/add-two-numbers/submissions/)
两个数相加，定义一个进位的标志，循环将list对应的位相加，注意出循环后需要处理flag
```c++
if (flag == 1) {
    ListNode* node = new ListNode();
    cur->next = node;
    node->val = 1;
}
```