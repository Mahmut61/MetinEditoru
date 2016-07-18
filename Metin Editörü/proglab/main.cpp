#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <string.h>

#include<malloc.h>

#include "defines.h"
#include "functions.h"
#include "structure.h"
#include "fileoperations.h"




structHarf *baslangicHarf=NULL,*sonHarf=NULL,*CursorHarf=NULL;
void BagliLiseyeEkle(char);
void IlkEkran();

void IlkElemanEkleme(char);
void SonElemanEkleme(char);
void ArayaEkleme(char);
void BasaEkleme(char);
bool UstuneEkle(char);
bool HarfSwitch(char);
void BagliListedenSil();
void AradanSil();
void SondanSil();
void BastanSil();
void BirlikteTusKontrol(char);
void BirlikteTusKontrolInsert(char);
                                         
int MouseX=0,MouseY=0,LastKey=0;
char strKayitliDosyaYol[255];
bool boolSaveAs=false;


clock_t time1,time2,time3,time4;
int ControlInt=0,ControlInt2=0;
main()
{
     SetConsoleTitle("Ana menu");
     IlkEkran();   
}


void DonguBaslat()
{
     SetConsoleTitle("Editor");
     
     CursorHarf=(structHarf*) malloc( sizeof(struct structHarf) ); 
     CursorHarf->Left=NULL;
     CursorHarf->Right=NULL;
     
     EkranSil();
     while(true)
     {
               char charOkunan = getch();
               if(!HarfSwitch(charOkunan))
               break;
     }
}

bool HarfSwitch(char charOkunan)
{
          switch(charOkunan)
          {
                                 case ESITTIR:                 
                                      ConsoleInfo(baslangicHarf,sonHarf,MouseX+1,MouseY+1);
                                      BagliListeyiYaz(baslangicHarf,sonHarf);
                                      SetConsoleTitle("Editor");
                                      Git(MouseX,MouseY);
                                      break; 
                                 case SORUISARETI:
                                      Help();                      
                                      BagliListeyiYaz(baslangicHarf,sonHarf);
                                      SetConsoleTitle("Editor");
                                      break;                 
                                 case ARTI:
                                      if(boolSaveAs)
                                      Save(baslangicHarf,sonHarf,filePath);                     
                                      else 
                                      {
                                      
                                           SaveAs(baslangicHarf,sonHarf,false);
                                           if(strlen(filePath)>0)
                                           {
                                              boolSaveAs=true;          
                                           }
                                      }
                                       BagliListeyiYaz(baslangicHarf,sonHarf);
                                       SetConsoleTitle("Editor");
                                      break; 
                                 case EKSI:
                                                                          
                                    
                                      SaveAs(baslangicHarf,sonHarf,boolSaveAs);
                                      if(strlen(filePath)>0)
                                      {
                                          boolSaveAs=true;
                                      }
                                       BagliListeyiYaz(baslangicHarf,sonHarf);
                                       SetConsoleTitle("Editor");
                                      break;
                                 case SILME:
                                      BagliListedenSil();
                                      BagliListeyiYaz(baslangicHarf,sonHarf);
                                      Git(MouseX,MouseY);
                                     
                                      break;
                                 case YONTUS:
                                      {
                                          char yonChara = getch();
                                          if(yonChara==YUKARI)
                                          {
                                               if(MouseY>0)
                                               {       
                                                   for(int i=0;i<80;i++)
                                                   {
                                                          CursorHarf=CursorHarf->Left;
                                                   }
                                                   MouseY--;
                                               }              
                                          }
                                          else if(yonChara==ASAGI)
                                          {
                                                   int i=0;
                                                   if(CursorHarf==NULL && baslangicHarf!=NULL)
                                                   {
                                                        CursorHarf = baslangicHarf;
                                                        i++;     
                                                        MouseX++;         
                                                   }
                                                   for(int i=0;i<80;i++)
                                                   {
                                                         if(CursorHarf->Right!=NULL)
                                                         {
                                                                 CursorHarf = CursorHarf->Right;
                                                                 MouseX++;
                                                                 if(MouseX>79)
                                                                 {
                                                                     MouseX=0;
                                                                     MouseY++;
                                                                 }
                                                         }
                                                         else
                                                         {
                                                              break;
                                                         }
                                                   }
                                          }
                                          else if(yonChara==SOL)
                                          {
                                               if(MouseX>0)
                                               {
                                                           if(CursorHarf!=NULL)
                                                           {
                                                               CursorHarf=CursorHarf->Left;
                                                               MouseX=MouseX-1;
                                                           }   
                                               }    
                                          }
                                          else if(yonChara==SAG)
                                          {
                                               if(MouseX<79)
                                               {
                                                           if(CursorHarf->Right!=NULL)
                                                           {
                                                               CursorHarf=CursorHarf->Right;
                                                               MouseX=MouseX+1;
                                                           }  
                                               }
                                          }
                                          Git(MouseX,MouseY);
                                      }
                                 break;
                                 
                                 case 13: 
                                 case 27:
                                      
                                      break;
                                
                                default:
                                    
                                         BagliLiseyeEkle(charOkunan);
                                        
                                         MouseX++;
                                         if(MouseX>79)
                                         {
                                             MouseX=0;
                                             MouseY++;
                                         }
                                         BirlikteTusKontrol(charOkunan);
                                         BirlikteTusKontrolInsert(charOkunan);
                                         BagliListeyiYaz(baslangicHarf,sonHarf);
                                         Git(MouseX,MouseY);
                                         break;                                 
               }
               return true;
}
void BirlikteTusKontrol(char charOkunan)
{
         if(charOkunan==NOKTA)
         {
               if(ControlInt==TIRNAK)
               {
                    time2=clock();
                    if(isSameTime(time2,time1))
                       exit(0);
                    else 
                       ControlInt=0;
               }
               else
               {
                    ControlInt = NOKTA;
                    time1=clock();
               }
         }
         else if(charOkunan==TIRNAK)
         {
                if(ControlInt==NOKTA)
                {
                     time2=clock();
                     if(isSameTime(time2,time1))
                        exit(0);
                     else 
                        ControlInt=0;
                }
                else
                {
                     ControlInt=TIRNAK;
                     time1=clock();
                }           
         }
         else ControlInt=0;  
}
bool isX(char charOkunan)
{
     if(charOkunan==XBUYUK || charOkunan ==XKUCUK)
     return true;
     else return false;
}
bool isY(char charOkunan)
{
     if(charOkunan==YBUYUK || charOkunan == YKUCUK)
     return true;
     else return false;
}

