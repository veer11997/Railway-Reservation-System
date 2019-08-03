#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include"conio2.h"
#include"rlyres.h"
//virendra
int enterchoice()
{
    int choice,i;
    textcolor(YELLOW);
    gotoxy(45,1);
    printf("RAILWAY RESEVATION SYSTEM\n");
    for(i=0;i<=120;i++)
    {
        printf("_");
    }
    printf("\nselect an option:\n");
    printf("\n1-view trains\n");
    printf("\n2-Book ticket\n");
    printf("\n3-view ticket\n");
    printf("\n4-search ticket No\n");
    printf("\n5-view all bookings\n");
    printf("\n6-view train booking\n");
    printf("\n7-cancel ticket\n");
    printf("\n8-cancel train\n");
    printf("\n9-Quit");
    printf("\n\nEnter choice:");
    scanf("%d",&choice);
    return choice;
}


void add_trains()
{
    FILE *fp;
    fp = fopen("f:\\myproject\\alltrains.dat","rb");
    if(fp == NULL)
    {
        train alltrains[4]={
        {"123","BPL","GWA",2100,1500},
        {"546","BPL","DEL",3500,2240},
        {"345","HBJ","AGR",1560,1135},
        {"896","HBJ","MUM",4500,3350}
        };
        fp = fopen("f:\\myproject\\alltrains.dat","wb");
        fwrite(alltrains,4*sizeof(train),1,fp);
        fclose(fp);
    }
    else
    {
        printf("file saved succesfully");
        fclose(fp);
    }
}


void view_trains()
{
    clrscr();
    int i;
    FILE *fp=fopen("f:\\myproject\\alltrains.dat","rb");
    train tr;
    if(fp==NULL)
    {
        return ;
    }
    printf("\nTRAIN NO\t\tTO\t\tFROM\t\tFIRST AC FAIR\t\tSECOND AC FAIR\n");
    for(i=1;i<=120;i++)
    {
        printf("-");
    }
    printf("\n");
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        printf("%s\t\t\t%s\t\t\t%s\t\t\t%d\t\t\t%d\n",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);
    }

    textcolor(WHITE);
    printf("\n\n\n\npress any  key to go back to the main screen ");
    getch();
    fclose(fp);
}


int check_train_no(char *train_no)
{
    FILE *fp;
    fp=fopen("f:\\myproject\\alltrains.dat","rb");
    train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,train_no)==0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}


