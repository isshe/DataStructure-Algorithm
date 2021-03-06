/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : QuickSort3Way.c
* Version      : v1.0.0
* Author       : 初代
* Date         : 2016/05/15
* Description  :
* Function list: 1.
*                2.
*                3.
* History      :
\*=========================================================================*/

/*-----------------------------------------------------------*
 * 头文件                                                    *
 *-----------------------------------------------------------*/

/*-----------------------------------------------------------*
 * 外部变量说明                                              *
 *-----------------------------------------------------------*/

/*-----------------------------------------------------------*
 * 外部函数原型说明                                          *
 *-----------------------------------------------------------*/

/*-----------------------------------------------------------*
 * 内部函数原型说明                                          *
 *-----------------------------------------------------------*/

/*-----------------------------------------------------------*
 * 全局变量                                                  *
 *-----------------------------------------------------------*/

/*-----------------------------------------------------------*
 * 模块级变量                                                *
 *-----------------------------------------------------------*/

/*-----------------------------------------------------------*
 * 常量定义                                                  *
 *-----------------------------------------------------------*/

/*-----------------------------------------------------------*
 * 宏定义                                                    *
 *-----------------------------------------------------------*/

/*-----------------------------------------------------------*
 * 函数实现                                                  *
 *-----------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

void exchange(int *array, int x, int y)
{
     int temp = array[x];
     array[x] = array[y];
     array[y] = temp;
}

void quick_sort3way(int *array, int left, int right)
{
    int lt = 0;
    int i = 0;
    int gt = 0;
    int v = 0;

    if (left >= right)
    {
         return ;
    }

    v = array[left];        //选择的元素
    lt = left;
    i = left + 1;
    gt = right;

    while (i <= gt)
    {
         if (array[i] < v)
         {
             exchange(array, lt, i);
             lt++;
             i++;
         }
         else if (array[i] > v)
         {
              exchange(array, i, gt);
              gt--;
//              i++;
         }
         else
         {
              i++;
         }
    }

    quick_sort3way(array, left, lt - 1);
    quick_sort3way(array, gt + 1, right);
}
