#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(void)
{
int num,aux,cont=0,aux2,i2;
char confirm;
system("clear");
cout<<"Informe quais primeiros numeros primos deseja saber: ";
cin>>aux;
cout<<"Primeiros "<<aux<<" numeros primos:"<<endl<<endl;
i2=1;
aux2=0;
while(cont<aux)
			{
				aux2=0;
				for(int i=1; i<=i2;i++)
					{
						if(i2%i==0){aux2++;}
					}
				if(aux2==2){cont++;cout<<i2<<endl;}
				i2++;
			}
    }
