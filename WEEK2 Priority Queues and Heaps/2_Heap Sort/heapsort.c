void swap(int a[i], int b[i]) {
    int temp = a[i];
    a[i] = b[i];
    b[i] = temp;
}

void  DownAdjust(int a[], int k, int n){
    int i = k; //当前需要下沉的节点（父节点）
    int j = 2*i; //左孩子节点
    while (j <= n) { //左孩子存在
        if (j+1 <= n && a[j+1] > a[j]) { //右孩子存在（j+1 <= n） 且 大于左孩子（a[j+1] > a[j]）
            j = j++; //j指向右孩子
        }
        if (a[i] < a[j]){ //父节点小于孩子节点，交换
            swap(a[i], a[j]); //交换父子节点
            i = j; //交换后，子节点变成需要下沉的节点（新父节点）
            j = 2*i; //更新 子节点的左孩子节点（新左孩子节点）

        } else { //a[i] >= a[j]调整完毕
        break; //没有左孩子，i是叶节点，直接退出
    }
}


void HeapSort(int a[], int n) {
    //1.建堆 - 从最后一个非叶子节点开始依次向下调整
    for (int i = n/2; i >= 1; i--) {
        DownAdjust(a, i, n);
    }

    //2.排序 - 每轮堆定换到数组末尾，向下调整新的堆顶
    for (int i = n; i >= 2; i--) {
        swap(a[1], a[i]); //交换堆顶元素a[1] 和 当前堆的最后一个元素a[i]
        DownAdjust(a, 1, i-1); //对新的堆顶元素进行下沉调整， 还剩下i-1个元素

    }
}