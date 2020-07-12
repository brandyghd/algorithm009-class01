学习笔记(排序算法c++，顺序从小到大)
1、冒泡排序
从头开始，每次比较两元素，若大者在前，则交换两元素，至数组末尾，此时最大元素为数组最后的元素；重复以上步骤，从头开始至上一轮比较的末尾元素；

void BubbleSort(int* h, size_t len)
{
    if(h==NULL) return;
    if(len<=1) return;
    //i是次数，j是具体下标
    for(int i=0;i<len-1;++i)
        for(int j=0;j<len-1-i;++j)
            if(h[j]>h[j+1])
                Swap(h[j],h[j+1]);
    return;
}
2、选择排序
搜索整个列表，找出最小项，若此项不为第1项，则与第1项交换位置；重复上述步骤，每次搜索未被排序的剩余列表，并将最小元素与已排序段的后一位交换，直至列表所有元素均被排序；
void selectSort(vector<int>& array){
    for (size_t i = 0; i < array.size(); i++){
        size_t minIndex = i;
        for (size_t j = i + 1; j < array.size(); j++){
            if (array[minIndex] > array[j]){
                minIndex = j;
            }
        }
        if (minIndex != i){
            swap(array[i], array[minIndex]);
        }
    }
}

