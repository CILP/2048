#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//estructura
struct jugar{
       int puntos;
       char nombre[20];
       };
//prototipos
//inicio y archivos 
int verifica(char nombre[]);      
void inicio(int **x,int puntos,int final);
void datos(int **x,int puntos,int final);
//tecla arriba
int prueba_arriba(int **x,int puntos,char nombre[20],int prueba,int final);
void tecla_arriba(int **x,int puntos,char nombre[20],int prueba,int final);
//tecla abajo
int prueba_abajo(int **x,int puntos,char nombre[20],int prueba,int final);
void tecla_abajo(int **x,int puntos,char nombre[20],int prueba,int final);
//tecla izquierda
int prueba_izquierda(int **x,int puntos,char nombre[20],int prueba,int final);
void tecla_izquierda(int **x,int puntos,char nombre[20],int prueba,int final);
//tecla derecha
int prueba_derecha(int **x,int puntos,char nombre[20],int prueba,int final);
void tecla_derecha(int **x,int puntos,char nombre[20],int prueba,int final);
//imprimir y jugar
void imprimir(int **x,int puntos,char nombre[20],int prueba,int final);
int jugar(int **x,int puntos,char nombre[20],int prueba,int final);
//funciones de termino
int game_over(int **x);
void registro(int puntos,char nombre[20]);
void general(int puntos,char nombre[20]);
void ordenamiento(struct jugar gamer[],int k);
/***********************************************************/
//funcion principal
int aux;

int main()
{
    int **x,i,puntos=0,final,a,b;
    
    x=(int **)calloc(4,sizeof(int*));
    for(i=0;i<4;i++)
       x[i]=(int*)calloc(4,sizeof(int));
    //inicia el juego
      srand(time(NULL));
           a=rand()%4;
           b=rand()%4;
           while(x[a][b]!=0)
              {
                 a=rand()%4;
                 b=rand()%4;             
              }
          x[a][b]=2;
       inicio(x,puntos,final);
    system("pause");
}
/***************************************************************/
//termina funcion principal

//funciones adicionales
//verificar que el nombre solo tenga una palabra
int verifica(char nombre[])
{
     int i;
     for(i=0;i<(strlen(nombre));i++)
     {
        if(nombre[i]==' ')
        return 1;
     }
   return 0;
}
//funcion para dar inicio al juego
void inicio(int **x,int puntos,int final)
{
     char tecla=0;
     while(tecla != 13)
     {
         system("cls");
         printf("\n\n\n\n\n\n\n\n\n\n");
         printf("                                  2048\n");
         printf("\n\n\n\n                          PRESS ENTER TO START\n\n\n\n\n");
         tecla = getch();      
     }
     
     datos(x,puntos,final);
}
//acaba la funcion de inicio

/***********************************************************/
//recabo datos del usuario del archivo score.txt
//recabo datos del nuevo usuario
void datos(int **x,int puntos,int final)
{
   char nombre[20];
   int prueba=1,comprobacion=0;
   
   do
   {
   system("cls");
   printf("favor de introducir UNA SOLA PALABRA!!!!!!!!!!!!!!!!!!  >.<");
    if(comprobacion==1)
       printf("\n\n\t\t******MUY GRACIOSO :/ ****");
    printf("\n\n\nNombre del usuario: ");
    fflush(stdin);
    gets(nombre);
    comprobacion= verifica(nombre);
   }while(comprobacion==1);
   
    puntos=0;
    
    imprimir(x,puntos,nombre,prueba,final);
}
//termino de recabar datos
//imprimo talero inicial
void imprimir(int **x,int puntos,char nombre[20],int prueba,int final)
{
    char tecla=0;
    int i,j,a,b;
    final= game_over(x);
    
    if(final==1)
    { 
       if(prueba == 0)
         {
            system("cls");
            printf("\n\n\n\tusuario:%s\t\t\t\t\tscore:  %d",nombre,puntos);
            printf("\n\n\n\n\n\n                        ");
            for(i=0;i<4;i++)
               {
                   for(j=0;j<4;j++)
                      {
                          printf("|%d|\t",x[i][j]);
                      }
                   printf("\n\n                        ");
               }
          }
       else
         {
           srand(time(NULL));
           a=rand()%4;
           b=rand()%4;
           while(x[a][b]!=0)
              {
                 a=rand()%4;
                 b=rand()%4;             
              }
          x[a][b]=2;
    
          system("cls");
          printf("\n\n\n\tusuario:%s\t\t\t\t\tscore:  %d",nombre,puntos);
          printf("\n\n\n\n\n\n                        ");
          for(i=0;i<4;i++)
             {           
                for(j=0;j<4;j++)
                {
                        printf("|%d|\t",x[i][j]);
                }
                printf("\n\n                        ");
         }
         
        }
      jugar(x,puntos,nombre,prueba,final);
    }
   else
    {
         while(tecla != 13)
           {
            printf("\n\n\n\tusuario:%s\t\t\t\t\tscore:  %d",nombre,puntos);
            printf("\n\n\n\n\n\n                        ");
            for(i=0;i<4;i++)
               {
                   for(j=0;j<4;j++)
                      {
                          printf("|%d|\t",x[i][j]);
                      }
                   printf("\n\n                        ");
               }
                   printf("\n\n\n\t\t\t******GAME OVER******");
                   printf("\n\nNombre: %s",nombre);
                   printf("\n\nPuntaje: %d\n\n",puntos);
                   printf("\n                          PRESS ENTER TO START\n\n");
                   tecla = getch();
                   system("cls");      
            }
        
        system("cls");
        registro(puntos,nombre);
    } 
}

