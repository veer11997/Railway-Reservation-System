#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include"rlyres.h"
int main()
{
    int choice;
    add_trains();
    passenger *ptr;
    int ticket_no;
    int* pticket_no;
    int result;
    char* pmob_no;
    char* ptrain_no;

    while(1)
      {
        clrscr();
        choice=enterchoice();
        if(choice==9)
           {
            exit(0);
           }
        switch(choice)
            {
        case 1:
            view_trains();
            break;
        case 2:
            clrscr();
            ptr=get_passenger_details();
            if(ptr!=NULL)
               {
                int ticketno=book_ticket(*ptr);
                if(ticketno==-1)
                   {
                    textcolor(LIGHTRED);
                    printf("BOOKING FAILED!");
                    textcolor(WHITE);
                    printf("\n\npress any key to go back");
                    getch();
                   }
                else
                    {
                    textcolor(GREEN);
                    printf("TICKET succesfully Booked!\n");
                    printf("your ticket no is %d",ticketno);
                    textcolor(WHITE);
                    printf("\n\npress any key to go back");
                    getch();
                    }
             }
            break;
        case 3:
            clrscr();
            ticket_no=accept_ticket_no();
            if(ticket_no!=0)
            view_ticket(ticket_no);
            textcolor(WHITE);
            printf("\npress any key to go back to the main screen ");
            getch();
            clrscr();
            break;
        case 4:
            clrscr();
            pmob_no=accept_mob_no();
            if(pmob_no!=NULL)
               {
                pticket_no=get_ticket_no(pmob_no);
                view_all_tickets(pmob_no,pticket_no);
               }
               clrscr();
            break;
        case 5:
            clrscr();
            view_all_bookings();
            break;

        case 6:
            clrscr();
            ptrain_no=accept_train_no();
            if(ptrain_no!=NULL)
             {
              view_booking(ptrain_no);
             }
            break;
        case 7:
            clrscr();
            ticket_no=accept_ticket_no();
            if(ticket_no!=0)
                 {
                  result=cancel_ticket(ticket_no);
                  if(result==0)
                     {
                     textcolor(LIGHTRED);
                     printf("sorry! NO ticket booked against ticket no %d ",ticket_no);
                     }
                else if(result==1)
                    {
                     textcolor(LIGHTGREEN);
                     printf("ticket no %d successfully cancelled!",ticket_no);
                     }
                textcolor(WHITE);
                printf("\n\nPress any key to go back to the main screen");
                }
                getch();
                clrscr();
            break;
        case 8:
             clrscr();
             ptrain_no=accept_train_no();
             if(ptrain_no!=NULL)
                 {
                 result=cancel_train(ptrain_no);
                 if(result==0)
                     {
                      textcolor(LIGHTRED);
                      printf("sorry no tickets booked n train %s",ptrain_no);
                     }
                else
                     {
                     textcolor(LIGHTGREEN);
                     printf("train no %s successfully canceled!",ptrain_no);
                     }
                     textcolor(WHITE);
                     printf("\npress any key to go back:");
                }
                     getch();
                     clrscr();
                break;
        default:
            textcolor(LIGHTRED);
            printf("WRONG CHOICE !try again..\n");
            getch();
            clrscr();
            break;
        }
    }
            return 0;
}
