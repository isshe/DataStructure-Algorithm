/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : heap.c
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
#include <string.h>

/*-----------------------------------------------------------*
 * 函数实现                                                  *
 *-----------------------------------------------------------*/


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/03/27
* Others     (其他): 清除输入缓冲区
\*=======================================================================*/
void clean_input_buf()
{
     int c = 0;

     while ((c = getchar()) != '\n' && c != EOF);
}

/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/03/27
* Others     (其他):
\*=======================================================================*/
int *input_data(int num)
{
     int i = 0;
     int *heap_array = NULL;

     //note: 从1开始, 第0位不用 &!, 分配多1个空间;
     heap_array = (int *)malloc((num + 1) * sizeof(int));
     if (heap_array == NULL)
     {
         fprintf(stderr, "heap_array malloc error!\n");
         exit(1);
     }

     for (i = 1; i < num + 1; i++)
     {
         scanf("%d", &heap_array[i]);
     }

//     heap_array[num + 1] = '\0';

     return heap_array;
}



/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/03/27
* Others     (其他):
\*=======================================================================*/
void print_heap(int *heap_array, int len)
{
     int i = 0;

     //注意是从1开始!
     for (i = 1; i < len + 1; i++)
     {
         printf("%d ", heap_array[i]);
     }
     printf("\n");
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/03/27
* Others     (其他):
\*=======================================================================*/
int heap_destroy(int *heap_array)
{
     if (heap_array != NULL)
     {
         free(heap_array);
     }

     return 0;
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/03/27
* Others     (其他): 交换两个元素
\*=======================================================================*/
void swap(int *heap_array, int x, int y)
{
    int temp        = heap_array[x];
    heap_array[x]   = heap_array[y];
    heap_array[y]   = temp;
}

/*=====================================================================\
* Function   (名称): siftdown()
* Description(功能): 向下调整成最小堆
* Called By  (被调): 1.
* Call_B file(被文): 1.
* Calls list (调用): 1.
* Calls file (调文): 1.
* Input      (输入): 1.
* Output     (输出): 1.
* Return     (返回):
*         success  :
*         failure  :
* Change log (修改): 1.
* Others     (其他): 1.
\*=====================================================================*/
static void siftdown(int *heap_array, int father, int len)
{
     int    left_child = 0;
     int    right_child = 0;
     int    min = 0;
     int    flag = 0;       //是否需要继续往下的标识, 为1不需要.

     while (father * 2 <= len && flag == 0)
     {
         left_child = father * 2;
         right_child = father * 2 + 1;

         if (left_child <= len)     //存在左节点
         {
             if (heap_array[left_child] < heap_array[father])
             {
    //              swap(heap_array, father, left_child);
                  min = left_child;
             }
             else
             {
                 min = father;
             }
         }

         if (right_child <= len)
         {
             if (heap_array[right_child] < heap_array[min])
             {
    //              swap(heap_array, father, right_child);
                  min = right_child;
             }
         }

         if (min != father)
         {
              swap(heap_array, father, min);
              father = min;                 //这句很重要, 相当于递归调用siftdown.
         }
         else
         {
              //因为是从下往上操作, 所以当前如果不需要位置改变的话,
              //也不需要往下测试, 因为, 下面是已经排序好的了.
              flag = 1;
         }

     }
}

/*=====================================================================\
* Function   (名称): max_siftdown()
* Description(功能): 向下调整成最大堆
* Called By  (被调): 1.
* Call_B file(被文): 1.
* Calls list (调用): 1.
* Calls file (调文): 1.
* Input      (输入): 1.
* Output     (输出): 1.
* Return     (返回):
*         success  :
*         failure  :
* Change log (修改): 1.
* Others     (其他): 1.
\*=====================================================================*/
static void max_siftdown(int *heap_array, int father, int len)
{
     int    left_child = 0;
     int    right_child = 0;
     int    min = 0;
     int    flag = 0;       //是否需要继续往下的标识, 为1不需要.

     while (father * 2 <= len && flag == 0)
     {
         left_child = father * 2;
         right_child = father * 2 + 1;

         if (left_child <= len)     //存在左节点
         {
             if (heap_array[left_child] > heap_array[father])
             {
    //              swap(heap_array, father, left_child);
                  min = left_child;
             }
             else
             {
                 min = father;
             }
         }

         if (right_child <= len)
         {
             if (heap_array[right_child] > heap_array[min])
             {
    //              swap(heap_array, father, right_child);
                  min = right_child;
             }
         }

         if (min != father)
         {
              swap(heap_array, father, min);
              father = min;                 //这句很重要, 相当于递归调用siftdown.
         }
         else
         {
              //因为是从下往上操作, 所以当前如果不需要位置改变的话,
              //也不需要往下测试, 因为, 下面是已经排序好的了.
              flag = 1;
         }
     }
}



/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/03/27
* Others     (其他):
\*=======================================================================*/
void create_min_heap(int *heap_array, int len)
{
    int     i = len/2;      //最后一个页节点的父节点.

    for (; i > 0; i--)      //不能=0!
    {
        siftdown(heap_array, i, len);
    }

}



/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/03/27
* Others     (其他):
\*=======================================================================*/
void create_max_heap(int *heap_array, int len)
{
     int    i = 0;

     for (i = len/2; i > 0; i--)
     {
          max_siftdown(heap_array, i, len);
     }

}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/03/27
* Others     (其他): 删除root节点
*                    输出根->把最后一个放到根->堆减1->调整, 一直循环.
\*=======================================================================*/
 void delete_root_and_sort(int *heap_array, int len)
{
     int temp_len = len;
     int temp = 0;
     int i = 0;

     for (i = 1; i < len + 1; i++)
     {
        temp = heap_array[1];
        heap_array[1] = heap_array[temp_len];
        temp_len--;
        siftdown(heap_array, 1, temp_len);
        printf("%d ", temp);
     }
     printf("\n");

}

/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/03/27
* Others     (其他): 删除root节点
*                    输出根->把最后一个放到根->堆减1->调整, 一直循环.
\*=======================================================================*/
 void max_delete_root_and_sort(int *heap_array, int len)
{
     int temp_len = len;
     int temp = 0;
     int i = 0;

     for (i = 1; i < len + 1; i++)
     {
        temp = heap_array[1];
        heap_array[1] = heap_array[temp_len];
        heap_array[temp_len] = temp;
        temp_len--;
        max_siftdown(heap_array, 1, temp_len);
//        heap_array[]
//        printf("%d ", temp);
     }

     for (i = 1; i < len + 1; i++)
     {
          printf("%d ", heap_array[i]);
     }
     printf("\n");

}



/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/03/27
* Others     (其他):
\*=======================================================================*/
int min_heap_up_sort(int *heap_array, int len)
{
     int    *temp_array = NULL;
     int    i = 0;

     //先生成最小堆
     create_min_heap(heap_array, len);

     //注意: 这里也要分配多一个单元的内存.
     temp_array = (int *)malloc((len + 1)* sizeof(int) );
     if (temp_array == NULL)
     {
          printf("排序失败: 临时数组分配失败!\n");
          return 0;
     }

     for (i = 1; i < len + 1; i++)
     {
          temp_array[i] = heap_array[i];
     }

     //下面排序
     //输出根->把最后一个放到根->堆减1->调整, 一直循环.
     delete_root_and_sort(temp_array, len);

     return 1;
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/03/27
* Others     (其他):
\*=======================================================================*/
int max_heap_up_sort(int *heap_array, int len)
{
     int    *temp_array = NULL;
     int    i = 0;

     //先生成最小堆
     create_max_heap(heap_array, len);

     //注意: 这里也要分配多一个单元的内存.
     temp_array = (int *)malloc((len + 1)* sizeof(int) );
     if (temp_array == NULL)
     {
          printf("排序失败: 临时数组分配失败!\n");
          return 0;
     }

     for (i = 1; i < len + 1; i++)
     {
          temp_array[i] = heap_array[i];
     }

     //下面排序
     //输出根->把最后一个放到根->堆减1->调整, 一直循环.
     max_delete_root_and_sort(temp_array, len);

     return 1;

}