// termina ejecucion del tablero inicial
/****************************************************************/
//*******************VAMOS A JUGAR******************//
int jugar(int **x,int puntos,char nombre[20],int prueba,int final)
{
     int i,j,k;
     char tecla;
     
     while(1)
     {
       fflush(stdin);
       tecla = getch();
       
         if(tecla == 0)
           {
             fflush(stdin);
             tecla = getch();
           }
          switch(tecla)
             {
                 case 72:
                       prueba_arriba(x,puntos,nombre,prueba,final);
                 break;
                 
                 case 80:
                      prueba_abajo(x,puntos,nombre,prueba,final);
                 break;
                 
                 case 75:
                      prueba_izquierda(x,puntos,nombre,prueba,final);
                 break;
                 case 77:
                      prueba_derecha(x,puntos,nombre,prueba,final);
                 break;
             }
      }     
}
//inician pruebas
//tecla arriba
int prueba_arriba(int **x,int puntos,char nombre[20],int prueba,int final)
{
    int i,j;
    
    for(i=1;i<4;i++)
    {
       for(j=0;j<4;j++)
       {
          if(x[i][j]==x[i-1][j] &&  x[i][j]!=0)
          {
            prueba=1;
            tecla_arriba(x,puntos,nombre,prueba,final);
          }
          else
          {
              if(x[i][j]!=0 && x[i-1][j]==0)
              {
                prueba=1;
                tecla_arriba(x,puntos,nombre,prueba,final);
              }
          }
       }
    }
    prueba=0;
    imprimir(x,puntos,nombre,prueba,final);
}
//tecla abajo
int prueba_abajo(int **x,int puntos,char nombre[20],int prueba,int final)
{
    int i,j;
     
     for(i=0;i<3;i++)
     {
       for(j=0;j<4;j++)
       {
          if(x[i][j]==x[i+1][j] &&  x[i][j]!=0)
          {
            prueba=1;
            tecla_abajo(x,puntos,nombre,prueba,final);
          }
          else
          {
              if(x[i][j]!=0 && x[i+1][j]==0)
              {
                prueba=1;
                tecla_abajo(x,puntos,nombre,prueba,final);
              }
          }
       }
     }
     
     prueba=0;
     imprimir(x,puntos,nombre,prueba,final);
     
}
//tecla izquierda
int prueba_izquierda(int **x,int puntos,char nombre[20],int prueba,int final)
{
    int i,j;
    
    for(i=0;i<4;i++)
    {
      for(j=1;j<4;j++)
      {
        if(x[i][j]==x[i][j-1] &&  x[i][j]!=0)
          {
            prueba=1;
            tecla_izquierda(x,puntos,nombre,prueba,final);
          }
          else
          {
              if(x[i][j]!=0 && x[i][j-1]==0)
              {
                prueba=1;
                tecla_izquierda(x,puntos,nombre,prueba,final);
              }
          }
      }
    }
    prueba=0;
    imprimir(x,puntos,nombre,prueba,final);
    
}
//tecla derecha
int prueba_derecha(int **x,int puntos,char nombre[20],int prueba,int final)
{
    int i,j;
    
    for(i=0;i<4;i++)
    {
      for(j=0;j<3;j++)
      {
        if(x[i][j]==x[i][j+1] &&  x[i][j]!=0)
          {
            prueba=1;
            tecla_derecha(x,puntos,nombre,prueba,final);
          }
          else
          {
              if(x[i][j]!=0 && x[i][j+1]==0)
              {
                prueba=1;
                tecla_derecha(x,puntos,nombre,prueba,final);
              }
          }              
      }
    }
    prueba=0;
    imprimir(x,puntos,nombre,prueba,final);
}
//se acaban comprobaciones
//inician programas teclas
//inicia tecla arriba
void tecla_arriba(int **x,int puntos,char nombre[20],int prueba,int final)
{
     int i,j,k=0;
         fflush(stdin);
     while(k!=4)    
       {  
         for(i=0;i<3;i++)//columnas
            {
                 for(j=0;j<=3;j++)//filas
                    {
                       if(x[i+1][j]==x[i][j])
                         { 
                            x[i][j]=x[i][j]+x[i+1][j];
                            x[i+1][j]=0;
                            puntos+=x[i][j];
                         }
                        else
                         {
                            if(x[i+1][j]!=0 && x[i][j]==0)
                            {
                              x[i][j]=x[i+1][j];
                              x[i+1][j]=0;
                            }
                         }
                     }
                        
             }
           k++;
        }
             fflush(stdin);
    imprimir(x,puntos,nombre,prueba,final);
}
//tecla abajo
void tecla_abajo(int **x,int puntos,char nombre[20],int prueba,int final)
{
     int i,j,k=0;
         fflush(stdin);
         while(k!=4)
         {
              for(i=3;i>0;i--)//columnas
                 {
                     for(j=0;j<=3;j++)//filas
                        {
                            if(x[i-1][j]==x[i][j])
                              { 
                                 x[i][j]=x[i][j]+x[i-1][j];
                                 x[i-1][j]=0;
                                 puntos+=x[i][j];
                              }
                            else
                              {
                                 if(x[i-1][j]!=0 && x[i][j]==0)
                                 {
                                     x[i][j]=x[i-1][j];
                                     x[i-1][j]=0;
                                 }
                              }
                         }               
                 }
              k++;
         }      
     imprimir(x,puntos,nombre,prueba,final);
}
//tecla izquierda
void tecla_izquierda(int **x,int puntos,char nombre[20],int prueba,int final)
{
     int i,j,k=0;
               while(k!=4)
               {
                   for(i=0;i<=3;i++)//filas
                    {
                       for(j=0;j<3;j++)//columnas
                       {
                            if(x[i][j+1]==x[i][j])
                            { 
                              x[i][j]=x[i][j]+x[i][j+1];
                              x[i][j+1]=0;
                              puntos+=x[i][j];
                            }
                            else
                                {
                                  if(x[i][j+1]!=0 && x[i][j]==0)
                                  {
                                    x[i][j]=x[i][j+1];
                                    x[i][j+1]=0;
                                  }
                                }
                       } 
                    }
                 k++;   
               }    
           imprimir(x,puntos,nombre,prueba,final);
}
//tecla derecha
void tecla_derecha(int **x,int puntos,char nombre[20],int prueba,int final)
{
     int i,j,k=0;
     while(k!=4)
     {  
        for(i=0;i<=3;i++)//filas
           {
               for(j=3;j>0;j--)//columnas
                  {
                      if(x[i][j-1]==x[i][j])
                        { 
                            x[i][j]=x[i][j]+x[i][j-1];
                            x[i][j-1]=0;
                            puntos+=x[i][j];
                        }
                      else
                        {
                            if(x[i][j-1]!=0 && x[i][j]==0)
                              {
                                 x[i][j]=x[i][j-1];
                                 x[i][j-1]=0;
                              }
                        }                        
                  }
           }
        k++;
      }    
      imprimir(x,puntos,nombre,prueba,final);
}

