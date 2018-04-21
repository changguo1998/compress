#include <iostream>
#include <fstream>
#include "Global.h"
#include "Huffman.h"
#include "code&decode.h"
using namespace std;
int Code::Coding(void){
/*
 *  This function will be called when the user want to compress a file.
 *  This is like an "main" function for all functions abort conpress
 */
    using namespace Huffman;
    if( !(Global::SourceFile.is_open()&&Global::CodedFile.is_open()) )
        return Global::File_Not_Ready;
    InitTree();
    Global::Statistic();
    CCreateTree();
//begin to code the file
    int code[CODE_TYPE_NUM];
    SourceFile.clear(ios::goodbit);
    SourceFile.seekg(ios::beg);//rewind the file pointer
    CodedFile.write(HT,8*TREE_NODE_NUM*sizeof(HuffmanNode));
    sourcetype source;
    buffertype buf_low,buf_high;
    int buf_bit=0;
    while(SourceFile.eof()){
        SourceFile.read(source,sizeof(source)); 
        HCode(code,source);//coding and storing in the array code;

    }
}
int Code::Statictic(void){
    sourcetype chbuf;
    int i;
    while(file.eof()){
        file.read(chbuf,sizeof(chbuf));
	for(i=0; i<=Global::TreeRoot; i++){
	    if(chbuf == HT[i]){
		HT[i].weight += 1.0;
		break;
	    }//if
	}//for
    }//while
    return 0;
}
