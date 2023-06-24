#include "login.h" // includes the functions of login.h
#include "admin.h" // includes the functions of admin.h

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
            system("cls");
            newUserRegistration();  // function for User Registration, Code in login.h file

            break;
        case 2:
            system("cls");
            userLogin();    // function for User Login, Code in login.h file

            break;
        case 3:
            system("cls");
            viewTrainSchedule();
            break;
        case 4:
            system("cls");
            ticketAvailability();

            break;
        case 5:
            system("cls");
            adminLogin();
            break;

        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");

        }                                            //Switch Ended
    }while(choice!=0);                                        //Loop Ended
}
