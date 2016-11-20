/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : BottomUpMS.c
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


void bottom_up_merge_sort(int *a, int *b, int len)
{
     int    sz = 0;             //size:间隔:2, 4, 8...
     int    lo = 0;
     int    hi = 0;
     int    N = len;

     for (sz = 1; sz < N; sz = sz + sz)       //1+1=2, 2+2=4...控制间隔
     {
         for (lo = 0; lo < N - sz; lo += sz + sz)　     //控制次数
         {
             hi = (lo + sz + sz -1) < (N - 1) ? (lo + sz + sz -1) : (N -1);
              merge(a, b, lo, lo+sz-1, hi);
         }
     }
}
