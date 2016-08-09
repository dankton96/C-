#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef class Aluno
{
    private:

    string name, addres, tel;
    int reg;
    float height, weight;

    public:
    Aluno *act, *next, *prev;
    Aluno()
        {
        act=next=prev=NULL;
        }
    void SetName(string text){name=text;}
    void SetHeight(float num){height=num;}
    void SetAddres(string text1){addres=text1;}
    void SetReg(int num1){matricula=num1;}
    string SetTelephone(string text2)
        {
        if(text2[0]!='(' && text2[3]!=')' && text2[8]!='-'){tel=text2;}
        else{tel="error";}
        }
    void SetWeight(float num3){weight=num3;}

    string GetName()
            {
                return name;
            }
    float GetHeight()
            {
                return height;
            }
    void Apresentation()
            {
            /*
                #ifdef _WIN32
                system("cls");
                #endif
                #ifdef __linux__
                system("clear");
                #endif
            */
                cout<<"Name:           "<<name<<endl
                    <<"Height:         "<<height<<endl
                    <<"Telephone:      "<<tel<<endl
                    <<"Address:        "<<addres<<endl
                    <<"Weight:         "<<weight<<endl
                    <<"Registration:   "<<reg;
            }
    void AddNext()
            {

            string name1, addres1, tel1;
            int reg1;
            float height1, weight1;
                if(act==next==prev)
                    {
                        act=this;
                        next=(*Aluno)malloc(sizeof(Aluno));
                        if(next==NULL){"Falha ao alocar memoria. Abortando."; Sleep(3000); exit();}
                        else
                            {
                                act=act->next;
                                cout<<"Enter your registration number, height, weight, name, address and telephone number : ";
                                cin>>reg1>>height1>>weight1;
                                cin.ignore();
                                getline(cin, name1);
                                cin.ignore();
                                getline(cin, addres1);
                                VerifyTel:
                                cin.ignore();
                                getline(cin, tel1);
                                this.SetReg(reg1);
                                this.SetHeight(height1);
                                this.SetWeight(weight1);
                                this.SetName(name1);
                                this.SetAddres(addres1);
                                this.SetTelephone(tel1);
                                if(tel=="error";)
                                {
                                cout<<"Numero de telefone invalido. Insira um numero valido no formato (XX)XXXX-XXXX:"<<endl;
                                goto VerifyTel;
                                }
                            }
                    }
            }
};

int main(void)
{
    People *turma, start=new People;
    float height1;
    string name1;
    turma=&start;
}
