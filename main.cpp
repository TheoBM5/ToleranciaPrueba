#include <iostream>
#include <sstream>
#include <stack>


using namespace std;
void imprimir(    stack<string> stack1);

int main ()
{
    int pos=0;
    int estado=0;
    int tamano=0;
    int opc=0;
    string cadena;
    char sim;
    stack<string> stack;
    cout<<"a^n b^2n"<<endl;
    do{
        estado=0;
        cout<<"Ingrese cadena valida: ";
        std::getline(std::cin, cadena);
        tamano=cadena.size();
        while(!stack.empty())
        {
            stack.pop();
        }
        if(tamano==0)
        {
            cout<<"Cadena no valida";
        }
    for(int pos=0;tamano!=0;pos++, tamano--){
        sim=cadena[pos];

        if(estado==-1)
        {
            break;
        }

    switch(estado)
    {
        case 0:if(stack.empty())
                {
                    stack.push("A");
                    estado=1;
                    //imprimir(stack);
                }

        case 1:if(sim=='a'&& stack.top()=="A")
                {
                    stack.pop();
                    stack.push("A");
                    stack.push("0");
                    stack.push("0");
                    estado=1;
                    //imprimir(stack);
                    break;
                }
                if(sim=='a'&& stack.top() == "0")
                {
                    stack.pop();
                    stack.push("0");
                    stack.push("0");
                    stack.push("0");
                    estado=1;
                    //imprimir(stack);
                    break;
                }
                if(sim=='b'&& stack.top() == "0")
                {
                    stack.pop();
                    estado=2;
                    //imprimir(stack);
                    break;
                }
                else
                {
                    estado=-1;
                    break;
                }
        case 2:if(sim=='b'&& stack.top() == "0")
                {
                    stack.pop();
                    estado=2;
                    //imprimir(stack);
                    break;
                }

                else
                {
                    estado=-1;
                    break;
                }

    }
}
    if(estado != -1 && stack.top() == "A")
    {
            stack.pop();
            estado=3;
            //imprimir(stack);
    }
    if(stack.empty())
    {
        cout<<"\nCadena valida"<<endl;
    }
    else{
        cout<<"\nCadena no valida"<<endl;
    }
    cout<<"\nIngresar otra cadena: ? 1.- si , 0.-no : ";
    std::cin>>opc;
    cin.ignore();
    }while(opc!=0);


    return 0;
}

void imprimir(stack<string> stack1)
{
    while (!stack1.empty()) {
        cout << ' ' << stack1.top()<<endl;
        stack1.pop();
    }
    cout<<endl;
}
