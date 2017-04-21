
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#ifdef LINUX
#include "conio.h"
#elif defined WIN32
#include <conio.h>
#else
#error Plataforma nao suportada
#endif

using namespace std;

void LimpaTela()
{
#ifdef LINUX
system("clear");
#elif defined WIN32
system("cls");
#else
#error Plataforma nao suportada
#endif
}

char DBFile[]="Database.txt";
char TransLogFile[]="OpLog.txt";

typedef struct
	{
	    float value;
		char type;
	} TransactionData;

typedef class Transaction
	{
		private:
		TransactionData data;
		public:
        Transaction *prev,*act,*next;
		Transaction()
			{
				act=this;
				next=prev=act;
			}
		bool IsEmpty(){return (next==act && act==prev);}
		void Insert(float quant,char operation)
			{
				if(IsEmpty()){act=new Transaction;}
				else
					{
						if(next!=NULL){do{act=next;}while(next!=NULL);}
						next=new Transaction;
						next->prev=act;
						act=next;
					}
				act->data.value=quant;
				act->data.type=operation;
			}
        char GetTransactionType()
            {
                if(!IsEmpty()){return act->data.type;}
                else return 'N';
            }
        float GetTransactionValue()
            {
                if(!IsEmpty()){return act->data.value;}
                else return 0;
            }

	}Transaction;

	typedef struct
	{
		int agencia;
		int conta;
		int digito;
	} AccountData;

typedef struct
	{
		char nome[100];
		Transaction TempLog;
		AccountData conta;
		int cpf;
		float saldo;
	} Account;

typedef class AccountList
	{
		private:
		Account data;
		FILE *AccountLog,*AccountDB;
		AccountList *prev,*act,*next;
		int ElementsNumber;
		public:
		bool IsEmpty(){return (next==act && act==prev);}
		AccountList()
		{
            act=this;
            next=prev=act;
			act->data.saldo=0;
			ElementsNumber=0;
		}
		void Insert()
			{
                LimpaTela();
				if(!(IsEmpty()))
					{
						while(next!=NULL)
							{
								act=next;
							}
						next=new AccountList;
						if(next==NULL){cout<<"Erro ao abrir nova conta"<<endl;return;}
						next->prev=act;
						act=next;
					}
				cout<<"Nome do correntista:";
				cin.ignore();
				gets(act->data.nome);
				cout<<"CPF:";
				cin>>act->data.cpf;
				cout<<"Agencia:";
				cin>>act->data.conta.agencia;
				cout<<"Conta:";
				cin>>act->data.conta.conta;
				cout<<"Digito:";
				cin>>act->data.conta.digito;
				cout<<endl<<endl
                    <<act->data.nome<<endl
                    <<act->data.cpf<<endl
                    <<act->data.conta.agencia<<endl
                    <<act->data.conta.conta<<endl
                    <<act->data.conta.digito;
                char wait=getche();
				ElementsNumber++;
				//gravar no arquivo
			}

		void Deposit(int AgencNumber, int AccountNumber, int Digit, float DepValue)
			{
				while(prev!=NULL){act=prev;}
				do
					{
						if(act->data.conta.agencia==AgencNumber && act->data.conta.conta==AccountNumber &&
						   act->data.conta.digito==Digit)
							{
								act->data.saldo+=DepValue;
								data.TempLog.Insert(DepValue,'C');
								AccountLog=fopen(TransLogFile,"a");
								fprintf(AccountLog,"%i\t%i\t%i\t%.2f\t%c\n",AgencNumber,AccountNumber,Digit,
                                        act->data.TempLog.GetTransactionValue(),act->data.TempLog.GetTransactionType());
                                fclose(AccountLog);
								return;
							}
						act=next;
					}while(next!=NULL);
				cout<<"Erro ao efetuar transacao: Conta informada nao encontrada"<<endl;
			}
		void Withdraw(int AgencNumber, int AccountNumber, int Digit, float WDValue)
			{
				while(prev!=NULL){act=prev;}
				do
					{
						if(act->data.conta.agencia==AgencNumber && act->data.conta.conta==AccountNumber &&
						   act->data.conta.digito==Digit)
							{
								act->data.saldo-=WDValue;
								data.TempLog.Insert(WDValue,'D');
								AccountLog=fopen(TransLogFile,"a");
								fprintf(AccountLog,"%i\t%i\t%i\t%.2f\t%c\n",AgencNumber,AccountNumber,Digit,
                                        act->data.TempLog.GetTransactionValue(),act->data.TempLog.GetTransactionType());
                                fclose(AccountLog);
								return;
							}
						act=next;
					}while(next!=NULL);
				cout<<"Erro ao efetuar transacao: Conta informada nao encontrada"<<endl;
			}
		void Transfer(float Value,int AgencNumber1, int AccountNumber1, int Digit1,int AgencNumber2, int AccountNumber2, int Digit2)
			{
				//from account1 to account2;
				Withdraw(AgencNumber1,AccountNumber1,Digit1,Value);
				Deposit(AgencNumber2,AccountNumber2,Digit2,Value);
			}
		void UpdateAccountsDB()
			{
			    /*corrigir*/
				int AccountNumber=0;
				char reader;
				AccountDB=fopen(DBFile,"r+");
				if(AccountDB==NULL){cout<<"Erro ao abrir base de dados";return;}
				do{reader=fgetc(AccountDB);}while(reader!=EOF);
				while(act!=NULL){act=prev;}
				//atualizar saldos das contas
				do
					{
						act=next;
						AccountNumber++;
                    }while(next!=NULL);
                ////////////////////////////////
				cout<<"Informacoes das contas armazenadas:"<<endl<<endl;
				while(act->prev!=NULL){act=prev;}
				while(act->next!=NULL)
					{
						cout<<act->data.nome<<"\t"<<act->data.conta.agencia<<"\t"<<act->data.conta.conta
						<<"\t"<<act->data.conta.digito<<"\t"<<act->data.cpf<<"\t"<<act->data.saldo<<endl;
						act=next;
					}
				cout<<"Total de contas armazenadas: "<<AccountNumber<<endl;
				while(act->prev!=NULL){act=prev;}
				while(act->next!=NULL)
					{
						fprintf(AccountDB,"%s\t%i\t%i\t%i\t%i\t%f\n",act->data.nome,act->data.conta.agencia,
						act->data.conta.conta,act->data.conta.digito,act->data.cpf,act->data.saldo);
						act=next;
					}
				ElementsNumber=AccountNumber;
				fclose(AccountDB);


			}
		void UpdateTransactionDB()
			{
			    /*corrigir*/
				AccountLog=fopen(TransLogFile,"r+");
				if(AccountLog==NULL){cout<<endl<<"Erro ao processar transacoes"<<endl;return;}
				while(prev!=NULL){act=prev;}
				do
					{
					    if(!act->data.TempLog.IsEmpty())
                        {
                            while(act->data.TempLog.prev!=NULL){act->data.TempLog.act=act->data.TempLog.prev;}
                            while(act->data.TempLog.next!=NULL)
                            {
                            fprintf(AccountLog,"%i\t%i\t%i\t%i\t%f\t%c\n",act->data.conta.agencia,act->data.conta.conta,
                                    act->data.conta.digito,act->data.TempLog.act->GetTransactionValue(),
                                    act->data.TempLog.act->GetTransactionType());
                            act->data.TempLog.act=act->data.TempLog.next;
                            };
                        }
                        act=next;
					}while(next!=NULL);
                fclose(AccountLog);
			}


	}AccountList;