void BirlikteTusKontrolInsert(char charOkunan)
{
         if(isX(charOkunan))
         {
               if(isY(ControlInt2))
               {
                    time4=clock();
                    if(isSameTime(time4,time3))
                    {boolInsertActive=!boolInsertActive;BagliListedenSil();BagliListedenSil();}
                    else 
                       ControlInt2=BOSHARF;
               }
               else
               {
                    ControlInt2 = XBUYUK;
                    time3=clock();
               }
         }
         else if(isY(charOkunan))
         {
                if(isX(ControlInt2))
                {
                     time4=clock();
                     if(isSameTime(time4,time3))
                     {boolInsertActive=!boolInsertActive;BagliListedenSil();BagliListedenSil();}
                     else 
                        ControlInt2=BOSHARF;
                }
                else
                {
                     ControlInt2=YBUYUK;
                     time3=clock();
                }           
         }
         else ControlInt2=BOSHARF;
         
         
           
}
void IlkEkran()
{
     SetConsoleTitle("Ana menu");
     printf("\n\n1. Yeni Dosya\n");
     printf("2. Yardim\n");
     printf("3. Cikis\n");
    
     printf("Seciminiz    ");
     
     bool boolSecildimi=false;
     bool yardimSecildimi=false;
     while(!boolSecildimi)
     {
                char secim=getch();
                switch(secim)
                {
                             case '1':boolSecildimi=true;DonguBaslat();boolSecildimi=true;break;
                             case '2':Help();yardimSecildimi=true;boolSecildimi=true;break;
                             case '3':exit(0);boolSecildimi=true; break;
                }
     }     
     if(yardimSecildimi==true)
     {
          IlkEkran();
     }
}
void BagliLiseyeEkle(char EklenenHarf)
{
    if((boolInsertActive && CursorHarf!=NULL))
    {
              if(UstuneEkle(EklenenHarf))
              return;
    }
    if(baslangicHarf==NULL)//baðlý listeye ekleme if leri   
        IlkElemanEkleme(EklenenHarf);
    else if(CursorHarf==sonHarf)
        SonElemanEkleme(EklenenHarf);
    else if(CursorHarf==NULL)
        BasaEkleme(EklenenHarf);
    else
         ArayaEkleme(EklenenHarf);
    return; 
}
bool UstuneEkle(char EklenenHarf)
{
     if(CursorHarf->Right!=NULL)
     {         
             CursorHarf->Right->Value=EklenenHarf; 
             CursorHarf=CursorHarf->Right;         
             return  true; 
     }
     else return false;
     
}
void IlkElemanEkleme(char EklenenHarf)
{
        structHarf*  YeniEleman =(structHarf*) malloc(sizeof(struct structHarf) ); 
        YeniEleman->Value=EklenenHarf;
        baslangicHarf=YeniEleman; 
        baslangicHarf->Right=NULL;
        baslangicHarf->Left=NULL;
        sonHarf=baslangicHarf;
        CursorHarf=baslangicHarf;
}

