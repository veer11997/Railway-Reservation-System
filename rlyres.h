#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED

struct train
{
    char train_no[10];
    char from[10];
    char to[10];
    int fac_fare;
    int sac_fare;
};

struct passenger
{
    char p_name[20];
    char gender;
    char train_no[10];
    char p_class;
    char mob_no[10];
    char address[20];
    char *p_mob[11];
    int age;
    int ticketno;

   };

   typedef struct train train;
   typedef struct passenger passenger;


    int enterchoice();
    void add_trains();
    void view_trains();
    int book_ticket(passenger);
    int* get_ticket_no(char *);
    void view_ticket(int);
    void view_all_bookings();
    void view_booking(char *);
    int cancel_ticket(int);
    int cancel_train(char *);
    int check_train_no(char*);
    passenger *get_passenger_details();
    int get_booked_ticket_count(char*,char);
    int last_ticket_no();
    int check_mob_no(char *);
    int accept_ticket_no();
    char* accept_train_no();
    char* accept_mob_no();
    void view_all_tickets(char*,int*);
    int cancel_train(char*);

#endif // RLYRES_H_INCLUDED
