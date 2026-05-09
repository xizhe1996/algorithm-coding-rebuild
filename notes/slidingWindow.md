# 知识点卡片：滑动窗口 (Sliding Window)

## 📌 核心特征
* **物理模型**：虫取法（毛毛虫爬行）。头部（`right`）向前吃进新元素扩大窗口，尾部（`left`）向前吐出旧元素缩小窗口。
* **适用场景**：寻找满足特定条件的**连续子数组 / 子串**。
* **核心威力**：将 $O(N^2)$ 的嵌套枚举降维打击为 $O(N)$ 的单次扫描。双指针只进不退。

## ⚔️ 经典例题
* **求最短合法窗口**：LeetCode 209 长度最小的子数组
* **求最长合法窗口**：LeetCode 3 无重复字符的最长子串

## 🛠️ SOP 编程模版

### 模版 1：求【最短】满足条件的窗口
**逻辑**：条件满足时，尝试收缩逼近极小值。
```cpp
int minWindow(vector<int>& nums, int target) {
    int left = 0, sum = 0;
    int min_len = nums.size() + 1; // 1. 🧱 初始化为物理上不可能达到的极大值

    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right]; // 2. 🐛 进食

        while (sum >= target) { // 3. 🛑 满足条件，开始收缩尾部
            min_len = min(min_len, right - left + 1); // 📸 拍快照求最小
            sum -= nums[left++]; // 💩 吐出旧元素并移动左指针
        }
    }
    return min_len == nums.size() + 1 ? 0 : min_len; 
}
```

### 模版 2：求【最长】满足条件的窗口
**逻辑**：条件被破坏时，被迫收缩直到重新合法。
```cpp
int maxWindow(string s) {
    unordered_set<char> window; // 1. 🗑️ 查重容器
    int left = 0, max_len = 0;

    for (int right = 0; right < s.length(); right++) {
        char new_char = s[right]; // 2. 🐛 准备进食

        while (window.count(new_char)) { // 3. 🛑 状态非法(吃重复了)，被迫收缩
            window.erase(s[left++]); // 💩 持续吐出最左侧元素，直到合法
        }

        window.insert(new_char); // 恢复合法，吃下新元素
        max_len = max(max_len, right - left + 1); // 📸 拍快照求最大
    }
    return max_len;
}
```