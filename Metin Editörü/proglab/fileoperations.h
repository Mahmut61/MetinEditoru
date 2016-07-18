#include<stdio.h>
#include<conio.h>
#include<string.h>

bool SaveFile(structHarf*,structHarf* ,char* );

static char filePath[255];
void Save(structHarf* baslangicHarf,structHarf *sonHarf,char * strdosyayol)
{
     SetConsoleTitle("Kaydet");
     EkranSil();   
     
     SaveFile(baslangicHarf,sonHarf,strdosyayol);
     char strMessage2[]="\n\n\n     Islem tamamlandi...\nBir tusa basarak editore donebilirsiniz.";
     for(int i=0;i<strlen(strMessage2);i++)
     {
             printf("%c",strMessage2[i]);
             Sleep(30);
     }
     getch();
}
char SaveAs(structHarf* baslangicHarf,structHarf *sonHarf,bool isAnySave)
{
  
     SetConsoleTitle("Farkli Kaydet");
     EkranSil();
     char strMessage[]="\n\n\n     Dosya yolu giriniz  :";
    
     for(int i=0;i<strlen(strMessage);i++)
     {
             printf("%c",strMessage[i]);
             Sleep(30);
     }
     structHarf *curs = baslangicHarf;
     char strDosyaYol[25];
     scanf("%s",&strDosyaYol); 
     bool issave= SaveFile(baslangicHarf,sonHarf,strDosyaYol);
     if(!isAnySave)
     {
         if(issave) 
           strcpy(filePath,strDosyaYol);
         else strcpy(filePath,"");
     }
     char strMessage2[]="\n\n\n     Islem tamamlandi...\nBir tusa basarak editore donebilirsiniz.";
     for(int i=0;i<strlen(strMessage2);i++)
     {
             printf("%c",strMessage2[i]);
             Sleep(30);
     }  
     getch();
}
bool SaveFile(structHarf * baslangicHarf,structHarf *sonHarf,char* Dosyayol)
{
      FILE *savefile=fopen(Dosyayol,"w");
      if (savefile==NULL)
      {
           printf("\n Dosyaya yazarken bir hatayla karsilasildi...");
           return false;
      }
     structHarf *curs = baslangicHarf;
     int i=0;
     while(curs!=NULL)
     {
            fprintf(savefile,"%c",curs->Value);  
            i++;        
            curs=curs->Right;
            if( i%80 == 0)
            fprintf(savefile,"\n"); 
      }
      fclose(savefile);
      return true;
}
