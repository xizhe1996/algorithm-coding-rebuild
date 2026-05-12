# 🚀 LeetCode 核心编程技巧与避坑指南 (SOP Tricks)

## 1. 🧮 数学与边界取整技巧
* **二分查找向上取整 (防死循环)**：
    当收缩逻辑是 `left = mid` 时，`mid` 必须向上取整：`int mid = left + (right - left + 1) / 2;`
* **二分查找向下取整 (防溢出)**：
    默认写法：`int mid = left + (right - left) / 2;`
* **整数除法向上取整 (Ceiling)**：
    如果要求 $A / B$ 向上取整，不要用 `ceil(A/B)`（涉及浮点数精度丢失），直接用整数公式：`(A + B - 1) / B`。

## 2. 🛡️ 链表防御性技巧
* **虚拟头节点 (Dummy Head)**：
    **铁律**：只要链表的 `head` 可能会被修改（删除头节点、反转前几个节点），**无脑加上 Dummy Head**。
    `ListNode* dummy = new ListNode(-1); dummy->next = head;` （最后返回 `dummy->next` 并记得 delete 避免内存泄漏）。
* **断链重连的安全顺序**：
    反转链表或修改指针时，永远**先保存 `next`**，再修改当前节点的 `next`。

## 3. 🗺️ 矩阵与网格 (Grid) 遍历套路
* **方向数组 (Direction Array)**：
    在二维网格中做 DFS/BFS，绝对不要写四个 `if` 语句，使用方向数组循环：
    ```cpp
    int dx[4] = {-1, 1, 0, 0}; // 上下左右
    int dy[4] = { 0, 0,-1, 1};
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) { // 边界拦截线 }
    }
    ```

## 4. 🪣 数组与字符串的 C++ 地道操作
* **哈希替代品 (固定大小数组)**：
    如果题目说明是“仅包含小写字母”，**绝对不要**用 `unordered_map`。直接用 `vector<int> count(26, 0);` 或者 `int count[26] = {0};`。速度快 10 倍以上。
* **避免 vector 动态扩容的开销**：
    如果预先知道数组的大致大小，提前使用 `res.reserve(n);`，避免底层多次拷贝。
* **引用传递 (Pass by Reference)**：
    在 DFS 回溯或者传递巨大容器时，必须带上 `&`：`void dfs(vector<vector<int>>& res, vector<int>& path)`。忘记写 `&` 会导致每次递归都在深拷贝，直接 TLE (超时)。

## 5. 🛑 防御性编程“拦截线” (Early Return)
* 进入任何函数的第一步，先写拦截线，处理极端空输入：
    ```cpp
    if (nums.empty()) return 0;
    if (head == nullptr || head->next == nullptr) return head;
    ```