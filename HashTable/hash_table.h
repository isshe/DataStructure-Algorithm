/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : hash_table.h
* Version      : v1.0.0
* Author       : i.sshe
* Github       : github.com/isshe
* Date         : 2016/03/26
* Description  :
* Function list: 1.
*                2.
*                3.
* History      :
\*=========================================================================*/

#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

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
typedef struct HASH_NODE_S_
{
    int                 data;
    struct HASH_NODE_S_ *prev;
    struct HASH_NODE_S_ *next;
}HASH_NODE_S;

typedef struct HASH_TABLE_S_
{
     HASH_NODE_S    *hash_node;
}HASH_TABLE_S;

/*=========================================================================*\
 * #function#                                                              *
\*=========================================================================*/


/*=====================================================================\
* Function   (名称): create_hash()
* Description(功能): 创建hash表,采用拉链法(链接法)插入用户数据
* Called By  (被调): 1.
* Call_B file(被文): 1.
* Calls list (调用): 1.
* Calls file (调文): 1.
* Input      (输入): 1. len: 哈希表中数组长度
*                    2. num: 用户数据个数
* Output     (输出): 1. 数组首地址
* Return     (返回): HASH_NODE_S *;
*         success  :
*         failure  :
* Change log (修改): 1.
* Others     (其他): 1.
\*=====================================================================*/
HASH_TABLE_S *create_hash_table(int len, int num);

/*=====================================================================\
* Function   (名称): destroy_hash_table()
* Description(功能): 销毁hash表, create的时候用了malloc, 所以要使用free销毁
* Called By  (被调): 1.
* Call_B file(被文): 1.
* Calls list (调用): 1.
* Calls file (调文): 1.
* Input      (输入): 1. HASH_NODE_S *
* Output     (输出): 1. void
* Return     (返回):
*         success  :
*         failure  :
* Change log (修改): 1.
* Others     (其他): 1.
\*=====================================================================*/
int destroy_hash_table(HASH_TABLE_S *hash_table, int mod_value);


/*=====================================================================\
* Function   (名称): realloc_hash_table()
* Description(功能): 重新分配hash表
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
HASH_NODE_S *realloc_hash_table(HASH_NODE_S *);


/*=====================================================================\
* Function   (名称): generate_mod_value()
* Description(功能): 除留余数法生成表长.d;
* Called By  (被调): 1.
* Call_B file(被文): 1.
* Calls list (调用): 1.
* Calls file (调文): 1.
* Input      (输入): 1. num : 数据个数
* Output     (输出): 1.
* Return     (返回):
*         success  :
*         failure  :
* Change log (修改): 1.
* Others     (其他): 1.
\*=====================================================================*/
int generate_mod_value(int num);


/*=====================================================================\
* Function   (名称): search_element()
* Description(功能): 查找元素
* Called By  (被调): 1.
* Call_B file(被文): 1.
* Calls list (调用): 1.
* Calls file (调文): 1.
* Input      (输入): 1. HASH_NODE_S *:  表头地址,
*                    2. value        :  要查找的元素的值.
* Output     (输出): 1.
* Return     (返回):
*         success  :
*         failure  :
* Change log (修改): 1.
* Others     (其他): 1.
\*=====================================================================*/
int search_element(HASH_TABLE_S *hash_table, int mod_value, int value);


/*=====================================================================\
* Function   (名称): insert_element()
* Description(功能): 插入元素
* Called By  (被调): 1.
* Call_B file(被文): 1.
* Calls list (调用): 1.
* Calls file (调文): 1.
* Input      (输入): 1. value: 元素值
* Output     (输出): 1.
* Return     (返回):
*         success  :
*         failure  :
* Change log (修改): 1.
* Others     (其他): 1.
\*=====================================================================*/
int insert_element(HASH_TABLE_S *hash_table, int hash_len, int value);


/*=====================================================================\
* Function   (名称): delete_element()
* Description(功能): 删除元素
* Called By  (被调): 1.
* Call_B file(被文): 1.
* Calls list (调用): 1.
* Calls file (调文): 1.
* Input      (输入): 1. value: 元素值
* Output     (输出): 1.
* Return     (返回):
*         success  :
*         failure  :
* Change log (修改): 1.
* Others     (其他): 1.
\*=====================================================================*/
int delete_element(HASH_TABLE_S *hash_table, int mod_value, int value);


/*=====================================================================\
* Function   (名称): print_hash_table()
* Description(功能): 打印hash表
* Called By  (被调): 1.
* Call_B file(被文): 1.
* Calls list (调用): 1.
* Calls file (调文): 1.
* Input      (输入): 1. HASH_NODE_S * : 表头地址
* Output     (输出): 1.
* Return     (返回):
*         success  :
*         failure  :
* Change log (修改): 1.
* Others     (其他): 1.
\*=====================================================================*/
void print_hash_table(HASH_TABLE_S *hash_table, int hash_len);


#ifdef __cplusplus
}
#endif

#endif

