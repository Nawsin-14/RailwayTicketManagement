//Menu and options for user to select
void menu()
{
    printf("\n\t\t\t");
    printf("\n\t\t\tMENU");
    int choice = 0;
    do
    {


        printf("\n\n\t\t\t1.New Registration");
        printf("\n\t\t\t2.User Login");
        printf("\n\t\t\t3.Train Schedule");
        printf("\n\t\t\t4.Ticket Availability");
        printf("\n\t\t\t");
        printf("\n\t\t\t5.Admin Login");
        printf("\n\t\t\t");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\n\n\t\t\tNew Registration");
            break;
        case 2:
            printf("\n\t\t\tUser Login");
            break;
        case 3:
            printf("\n\t\t\tTrain Schedule");
            break;
        case 4:
            printf("\n\t\t\tTicket Availability");
            break;
        case 5:
            printf("\n\t\t\t5.Admin Login");
            break;
        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");

        }                                            //Switch Ended
    }
    while(choice!=0);                                        //Loop Ended
}
