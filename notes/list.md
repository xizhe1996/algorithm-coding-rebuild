# 知识点卡片：链表 (Linked List)

## 📌 核心特征
* **操作特性**：内存不连续，靠指针连接。增删快（修改指针），查找慢（需遍历）。
* **适用场景**：节点合并/拆分、环形检测、长度未知的序列处理。

## ⚔️ 经典例题
* **反转与虚拟头**：LeetCode 206 反转链表、LeetCode 21 合并两个有序链表
* **快慢指针与环**：LeetCode 141 环形链表、LeetCode 142 环形链表 II（找入口）

## 🛠️ 链表三大核心模版 (SOP)

### 1. 🛡️ 虚拟头节点 (Dummy Head)
* **解决痛点**：头节点可能会被删除或改变，导致需要单独写 `if` 逻辑处理头节点。
* **SOP**：
```cpp
ListNode* dummy = new ListNode(0); // 1. 创建虚拟头
dummy->next = head;                // 2. 连上真实头
ListNode* curr = dummy;            // 3. curr 从 dummy 开始遍历
// ... 业务逻辑 ...
return dummy->next;                // 4. 返回时丢弃 dummy

```
### 2. 🔄 原地反转链表
* **解决痛点**：断开当前节点时，找不到下一个节点。
* **SOP**：

```C++
ListNode* prev = nullptr;
ListNode* curr = head;
while (curr != nullptr) {
    ListNode* next_temp = curr->next; // 1. 📸 提前保存下一个节点
    curr->next = prev;                // 2. 🔀 反转当前指针
    prev = curr;                      // 3. 🚶‍♂️ prev 前进
    curr = next_temp;                 // 4. 🚶‍♂️ curr 前进
}
return prev; // 最终 prev 是新的头节点
```

### 3. 🐇🐢 快慢指针安全边界与找环
* **解决痛点**：找中点、判断是否有环。
* **SOP**：fast 走两步，slow 走一步。如果相遇则有环。

* **⚠️ 安全边界铁律：**：while (fast != nullptr && fast->next != nullptr)。必须保证 fast 本身和它的一下个节点都不为空，才能安全地走两步。

* **找环入口定理:**：快慢指针相遇后，把其中一个指针移回 head，然后两个指针每次都只走 1 步。他们再次相遇的地方，就是环的入口。
