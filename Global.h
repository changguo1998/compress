#ifndef GLOBAL_HPP_INCLUDED
#define GLOBAL_HPP_INCLUDED
#include <iostream>
#include <fstream>
#include "Huffman.h"
    typedef char sourcetype;
    typedef char codetype;
    typedef char buffertype;

//namespace Global{
    struct HuffmanNode{
        sourcetype content;
        int parent,lchild,rchild;
        double weight;
    };
    const int BYTE_NUM = sizeof(sourcetype);
    const int BIT_NUM = 8*BYTE_NUM;
    const int CODE_TYPE_NUM = 256;
    const int TREE_NODE_NUM = 2*CODE_TYPE_NUM;

    const enum status{Ok,File_Not_Ready,Calcu_Error}


//}//namespace
#endif // GLOBAL_HPP_INCLUDED