//terminan programas teclas
//comienza funcion gane_over
int game_over(int **x)
{
    int i,j;
    //abajo hacia arriba
    for(i=1;i<4;i++)
    {
       for(j=0;j<4;j++)
       {
          if(x[i][j]==x[i-1][j] &&  x[i][j]!=0)
          {
            return 1;
          }
          else
          {
              if(x[i][j]!=0 && x[i-1][j]==0)
              {
                return 1;
              }
          }
       }
    }
    //arriba hacia abajo
    for(i=0;i<3;i++)
     {
       for(j=0;j<4;j++)
       {
          if(x[i][j]==x[i+1][j] &&  x[i][j]!=0)
          {
            return 1;
          }
          else
          {
              if(x[i][j]!=0 && x[i+1][j]==0)
              {
                return 1;
              }
          }
       }
     }
    //derecha hacia izquierda
     for(i=0;i<4;i++)
    {
      for(j=1;j<4;j++)
      {
        if(x[i][j]==x[i][j-1] &&  x[i][j]!=0)
          {
            return 1;
          }
          else
          {
              if(x[i][j]!=0 && x[i][j-1]==0)
              {
                return 1;
              }
          }
      }
    }
    //izquierda hacia derecha
    for(i=0;i<4;i++)
    {
      for(j=0;j<3;j++)
      {
        if(x[i][j]==x[i][j+1] &&  x[i][j]!=0)
          {
            return 1;
          }
          else
          {
              if(x[i][j]!=0 && x[i][j+1]==0)
              {
                return 1;
              }
          }              
      }
    }
    
    return 0;
    
}
//registrando datos del nuevo usuario
void registro(int puntos,char nombre[20])
{
     FILE *ae,*al;
     char salva[20],c;
     
     strcpy(salva,nombre);
     strcat(nombre,(char*)".txt");
     
     ae=fopen(nombre,"a");
        
        if(ae==NULL)
           ae=fopen(nombre,"w");
     
     fprintf(ae,"%d\n",puntos);   
     
     fclose(ae);
     
     al=fopen(nombre,"r");
     
     printf("\n\n\t\t****JUEGO INDIVIDUAL ****");
     printf("\n\nNOTA: Cada renglon es un juego diferente\n\n");
          
     while(feof(al)==0)
     {
         c=fgetc(ae);
           printf("%c",c); 
     }
     fclose(al);
     system("pause");
     general(puntos,salva);
}

