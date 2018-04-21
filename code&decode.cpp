#include <iostream>
#include <fstream>
#include "Global.h"
#include "Huffman.h"
#include "code&decode.h"
using namespace std;
int Code::Coding(void){
    using namespace Huffman;
    if( !(Global::SourceFile.is_open()&&Global::CodedFile.is_open()) )
        return Global::File_Not_Ready;
    InitTree();
    Statistic();
}
int Code::Statictic(void){
    unsigned char chbuf;
    while(file.eof()){
        file.read(chbuf,sizeof(chbuf))
    }
}