void SonElemanEkleme(char EklenenHarf)
{
        structHarf*  YeniEleman =(structHarf*) malloc(sizeof(struct structHarf) ); 
        YeniEleman->Value=EklenenHarf;
        
        sonHarf->Right=YeniEleman;   
        YeniEleman->Left=sonHarf;
        sonHarf=YeniEleman;
        sonHarf->Right=NULL;
        CursorHarf=YeniEleman;
}
void ArayaEkleme(char EklenenHarf)
{
         structHarf*  YeniEleman =(structHarf*) malloc(sizeof(struct structHarf) ); 
         YeniEleman->Value=EklenenHarf;
        
         YeniEleman->Right=CursorHarf->Right;
         YeniEleman->Right->Left=YeniEleman;
         YeniEleman->Left=CursorHarf;
         CursorHarf->Right=YeniEleman;
         CursorHarf=YeniEleman;
}
void BasaEkleme(char EklenenHarf)
{
        structHarf*  YeniEleman =(structHarf*) malloc(sizeof(struct structHarf) ); 
       
        YeniEleman->Right=baslangicHarf;   
        baslangicHarf->Left=YeniEleman;
        YeniEleman->Value=EklenenHarf;
        YeniEleman->Left=NULL;
        
        baslangicHarf=YeniEleman;
        CursorHarf=YeniEleman;    
}

void BagliListedenSil()
{
    if((MouseX==0 && MouseY==0) || CursorHarf==NULL)
    return;
   
    
    if(CursorHarf==baslangicHarf)
    {
        BastanSil();
    }
    else if(CursorHarf==sonHarf)
    {    
         SondanSil();
    }
    else
    {
        AradanSil();
    }
}
void BastanSil()
{
      if(baslangicHarf->Right==NULL)
      {
           CursorHarf=NULL;
           baslangicHarf=NULL;
           sonHarf=NULL;   
           free(baslangicHarf); 
           free(sonHarf);
           CursorHarf=(structHarf*) malloc( sizeof(struct structHarf) ); 
           CursorHarf->Left=NULL;
           CursorHarf->Right=NULL;         
      }
      else
      {
           structHarf*  StructRight=CursorHarf->Right;
           free(CursorHarf);
           baslangicHarf=StructRight;
           baslangicHarf->Left=NULL;
           CursorHarf=NULL;
      }
      MouseX=0;
      MouseY=0;  
}
void SondanSil()
{
      sonHarf=sonHarf->Left;
      sonHarf->Right=NULL;
      free(CursorHarf);
      CursorHarf=sonHarf;
      if(MouseX>0)
      MouseX--;
      else
      {
          MouseY--;
          MouseX=79;
      }
}
void AradanSil()
{
      structHarf*  StructLeft=CursorHarf->Left;
      CursorHarf->Left->Right=CursorHarf->Right;
      CursorHarf->Right->Left=CursorHarf->Left;
      free(CursorHarf);
      CursorHarf=StructLeft;  
      if(MouseX>0)
      MouseX--;
      else
      {
          MouseY--;
          MouseX=79;
      }
}
