#ifndef PLATOS_H_INCLUDED
#define PLATOS_H_INCLUDED

struct plato{
int id;
char nombre[50];
float costo;
float valor;
int tiempo;
int IDRestarurante;
int Comision;
int IDCategoria;
bool estado;

};

bool checkIDPlato(int id){
FILE *p;
p=fopen("platos.dat","rb");
if(p==NULL){
    cout<<"Error al abrir el archivo";
}
plato reg;
while(fread(&reg, sizeof reg,1,p)==1){
    if(reg.id==id){
        fclose(p);
        return true;
    }
}
fclose(p);
return false;
}

void nuevoPlato(){
    FILE *p;
    p=fopen("platos.dat","ab");
    if(p==NULL){
    cout<<"Error al abrir el archivo";
}
plato reg;
cout<<"Ingrese ID: "<<endl;
cin>>reg.id;
while(reg.id<0 || checkIDPlato(reg.id)){
    cout<<"ID invalida, ingrese ID: "<<endl;
    cin>>reg.id;
}
cout<<"Ingrese nombre del plato: "<<endl;
reg.nombre[0]=0;
cin.getline(reg.nombre,50);
while(reg.nombre[0]==0){
    cout<<"nombre invalido"<<endl;
    cin.getline(reg.nombre,50);
}
cout<<"Ingrese costo: "<<endl;
cin>>reg.costo;
while(reg.costo<0){
    cout<<"Costo invalido, ingrese costo: "<<endl;
    cin>>reg.costo;
}
cout<<"Ingrese valor: "<<endl;
cin>>reg.valor;
while(reg.valor<reg.costo){
    cout<<"Valor invalido, ingrese valor: "<<endl;
    cin>>reg.valor;
}
cout<<"Ingrese tiempo: "<<endl;
cin>>reg.tiempo;
while(reg.tiempo<0){
      cout<<"Tiempo invalido, ingrese tiempo: "<<endl;
    cin>>reg.tiempo;
}
cout<<"Ingrese id Restaurante: "<<endl;
cin>>reg.IDRestarurante;
while(reg.IDRestarurante<0){
      cout<<"ID invalida, ingrese ID: "<<endl;
    cin>>reg.IDRestarurante;
}
cout<<"Ingrese comision: "<<endl;
cin>>reg.Comision;
while(reg.Comision<=0 || reg.Comision>=100){
      cout<<"Comision invalido, ingrese comision: "<<endl;
    cin>>reg.Comision;
}
cout<<"Ingrese ID Categoria: "<<endl;
cin>>reg.IDCategoria;
while(reg.IDCategoria<0){
      cout<<"ID invalida, ingrese ID: "<<endl;
    cin>>reg.IDCategoria;
}
reg.estado=true;

fwrite(&reg, sizeof(reg),1,p);

fclose(p);
}

