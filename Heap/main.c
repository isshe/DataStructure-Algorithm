/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : main.c
* Version      : v1.0.0
* Author       : 初代
* Date         : 2016/03/27
* Description  :
* Function list: 1.
*                2.
*                3.
* History      :
\*=========================================================================*/

/*-----------------------------------------------------------*
 * 头文件                                                    *
 *-----------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"


/*-----------------------------------------------------------*
 * 函数实现                                                  *
 *-----------------------------------------------------------*/


int main(void)
{
    int         num = 0;
    int         *heap_array = NULL;
    int         option_num = 0;
    int         flag = 0;

    //输入数据个数
    printf("请输数据素个数:\n");
    scanf("%d", &num);
    clean_input_buf();

    //输入数据
    printf("请输入数据:\n");
    heap_array = input_data(num);

    flag = 1;
    while(flag)
    {
        clean_input_buf();
         printf("1.构成最小堆\n2.构成最大堆\n"
                 "3.最小堆升序排序\n4.最大堆升序排序\n"
                 "5.打印堆\n6.退出程序\n");
         printf("请选择:\n");
         scanf("%d", &option_num);

         switch(option_num)
         {
             case 1:
                 create_min_heap(heap_array, num);
                 print_heap(heap_array, num);
                 break;
             case 2:
                 create_max_heap(heap_array, num);
                 print_heap(heap_array, num);
                 break;
             case 3:
                 min_heap_up_sort(heap_array, num);
                 break;
             case 4:
                 max_heap_up_sort(heap_array, num);
                 break;
             case 5:
                 print_heap(heap_array, num);
                 break;
             case 6:
                 flag = 0;
                 break;
             default:
                 break;
         }
    }

    heap_destroy(heap_array);

    return 0;
}
