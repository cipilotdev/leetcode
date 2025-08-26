# LeetCode 算法题解集合

## 项目概述

本项目是一个系统化的 LeetCode 算法题解集合，包含多个分类的 C++ 实现。项目按照算法类型和学习路径进行重新组织，涵盖了从基础到高级的各种算法和数据结构题目。

## 项目结构

```
leetcode/
├── problems/                    # 按算法类型分类的题目
│   ├── arrays-and-strings/      # 数组与字符串
│   ├── two-pointers/           # 双指针技巧
│   ├── sliding-window/         # 滑动窗口
│   ├── hash-table/            # 哈希表
│   ├── linked-list/           # 链表
│   ├── binary-tree/           # 二叉树
│   ├── dynamic-programming/    # 动态规划
│   ├── math/                  # 数学算法
│   ├── bit-manipulation/      # 位运算
│   └── stack-and-queue/       # 栈与队列
├── collections/               # 主题集合
│   ├── leetcode-75/          # LeetCode 75 经典题目
│   ├── daily-challenges/     # 每日一题
│   └── interview-questions/  # 面试题目
├── scripts/                  # 构建和测试脚本
│   ├── build.sh             # 编译脚本
│   └── test.sh              # 测试脚本
├── docs/                     # 文档
└── build/                    # 编译输出目录 (自动生成)
```

## 目录详细说明

### problems/ - 按算法类型分类

#### 数组与字符串 (arrays-and-strings/)

- `0004-median-of-two-sorted-arrays.cpp` - 寻找两个正序数组的中位数
- `0005-longest-palindromic-substring.cpp` - 最长回文子串
- `0006-zigzag-conversion.cpp` - Z 字形变换
- `0066-plus-one.cpp` - 加一
- `0498-diagonal-traverse.cpp` - 对角线遍历

#### 哈希表 (hash-table/)

- `0001-two-sum.cpp` - 两数之和 (经典哈希表应用)
- `0013-roman-to-integer.cpp` - 罗马数字转整数

#### 链表 (linked-list/)

- `0002-add-two-numbers.cpp` - 两数相加 (链表数学运算)

#### 滑动窗口 (sliding-window/)

- `0003-longest-substring-without-repeating-characters.cpp` - 无重复字符的最长子串

#### 动态规划 (dynamic-programming/)

- `0010-regular-expression-matching.cpp` - 正则表达式匹配 (字符串 DP 经典问题)

#### 数学算法 (math/)

- `0007-reverse-integer.cpp` - 整数反转
- `0009-palindrome-number.cpp` - 回文数
- `0060-permutation-sequence.cpp` - 排列序列
- `0149-max-points-on-line.cpp` - 直线上最多的点数 (几何算法)

### collections/ - 主题集合

#### LeetCode 75 (leetcode-75/)

精选的 75 道必刷题目，采用标准命名格式：

- `0011-container-with-most-water.cpp` - 盛最多水的容器
- `0151-reverse-words-in-string.cpp` - 翻转字符串里的单词
- `0238-product-of-array-except-self.cpp` - 除自身以外数组的乘积
- `0283-move-zeroes.cpp` - 移动零
- `0334-increasing-triplet-subsequence.cpp` - 递增的三元子序列
- `0345-reverse-vowels-of-string.cpp` - 反转字符串中的元音字母
- `0392-is-subsequence.cpp` - 判断子序列
- `0443-string-compression.cpp` - 压缩字符串
- `0605-can-place-flowers.cpp` - 种花问题
- `0724-find-pivot-index.cpp` - 寻找数组的中心下标
- `0739-daily-temperatures.cpp` - 每日温度
- `1071-greatest-common-divisor-of-strings.cpp` - 字符串的最大公因子
- `1207-unique-number-of-occurrences.cpp` - 独一无二的出现次数
- `1431-kids-with-greatest-number-of-candies.cpp` - 拥有最多糖果的孩子
- `1456-maximum-number-of-vowels-in-substring.cpp` - 定长子串中元音的最大数目
- `1657-determine-if-two-strings-are-close.cpp` - 确定两个字符串是否接近
- `1679-max-number-of-k-sum-pairs.cpp` - K 和数对的最大数目
- `1732-find-highest-altitude.cpp` - 找到最高海拔
- `1768-merge-strings-alternately.cpp` - 交替合并字符串
- `2215-find-difference-of-two-arrays.cpp` - 找出两数组的不同
- `2352-equal-row-and-column-pairs.cpp` - 相等行列对
- `2390-removing-stars-from-string.cpp` - 从字符串中移除星号

#### 每日挑战 (daily-challenges/)

- `1004-max-consecutive-ones-iii.cpp` - 最大连续 1 的个数 III
- `1493-longest-subarray-after-deleting-one-element.cpp` - 删掉一个元素以后全为 1 的最长子数组

#### 面试题目 (interview-questions/)