void modificarPlato(){
int id,costo, tiempo;
int cnt=0;
cout<<"Ingrese ID: "<<endl;
cin>>id;
FILE *p;
p=fopen("platos.dat","rb+");
if(p==NULL){
    cout<<"Error al abrir el archivo";
}
plato reg;
while(fread(&reg,sizeof reg,1,p)==1){
    if(reg.id==id){
        cout<<"Ingrese nuevo costo: "<<endl;
        cin>>costo;
        while(costo<0){
        cout<<"Costo invalido, ingrese costo: "<<endl;
        cin>>costo;
        }
        cout<<"Ingrese nuevo tiempo: "<<endl;
        cin>>tiempo;
        while(tiempo<0){
        cout<<"Tiempo invalido, ingrese tiempo: "<<endl;
        cin>>tiempo;
        }
        reg.costo=costo;
        reg.tiempo=tiempo;
        fseek(p,cnt*sizeof(reg),0);
        fwrite(&reg,sizeof(reg),1,p);
        fclose(p);
        return;
    }
    cnt++;
}
cout<<"No existe un plato con esa ID"<<endl;
fclose(p);
}
void listarPlatos(){
    FILE *p;
    p=fopen("platos.dat","rb");
    plato reg;
    while(fread(&reg,sizeof reg,1,p)==1){
        cout<<"------------------------"<<endl;
        cout<<"ID: "<<reg.id<<endl;
        cout<<"Nombre: "<<reg.nombre<<endl;
        cout<<"Costo: "<<reg.costo<<endl;
        cout<<"Valor: "<<reg.valor<<endl;
        cout<<"Tiempo: "<<reg.tiempo<<endl;
        cout<<"ID Restaurante: "<<reg.IDRestarurante<<endl;
        cout<<"Comision: "<<reg.Comision<<endl;
        cout<<"ID Categoria: "<<reg.IDCategoria<<endl;
        cout<<"Estado: "<<reg.estado<<endl;
        cout<<"------------------------"<<endl;
    }
    fclose(p);
}
void eliminarPlato(){
int id;
int cnt=0;
cout<<"Ingrese ID: "<<endl;
cin>>id;
FILE *p;
p=fopen("platos.dat","rb+");
if(p==NULL){
    cout<<"Error al abrir el archivo";
}
plato reg;
while(fread(&reg,sizeof reg,1,p)==1){
    if(reg.id==id){
        reg.estado=false;
        cout<<"Plato eliminado (Estado=false)"<<endl;
          fseek(p,cnt*sizeof(reg),0);
          fwrite(&reg,sizeof(reg),1,p);
          fclose(p);
          return;
    }
    cnt++;
}
cout<<"No se encontro al plato"<<endl;
fclose(p);
}
void listarPlatoXID(){
    plato reg;
    int id;
    FILE *p;
    p=fopen("platos.dat","rb");
    cout<<"Ingrese ID: ";
    cin>>id;
    while(fread(&reg, sizeof reg,1,p)==1){
        if(reg.id==id){
        cout<<"------------------------"<<endl;
        cout<<"ID: "<<reg.id<<endl;
        cout<<"Nombre: "<<reg.nombre<<endl;
        cout<<"Costo: "<<reg.costo<<endl;
        cout<<"Valor: "<<reg.valor<<endl;
        cout<<"Tiempo: "<<reg.tiempo<<endl;
        cout<<"ID Restaurante: "<<reg.IDRestarurante<<endl;
        cout<<"Comision: "<<reg.Comision<<endl;
        cout<<"ID Categoria: "<<reg.IDCategoria<<endl;
        cout<<"Estado: "<<reg.estado<<endl;
        cout<<"------------------------"<<endl;
        fclose(p);
        return;
        }
    }
    fclose(p);
    cout<<"No hay un plato con ese ID"<<endl;
}
void listarPlatoXIDRestaurante(){
    plato reg;
    int id;
    FILE *p;
    p=fopen("platos.dat","rb");
    cout<<"Ingrese ID: ";
    cin>>id;
    while(fread(&reg, sizeof reg,1,p)==1){
        if(reg.IDRestarurante==id){
        cout<<"------------------------"<<endl;
        cout<<"ID: "<<reg.id<<endl;
        cout<<"Nombre: "<<reg.nombre<<endl;
        cout<<"Costo: "<<reg.costo<<endl;
        cout<<"Valor: "<<reg.valor<<endl;
        cout<<"Tiempo: "<<reg.tiempo<<endl;
        cout<<"ID Restaurante: "<<reg.IDRestarurante<<endl;
        cout<<"Comision: "<<reg.Comision<<endl;
        cout<<"ID Categoria: "<<reg.IDCategoria<<endl;
        cout<<"Estado: "<<reg.estado<<endl;
        cout<<"------------------------"<<endl;
        }
    }
    fclose(p);
}
void menuPlatos(){
 int opc;
 bool c=true;
    while(c){
        system("cls");
        cout<<"-------------MENU PLATOS--------------"<<endl;
        cout<<"1) Nuevo Plato"<<endl;
        cout<<"2) Modificar Plato"<<endl;
        cout<<"3) Listar Plato por ID"<<endl;
        cout<<"4) Platos por restaurant"<<endl;
        cout<<"5) Listar todos los platos"<<endl;
        cout<<"6) Eliminar plato"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"0) Volver"<<endl;
        cin>>opc;
        switch(opc){
        case 1:nuevoPlato();
        break;
        case 2:modificarPlato();
        break;
        case 3:listarPlatoXID();
        break;
        case 4:listarPlatoXIDRestaurante();
        break;
        case 5:listarPlatos();
        break;
        case 6:eliminarPlato();
        break;
        case 0:c=false;
        break;
        }
        system("pause");
        system("cls");

    }


}



#endif // PLATOS_H_INCLUDED

