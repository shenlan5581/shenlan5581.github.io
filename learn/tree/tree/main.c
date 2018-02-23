/*
 *  一个简单的二叉树实现
 *    启动时 从文件读取并在内存中重建树
 *    推出时 将树的节点持久化到文件
 *
 * 
 *
 *  简单的操作：       
 *  创建节点       create <nodename> CHI or SIB where <nodenme>
 *  遍历显示树     traverse
 *  退出           exit
 *  查找父节点     search parent of "str"
 *  删除           delete "str"
 * 
 * 
*/

#include "tree.h"
#include "ser.h"

int main()
{
    init_cfg(&conf); //初始化路径
    
    // 创建树并写入文件
 /*   node tree;
    tree = malloc(SIZE) ;
    create(tree, "MAMA", ROOT);
    create(get_node(tree, "MAMA"), "XINGKE", CHILD);
    create(get_node(tree, "XINGKE"), "yaoyao", SIBLING);
    create(get_node(tree, "yaoyao"), "buding", CHILD);
    create(get_node(t
     ree, "XINGKE"), "yuxinji", CHILD);
    create(get_node(tree, "yuxinji"), "dd", CHILD);
    create(get_node(tree, "yuxinji"), "xinxia", SIBLING);
    create(get_node(tree, "buding"), "gg", SIBLING);
    save_tree(tree, conf.savepath); */ 

     node tree; 
     tree = createfromfile(conf.savepath);
     createfromfile(conf.savepath);            //从文件载入  
     operatorbycommand(tree);                  //执行命令
     traverse(tree);
     node p = get_parent_node(tree,"gg");
     cout(p->name);
}
