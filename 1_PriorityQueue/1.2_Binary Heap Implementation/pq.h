#ifndef PQ_H
#define PQ_H

#include <stdbool.h>

typedef struct {
    int item;
    int priority;
} PQElement;

typedef struct {
    PQElement *data; 
    int size;
    int capacity;
} MaxPQ;

MaxPQ *createMaxPQ(int capacity);
void free_pq(MaxPQ *pq);

int find_max(MaxPQ *pq);
void insert(MaxPQ *pq, int val, int priority);
int extract_max(MaxPQ *pq);
void increase_key(MaxPQ *pq, int index, int new_priority);

#endif 