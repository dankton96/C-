#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void gravaComando(char a, char b, FILE *arq, string line)
{
    char num[3];
    
    num[0] = a;
    num[1] = b;

    switch(line) {
        case "An;":
            num[2] = '0'; break;
        case "nAoB;":
            num[2] = '1'; break;
        case "AnB;":
            num[2] = '2'; break;
        case "zeroL;":
            num[2] = '3'; break;
        case "nAeB;":
            num[2] = '4'; break;
        case "Bn;":
            num[2] = '5'; break;
        case "AxB;":
            num[2] = '6'; break;
        case "ABn;":
            num[2] = '7'; break;
        case "AnoB;":
            num[2] = '8'; break;
        case "nAxB;":
            num[2] = '9'; break;
         case "B;":
            num[2] = 'a'; break;
         case "AB;":
            num[2] = 'b'; break;
         case "umL;":
            num[2] = 'c'; break;
         case "AoBn;":
            num[2] = 'd'; break;
         case "AoB;":
            num[2] = 'e'; break;
         case "A;":
            num[2] = 'f'; break;
    }
    int written = fwrite(&num, sizeof(char), 3, arq);
    
    if(written != 3){
        cout << "Erro ao compilar arquivo" << endl;
        return;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool foundInObjStr(string tofind, char pattern[],size_t &posfind)
{
    size_t match;
    match=tofind.find(pattern);
    if(match==tofind.npos){return false;}
    else{posfind=match;return true;}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    size_t foundPos;
    string line1;
    char a,b,reader;
    //fstream arqIn, arqOut;
    FILE *arqIn,*arqOut;
    arqIn=fopen("74181.alu","rb");
    arqOut=fopen("74181.hex","wb");
    if(arqIn!=NULL && arqOut!=NULL)
    {
        cout<<"Geracao do arquivo compilado:"<<endl;
        do
            {
                //verify if the line1 is an instruction, if it is, burn in arqOut
                int i=-1;
                line1.clear();
                do
                    {
                        i++;
                        fread(&reader,sizeof(char),1,arqIn);
                        line1+=reader;
                        cout<<reader;//debug tool
                        if(reader=='\n')
                        {
                        if(!foundInObjStr(line1,"=",foundPos)){gravaComando(a,b,arqOut,line1);line1.clear();}
                        //if it is not, it is an attribution,so it does it
                        else
                            {
                                if(line1[0]=='A'){a=line1[2];}
                                if(line1[0]=='B'){b=line1[2];}
                                line1.clear();
                            }
                        }
                        int j=0;//debug tool
                        while(j<10000000){j++;}//debug tool
                    }while(!feof(arqIn));
            }while(!feof(arqIn));
        fclose(arqIn);
        fclose(arqOut);
        cout<<endl<<"Sucesso ao ler codigo fonte e criar arquivo compilado"<<endl;
    }
    else
    {
        if(arqIn==NULL)
            {cout<<"Falha ao ler codigo fonte - verifique as permissoes de leitura em seu S.O."<<endl; return 1;}
        if(arqOut==NULL)
            {cout<<"Falha ao gerar arquivo compilado - verifique as permissoes de escrita em seu S.O."<<endl; return 2;}
    }
    //execute the .hex in arduino
    cout<<"Transmissao das instrucoes ao arduino"<<endl;
    arqOut=fopen("74181.hex","rb");
    if(arqOut==NULL)
        {cout<<"Falha ao ler codigo fonte - verifique as permissoes de leitura em seu S.O."<<endl; return 1;}
    else
        {
            string comport;
            cout<<"Informe a porta COM:";
            cin.ignore();
            getline(cin,comport);
            size_t pos;
            if(!foundInObjStr(comport,"com",pos)){comport="com"+comport;}
            while(!feof(arqOut))
            {
                switch('\n')
                {
                    line1.clear();
                   int i=-1;
                    do
                    {
                        i++;
                        fread(&a,sizeof(char),1,arqIn);
                        line1+=a;
                    }while(line1[i]!='\n' || line1[i]!=EOF);
                    string comando;
                    comando="envia "+comport+" "+line1[0]+" "+line1[1]+" "+line1[2];
                    cout<<comando<<endl;
                    system(comando.c_str());
                }
            }
        }
}
