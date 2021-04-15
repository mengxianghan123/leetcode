## 1.题目
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。  
candidates 中的每个数字在每个组合中只能使用一次。  

说明：  
所有数字（包括目标数）都是正整数。  
解集不能包含重复的组合。   

示例 1:  
```
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
```

示例 2:  
```
输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
```

---

## 2.分析
先记录个感悟，v1版本运行用时1300ms，v2版本运行用时8ms，真的很好笑。这么简单的功能写出来就会有100倍以上的速度差距。要知道速度差距往往与数据量成比例，如果数据量大，这个差距会比100倍更大。感觉如果自己写一个复杂的系统，可能就是一座“屎山”。  
与题目47一样，也是在原有代码的基础上考虑数据重复的情况。假如我有一组数，排序后为：[1,2,2,3,3]，假如我已经选择了1，当选择第一个2时，后续所有可能组合为[2,3,3]的组合+已选的[1,2]；如果选择第二个2时，后续所有可能组合为[3,3]的组合+已选的[1,2]。可以看到，当我选择第一个2，递归后得到的所有组合已经包含了选择第二个2的所有组合情况。因此可以continue掉第二个2，不重不漏。  
这个道理与47题的道理相通。  