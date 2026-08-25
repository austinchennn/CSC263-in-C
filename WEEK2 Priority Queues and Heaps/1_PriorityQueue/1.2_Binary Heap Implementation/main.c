#include <stdio.h>
#include "pq.h"

int main() {
    // 1. 创建一个容量为 10 的最大优先队列
    MaxPQ *pq = createMaxPQ(10);
    printf("--- Priority Queue Initialized ---\n\n");

    // 2. 插入测试数据：insert(pq, val, priority)
    // 我们用 val 代表任务ID，priority 代表任务紧急程度
    printf("Inserting tasks...\n");
    insert(pq, 101, 10); // 插入后：数组 [0] 是任务101(p=10)
    insert(pq, 102, 30); // 插入后：触发上浮，数组 [0] 变成 102(p=30)，[1] 是 101(p=10)
    insert(pq, 103, 20); // 插入后：无需上浮，数组 [2] 是 103(p=20)
    insert(pq, 104, 5);  // 插入后：无需上浮，数组 [3] 是 104(p=5)
    insert(pq, 105, 40); // 插入后：连跨两级上浮，夺得根节点位置！
    
    /* 
     此时底层的数组大概长这样：
     [0]: 105 (p=40) -> 根节点，最大
     [1]: 102 (p=30)
     [2]: 103 (p=20)
     [3]: 104 (p=5)
     [4]: 101 (p=10)
    */

    // 3. 测试 find_max
    printf("\nCurrent Max Item (find_max): %d\n", find_max(pq)); // 应该输出 105

    // 4. 测试 increase_key
    // 我们来看看下标 3 的位置，原本是任务 104（优先级极其低下，只有 5）
    // 现在我们模拟突发急诊，把下标为 3 的任务，优先级拉满到 100！
    printf("\nIncreasing priority of index 3 (Task 104) to 100...\n");
    increase_key(pq, 3, 100); 

    // 5. 持续抽出最大值，测试 extract_max 的下沉能力
    printf("\n--- Extracting all tasks --- \n");
    
    // 我们只要看每次拿出来的任务ID，是不是严格按照目前的优先级高低排列的
    while (pq->size > 0) {
        int task_id = extract_max(pq);
        printf("Extracted Task ID: %d\n", task_id);
    }
    
    /* 
     预期的输出顺序应该是：
     104 (因为它的 p 被提拔到了 100)
     105 (p=40)
     102 (p=30)
     103 (p=20)
     101 (p=10)
    */

    // 6. 释放内存
    free_pq(pq);
    printf("\nMemory freed successfully. Done!\n");

    return 0;
}