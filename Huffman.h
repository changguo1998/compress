/*
 *  This file includes functions about establishing an Huffman tree.
 */
#ifndef HUFFMANCODE_HPP_INCLUDED
#define HUFFMANCODE_HPP_INCLUDED
#define Code_End (-1)
namespace Huffman{
    int InitTree(void);
    int DestroyTree(void);
    int CCreateTree(void);
    int DCreateTree(void);
    int HCode(int *code,Global::sourcetype source);
    int HDecode(Global::buffertype buffer,Global::sourcetype &S);
    int FlagFull(int flag[]);
}


#endif // HUFFMANCODE_HPP_INCLUDED
