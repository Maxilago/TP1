#include <iostream>
#include <cstdlib>
using namespace std;
#include "platos.h"
#include "clientes.h"
#include "pedidos.h"
#include "configuracion.h"

int main()
{
    int opc;
    while(true){
        system("cls");
        cout<<"-------------MENU--------------"<<endl;
        cout<<"1) Platos"<<endl;
        cout<<"2) Clientes"<<endl;
        cout<<"3) Pedidos"<<endl;
        cout<<"4) Reportes"<<endl;
        cout<<"5) Configuracion"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"0)Salir del programa"<<endl;
        cin>>opc;
        switch(opc){
        case 1:menuPlatos();
        break;
        case 2:menuClientes();
        break;
        case 3:menuPedidos();
        break;
        case 5:menuConfig();
        break;
        case 0:exit(0);
        break;
        }
        system("pause");
        system("cls");

    }
}
