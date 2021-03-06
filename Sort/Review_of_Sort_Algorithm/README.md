## 在练习排序类题目前，先回顾下经典的排序算法

---

## 1.快速排序
如果我要对一个序列进行快速排序，先选择一个基准值，给这个基准值找到其正确的位置，即，序列中比它小的都在它左边，序列中比它大的都在它右边。  
具体实现时，用双指针从序列两头往中间遍历。当基准值（一般是第一个数）确定后，把这个值赋给key，这个位置就空出来了，空位置留给尾指针找到的第一个比key小的值，此时尾指针对应的位置就空出来了，空位留给头指针找到的第一个比key大的值，此时头指针对应的位置就空出来了，后面循环重复，直到头尾指针重合。  
在双指针遍历过程中，已经遍历过的位置，一定可以保证：头指针左侧的值都比key小，头指针右侧的值都比key大，因此最后两指针重合时，对应一个空位，那个位置一定就是key值的正确位置。  

这里贴一下《leetcode101》的写法，比较漂亮。
```
void quick_sort(vector<int>& nums, int l, int r) {
  if (l + 1 >= r) {
    return;
  }
  int first = l, last = r - 1, key = nums[first];
  while (first < last) {
    while (first < last && nums[last] >= key) {
      --last;
    }
    nums[first] = nums[last];
    while (first < last && nums[first] <= key) {
      ++first;
    }
    nums[last] = nums[first];
  }
  nums[first] = key;
  quick_sort(nums, l, first);
  quick_sort(nums, first + 1, r);
}
```

---

## 2.归并排序
归并排序体现了一种分治思想，将一个序列进行排序，这问题我不会解决，但是我解决过将两个有序序列归并成一个有序序列的问题（双指针第88题）。那么怎么将两个子序列分别排序呢，只好再将每个子序列分成两个子序列，分别排序，归并。问题就这样传递下去，直到划分到只剩一个数，这个排序问题我会，直接返回该值就行，那么一个排序问题就被我分治开，最后变成归并问题，真的神奇。  
这里贴一下《leetcode101》的写法，比较漂亮。
```
void merge_sort(vector<int> &nums, int l, int r, vector<int> &temp) {
  if (l + 1 >= r) {
    return;
  }
  // divide
  int m = l + (r - l) / 2;
  merge_sort(nums, l, m, temp);
  merge_sort(nums, m, r, temp);
  // conquer
  int p = l, q = m, i = l;
  while (p < m || q < r) {
    if (q >= r || (p < m && nums[p] <= nums[q])) {
      temp[i++] = nums[p++];
    } else {
      temp[i++] = nums[q++];
    }
  }
  for (i = l; i < r; ++i) {
    nums[i] = temp[i];
  }
}
```

---

## 3.插入排序
插入排序是逐步将元素插入到已经排序好的序列中。思路非常简单，但是具体实现起来，并不需要在原序列外另外再构造一个序列，只需要在原序列上进行操作即可。  
对于原序列的第一个元素，已经排好序，此时第二个元素插入进来，要将其插入到已经排好序的序列中（即，第一个元素单独构成的序列）。只需要将其与前面每个元素比较，如果被插元素小了就说明没到它的位置，需要往前移，如果被插元素大说明它已经到达自己的位置。  
感觉插入排序虽然原理非常清晰，但是具体实现起来还是挺讲究的。  

---

## 4.冒泡排序
冒泡排序要遍历n次序列，每次遍历将序列的乱序部分的最大值放到乱序序列的最后。至于怎么筛选最大以及放到最后的，就是通过相邻数据两两比较，让较大值在后面。  
思路也是非常简单，具体实现起来时，可以留意一下终止条件：当某一次遍历时，乱序部分都有序，那么就说明排序完成，提前终止循环即可。  

---

## 5.选择排序
这个可能是最直观的一种排序方法，每次选出没排序序列中的最小的。感觉其内核与冒泡排序是一样的，但是具体实现方式有所不同，选择排序感觉比冒泡排序还要直观。  
如果要选择出vector最小/最大值可以用min_element/max_element函数，位于algorithm下  