void menu(AccountList *contas)
	{
	    char op;
	    do{
            float val1;
            int TransfData[6];
            LimpaTela();
            cout<<"1-Abrir uma conta"<<endl
                <<"2-Encerrar uma conta"<<endl
                <<"3-Transferencia"<<endl
                <<"4-Saque"<<endl
                <<"5-Deposito"<<endl
                <<"6-Sair"<<endl;
            do{op=getche();}while(op!='1' && op!='2' && op!='3' && op!='4' && op!='5' && op!='6');
            cout<<endl;
            if(op=='1')
            {
                contas->Insert();
            }
            if(op=='3')
            {
                LimpaTela();
                cout<<"Valor: ";
                cin>>val1;
                cout<<"Agencia de origem: ";
                cin>>TransfData[0];
                cout<<"Conta de origem: ";
                cin>>TransfData[1];
                cout<<"Digito verificador da conta de origem: ";
                cin>>TransfData[2];
                cout<<"Agencia de destino: ";
                cin>>TransfData[3];
                cout<<"Conta de destino: ";
                cin>>TransfData[4];
                cout<<"Digito verificador da conta de destino: ";
                cin>>TransfData[5];
                contas->Transfer(val1,TransfData[0],TransfData[1],TransfData[2],TransfData[3],TransfData[4],TransfData[5]);
            }
            if(op=='4')
            {
                LimpaTela();
                cout<<"Numero da agencia:";
                cin>>TransfData[0];
                cout<<"Numero da conta:";
                cin>>TransfData[1];
                cout<<"Digito:";
                cin>>TransfData[2];
                cout<<"Valor:";
                cin>>val1;
                contas->Withdraw(TransfData[0],TransfData[1],TransfData[2],val1);
            }
            if(op=='5')
            {
                LimpaTela();
                cout<<"Numero da agencia:";
                cin>>TransfData[0];
                cout<<"Numero da conta:";
                cin>>TransfData[1];
                cout<<"Digito:";
                cin>>TransfData[2];
                cout<<"Valor:";
                cin>>val1;
                contas->Deposit(TransfData[0],TransfData[1],TransfData[2],val1);
            }
            if(op=='6')
            {
                LimpaTela();
                contas->UpdateTransactionDB();
                contas->UpdateAccountsDB();
                return;
            }
        }while(op!='6');
	}

int main()
	{
		FILE *Accountlistf=fopen(DBFile,"r");
		if(Accountlistf==NULL){Accountlistf=fopen(DBFile,"w");}
		FILE *LogFile=fopen(TransLogFile,"r");
		if(LogFile==NULL){LogFile=fopen(TransLogFile,"w");}
		//else{printf("Erro ao abrir o arquivo");return 1;}
		fclose(Accountlistf);
		fclose(LogFile);
		AccountList *DBAccount= new AccountList;
		menu(DBAccount);
		return 0;
	}
