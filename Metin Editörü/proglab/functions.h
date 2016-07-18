#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<ctime>
#include <stdlib.h>


static bool boolInsertActive=false;
void EkranSil()
{
     system("cls");     
}

void Help()
{
     SetConsoleTitle("Yardim");
     EkranSil();
     char HelpString[]="\n\n\n     Ok tuslarini kullanarak imleci hareket ettirin.\n     Kaydetme islemi icin + farkli kaydet islemi icin eksi tuslarini kullanin.\n     Insert islevini aktif ve inaktif hale getirmek icin x ve y tuslarina basin.\n     Editorden cikis yapip ana menuye donmek icin tirnak ve nokta tuslarina\n\t birlikte basin.\n     Bir onceki bolume donmek icin herhangi bir tusa basin..." ;
     
     for(int i=0;i<strlen(HelpString);i++)
     {
             printf("%c",HelpString[i]);
             if(HelpString[i]=='.')
             Sleep(500);
             else
             Sleep(30);
     }

     getch();
     EkranSil();
}

void Git(int PositionX, int PositionY)
{
    COORD CursorCoordinat;
    CursorCoordinat.X=PositionX;
    CursorCoordinat.Y=PositionY;
    SetConsoleCursorPosition(GetStdHandle (STD_OUTPUT_HANDLE) ,CursorCoordinat);
}

double isSameTime(clock_t time1,clock_t time2 ) 
{
    if( (time1-time2)/(CLOCKS_PER_SEC/1000 )<80)
    return true;
    else return false;
}
