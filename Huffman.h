/*
 *  This file includes functions about establishing an Huffman tree.
 */
#ifndef HUFFMANCODE_HPP_INCLUDED
#define HUFFMANCODE_HPP_INCLUDED
#define Code_End (-1)
#include "Global.h"
//namespace Huffman{

    void InitTree(HuffmanNode *HT,int &TreeRoot);//
    void DestroyTree(int &TreeRoot);//
    void CCreateTree(HuffmanNode *HT,int &TreeRoot);//
    void DCreateTree(std::string &InFile,int &TreeRoot,HuffmanNode *HT);//
    void HCode(int *code,sourcetype source,HuffmanNode *HT,int &TreeRoot);//
    //int HDecode(Global::buffertype buffer,Global::sourcetype &S);//-
    int FlagFull(int flag[],int TreeRoot);//
//}


#endif // HUFFMANCODE_HPP_INCLUDED
