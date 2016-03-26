/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : hash_table.c
* Version      : v1.0.0
* Author       : 初代
* Date         : 2016/03/26
* Description  :
* Function list: 1.
*                2.
*                3.
* History      :
\*=========================================================================*/

/*-----------------------------------------------------------*
 * 头文件                                                    *
 *-----------------------------------------------------------*/
#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------------------------------------*
 * 函数实现                                                  *
 *-----------------------------------------------------------*/

/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/03/26
* Others     (其他):
\*=======================================================================*/

HASH_TABLE_S *create_hash_table(int len, int num)
{
    HASH_TABLE_S     *hash_table = NULL;
    int             i = 0;
    int             tempvalue = 0;

    hash_table = (HASH_TABLE_S *)malloc(len * sizeof(HASH_TABLE_S));
    if (hash_table == NULL)
    {
         printf("hash table malloc error!\n");
         exit(1);
    }
    memset(hash_table, 0, len * sizeof(HASH_TABLE_S));

    //还要增加用户输入数据, 重复的需要链接到后面
    printf("请输入数据:\n");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &tempvalue);
        insert_element(hash_table, len, tempvalue);
    }

    return hash_table;
}



/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/03/26
* Others     (其他): 寻找<num的最大质数
\*=======================================================================*/
int generate_mod_value(int num)
{
     int i = 0;
     int j = 0;
     int temp = 0;
     int flag = 0;

     for (i = num; i > 2; i--)
     {
         flag = 1;
         for (j = 2; j <= i/2; j++)
         {
              if(i % j == 0)     //不是质数
              {
                  flag = 0;
                  break;
              }
         }

         if (flag == 1)
         {
              temp = i;
              break;
         }
     }
 //    temp = i;
     if (num < 4)
     {
          temp = num;
     }

     printf("除留余数法取得的mod值为:%d\n", temp);

     return temp;
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/03/26
* Others     (其他):
\*=======================================================================*/
int insert_element(HASH_TABLE_S *hash_table, int hash_len, int value)
{
    int         position_num = value % hash_len;
    HASH_NODE_S *node ;

    if (search_element(hash_table, hash_len, value))
    {
        return 0;
    }

    node = (HASH_NODE_S *)malloc(sizeof(HASH_NODE_S));
    if (node == NULL)
    {
        printf("insert element malloc error!\n");
        exit(1);
    }

    node->data = value;

    if (hash_table[position_num].hash_node != NULL)     //冲突了
    {
         node->next = hash_table[position_num].hash_node;
         hash_table[position_num].hash_node->prev = node;
         hash_table[position_num].hash_node = node;
         node->prev = NULL;
    }
    else
    {
        hash_table[position_num].hash_node = node;
    }

    return 1;
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/03/26
* Others     (其他):
\*=======================================================================*/
void print_hash_table(HASH_TABLE_S *hash_table, int hash_len)
{
    int         i = 0;
    HASH_NODE_S *current_node;

    for (i = 0; i < hash_len; i++)
    {
        if (hash_table[i].hash_node == NULL)
        {
            printf("/\n");
            continue;
        }
        printf ("%d-->\t", i);

        current_node = hash_table[i].hash_node;
        for (; current_node != NULL; current_node = current_node->next)
        {
            if (current_node->next == NULL)
            {
                 printf("%d", current_node->data);
            }
            else
            {
                 printf("%d-->\t", current_node->data);
            }
        }
        printf("\n");
    }
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/03/26
* Others     (其他):
\*=======================================================================*/
int search_element(HASH_TABLE_S *hash_table, int mod_value, int value)
{
     HASH_NODE_S    *current_node = NULL;
    int             position_key = value % mod_value;

     current_node = hash_table[position_key].hash_node;
     while (current_node != NULL)
     {
          if (current_node->data == value)
          {
              return 1;
          }
          current_node = current_node->next;
     }

     return 0;
}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/03/26
* Others     (其他):
\*=======================================================================*/
int delete_element(HASH_TABLE_S *hash_table, int mod_value, int value)
{
     HASH_NODE_S        *current_node = NULL;
     int                position_key = value % mod_value;

     current_node = hash_table[position_key].hash_node;
     while (current_node != NULL)
     {
          if (current_node->data == value)
          {
              //此元素的第一个元素
              if (current_node->prev == NULL && current_node->next != NULL)
              {
                   hash_table[position_key].hash_node = current_node->next;
                   current_node->next->prev = NULL;
              }
              else if (current_node->prev != NULL && current_node->next == NULL)
              {
                   // 此元素是最后一个元素
                   current_node->prev->next = NULL;
              }
              else  if(current_node->prev != NULL && current_node->next != NULL)
              {
                  //此元素是中间的元素
                  current_node->prev->next = current_node->next;
                  current_node->next->prev = current_node->prev;
              }
              else
              {
                   //只剩一个元素
                   hash_table[position_key].hash_node = NULL;
              }

              free(current_node);
              printf("删除成功!\n");
              return 1;
          }
          current_node = current_node->next;
     }

     printf("没有此元素!\n");
     return 0;

}


/*======================================================================\
* Author     (作者): i.sshe
* Date       (日期): 2016/03/26
* Others     (其他):
\*=======================================================================*/
int destroy_hash_table(HASH_TABLE_S *hash_table, int mod_value)
{
     HASH_NODE_S       *current_node = NULL;
     HASH_NODE_S       *next_node = NULL;
     int                i = 0;

     for (i = 0; i < mod_value; i++)
     {
         if(hash_table[i].hash_node == NULL)
         {
              continue;
         }
         else
         {
             current_node = hash_table[i].hash_node;
         }

         while (current_node->next != NULL)
         {
              next_node = current_node->next;
              free(current_node);
              current_node = next_node;
         }
         free(current_node);
     }

     free(hash_table);

     return 0;
}
