#include <iostream>
#include <stdio.h>
#include <memmanip.h>
#include <string.h>
#include <string>
#include <conio.h>

using namespace std;

class worker
{
    private:
        string name;
        float salary;
        string admisdate;//data de admissao na empresa
        string department;

    public:
        void AboutWorker()
        {
            cout<<"Nome: "<<name<<endl
                <<"Salario: "<<salary<<endl
                <<"Data de admissao: "<<admisdate<<endl<<endl;
            getch();
            system("cls");
        };
        void Inf_Editor()
        {
            char op;
            fflush(stdin);
            while(op!='4')
            {
                menu:
                system("cls");
                cout<<"Selecione a informacao que deseja editar:"<<endl
                    <<"1-Nome"<<endl
                    <<"2-Salario"<<endl
                    <<"3-Data de admissao"<<endl
                    <<"4-Edicoes terminadas"<<endl;
                op=getche();
                if(op=='1')
                {
                    system("cls");
                    cout<<"Insira o nome do funcionario: ";
                    cin.ignore();
                    getline(cin,name);
                }
                if(op=='2')
                {
                    system("cls");
                    cout<<"Insira o salario do funcionario: ";
                    cin>>salary;
                }
                if(op=='3')
                {
                    system("cls");
                    cout<<"Insira a data de admisssao: ";
                    cin.ignore();
                    getline(cin,admisdate);
                }
                if(op=='4')
                {
                    system("cls");
                    return;
                }
                else{goto menu;}
            };
        };
};

class company
{
    private:
        string cnpj;
        string compname;


    public:
        void DataEditor()
        {
            cout<<"Insira o nome da empresa";
            cin.ignore();
            getline(cin,compname);
            cout<<"Insira o CNPJ da empresa";
            cin.ignore();
            getline(cin,cnpj);
        };
};


int main(void)
{
menu:
cout<<"1-Criar uma empresa"<<endl<<"2-Editar dados de uma empresa ja existente";
char op=getche();
if(op=='1')
    {

    }
}