- `height-checker.cpp` - 高度检查器 (数组排序比较)
- `find-largest-value-in-each-tree-row.cpp` - 二叉树每层最大值 (层序遍历)
- `mixed-problems.cpp` - 混合问题集合 (链表操作、位运算、博弈论等)

## 技术特点

### 编程语言与标准

- **主要语言**: C++
- **标准**: C++17 及以上
- **编译器支持**: GCC 7+, Clang 5+, MSVC 2017+

### 算法分类覆盖

1. **数据结构**: 数组、链表、栈、队列、哈希表、树
2. **算法技巧**: 双指针、滑动窗口、前缀和、单调栈
3. **算法思想**: 动态规划、贪心算法、分治算法、回溯算法
4. **数学算法**: 位运算、数论、几何算法
5. **字符串算法**: 模式匹配、字符串处理

### 代码特点

- 统一的文件命名规范 (`问题编号-问题描述.cpp`)
- 每个解决方案包含完整的测试用例
- 代码注释清晰，便于理解算法思路
- 采用标准的 LeetCode 题目格式
- 优化的时间和空间复杂度实现

## 快速开始

### 构建项目

#### 构建所有题目

```bash
./scripts/build.sh
```

#### 构建特定分类

```bash
./scripts/build.sh hash-table        # 构建哈希表相关题目
./scripts/build.sh leetcode-75       # 构建 LeetCode 75
```

#### 构建特定题目

```bash
./scripts/build.sh hash-table 0001   # 构建两数之和
./scripts/build.sh leetcode-75 1071  # 构建字符串最大公因子
```

### 运行测试

#### 运行所有测试

```bash
./scripts/test.sh
```

#### 运行特定分类测试

```bash
./scripts/test.sh hash-table
./scripts/test.sh leetcode-75
```

#### 运行特定题目测试

```bash
./scripts/test.sh 0001              # 运行两数之和测试
./scripts/test.sh hash-table 0001   # 运行特定分类中的题目
```

### 手动编译 (可选)

```bash
# 编译单个文件
g++ -std=c++17 -O2 -Wall -Wextra problems/hash-table/0001-two-sum.cpp -o build/0001-two-sum

# 运行
./build/0001-two-sum
```

## 学习路径建议

### 初学者路径 (1-2 个月)

1. **哈希表基础**: 从 `0001-two-sum.cpp` 开始
2. **数组操作**: 学习 `arrays-and-strings/` 中的基础题目
3. **字符串处理**: 掌握基本的字符串算法
4. **LeetCode 75 入门**: 选择标记为 Easy 的题目

### 进阶路径 (2-3 个月)

1. **双指针技巧**: 深入学习 `two-pointers/` 相关算法
2. **滑动窗口**: 掌握 `sliding-window/` 的核心思想
3. **动态规划入门**: 从简单的 DP 问题开始
4. **树和链表**: 学习基本的数据结构操作

### 高级路径 (3-6 个月)

1. **复杂动态规划**: 深入学习 `dynamic-programming/`
2. **高级数学算法**: 挑战 `math/` 中的几何和数论问题
3. **系统刷题**: 完成整个 `leetcode-75/` 集合
4. **面试准备**: 重点练习 `interview-questions/`

### 专项强化

- **每日练习**: 跟进 `daily-challenges/` 保持手感
- **算法竞赛**: 挑战高难度的数学和动态规划问题
- **面试冲刺**: 系统练习 `interview-questions/` 和热门题目

## 项目管理

### 代码质量标准

- 遵循 C++ 编码规范 (Google Style Guide)
- 变量命名清晰有意义
- 时间和空间复杂度在注释中说明
- 包含边界条件处理
- 提供多组测试用例验证正确性

### 贡献指南

1. 新增题目应归类到合适的算法分类目录
2. 使用标准命名格式: `问题编号-问题描述.cpp`
3. 保持代码风格一致性
4. 包含完整的测试用例和预期输出
5. 添加必要的算法思路和复杂度分析注释
6. 更新相应的文档说明

### 文件命名规范

- 问题编号使用 4 位数字 (不足补零): `0001`, `0012`, `1234`
- 问题描述使用小写字母和连字符: `two-sum`, `longest-substring`
- 完整格式: `问题编号-问题描述.cpp`

## 版本信息

- **创建日期**: 2025 年 8 月
- **最后更新**: 2025 年 8 月 26 日
- **重构版本**: v2.0 (按算法类型重新组织)
- **题目总数**: 60+ 道经典算法题
- **代码行数**: 3000+ 行高质量 C++ 代码
- **支持平台**: Linux, macOS, Windows

## 更新日志

### v2.0 (2025-08-26)

- 重构项目结构，按算法类型分类
- 统一文件命名规范
- 添加自动化构建和测试脚本
- 优化项目文档结构
- 改进代码质量和注释

### v1.0 (2025-08-25)

- 初始版本，基础题目收集
- 按来源分类组织 (daily, interview, study 等)

本项目持续更新维护，致力于为算法学习者提供高质量的代码参考和系统性的学习资源。
