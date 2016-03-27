/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : heap.h
* Version      : v1.0.0
* Author       : i.sshe
* Github       : github.com/isshe
* Date         : 2016/03/27
* Description  :
* Function list: 1.
*                2.
*                3.
* History      :
\*=========================================================================*/

#ifndef HEAP_H_
#define HEAP_H_

#ifdef __cplusplus
extern "C"{
#endif

/*=========================================================================*\
 * #include#                                                               *
\*=========================================================================*/

/*=========================================================================*\
 * #define#                                                                *
\*=========================================================================*/

/*=========================================================================*\
 * #enum#                                                                  *
\*=========================================================================*/

/*=========================================================================*\
 * #struct#                                                                *
\*=========================================================================*/

/*=========================================================================*\
 * #function#                                                              *
\*=========================================================================*/


/*=====================================================================\
* Function   (名称): clean_input_buf()
* Description(功能): 清除输入缓冲区
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
void clean_input_buf();


/*=====================================================================\
* Function   (名称): input_data()
* Description(功能): 用户输入数据
* Called By  (被调): 1.
* Call_B file(被文): 1.
* Calls list (调用): 1.
* Calls file (调文): 1.
* Input      (输入): 1. num : 要输入数据的个数
* Output     (输出): 1.
* Return     (返回): int * : 指向数组的指针
*         success  :
*         failure  :
* Change log (修改): 1.
* Others     (其他): 1.
\*=====================================================================*/
int *input_data(int num);


/*=====================================================================\
* Function   (名称): print_heap()
* Description(功能): 输出堆
* Called By  (被调): 1.
* Call_B file(被文): 1.
* Calls list (调用): 1.
* Calls file (调文): 1.
* Input      (输入): 1.
* Output     (输出): 1.
* Return     (返回): void
*         success  :
*         failure  :
* Change log (修改): 1.
* Others     (其他): 1.
\*=====================================================================*/
void print_heap(int *heap_array, int len);



/*=====================================================================\
* Function   (名称): heap_destroy()
* Description(功能): 销毁堆, malloc的内存
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
int heap_destroy(int *heap_array);


/*=====================================================================\
* Function   (名称): create_min_heap()
* Description(功能): 创建最小堆
* Called By  (被调): 1.
* Call_B file(被文): 1.
* Calls list (调用): 1.
* Calls file (调文): 1.
* Input      (输入): 1. int *: 数组的首地址.
* Output     (输出): 1.
* Return     (返回):
*         success  : 1
*         failure  : 0
* Change log (修改): 1.
* Others     (其他): 1.
\*=====================================================================*/
int create_min_heap(int *heap_array, int len);


/*=====================================================================\
* Function   (名称): min_heap_up_sort()
* Description(功能): 最小堆升序排序
* Called By  (被调): 1.
* Call_B file(被文): 1.
* Calls list (调用): 1.
* Calls file (调文): 1.
* Input      (输入): 1.
* Output     (输出): 1.
* Return     (返回):
*         success  : 1
*         failure  : 0
* Change log (修改): 1.
* Others     (其他): 1.
\*=====================================================================*/
int min_heap_up_sort(int *heap_array, int len);


/*=====================================================================\
* Function   (名称): delete_root_and_sort()
* Description(功能):
* Called By  (被调): 1. min_heap_up_sort();
* Call_B file(被文): 1.
* Calls list (调用): 1.
* Calls file (调文): 1.
* Input      (输入): 1.
* Output     (输出): 1.
* Return     (返回):
*         success  :
*         failure  :
* Change log (修改): 1.
* Others     (其他): 1. 思想是: 先把根节点输出, 然后删除, 再把
*                       最后一个节点换到根位置, 再调整.一直循环此过程.
\*=====================================================================*/
void delete_root_and_sort(int heap_array, int len);



#ifdef __cplusplus
}
#endif

#endif

