

void newUserRegistration();
void userLogin();
void userProfile();

struct login{

    char userName[20];
    char password[20];
    char firstName[20];
    char lastName[20];
    char address[40];
    char phone[11];


};

char whoLoggedin [20];

void newUserRegistration(){

    system("cls");

     FILE *fp;

     struct login info;


        printf("\n\t\t\t");
        printf("\n\t\t\tNew User Registration");
        printf("\n\t\t\t\n");

        fp=fopen("userList.txt","a"); //a means read and write

          printf("\n\t\t\tEnter username:");
          scanf("%s",&info.userName);

          printf("\n\t\t\tEnter Password:");
          scanf("%s",&info.password);

          printf("\n\t\t\tEnter Your First Name:");
          scanf("%s",&info.firstName);

          printf("\n\t\t\tEnter Your Last Name:");
          scanf("%s",&info.lastName);

          printf("\n\t\t\tEnter Your Address:");

          scanf("%s",&info.address); //take comma as input ,  C scanf doesn’t consider the comma(,) as a delimiter for the specifier “%s.

          printf("\n\t\t\tEnter Your Phone Number:");
          scanf("%s",&info.phone);

          printf("\n\t\t\t______________________________\n");

      if(fp==NULL){
        fprintf(stderr,"Registration Failed, Try again");
    }else{
        system("cls");
        printf("\t\t\tRegistration Successful\n");

    }

    fwrite(&info, sizeof(struct login), 1, fp);

    fclose(fp);


}

void userLogin(){



    int found=0;
      struct login info;
      FILE *fp;

      char un[20];
      char pass[20];

    fp=fopen("userList.txt","r");

    printf("\n\t\t\t");
    printf("\n\t\t\t---User Login---\n");

    printf("\n\t\t\tEnter Username:");
    scanf("%s",&un);

    printf("\n\t\t\tEnter Password:");
    scanf("%s",&pass);



    while(fread(&info,sizeof(struct login),1,fp)){



        if(strcmp(un,info.userName)==0 && strcmp(pass,info.password)==0){  // String Comparison using strcmp

        found = 1;
        system("cls");
        printf("\n\t\t\tLogin Successful\n");
        printf("\n\t\t\t______________________________________\n");
        printf("\n\t\t\tWelcome %s %s" , info.firstName, info.lastName);
        printf("\n");

        strcpy(whoLoggedin , info.userName);  //String Copy
        //whoLoggedin = info.userName;

        int select = 0;

        do
        {
                printf("\n\n\t\t\t1.Your Profile");
                printf("\n\t\t\t2.Check Ticket Availability");
                printf("\n\t\t\t3.Ticket Booking");
                printf("\n\t\t\t4.Your Tickets");
                printf("\n\t\t\t0.Logout\n");

                printf("\n\t\t\t");

                printf("\n\n\n\t\t\tEnter choice => ");
                scanf("%d",&select);

            switch(select)
            {
            case 1:

                system("cls");
                printf("\n\t\t\tYour Profile");
                printf("\n\t\t\t______________________________________\n");
                printf("\n\n\t\t\tUsername: %s", info.userName);
                printf("\n\n\t\t\tFirst Name: %s", info.firstName);
                printf("\n\n\t\t\tLast Name: %s", info.lastName);
                printf("\n\n\t\t\tAddress: %s", info.address);
                printf("\n\n\t\t\tPhone: %s", info.phone);
                printf("\n\t\t\t______________________________________\n");

                break;

            case 2:
                system("cls");
                userCheckTicketAvailability();
                //printf("\n\t\t\tCheck Ticket Availability");

                break;
            case 3:
                system("cls");
                ticketBooking();
                //printf("\n\t\t\tTicket Booking");
                break;
            case 4:
                system("cls");
                yourTickets();
                //printf("\n\t\t\tYour Tickets");
                break;

            case 0:
            printf("\n\n\n\t\t\t\tThank you\n\n\n\n\n");
            exit(1);
            break;

            default:
                printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");

            }

        }while(select!=0);

        }
    }

    if (!found) {
            system("cls");
            printf("\n\t\t\tInvalid Credentials, TRY Again\n");
            userLogin();
        }



    fclose(fp);
    getch();

}


struct TrainSchedule2{

    int id;
    char trainName[40];
    char from[40];
    char to[40];
    char departure[40];
    char arrival[40];
    int price;
    int seats;

};


void userCheckTicketAvailability(){

     printf(" \n");
    printf("\t\t\t\t=======Train Schedule and Ticket Availability=======\n\n\n");

    FILE *fp;

    struct TrainSchedule2 info;
    fp=fopen("trainSchedule.txt","r");


    if(fp==NULL){

        fprintf(stderr,"Can't open file\n");
        exit(0);
    }

        while(fread(&info,sizeof(struct TrainSchedule2),1,fp)){

        printf("\n\t\t\tTrain ID: %d \n\t\t\tTrain Name: %s \n\t\t\tFrom: %s \n\t\t\tTo: %s \n\t\t\tDeparture Time: %s \n\t\t\tArrival Time: %s \n\t\t\tTicket Price: %d\n\t\t\tSeats available: %d", info.id, info.trainName, info.from, info.to, info.departure, info.arrival, info.price, info.seats);


        printf("\n\t\t\t\_________________________\n");

         }
        fclose(fp);


}

