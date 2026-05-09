# 知识点卡片：栈 (Stack)

## 📌 核心特征
* **操作特性**：后进先出 (LIFO)。
* **适用场景**：匹配问题（括号、路径拆解）、历史回溯、寻找最近的更大/更小元素（单调栈）。

## ⚔️ 经典例题
* **基础匹配**：LeetCode 20 有效的括号
* **单调栈**：LeetCode 739 每日温度、LeetCode 84 柱状图中最大的矩形

## 🛠️ SOP 与核心技巧

### 1. 基础避坑铁律
* **⚠️ 先判空，再取值**：在调用 `st.top()` 或 `st.pop()` 之前，**必须**写 `!st.empty()` 检查。否则直接段错误 (Segfault)。

### 2. 单调栈 SOP (寻找下一个更大元素)
* **核心技巧**：栈里**不要存数值，存数组下标**。这样既能通过下标找到值 `nums[i]`，又能计算距离 `i - st.top()`。
```cpp
vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> ans(nums.size(), -1);
    stack<int> st; // 存下标
    
    for (int i = 0; i < nums.size(); i++) {
        // 当前元素大于栈顶元素所指的值，说明找到了栈顶元素的“下一个更大值”
        while (!st.empty() && nums[i] > nums[st.top()]) {
            int topIndex = st.top();
            st.pop();
            ans[topIndex] = nums[i]; // 记录答案
        }
        st.push(i); // 当前元素入栈，等待它的“下一个更大值”
    }
    return ans;
}
