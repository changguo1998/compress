#include <iostream>
#include <string>
#include <fstream>
#include "Global.h"
#include "Huffman.h"
#include "code&decode.h"
using namespace std;

int main(void){
    string InFile,OutFile;
    char ch;
    cout << "compress?[y or n]" <<endl;
    cin >> ch;
    if(ch == 'y'){
        cout << "Input source file:";
        cin >> InFile;
        Global::SourceFile.open(InFile,ios::in|ios::binary);
        OutFile = InFile + ".gccp";
        Global::CodedFile.open(OutFile,ios::out|ios::binary);
        Code::Coding();

        Global::SourceFile.close();
        Global::CodedFile.close();
        return 0;
    }

    cout << "uncompress?[y|n]" <<endl;
    cin >> ch;
    if(ch=='y'){
        cout << "Input source file:";
        cin >> InFile;
        Global::CodedFile.open(InFile,ios::in|ios::binary);
        OutFile = InFile + ".gccp";
        Global::SourceFile.open(OutFile,ios::out|ios::binary);
        Code::Decoding();

        Global::SourceFile.close();
        Global::CodedFile.close();
        return 0;
    }

    return 0;
}
/*int main(int argc,char *argv[]){
    if(argc<=1){
        doc();
        return 0;
    }
    else if(argc >4 ){
        cout << "Too many parameters." <<endl;
        doc();
        return 0;
    }
    string choice,InFile,OutFile;
    if(argc==2){
        choice.assign(argv[1]);
        if(choice=="-c"){
            cout << "Input source file:";
            cin >> InFile;
            Global::SourceFile.open(InFile,ios::in|ios::binary);
            OutFile = "compress_" + InFile + ".gccp";
            Global::CodedFile.open(OutFile,ios::out|ios::binary);
            Code::Coding();
        }
        else if(choice=="-d"){
            cout << "Input source file:";
            cin >> InFile;
            Global::CodedFile.open(InFile,ios::in|ios::binary);
            OutFile = "release_" + InFile-".gccp";
            Global::SourceFile.open(OutFile,ios::out|ios::binary);
            Code::Decoding();
        }
    }
    else if(argc==3){
        choice.assign(argv[1]);
        OutFile.assign(argv[2]);
        if(choice=="-c"){
            OutFile = "compress_" + InFile;
            OutFile += ".gccp";
        }
        else if(choice=="-d"){

        }
        else{
            cout << "choice is wrong"<<endl;
            doc();
            return 0;
        }
    }
    else {
        choice.assign(argv[1]);
        InFile.assign(argv[2]);
        OutFile.assign(argv[3]);
        if(choice=="-c"){
        }
        else if(choice=="-d"){

        }
        else{
            cout << "choice is wrong"<<endl;
            doc();
            return 0;
        }
    }
        OutFile = "compress_" + InFile;
        OutFile += ".gccp";

    char *buf;


    Global::SourceFile.close();
    Global::CodedFile.close();
    return 0;
}

void doc(void){
    cout << "Usage:" <<endl;
    cout << "compress [-c|-d] [input file] [output file]" <<endl;
    cout << "-c: compress" <<endl;
    cout << "-d: decompress" <<endl;
    cout << "The output file's name is alternative.If you don't enter the output file's name, the program will output the file named compress_[input file].gccp."<<endl;
        cout <<"You are not supposed to add the extern name \".gccp\",the program will add it automatically."<<endl;
}*/
