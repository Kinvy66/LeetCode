
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
