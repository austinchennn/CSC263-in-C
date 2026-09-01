

/*边节点定义
* adjvex  邻接点域，存储该顶点对应的下标
* EdgeNode*next 指向下一条边的指针（链表）
*/
typedef struct EdgeNode {
    int adjvex;  /* 邻接点域，存储该顶点对应的下标 */
    struct EdgeNode*next;  /* 指向下一条边的指针（链表） */
} EdgeNode;
