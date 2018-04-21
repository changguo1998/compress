#include <iostream>
#include <fstream>
#include "Global.h"
#include "Huffman.h"

int Huffman::InitTree(void){
/*
 *initial the huffman tree
 */
    using namespace Global;
    int i;
    for(i=0; i<CODE_TYPE_NUM; i++){
        HT[i].lchild = HT[i].rchild = HT[i].parent = -1;
        HT[i].weight = 0;
        HT[i].content = sourcetype(i);
    }
    TreeRoot = i-1;
    return Global::Ok;
}

int Huffman::DestroyTree(void){
    Global::TreeRoot = -1;
    Global::TreeRoot = -1;
    return Global::Ok;
}

void Huffman::CCreateTree(void){
    int flag[Global::
}
