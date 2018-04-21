/*
 *  This file includes functions about establishing an Huffman tree.
 */
#ifndef HUFFMANCODE_HPP_INCLUDED
#define HUFFMANCODE_HPP_INCLUDED
namespace Huffman{
    int InitTree(void);
    int DestroyTree(void);
    int CCreateTree(void);
    int DCreateTree(void);
    int HCode(int *code,Global::sourcetype source);
    int HDecode(Global::buffertype buffer,Global::sourcetype &S);
}


#endif // HUFFMANCODE_HPP_INCLUDED
