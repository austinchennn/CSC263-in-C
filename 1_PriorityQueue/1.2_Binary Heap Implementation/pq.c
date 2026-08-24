#include "pq.h"
#include <stdio.h>
#include <stdlib.h>

// --- 内部辅助函数（对外隐藏） ---

static void swap(PQElement *a, PQElement *b) {
    PQElement temp = *a;
    *a = *b;
    *b = temp;
}

// 节点上浮：比较的核心是 priority
static void sift_up(MaxPQ *pq, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (pq->data[parent].priority >= pq->data[i].priority) {
            break; 
        }
        swap(&pq->data[parent], &pq->data[i]);
        i = parent; 
    }
}

// 节点下沉：比较的核心是 priority
static void sift_down(MaxPQ *pq, int i) {
    while (2 * i + 1 < pq->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = left;

        if (right < pq->size && pq->data[right].priority > pq->data[left].priority) {
            largest = right;
        }

        if (pq->data[i].priority >= pq->data[largest].priority) {
            break;
        }

        swap(&pq->data[i], &pq->data[largest]);
        i = largest;
    }
}

// --- 对外公开的核心接口 ---

MaxPQ *createMaxPQ(int capacity) {
    MaxPQ *pq = (MaxPQ*)malloc(sizeof(MaxPQ));
    pq->data = (PQElement*)malloc(sizeof(PQElement) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void free_pq(MaxPQ *pq) {
    if (pq != NULL) {
        free(pq->data);
        free(pq);
    }
}

// 插入新元素 val 和对应的 priority
void insert(MaxPQ *pq, int val, int priority) {
    if (pq->size == pq->capacity) {
        printf("Error: Priority Queue is full!\n");
        return;
    }
    
    pq->data[pq->size].item = val;
    pq->data[pq->size].priority = priority;
    
    sift_up(pq, pq->size);
    pq->size++;
}

// 返回优先级最高的元素 (item)
int find_max(MaxPQ *pq) {
    if (pq->size == 0) {
        printf("Error: Priority Queue is empty!\n");
        return -1; 
    }
    return pq->data[0].item; 
}

// 取出并返回优先级最高的元素 (item)
int extract_max(MaxPQ *pq) {
    if (pq->size == 0) {
        printf("Error: Priority Queue is empty!\n");
        return -1;
    }
    
    int max_item = pq->data[0].item; 
    
    pq->data[0] = pq->data[pq->size - 1]; 
    pq->size--; 
    
    sift_down(pq, 0); 
    
    return max_item;
}

// 直接根据数组下标 index 修改优先级
void increase_key(MaxPQ *pq, int index, int new_priority) {
    // 边界检查
    if (index < 0 || index >= pq->size) {
        printf("Error: Index out of bounds!\n");
        return;
    }

    // 检查新优先级是否真的比老优先级大
    if (new_priority <= pq->data[index].priority) {
        printf("Error: New priority must be strictly greater than current priority!\n");
        return;
    }

    // 更新优先级，触发上浮
    pq->data[index].priority = new_priority;
    sift_up(pq, index);
}