void ticketBooking(){

    userCheckTicketAvailability();

    int trainid, howManyTickets;
    char date[40];
    int foundID=0;
    char ans;

    printf("\n\t\t\tTo book your ticket, Enter Tarin ID: ");
    scanf("%d",&trainid);

    printf("\n\t\t\tHow many Tickets would you like to Book: ");
    scanf(" %d",&howManyTickets);


    FILE *fp;

    struct TrainSchedule2 info;
    fp=fopen("trainSchedule.txt","r");


    if(fp==NULL){

        fprintf(stderr,"Can't open file\n");
        exit(0);
    }

        while(fread(&info,sizeof(struct TrainSchedule2),1,fp)){

            if(info.id == trainid) {

                    foundID=1;

                if (info.seats >= howManyTickets ) {




                    printf("\n\t\t\tEnter date of travel in this format DD/MM/YEAR: ");
                    scanf(" %s",&date);

                    int totalPrice= howManyTickets * info.price;

                    printf("\n\t\t\tTotal Price for %d ticket is BDT: %d ",howManyTickets, totalPrice);

                    printf("\n\t\t\tEnter y/Y if you want to Confirm : ");
                    scanf(" %c",&ans);

                    if (ans =='y' || ans =='Y'){

                        int remainingTickets = info.seats - howManyTickets;
                        fclose(fp); //very important to close file here, otherwise no of ticket will not be updated

                        updateNoOfTickets(trainid, remainingTickets, howManyTickets, date); // Update the file for ticket booking and no of tickets available will be changed

                        updateMyTickets(howManyTickets, date, info.trainName, info.from, info.to, totalPrice); //For Updating "Your Ticket" ticket purchased by specific user

                    }else{
                        printf("\n\n\n\t\t\t\tBooking Cancelled\n\n\n\n\n");

                    }


                }else {
                    printf("\n\t\t\tTicket Not Available ");
                }
            }else {

            }


    }

    if(!foundID){
          printf("\n\t\t\t\tInvalid Train ID, try again\n");
    }


    fclose(fp);
    getch();


}


void updateNoOfTickets(int tid, int remainTickets, int howManyTickets, char dates[40]){


    struct TrainSchedule2 info;
    FILE *fp, *fp1;


    int found=0;


    fp=fopen("trainSchedule.txt","r");
    fp1=fopen("temp.txt","w");


    if(fp==NULL){
       fprintf(stderr,"can't open file\n");
       exit(0);
    }

    while(fread(&info,sizeof(struct TrainSchedule2),1,fp)){

        if(info.id == tid){

         found=1;
         info.seats = remainTickets;

        fwrite(&info,sizeof(struct TrainSchedule2),1,fp1);

        }else{

           fwrite(&info,sizeof(struct TrainSchedule2),1,fp1); // when Id do not match, copy from main file to temp fie. when match that will not be copied. all data except that given id will be stored
        }

    }

     fclose(fp);
     fclose(fp1);

    if(found){
     remove("trainSchedule.txt");

     rename("temp.txt","trainSchedule.txt");

    printf("\n\t\t\tBooking Updated Succesfully\n");

    printf("\n\t\t\t%s have purchased %d tickets for %s",whoLoggedin, howManyTickets, dates);

    system( "image_02.jpg" );




    }



}


// For Updating "Your Ricket" ticket purchased by specific user

struct purchasedTicket{

    char userName[20];
    char date[40];
    char trainName[40];
    char from[40];
    char to[40];
    int price;
    int ticketsCount;


};

void updateMyTickets(int howManyTickets, char dates[40], char trainName[40], char from[40], char to[40], int price){

   // printf("\n\t\t\t%s have purchased %d tickets for %s",whoLoggedin, howManyTickets, dates);

   FILE *fp3;

     struct purchasedTicket info;
        char tn[40];


          fp3=fopen("purchasedTickets.txt","a");

          strcpy(info.userName, whoLoggedin);  //String Copy
          strcpy(info.date, dates);
          strcpy(info.trainName, trainName);
          strcpy(info.from, from);
          strcpy(info.to, to);
          info.ticketsCount = howManyTickets;
          info.price = price;


    if(fp3==NULL){
        fprintf(stderr,"Can't open file");
    }else{

    }

    fwrite(&info, sizeof(struct purchasedTicket), 1, fp3);
    fclose(fp3);

}


// It will show purchaed tickets of logged in user

void yourTickets(){

    int foundID =0;

    printf(" \n");
    printf("\t\t\t\t=======Order History=======\n\n\n");


    struct purchasedTicket info;
    FILE *fp;



    fp=fopen("purchasedTickets.txt","r");

    int counting = 1;


    while(fread(&info,sizeof(struct purchasedTicket),1,fp)){



        if(strcmp(whoLoggedin,info.userName)==0){  // String Comparison using strcmp

        foundID = 1;

        printf("\n\t\t\t%d. Bought %d ticket, Travel date: %s , Train Name:  %s, From %s to %s, Total Price: %d: " , counting, info.ticketsCount, info.date, info.trainName, info.from, info.to, info.price);
        printf("\n");
        counting = counting+1;

        }

    }

      if(!foundID){
          printf("\n\t\t\t\tYou have not Purchased any ticket yet.\n");
        }

    fclose(fp);
    getch();

}
