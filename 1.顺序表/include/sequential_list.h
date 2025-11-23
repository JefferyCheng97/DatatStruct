#pragma once
#include <iostream>

// 定义元素类型，使用 using 比 #define 更安全
using eleType = int;

// 顺序表结构体定义
struct SequentialList
{
    eleType* elements;  // 动态数组指针
    int size;           // 当前元素个数
    int capacity;       // 当前容量
};

// 初始化顺序表
void initializeList(SequentialList* list, int capacity);

// 销毁顺序表
void destroyList(SequentialList* list);

// 获取顺序表的大小
int getSize(SequentialList* list);

// 判断顺序表是否为空
bool isEmpty(SequentialList* list);

// 在指定位置插入元素（0 ~ size）
void insertElement(SequentialList* list, int index, eleType element);

// 删除指定位置的元素（0 ~ size-1）
void deleteElement(SequentialList* list, int index);

// 查找元素的位置, 返回第一个匹配元素的索引, 未找到返回 -1
int findElement(SequentialList* list, eleType element);

// 获取指定位置的元素（带边界检查）
eleType getElement(SequentialList* list, int index);

// 更新指定位置的元素（带边界检查）
void updateElement(SequentialList* list, int index, eleType value);


