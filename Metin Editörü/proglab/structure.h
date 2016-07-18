#include<stdio.h>
#include<conio.h>

struct structHarf
{
       int Value;
       structHarf* Left;
       structHarf* Right;
};

void BagliListeyiYaz(structHarf* baslangicHarf,structHarf *sonHarf)
{
     char charYazilan[10000];
     EkranSil();
     structHarf *curs = baslangicHarf;
     int i=0;
     while(curs!=NULL)
     {
                      if(curs->Value!=BOSHARF)
                      {
                            charYazilan[i]=curs->Value;
                            i++;
                      }
                      curs=curs->Right;
     }
     charYazilan[i]=SONKARAKTER;
     printf("%s",charYazilan);
     
}

void ConsoleInfo(structHarf* baslangicHarf,structHarf *sonHarf,int CurrentX,int CurrentY)
{
     SetConsoleTitle("Editor Mevcut Durum Bilgileri");
     EkranSil();
     structHarf *curs = baslangicHarf;
     int i=0,j=1;
     while(curs!=NULL)
     {
                    
           curs=curs->Right;
           i++;
           if(i%80==0)
           j++;
     }
     char CursorInfo[255];
     char ToplamHarf[255];
     char stringoTopSatir[255];
     sprintf(CursorInfo,"\nMouse pozisyonu [Y,X] [%d: %d]",CurrentY,CurrentX);
     sprintf(ToplamHarf,"\nToplam harf %d.",i);
     sprintf(stringoTopSatir,"\nToplam satir %d. \nGeri donmek icin bir tusa basin...",j);
     for(int x=0;x<strlen(CursorInfo);x++)
     {
             printf("%c",CursorInfo[x]);
             Sleep(30);
     }  
     Sleep(350);
     for(int x=0;x<strlen(ToplamHarf);x++)
     {
             printf("%c",ToplamHarf[x]);
             Sleep(30);
     }  
     
     Sleep(350);
     for(int x=0;x<strlen(stringoTopSatir);x++)
     {
             printf("%c",stringoTopSatir[x]);
             Sleep(30);
     }  
     getch();
}
