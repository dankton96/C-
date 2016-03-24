#include <iostream>
#include <stdio.h>
#include <memmanip.h>
#include <string.h>
#include <string>
#include <conio.h>

using namespace std;

class worker
{
    private: string name;
    private: float salary;
    private: string admisdata;
    public: worker AboutWorker()
    {
        cout<<"Nome: "<<worker.name<<endl
            <<"Salario: "<<worker.salary<<endl
            <<"Data de admissao: "<<worker.admisdata<<endl<<endl;
        getch();
        system("cls");
    };
    public: worker Inf_Editor()
    {
        char op;
        fflush(stdin);
        while(op!='4')
        {
            while(op='1' || op!='2' || op!='3' || op!='4')
            {
            system("cls");
            cout<<"Selecione a informacao que deseja editar:"<<endl
                <<"1-Nome"<<endl
                <<"2-Salario"<<endl
                <<"3-Data de admissao"<<endl
                <<"4-Edicoes terminadas";
            char op=getch();
            };
            if(op=='1')
            {
                system("cls");
                cout<<"Insira o nome do funcionario: ";
                fflush(stdin);
                getline(cin,worker.name);
            }
            if(op=='2')
            {
                system("cls");
                cout<<"Insira o salario do funcionario: ";
                cin>>worker.salary;
            }
            if(op=='3')
            {
                cout<<"Insira a data de admisssao: ";
                fflush(stdin);
                getline(cin,worker.admisdata);
            }
            if(op=='4')
            {
                return;
            }
        };
    };
};

class company
{
    private: string cnpj;
    private: string compname;
};


int main(void)
{
 new worker joao;
 joao.Inf_Editor();
}
