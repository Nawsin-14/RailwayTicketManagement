#include <dos.h>

//First Screen Animation
void welcomeAnimation()
{


    FILE *fptr;

    // Open a file in read mode
    fptr = fopen("image.txt", "r");

    // Store the content of the file
    char myString[100];

    // Read the file content and print it
    while(fgets(myString, 100, fptr)) {
      printf("%s", myString);
      Sleep(150); // for delay in display

    }

    system( "image_01.jpg" );

    fclose(fptr); // Close the file

}