void general(int puntos,char nombre[20])
{
  char c[20];
  struct jugar *gamer;    
  FILE *aa,*ar,*aw;
  int i=0,j=0,p;
  
  system("cls");
  printf("\t\t***********RECORD GENERAL****************\n\n\n\n");
  printf("\t\t      ******** TOP 10 *******\n");
  printf("\t\t*****Sino apareces FELICIDADES LUCER  :D*****\n\n");
  aa=fopen("general.txt","r");
     if(aa==NULL)
     {
         aa=fopen("general.txt","a");
         fprintf(aa,"%d %s",puntos,nombre);
     }
     else
     {
         aa=fopen("general.txt","a");
         fprintf(aa,"\n%d %s",puntos,nombre);
     }
  fclose(aa);
  
  ar=fopen("general.txt","r");
  rewind(ar);
  while(feof(ar)== 0)
  {
    fscanf(ar,"%d",&p);
    fscanf(ar,"%s",c);
    j++;
  } 
  
  gamer=(struct jugar*)calloc(j,sizeof(struct jugar));
  
  rewind(aa);
  
  while(feof(aa)== 0)
  {
    fscanf(ar,"%d",&gamer[i].puntos);
    fscanf(ar,"%s",gamer[i].nombre);
    i++;
  }
  fclose(ar);
  
  ordenamiento(gamer,j);
  
  printf("Nombre\tPuntos\n\n");
  
  for(j=0;j<i && j<10;j++)
  {
     printf("%s\t%d\n",gamer[j].nombre,gamer[j].puntos);
  }
  system("pause");
  exit(0);
}

void ordenamiento(struct jugar gamer[],int k)
{
   struct jugar aux;
   int i,j,jug;
   
   for(i=1;i<k;i++)
   {
      aux = gamer[i];
      jug = gamer[i].puntos; 
      for(j=i;j>0 && (gamer[j-1].puntos)<jug;j--)
      {
           gamer[j]=gamer[j-1];
      }             
      gamer[j]=aux;
   }
}
