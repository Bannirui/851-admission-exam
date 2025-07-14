//
// Created by dingrui on 2024/6/28.
//

#pragma once

typedef struct MyTreeNode
{
    int                val;
    struct MyTreeNode* left;
    struct MyTreeNode* right;
} MyTreeNode;

/**
 * 实例化节点.
 */
MyTreeNode* TreeNodeInit();
/**
 * 实例化节点 指定值
 * @param val 指定的值
 */
MyTreeNode* TreeNodeInitWithVal(int val);
int         InorderSerial(MyTreeNode* t, int arr[]);
/**
 * 给定数组 以中序遍历的顺序反序列化为二叉树.
 * @param arr 数组
 * @param sz 数组长度
 */
MyTreeNode* InorderDeserial(int* arr, int sz);