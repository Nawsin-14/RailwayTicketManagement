void adminLogin(){

        int found=0;


        printf("\n\t\t\t");
        printf("\n\t\t\tAdmin Login");
        printf("\n\t\t\t\n");

        char adminUsername[20];
        char adminPass[20];


        printf("\n\t\t\tEnter Username:");
        scanf("%s",&adminUsername);

        printf("\n\t\t\tEnter Password:");
        scanf("%s",&adminPass);

        if(strcmp(adminUsername,"nawsin")==0 && strcmp(adminPass,"1234")==0){  // String Comparison using strcmp

            found = 1;
            system("cls");
            printf("\n\t\t\tAdmin Login Successful\n");
            printf("\n\t\t\t______________________________________\n");
            printf("\n");

            int select = 0;

        do
        {
                printf("\n\n\t\t\t1.Add Train Schedule");
                printf("\n\t\t\t2.View Train Schedule");
                printf("\n\t\t\t3.Delete Train Schedule");

                printf("\n\t\t\t0.Logout\n");

                printf("\n\t\t\t");

                printf("\n\n\n\t\t\tEnter choice => ");
                scanf("%d",&select);

            switch(select)
            {
            case 1:

                system("cls");
                printf("\n\t\t\tAdd Train Schedule\n");
                addTrainSchedule();

                break;

            case 2:
                system("cls");
                printf("\n\t\t\tView Train Schedule\n");
                viewTrainSchedule();

                break;

            case 3:
                system("cls");
                printf("\n\t\t\tDelete Train Schedule\n");
                deleteTrainSchedule();

                break;


            case 0:
            printf("\n\n\n\t\t\t\tThank you\n\n\n\n\n");
            exit(1);
            break;

            default:
                printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");

            }

        }while(select!=0);




        } // end of if statement



        if (!found) {
            system("cls");
            printf("\n\t\t\tInvalid Admin Credentials, TRY Again\n");
            adminLogin();
        }


    return 0;
}

struct TrainSchedule{

    int id;
    char trainName[40];
    char from[40];
    char to[40];
    char departure[40];
    char arrival[40];
    int price;
    int seats;

};



void addTrainSchedule(){


    FILE *fp3;

     struct TrainSchedule info;


       printf("\t\t\t\t=======Add Train Info=======\n\n\n");
       fp3=fopen("trainSchedule.txt","a");

          printf("\n\t\t\tEnter Train No:");
          scanf("%d",&info.id);
          printf("\n\t\t\tEnter Train Name:");
          scanf("%s",&info.trainName);
          printf("\n\t\t\tFrom (Location):");
          scanf("%s",&info.from);
          printf("\n\t\t\tTo (Location):");
          scanf("%s",&info.to);
          printf("\n\t\t\tDeparture Time:");
          scanf("%s",&info.departure);
          printf("\n\t\t\tArrival Time:");
          scanf("%s",&info.arrival);
          printf("\n\t\t\tEnter Ticket Price:");
          scanf("%d",&info.price);
          printf("\n\t\t\tEnter No of seats available:");
          scanf("%d",&info.seats);
          printf("\n\t\t\t______________________________\n");

    if(fp3==NULL){
        fprintf(stderr,"Can't open file");
    }else{
        printf("\t\t\tRecord stored successfuly\n");
    }

    fwrite(&info, sizeof(struct TrainSchedule), 1, fp3);
    fclose(fp3);


}

void viewTrainSchedule(){

    FILE *fp;

    struct TrainSchedule info;
    fp=fopen("trainSchedule.txt","r");


    if(fp==NULL){

        fprintf(stderr,"Can't open file\n");
        exit(0);
    }

        while(fread(&info,sizeof(struct TrainSchedule),1,fp)){
        printf("\n\tTrain ID \tTrain Name \t\tFrom \t\tTo \tDeparture Time \tArrival Time \tTicket Price \tSeats available");

        printf("\n \t%d \t%[^\n]%*s \t\t%[^\n]%*s \t\t%s \t%s \t%s \t%d \t%d", info.id, info.trainName, info.from, info.to, info.departure, info.arrival, info.price, info.seats);

         }
        fclose(fp);
        getch();

}

void deleteTrainSchedule(){


}
