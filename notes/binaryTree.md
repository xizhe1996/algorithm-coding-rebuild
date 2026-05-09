# 二叉树五大核心武器库 ⚔️

这份文档总结了二叉树解题的五种核心递归与迭代模板（SOP）。在解决二叉树问题时，请根据题目特征选择最合适的“武器”。

---

## 1. 📡 雷达扫描 (BFS 层序遍历)
**核心特征**：按层处理。适用于求最短路径、层级属性（如每层最大值）、对称性等。

```cpp
void bfs(TreeNode* root) {
    if (root == nullptr) return;
    
    queue<TreeNode*> q;
    q.push(root); 
    
    while (!q.empty()) {
        int levelSize = q.size(); // 📸 拍快照：记录当前层节点数
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* curr = q.front();
            q.pop();
            
            // 🛠️ 处理当前节点 curr
            // ...
            
            // 🚀 将下一层节点加入队列
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
}
```

---

## 2. 🥷 纯办事 (基础 DFS)
**核心特征**：无状态传递，直接操作。适用于翻转二叉树、合并二叉树等简单变换。

```cpp
TreeNode* dfs(TreeNode* root) {
    // 1. 🧱 绝对拦截线
    if (root == nullptr) return nullptr;

    // 2. 🛠️ 执行操作 (如：swap(root->left, root->right))
    // ...

    // 3. 🪂 信任之跃 (递归处理子树)
    dfs(root->left);
    dfs(root->right);

    return root; 
}
```

---

## 3. 📜 传圣旨 (自顶向下 DFS)
**核心特征**：历史状态随参数下传。适用于路径求和、求最大/最小深度等。

```cpp
void dfs(TreeNode* root, int current_state, int& global_res) {
    // 1. 🧱 绝对拦截线
    if (root == nullptr) return;

    // 2. 🛠️ 更新当前状态 (圣旨)
    int next_state = current_state + root->val; 
    
    // 到达叶子节点时，更新全局结果
    if (!root->left && !root->right) {
        global_res = max(global_res, next_state);
    }

    // 3. 🚀 带着新状态继续下传
    dfs(root->left, next_state, global_res);
    dfs(root->right, next_state, global_res);
}
// 启动：dfs(root, 0, res);
```

---

## 4. 🎒 带背包的回溯 (DFS 路径搜索)
**核心特征**：共享物理背包（引用）。必须遵守“进门装包，出门退包”的对称美学。

```cpp
void dfs(TreeNode* root, vector<int>& path, vector<vector<int>>& ans) {
    // 1. 🧱 绝对拦截线
    if (root == nullptr) return;

    // 2. 🛠️ 装包
    path.push_back(root->val);

    // 满足条件（如叶子节点）则存档
    if (!root->left && !root->right) {
        ans.push_back(path);
    }

    // 3. 🪂 信任之跃
    dfs(root->left, path, ans);
    dfs(root->right, path, ans);

    // 4. 🧹 清理现场 (退包)
    path.pop_back(); 
}
```

---

## 5. 📊 听汇报 (自底向上 DFS)
**核心特征**：依赖子树返回的情报。适用于最近公共祖先 (LCA)、树的最大直径等。

```cpp
ReturnType dfs(TreeNode* root) {
    // 1. 🧱 绝对拦截线 或 抓到通缉犯
    if (root == nullptr /* || root == p || root == q */) {
        return root; 
    }

    // 2. 🕵️ 听取左右子树汇报
    ReturnType left_report = dfs(root->left);
    ReturnType right_report = dfs(root->right);

    // 3. 📝 汇总决策
    if (left_report && right_report) {
        return root; // 左右都有，我就是结果
    }
    
    return left_report ? left_report : right_report; // 否则上报有值的那一边
}
```