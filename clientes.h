#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include <cctype>
#include <ctype.h>
#include <cstring>

struct Fecha{
  int dia, mes, anio;
};

struct cliente{
int id;
char apellidos[50];
char nombre[50];
char mail[50];
char domicilio[100];
int CP;
Fecha nac;
bool estado=true;
};
bool checkMail(char mail[100]){
    if(mail[0]=='@' ||mail[0]=='.'){
            cout<<"1";
        return false;
    }
    int arroba=0;
    int punto=0;
        for(int i=0;i<100;i++){
            if(mail[i]=='@'){
                arroba++;
            }
            if(mail[i]=='.'){
                    if(mail[i+1]=='.'){
                                    cout<<"2";
                        return false;
                    }
                punto++;
            }
            /*if(mail[i]==' '){
                            cout<<"3";
                return false;
            }*/
            if(mail[i]=='\0'){
                if(mail[i-1]=='.'){
                                cout<<"4";
                    return false;
                }
            }
        }
        if(punto<1){
                        cout<<"5";
            return false;
        }
        if(arroba!=2){
                        cout<<arroba;
            return false;
        }
        return true;
}
void nuevoCliente(){
FILE *p;
p=fopen("clientes.dat","ab+");
if(p==NULL){
    cout<<"Error al abrir el archivo";
}
cliente reg;
int cnt=1;
while(fread(&reg,sizeof reg,1,p)==1){
    cnt++;
}
reg.id=cnt;

cout<<"Ingrese apellidos: "<<endl;
reg.apellidos[0]=0;
cin.getline(reg.apellidos,50);
while(reg.apellidos[0]==0){
    cout<<"Apellido invalido"<<endl;
    cin.getline(reg.apellidos,50);
}
cout<<"Ingrese nombres: "<<endl;
reg.nombre[0]=0;
cin.getline(reg.nombre,50);
while(reg.nombre[0]==0){
    cout<<"nombre invalido"<<endl;
    cin.getline(reg.nombre,50);
}
cout<<"Ingrese mail: "<<endl;
reg.mail[0]=0;
cin.getline(reg.mail,50);
while(checkMail(reg.mail)==false){
    cout<<"mail invalido"<<endl;
    cin.getline(reg.mail,50);
}
cout<<"Ingrese domicilio: "<<endl;
reg.domicilio[0]=0;
cin.getline(reg.domicilio,100);
while(reg.domicilio[0]==0){
    cout<<"Domicilio invalido"<<endl;
    cin.getline(reg.domicilio,100);
}
cout<<"Ingrese CP: "<<endl;
cin>>reg.CP;
if(reg.CP<1000 || reg.CP>9999){
    cout<<"CP Invalido, ingrese CP: "<<endl;
    cin>>reg.CP;
}
cout<<"Ingrese fecha: "<<endl;
cout<<"Dia: ";
cin>>reg.nac.dia;
while(reg.nac.dia<1 || reg.nac.dia>31){
    cout<<"Dia invalido, ingrese dia: "<<endl;
    cin>>reg.nac.dia;
}
cout<<"Mes: ";
cin>>reg.nac.mes;
while(reg.nac.mes<1 || reg.nac.mes>12){
    cout<<"Mes invalido, ingrese mes: "<<endl;
    cin>>reg.nac.mes;
}
cout<<"Anio: ";
cin>>reg.nac.anio;
while(reg.nac.anio<1900 || reg.nac.anio>2020){
    cout<<"Anio invalido, ingrese anio: "<<endl;
    cin>>reg.nac.anio;
}
fwrite(&reg,sizeof reg,1,p);
fclose(p);
}
void listarClientes(){
    FILE *p;
    p=fopen("clientes.dat","rb");
    cliente reg;
    while(fread(&reg,sizeof reg,1,p)==1){
        cout<<"------------------------"<<endl;
        cout<<"ID: "<<reg.id<<endl;
        cout<<"Nombre: "<<reg.nombre<<endl;
        cout<<"Apellido: "<<reg.apellidos<<endl;
        cout<<"Mail: "<<reg.mail<<endl;
        cout<<"Domicilio: "<<reg.domicilio<<endl;
        cout<<"CP: "<<reg.CP<<endl;
        cout<<"Fecha: "<<reg.nac.dia<<"/"<<reg.nac.mes<<"/"<<reg.nac.anio<<endl;
        cout<<"Estado: "<<reg.estado<<endl;
        cout<<"------------------------"<<endl;
    }
    fclose(p);
}
void modificarCliente(){
int id;
int cnt=0;
//char dom[100];
cout<<"Ingrese ID: "<<endl;
cin>>id;
FILE *p;
p=fopen("clientes.dat","rb+");
if(p==NULL){
    cout<<"Error al abrir el archivo";
}
cliente reg;
while(fread(&reg,sizeof reg,1,p)==1){
    if(reg.id==id){
        cout<<"Ingrese nuevo domicilio: "<<endl;
        cin.getline(reg.domicilio,100);
        while(reg.domicilio[0]==0){
        cout<<"Domicilio invalido"<<endl;
        cin.getline(reg.domicilio,100);
          }
          //strcpy(reg.domicilio,dom);
          fseek(p,cnt*sizeof(reg),0);
          fwrite(&reg,sizeof(reg),1,p);
          fclose(p);
          return;
    }
    cnt++;
}
fclose(p);
}
void listarID(){
    cliente reg;
    int id;
    FILE *p;
    p=fopen("clientes.dat","rb");
    cout<<"Ingrese ID: ";
    cin>>id;
    while(fread(&reg, sizeof reg,1,p)==1){
        if(reg.id==id){
        cout<<"------------------------"<<endl;
        cout<<"ID: "<<reg.id<<endl;
        cout<<"Nombre: "<<reg.nombre<<endl;
        cout<<"Apellido: "<<reg.apellidos<<endl;
        cout<<"Mail: "<<reg.mail<<endl;
        cout<<"Domicilio: "<<reg.domicilio<<endl;
        cout<<"CP: "<<reg.CP<<endl;
        cout<<"Fecha: "<<reg.nac.dia<<"/"<<reg.nac.mes<<"/"<<reg.nac.anio<<endl;
        cout<<"Estado: "<<reg.estado<<endl;
        cout<<"------------------------"<<endl;
        fclose(p);
        return;
        }
    }
    fclose(p);
    cout<<"No hay un cliente con ese ID"<<endl;
}
void eliminarCliente(){
int id;
int cnt=0;
cout<<"Ingrese ID: "<<endl;
cin>>id;
FILE *p;
p=fopen("clientes.dat","rb+");
if(p==NULL){
    cout<<"Error al abrir el archivo";
}
cliente reg;
while(fread(&reg,sizeof reg,1,p)==1){
    if(reg.id==id){
        reg.estado=false;
        cout<<"Cliente eliminado (Estado=false)"<<endl;
          fseek(p,cnt*sizeof(reg),0);
          fwrite(&reg,sizeof(reg),1,p);
          fclose(p);
          return;
    }
    cnt++;
}
cout<<"No se encontro al cliente"<<endl;
fclose(p);
}
void menuClientes(){
 int opc;
 bool c=true;
    while(c){
        system("cls");
        cout<<"-------------MENU CLIENTES--------------"<<endl;
        cout<<"1) Nuevo cliente"<<endl;
        cout<<"2) Modificar cliente"<<endl;
        cout<<"3) Listar cliente por ID"<<endl;
        cout<<"4) Listar todos los clientes"<<endl;
        cout<<"5) Eliminar cliente"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"0) Volver"<<endl;
        cin>>opc;
        switch(opc){
        case 1:nuevoCliente();
        break;
        case 2:modificarCliente();
        break;
        case 3:listarID();
        break;
        case 4:listarClientes();
        break;
        case 5:eliminarCliente();
        break;
        case 0:c=false;
        break;
        }
        system("pause");
        system("cls");

    }


}
#endif // CLIENTES_H_INCLUDED
