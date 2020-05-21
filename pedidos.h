#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED
#include "clientes.h"

/*struct Fecha{
  int dia, mes, anio;
};*/

struct pedido{
int id;
int IDCliente;
int IDPlato;
int cantidad;
float precioUn;
Fecha diaPedido;
float valor;
int estado=1;
};

void modificarPedido(){
    int id;
    FILE *p;
    p=fopen("pedidos.dat","rb+");
    if(p==NULL){
    cout<<"Error al abrir el archivo";
    }
    cout<<"Ingrese ID del pedido: "<<endl;
    cin>>id;
    pedido reg;
    int cnt=0;
    while(fread(&reg,sizeof reg,1,p)==1){
        if(id==reg.id){
            cout<<"Ingrese nuevo estado: ";
            cin>>reg.estado;
            while(reg.estado<1 || reg.estado>3){
                cout<<"Estado invalido, ingrese estado: ";
                cin>>reg.estado;
            }
          fseek(p,cnt*sizeof(reg),0);
          fwrite(&reg,sizeof(reg),1,p);
          fclose(p);
          return;
        }
        cnt++;
    }
    cout<<"ID invalido"<<endl;
    fclose(p);
    return;
}
float valorPedido(pedido ped){
    FILE *p;
    p=fopen("platos.dat","rb");
    if(p==NULL){
    cout<<"Error al abrir el archivo";
    }
    plato reg;
    while(fread(&reg,sizeof reg,1,p)==1){
    if(ped.IDPlato==reg.id){
        fclose(p);
        return reg.valor;
    }
}
fclose(p);
return -1;
}

bool checkIDCliente(int id){
    FILE *p;
    p=fopen("clientes.dat","rb");
    if(p==NULL){
    cout<<"Error al abrir el archivo";
}
cliente reg;
while(fread(&reg,sizeof reg,1,p)==1){
    if(id==reg.id){
        fclose(p);
        return true;
    }
}
fclose(p);
return false;
}

void nuevoPedido(){
FILE *p;
p=fopen("pedidos.dat","ab+");
if(p==NULL){
    cout<<"Error al abrir el archivo";
}
pedido reg;
int cnt=1;
while(fread(&reg,sizeof reg,1,p)==1){
    cnt++;
}
reg.id=cnt;
cout<<"Ingrese ID del cliente: "<<endl;
cin>>reg.IDCliente;
while(checkIDCliente(reg.IDCliente)==false){
    cout<<"Cliente invalido, ingrese ID: "<<endl;
    cin>>reg.IDCliente;
}
cout<<"Ingrese ID del plato: "<<endl;
cin>>reg.IDPlato;
while(valorPedido(reg)==-1){
    cout<<"ID invalido, ingrese ID: "<<endl;
    cin>>reg.IDPlato;
}
reg.precioUn=valorPedido(reg);
cout<<"Ingrese cantidad: "<<endl;
cin>>reg.cantidad;
while(reg.cantidad<=0){
    cout<<"Cantidad invalida, ingrese cantidad: "<<endl;
    cin>>reg.cantidad;
}
cout<<"Ingrese fecha: "<<endl;
cout<<"Dia: ";
cin>>reg.diaPedido.dia;
while(reg.diaPedido.dia<1 || reg.diaPedido.dia>31){
    cout<<"Dia invalido, ingrese dia: "<<endl;
    cin>>reg.diaPedido.dia;
}
cout<<"Mes: ";
cin>>reg.diaPedido.mes;
while(reg.diaPedido.mes<1 || reg.diaPedido.mes>12){
    cout<<"Mes invalido, ingrese mes: "<<endl;
    cin>>reg.diaPedido.mes;
}
cout<<"Anio: ";
cin>>reg.diaPedido.anio;
while(reg.diaPedido.anio<1900 || reg.diaPedido.anio>2020){
    cout<<"Anio invalido, ingrese anio: "<<endl;
    cin>>reg.diaPedido.anio;
}
cout<<"Ingrese valoracion: "<<endl;
cin>>reg.valor;
while(reg.valor<0 || reg.valor>10){
    cout<<"Valoracion invalida, ingrese valoracion: "<<endl;
    cin>>reg.valor;
}
fwrite(&reg,sizeof reg,1,p);
fclose(p);
}

void listarPedidos(){
    FILE *p;
    p=fopen("pedidos.dat","rb");
    if(p==NULL){
    cout<<"Error al abrir el archivo";
}
pedido reg;
while(fread(&reg,sizeof reg,1,p)==1){
        cout<<"------------------------"<<endl;
        cout<<"ID: "<<reg.id<<endl;
        cout<<"ID Cliente: "<<reg.IDCliente<<endl;
        cout<<"ID Plato: "<<reg.IDPlato<<endl;
        cout<<"Cantidad: "<<reg.cantidad<<endl;
        cout<<"Precio: "<<reg.precioUn<<endl;
        cout<<"Fecha: "<<reg.diaPedido.dia<<"/"<<reg.diaPedido.mes<<"/"<<reg.diaPedido.anio<<endl;
        cout<<"Valor: "<<reg.valor<<endl;
        cout<<"Estado: "<<reg.estado<<endl;
        cout<<"------------------------"<<endl;
}
fclose(p);
}
void listarPedidoXID(){
    FILE *p;
    p=fopen("pedidos.dat","rb");
    if(p==NULL){
        cout<<"Error al abrir el archivo"<<endl;
    }
    pedido reg;
    int id;
    cout<<"Ingrese ID: ";
    cin>>id;
    while(fread(&reg, sizeof reg,1,p)==1){
        if(reg.id==id){
        cout<<"------------------------"<<endl;
        cout<<"ID: "<<reg.id<<endl;
        cout<<"ID Cliente: "<<reg.IDCliente<<endl;
        cout<<"ID Plato: "<<reg.IDPlato<<endl;
        cout<<"Cantidad: "<<reg.cantidad<<endl;
        cout<<"Precio: "<<reg.precioUn<<endl;
        cout<<"Fecha: "<<reg.diaPedido.dia<<"/"<<reg.diaPedido.mes<<"/"<<reg.diaPedido.anio<<endl;
        cout<<"Valor: "<<reg.valor<<endl;
        cout<<"Estado: "<<reg.estado<<endl;
        cout<<"------------------------"<<endl;
        fclose(p);
        return;
        }
    }
    cout<<"No se encontro el ID"<<endl;
    fclose(p);
    return;
}
void menuPedidos(){
 int opc;
 bool c=true;
    while(c){
        system("cls");
        cout<<"-------------MENU PEDIDOS--------------"<<endl;
        cout<<"1) Nuevo pedido"<<endl;
        cout<<"2) Modificar pedido"<<endl;
        cout<<"3) Listar pedido por ID"<<endl;
        cout<<"4) Listar todos los pedidos"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"0) Volver"<<endl;
        cin>>opc;
        switch(opc){
        case 1:nuevoPedido();
        break;
        case 2:modificarPedido();
        break;
        case 3:listarPedidoXID();
        break;
        case 4:listarPedidos();
        break;
        case 0:c=false;
        break;
        }
        system("pause");
        system("cls");

    }


}
#endif // PEDIDOS_H_INCLUDED
