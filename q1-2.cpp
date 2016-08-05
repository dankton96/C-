#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef class People
{
    private:

    string name;
    int age;
    float height;

    public:

    void SetAge(int age1){age=age1;}
    void SetName(string text){name=text;}
    void SetHeight(float num){height=num;}
    string GetName()
            {
                return name;
            }
    int GetAge()
            {
                return age;
            }
    float GetHeight()
            {
                return height;
            }
    void Apresentation()
            {
                #ifdef _WIN32
                system("cls");
                #endif
                #ifdef __linux__
                system("clear");
                #endif
                cout<<"Name: "<<name<<endl
                    <<"Age: "<<age<<endl
                    <<"Height: "<<height<<endl<<endl;
            }
};

int main(void)
{
    People alguem;
    int age1;
    float height1;
    string name1;
    cout<<"Informe a altura, idade e nome da pessoa: ";
    cin>>height1>>age1;
    gets(name1);
    alguem.SetAge(age1);
    alguem.SetHeight(height1);
    alguem.SetName(name1);
    alguem.Apresentation();
}
