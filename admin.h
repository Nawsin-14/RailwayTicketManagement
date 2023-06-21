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

                addTrainSchedule();

                break;

            case 2:
                system("cls");

                viewTrainSchedule();

                break;

            case 3:
                system("cls");

                deleteTrainSchedule();

                break;


            case 0:
            printf("\n\n\n\t\t\t\tThank you\n\n\n\n\n");
            exit(1);
            break;



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
        char tn[40];

       printf("\t\t\t\t=======Add Train Info=======\n\n\n");
       fp3=fopen("trainSchedule.txt","a");

          printf("\n\t\t\tEnter Train No:");
          scanf("%d",&info.id);
          printf("\n\t\t\tEnter Train Name:");
          scanf("%s",info.trainName);
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

     printf(" \n");
    printf("\t\t\t\t=======Train Schedule=======\n\n\n");

    FILE *fp;

    struct TrainSchedule info;
    fp=fopen("trainSchedule.txt","r");


    if(fp==NULL){

        fprintf(stderr,"Can't open file\n");
        exit(0);
    }

        while(fread(&info,sizeof(struct TrainSchedule),1,fp)){

        printf("\n\t\t\tTrain ID: %d \n\t\t\tTrain Name: %s \n\t\t\tFrom: %s \n\t\t\tTo: %s \n\t\t\tDeparture Time: %s \n\t\t\tArrival Time: %s \n\t\t\tTicket Price: %d\n\t\t\tSeats available: %d", info.id, info.trainName, info.from, info.to, info.departure, info.arrival, info.price, info.seats);


        printf("\n\t\t\t\_________________________\n");

         }
        fclose(fp);
        getch();

}

void deleteTrainSchedule(){

    printf("\t\t\t\t=======DELETE Train Schedule=======\n\n\n");

    struct TrainSchedule info;
    FILE *fp, *fp1;


    int train_id,found=0;
    char ans;

    fp=fopen("trainSchedule.txt","r");
    fp1=fopen("temp.txt","w");
    printf("\t\t\t\tEnter Train ID to delete : ");
    scanf("%d",&train_id);
    if(fp==NULL){
       fprintf(stderr,"can't open file\n");
       exit(0);
    }

    while(fread(&info,sizeof(struct TrainSchedule),1,fp)){

        if(info.id == train_id){

            printf("\n\t\t\tTrain ID: %d \n\t\t\tTrain Name: %s \n\t\t\tFrom: %s \n\t\t\tTo: %s \n\t\t\tDeparture Time: %s \n\t\t\tArrival Time: %s \n\t\t\tTicket Price: %d\n\t\t\tSeats available: %d", info.id, info.trainName, info.from, info.to, info.departure, info.arrival, info.price, info.seats);


            printf("\n\t\t\t\_________________________\n");

            printf("\t\t\t\tEnter y/Y if you want to delete : ");
            scanf(" %c",&ans);

            if (ans =='y' || ans =='Y'){
                found=1;
            }else{
                printf("\n\n\n\t\t\t\tNot Deleted\n\n\n\n\n");
                exit(0);
            }


        }else{

           fwrite(&info,sizeof(struct TrainSchedule),1,fp1); // when Id do not match, copy from main file to temp fie. when match that will not be copied. all data except that given id will be stored
        }

    }

     fclose(fp);
     fclose(fp1);

    if(!found){
          printf("\n\t\t\t\tTrain Schedule not found\n");
    }

    if(found){
    remove("trainSchedule.txt");

    rename("temp.txt","trainSchedule.txt");

    printf("\n\t\t\t\tRecord deleted succesfully\n");

    }

  getch();

}
