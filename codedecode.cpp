#include <iostream>
#include <fstream>
#include <string>
#include "Global.h"
#include "Huffman.h"
#include "codedecode.h"
//extern HuffmanNode HT[TREE_NODE_NUM];
//extern int TreeRoot;
//extern ifstream SourceFile;
//extern ofstream CodedFile;
using namespace std;
void Coding(string &InFile,string &OutFile,int &TreeRoot,HuffmanNode *HT){
/*
 *  This function will be called when the user want to compress a file.
 *  This is like an "main" function for all functions abort conpress
 */
    ifstream SourceFile;
    ofstream CodedFile;

    InitTree(HT,TreeRoot);

    Statistic(InFile,TreeRoot,HT);
    //if( !(SourceFile.is_open()&&CodedFile.is_open()) )
        //return File_Not_Ready;
    CCreateTree(HT,TreeRoot);
//begin to code the file
    int code[CODE_TYPE_NUM];
    SourceFile.open(InFile,ios::in|ios::binary);
    CodedFile.open(OutFile,ios::out|ios::binary);
    SourceFile.clear(ios::goodbit);
    SourceFile.seekg(ios::beg);//rewind the file pointer
    void *t=&(TreeRoot);
    CodedFile.write(static_cast<char *>(t),sizeof(TreeRoot));
    t = HT;
    CodedFile.write(static_cast<char *>(t),TREE_NODE_NUM*sizeof(HuffmanNode));
    sourcetype source;
    buffertype buff;//buf_low,buf_high;
    int buf_bit=0,i;
    while(!SourceFile.eof()){
        SourceFile.read(static_cast<char*>(&source),sizeof(source));
        HCode(code,source,HT,TreeRoot);//coding and storing in the array code;
        for(i=0;code[i]!=Code_End;i++){
            if(code[i] == 1){//transform to bit
                buff <<= 1;
            buff |= 0x01;
                    buf_bit += 1;
            }//if
            else if(code[i] == 0){
                    buff <<= 1;
                buff &= 0xfe;
                buf_bit += 1;
            }//else if
	    //write to file
            if(buf_bit==8*sizeof(buff)){
                CodedFile.write(static_cast<char *>(&buff),sizeof(buff));
                buf_bit = 0;
            }//write to file
        }//for
    }//while
    //deal with the rest bit in buff
    //CodedFile.write(buff,sizeof(buff));
    //CodedFile.write(buf_bit,sizeof(buf_bit));
    while(buf_bit!=sizeof(buff)){
        buff <<= 1;
        buf_bit ++;
    }
    CodedFile.write(static_cast<char *>(&buff),sizeof(buff));
    SourceFile.close();
    CodedFile.close();
    return;
}
void Statictic(string &InFile,int &TreeRoot,HuffmanNode *HT){
    ifstream SourceFile;
    SourceFile.open(InFile,ios::in|ios::binary);
    sourcetype chbuf;
    int i;
    while(!SourceFile.eof()){
        SourceFile.read(static_cast<char *>(&chbuf),sizeof(chbuf));
        for(i=0; i<=TreeRoot; i++){
            if(chbuf == HT[i].content){
            HT[i].weight += 1.0;
            break;
            }//if
        }//for
    }//while
    SourceFile.close();
    return;
}
void Decoding(string &InFile,string &OutFile,int &TreeRoot,HuffmanNode *HT){
/*
 *
 *
 */
    ofstream SourceFile;
    ifstream CodedFile;
    InitTree(HT,TreeRoot);
    DCreateTree(InFile,TreeRoot,HT);
    SourceFile.open(OutFile,ios::out|ios::binary);
    CodedFile.open(InFile,ios::in|ios::binary);
//    if( !(SourceFile.is_open()&&CodedFile.is_open()) )
//        return File_Not_Ready;
    CodedFile.seekg(sizeof(TreeRoot)+TREE_NODE_NUM*sizeof(HuffmanNode),ios::beg);
    buffertype buff;
    sourcetype decompress;
    int rest_bit,decom_loc;
    rest_bit = 0;
    decom_loc = TreeRoot;
    while(!CodedFile.eof()||rest_bit>0){
        if(rest_bit==0){
            CodedFile.read(static_cast<char *>(&buff),sizeof(buff));
            rest_bit = 8*sizeof(buff);
        }
        if((buff & 0x80) == 0x80)
            decom_loc = HT[decom_loc].rchild;
        else if((buff & 0x80) == 0x00)
            decom_loc = HT[decom_loc].lchild;

        if(HT[decom_loc].lchild == -1){
            decompress = HT[decom_loc].content;
            SourceFile.write(static_cast<char *>(&decompress),sizeof(decompress));
            buff <<= 1;
            rest_bit -= 1;
        }
    }//while
    SourceFile.close();
    CodedFile.close();
    return;
}
