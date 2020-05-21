#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED
#include "platos.h"
#include "clientes.h"
#include "pedidos.h"

void realizarBackup(){

    char opc;
    cout<<"Realizar un backup eliminara el backup anterior, esta seguro? Y/N"<<endl;
    cin>>opc;
    while(opc!='y' && opc!='n'){
        cout<<"Opcion invalida, ingrese opcion: ";
        cin>>opc;
    }
    if(opc=='y'){
        FILE *pl,*cl,*pe,*plB,*clB,*peB;
        pl=fopen("platos.dat","rb");
        cl=fopen("clientes.dat","rb");
        pe=fopen("pedidos.dat","rb");
        plB=fopen("platos.bkp","wb");
        clB=fopen("clientes.bkp","wb");
        peB=fopen("pedidos.bkp","wb");

        plato plat;
        cliente clien;
        pedido ped;
        while(fread(&plat,sizeof(plat),1,pl)==1){
                fwrite(&plat,sizeof(plat),1,plB);
        }
        while(fread(&clien,sizeof(clien),1,cl)==1){
                fwrite(&clien,sizeof(clien),1,clB);
        }
        while(fread(&ped,sizeof(ped),1,pe)==1){
                fwrite(&ped,sizeof(ped),1,peB);
        }
        fclose(pl);
        fclose(cl);
        fclose(pe);
        fclose(plB);
        fclose(clB);
        fclose(peB);
        }
    if(opc=='n'){
        return;
    }
}

void restaurarBackup(){
    char opc;
    cout<<"Restaurar un backup eliminara los datos actuales, esta seguro? Y/N"<<endl;
    cin>>opc;
    while(opc!='y' && opc!='n'){
        cout<<"Opcion invalida, ingrese opcion: ";
        cin>>opc;
    }
    if(opc=='y'){
        FILE *pl,*cl,*pe,*plB,*clB,*peB;
        pl=fopen("platos.dat","wb");
        cl=fopen("clientes.dat","wb");
        pe=fopen("pedidos.dat","wb");
        plB=fopen("platos.bkp","rb");
        clB=fopen("clientes.bkp","rb");
        peB=fopen("pedidos.bkp","rb");

        plato plat;
        cliente clien;
        pedido ped;
        while(fread(&plat,sizeof(plat),1,plB)==1){
                fwrite(&plat,sizeof(plat),1,pl);
        }
        while(fread(&clien,sizeof(clien),1,clB)==1){
                fwrite(&clien,sizeof(clien),1,cl);
        }
        while(fread(&ped,sizeof(ped),1,peB)==1){
                fwrite(&ped,sizeof(ped),1,pe);
        }
        fclose(pl);
        fclose(cl);
        fclose(pe);
        fclose(plB);
        fclose(clB);
        fclose(peB);
        }
    if(opc=='n'){
        return;
    }
}

void menuConfig(){
int opc;
    bool c=true;
while(c){
        system("cls");
    cout<<"Menu configuracion"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"1)Realizar Backup"<<endl;
    cout<<"2)Restaurar Backup"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"0)Volver al menu principal"<<endl;
    cin>>opc;
    switch(opc){
    case 1:realizarBackup();
    break;
    case 2:restaurarBackup();
    break;
    case 0:c=false;
    break;
    }
    system("pause");
    system("cls");
}
}

#endif // CONFIGURACION_H_INCLUDED
