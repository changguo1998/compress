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
    using namespace Global;
    if( !(SourceFile.is_open()&&CodedFile.is_open()) )
        return File_Not_Ready;
    InitTree();
    Statistic();
    CCreateTree();
//begin to code the file
    int code[CODE_TYPE_NUM];
    SourceFile.clear(ios::goodbit);
    SourceFile.seekg(ios::beg);//rewind the file pointer
    CodedFIle.write(TreeRoot,sizeof(TreeRoot));
    CodedFile.write(HT,TREE_NODE_NUM*sizeof(HuffmanNode));
    sourcetype source;
    buffertype buff;//buf_low,buf_high;
    int buf_bit=0;
    while(SourceFile.eof()){
        SourceFile.read(source,sizeof(source)); 
        HCode(code,source);//coding and storing in the array code;
        for(i=0;code[i]!=Code_End;i++){
	    if(code[i] == 1){//transform to bit
	        buff << 1;
		buff |= 0x01;
                buf_bit += 1;
	    }//if
	    else if(code[i] == 0){
                buff << 1;
		buff &= 0xfe;
		buf_bit += 1;
	    }//else if
	    //write to file
	    if(buf_bit==sizeof(buff)){
		CodedFIle.write(buff,sizeof(buff));
		buf_bit = 0;
	    }//write to file
	}//for
    }//while
    //deal with the rest bit in buff
    CodedFile.write(buff,sizeof(buff));
    CodedFile.write(buf_bit,sizeof(buf_bit));
    return Ok;
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
