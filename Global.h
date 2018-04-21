#ifndef GLOBAL_HPP_INCLUDED
#define GLOBAL_HPP_INCLUDED

#include <fstream>
    typedef char sourcetype;
    typedef char codetype;
    typedef char buffertype;

namespace Global{
    extern const int BYTE_NUM = sizeof(sourcetype);
    extern const int BIT_NUM = 8*BYTE_NUM;
    extern const int CODE_TYPE_NUM = 256;
    extern const int TREE_NODE_NUM = 2*CODE_TYPE_NUM;

    extern const enum status{Ok,File_Not_Ready}

    typedef struct{
        sourcetype content;
        int parent,lchild,rchild;
        double weight;
    } HuffmanNode;

    extern HuffmanNode HT[TREE_NODE_NUM];
    extern int TreeRoot=-1;
extern ifstream SourceFile;
extern ofstream CodedFile;
}//namespace
#endif // GLOBAL_HPP_INCLUDED
