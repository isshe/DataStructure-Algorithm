/*=========================================================================\
* Copyright(C)2016 Chudai.
*
* File name    : main.c
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
#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

/*-----------------------------------------------------------*
 * 函数实现                                                  *
 *-----------------------------------------------------------*/
//hash表中的数据使用了int类型, 如何才能使程序能用多类型能?
int main(void)
{
    int             num = 0;
    int             *data;
    int             i = 0;
    int             hash_array_len = 0;
    HASH_TABLE_S    *hash_table = NULL;
    int             user_select = 0;
    int             flag = 0;
    int             value = 0;


    printf ("请输入数据个数:\n");
    scanf("%d", &num);
    if (num <= 0)
    {
        printf("输入数据个数小于等于0!\n");
        exit(1);
    }

    //用除留余数法算hash数组的长度d
    hash_array_len = generate_mod_value(num);
    //利用d创建hash表
    hash_table = create_hash_table(hash_array_len, num);

    //打印hash表
    print_hash_table(hash_table, hash_array_len);

    flag = 1;
    while (flag)
    {
        printf("1.查找元素\n2.插入元素\n3.删除元素\n4.打印hash表\n5.退出程序\n");
        printf("选择操作:\n");
        scanf("%d", &user_select);
        switch(user_select)
        {
            case 1:
                printf("输入要查找元素:\n");
                scanf("%d", &value);
                if (search_element(hash_table, hash_array_len, value))
                {
                    printf("找到%d!\n", value);
                }
                else
                {
                    printf("未找到!\n");
                }
//                print_hash_table(hash_table, hash_array_len);
                break;
            case 2:
                printf("输入要插入元素:\n");
                scanf("%d", &value);
                if (insert_element(hash_table, hash_array_len, value))
                {
                     printf("插入新元素!\n");
                }
                else
                {
                    printf("插入元素失败或已经存在此元素!\n");
                }
                break;
            case 3:
                printf("输入要删除的元素:\n");
                scanf("%d", &value);
                delete_element(hash_table, hash_array_len, value);
//                print_hash_table(hash_table, hash_array_len);
                break;
            case 4:
                print_hash_table(hash_table, hash_array_len);
                break;
            case 5:
                flag = 0;
                //
                break;
            default:
                break;
        }
    }
    //销毁hash表及其他malloc的东西.
    destroy_hash_table(hash_table, hash_array_len);

    return 0;
}
