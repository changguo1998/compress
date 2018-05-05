/*
 *This file contains functions about compressing.
 */
#ifndef COMPRESS_HPP_INCLUDE
#define COMPRESS_HPP_INCLUDE

#include <string>
//#include "Global.h"
//namespace Code{
//code
//using namespace std;
    void Coding(std::string &InFile,std::string &OutFile,int &TreeRoot,HuffmanNode *HT);//+
    void Statistic(std::string &InFile,int &TreeRoot,HuffmanNode *HT);//+

//decode
    void Decoding(std::string &InFile,std::string &OutFile,int &TreeRoot,HuffmanNode *HT);//+
//}
#endif // COMPRESS_HPP_INCLUDE