passenger *get_passenger_details()
{
    clrscr();
    gotoxy(100,1);
    textcolor(LIGHTRED);
    printf("press 0 to Exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    static passenger psn;
    printf("Enter passenger Name:");
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    char *pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Reservation cancelled!");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    int valid;
    printf("Enter Gender(M/F):");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%c",&psn.gender);
        if(psn.gender=='0')
            {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation cancelled!");
            getch();
            textcolor(YELLOW);
            return NULL;
            }
        if(psn.gender!='M'&&psn.gender!='F')
            {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("enter gender should be M or F(uppercase)");
            valid=0;
            getch();
            gotoxy(19,2);
            printf("\t\b");
            textcolor(YELLOW);
            }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t");
    gotoxy(1,3);
    printf("Enter train number:");
    do
    {
    fflush(stdin);
    scanf("%s",psn.train_no);
    if(strcmp(psn.train_no,"0")==0)
        {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Reservation cancelled!");
        getch();
        textcolor(YELLOW);
        return NULL;
        }
     valid=check_train_no(psn.train_no);
      if(valid==0)
        {
          textcolor(LIGHTRED);
          gotoxy(1,25);
          printf("Error! invalid train No.");
          getch();
          gotoxy(20,3);
          printf("\t\t\t\t\t\t");
          gotoxy(20,3);
          textcolor(YELLOW);
            }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t");
    gotoxy(1,4);
    printf("Enter traveling class(First AC-F,second Ac-s):");
    do
    {
    valid=1;
    fflush(stdin);
    scanf("%c",&psn.p_class);
    if(psn.p_class=='0')
        {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Reservation cancelled!");
        getch();
        textcolor(YELLOW);
        return NULL;
        }
    if(psn.p_class!='F'&&psn.p_class!='S')
        {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Error traveling class should be  F or S(in uppercase)");
        valid=0;
        getch();
        gotoxy(47,4);
        printf("\t\b");
        textcolor(YELLOW);
       }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t\t\t");
    gotoxy(1,5);
    printf("Enter address:");
    fflush(stdin);
    fgets(psn.address,20,stdin);
    pos=strchr(psn.address,'\n');
    *pos='\0';
    if(strcmp(psn.address,"0")==0)
        {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("Reservation canceled");
        getch();
        textcolor(YELLOW);
        return NULL;
        }
    printf("Enter age:");
    do
    {
    valid=1;
    fflush(stdin);
    scanf("%d",&psn.age);
    if(psn.age==0)
        {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(1,25);
        printf("reservation canceled");
        getch();
        textcolor(YELLOW);
        return NULL;
        }
    if(psn.age<=0)
        {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Error ! age should be positive");
        valid=0;
        getch();
        gotoxy(11,6);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(11,6);
        textcolor(YELLOW);
        }
  }while(valid==0);
  gotoxy(1,25);
  printf("\t\t\t\t\t\t\t\t\t");
  gotoxy(1,7);
  printf("Enter mobile number:");
        do
        {
        fflush(stdin);
        fgets(psn.mob_no,11,stdin);
        pos=strchr(psn.mob_no,'\n');
        if(pos!=NULL)
        *pos='\0';
        if(strcmp(psn.mob_no,"0")==0)
            {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation canceled!");
            getch();
            textcolor(YELLOW);
            return NULL;
            }
      valid=check_mob_no(psn.mob_no);
        if(valid==0)
        {

          textcolor(LIGHTRED);
          printf("Error !invalid mobile no");
          getch();
          gotoxy(21,7);
          printf("\t\t\t\t\t\t\t\t\t\t\t");
          gotoxy(21,7);
          textcolor(YELLOW);
        }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t\t");
    return &psn;
    }


  int check_mob_no(char *p_mob)
        {
        if(strlen(p_mob)!=10)
        return 0;
        while(*p_mob!='\0')
        {
           if(isdigit(*p_mob)==0)
            return 0;
           p_mob++;
        }
      return 1;
        }


int get_booked_ticket_count(char *train_no,char tc)
    {
    FILE *fp=fopen("f:\\myproject\\allbookings.dat","rb");
        if(fp==NULL)
        return 0;
        passenger pr;
        int count=0;
        while(fread(&pr,sizeof(pr),1,fp)==1)
            {
                if(strcmp(pr.train_no,train_no)==0&&pr.p_class==tc)
                ++count;
            }
        fclose(fp);
        return count;
    }


int last_ticket_no()
    {
    FILE *fp=fopen("f:\\myproject\\allbookings.dat","rb");
    if(fp==NULL)
    return 0;
    passenger pr;
    fseek(fp,-1*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;
}


int book_ticket(passenger p)
{
    int result=get_booked_ticket_count(p.train_no,p.p_class);
    if(result==2)
    {
        textcolor(LIGHTBLUE);
        printf("All seats full in train  no %s in %c  class !\n",p.train_no,p.p_class);
        return -1;
    }
    int count=last_ticket_no()+1;
    p.ticketno=count;
    FILE *fp=fopen("f:\\myproject\\allbookings.dat","ab");
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return count;
}


int accept_ticket_no()
{
    printf("Enter ticket no:");
    int valid;
    int ticket_no;
    do{
        valid=1;
        scanf("%d",&ticket_no);
        if(ticket_no==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("cancelling input!");
            textcolor(YELLOW);
            return 0;
        }
        if(ticket_no<0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error! ticket no should be positive");
            valid=0;
            getch();
            gotoxy(11,1);
            textcolor(YELLOW);
        }
    }while(valid==0);
    return ticket_no;
}


void view_ticket(int ticket_no)
{
    FILE *fp=fopen("f:\\myproject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("\n NO bookings done  yet");
        return ;
    }
    passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
      if(pr.ticketno==ticket_no)
      {
       printf("\nName:%s\nGender:%c\nClass:%c\nTrain no:%s\nAge:%d\nMobile No:%s\nTICKET NO:%d\n",pr.p_name,
              pr.gender,pr.p_class,pr.train_no,pr.age,pr.mob_no,pr.ticketno);
        printf("\n\n");
        found=1;
        break;
      }
    }
    if(!found)
    {
        textcolor(LIGHTRED);
        printf("\n NO details FOund of ticket no %d !",ticket_no);
    }
    fclose(fp);
}


int cancel_ticket(int ticket_no)
{
    FILE *fp1=fopen("f:\\myproject\\allbookings.dat","rb+");
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\n NO bookings done yet");
        return -1;
    }
    FILE *fp2=fopen("f:\\myproject\\temp.dat","wb+");
    passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(pr.ticketno!=ticket_no)
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
        else{
            found=1;
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("f:\\myproject\\temp.dat");
    }
    else{
        remove("f:\\myproject\\allbookings.dat");
        rename("f:\\myproject\\temp.dat","f:\\myproject\\allbookings.dat");
    }
    return found;

}


 char* accept_mob_no()
 {
     static char mob_no[11];
     char* pos;
     int valid;
     printf("ENTER MOBILE NUMBER:");
          do{
        fflush(stdin);
        fgets(mob_no,11,stdin);
        pos=strchr(mob_no,'\n');
        if(pos!=NULL)
        *pos='\0';
        if(strcmp(mob_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation cancelled!");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
      valid=check_mob_no(mob_no);
      if(valid==0)
      {
          textcolor(LIGHTRED);
          printf("Errror !invalid mobile no");
          getch();
          gotoxy(21,7);
          printf("\t\t\t\t\t\t\t\t\t\t\t");
          gotoxy(21,7);
          textcolor(YELLOW);
      }
      }while(valid==0);
      clrscr();
      return mob_no;
 }


 int* get_ticket_no(char* p_mob_no)
 {
     int count=0;
     FILE *fp=fopen("f:\\myproject\\allbookings.dat","rb");
     if(fp==NULL)
     {
         return NULL;
     }
     passenger pr;
     while(fread(&pr,sizeof(pr),1,fp)==1)
     {
         if(strcmp(pr.mob_no,p_mob_no)==0)
            ++count;
     }
     if(count==0)
     {
         fclose(fp);
         return NULL;
     }
     rewind (fp);
     int *p=(int*)malloc((count+1)*sizeof(int));
     int i=0;
     while(fread(&pr,sizeof(pr),1,fp)==1)
     {
         if(strcmp(pr.mob_no,p_mob_no)==0)
         {
             *(p+i)=pr.ticketno;
             i++;
         }
     }
     *(p+i)=-1;
     fclose(fp);
     return p;
 }


void view_all_tickets(char* pmob_no,int* pticket_no)
{
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("sorry ! no ticket booked against mobile no %s",pmob_no);
        textcolor(WHITE);
        printf("\n\npress any key to go back to the main screen ");
        textcolor(YELLOW);
        getch();
        return;
    }
    printf("Following are tickets booked for mobile no: %s",pmob_no);
    int i;
    printf("\nTicket no\n");
    printf("---------");
    for(i=0;*(pticket_no+i)!=-1;i++)
        printf("\n%d",*(pticket_no+i));
        textcolor(WHITE);
        printf("\n\nPress any key to go back to the main screen");
        textcolor(YELLOW);
        getch();
}


char* accept_train_no()
{
    static char* train_no[10];
    int valid;
    printf("Enter train number:");
    do{
        fflush(stdin);
        scanf("%s",train_no);
        if(strcmp(train_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("canceling input !");
            textcolor(YELLOW);
            return NULL;

        }
        valid=check_train_no(train_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error ! invalid train no");
            getch();
            gotoxy(20,1);
            printf("\t\t\t\t\t\t\t\t\t\t\t");
            gotoxy(20,1);
            textcolor(YELLOW);

        }
    }while(valid==0);
    clrscr();
    return train_no;
}


  int cancel_train(char* ptrain_no)
  {
      FILE *fp1=fopen("f:\\myproject\\allbookings.dat","rb+");
      if(fp1==NULL)
      {
          textcolor(LIGHTRED);
          printf("\nNo bookings done Yet!");
          return -1;

      }
     FILE *fp2=fopen("f:myproject\\temp.dat","wb+");
      passenger pr;
      int found=0;
      while(fread(&pr,sizeof(pr),1,fp1)==1)
{
    if(strcmp(pr.train_no,ptrain_no)!=0)
    {
        fwrite(&pr,sizeof(pr),1,fp2);

    }
    else
        {
            found=1;
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
        {
           remove("f:\\myproject\\temp.dat");

            }
            else
                {
                remove("f:\\myproject\\allbookings.dat");
                rename("f:\\myproject\\temp.dat","f:\\myproject\\allbookings.dat");
            }
            return found;
}
  }


  void view_booking(char* trainno)
  {
      clrscr();
      FILE *fp;
      fp=fopen("f:\\myproject\\allbookings.dat","rb");
      if(fp==NULL)
      {
          textcolor(LIGHTRED);
          printf("\nNo booking done yet");
          textcolor(YELLOW);
          getch();
          return ;
      }
      passenger pr;
      int valid=0;
      printf("ticket no\t\t\t\tclass\t\t\t\t\tpassenger\n");
      while(fread(&pr,sizeof(pr),1,fp)==1)
      {

           if(strcmp(trainno,pr.train_no)==0)
           {
              printf("%d\t\t\t\t\t%c\t\t\t\t\t%s",pr.ticketno,pr.p_class,pr.p_name);
              printf("\n");
           }
      }
      fclose(fp);
      textcolor(WHITE);
      printf("\npress any key to go back");
      getch();
  }


  void view_all_bookings()
  {
      clrscr();
      int i;
      FILE *fp;
      fp=fopen("f:\\myproject\\allbookings.dat","rb");
      if(fp==NULL)
      {
          textcolor(LIGHTBLUE);
          printf("No tickets found!");
          getch();
          textcolor(YELLOW);
          return;
      }
      printf("\tTrain No\t\t\t\t Ticket NO\t\t\t\tClass\n");
      for(i=1;i<=120;i++)
      {
          printf("_");
      }
      passenger ps;
      int valid=0;
      while(fread(&ps,sizeof(ps),1,fp)==1)
      {
          valid=1;
          printf("\t%s\t\t\t\t\t%d\t\t\t\t\t%c",ps.train_no,ps.ticketno,ps.p_class);
          printf("\n");
      }
      fclose(fp);
      textcolor(WHITE);
      printf("\n\nPress any key  to go back");
      getch();
  }
