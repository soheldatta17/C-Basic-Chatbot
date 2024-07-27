#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void playNote(int frequency) 
{
    Beep(frequency, 500);
}

int main() 
{
    printf("\n 1 - 440 Hz\t 2 - 494 Hz\n 3 - 523 Hz\t 4 - 587 Hz\n 5 - 659 Hz\t 6 - 698 Hz\n 7 - 784 Hz\n\n");
    printf(" ____________________\n");
    printf("||   P  I  A  N  O  ||\n");
    printf("||__________________||\n");
    printf("|  |  |  |  |  |  |  |\n");
    printf("|  |  |  |  |  |  |  |\n");
    printf("|  |  |  |  |  |  |  |\n");
    printf("| 1| 2| 3| 4| 5| 6| 7|\n");
    printf("|  |  |  |  |  |  |  |\n");
    printf("|  |  |  |  |  |  |  |\n");
    printf("|__|__|__|__|__|__|__|\n\n");
    while (1) 
    {
        // Read user input
        char input = getchar();

        // Exit loop if user enters '0'
        if (input == '0') {
            break;
        }
        if(input =='1')
        {
            playNote(440);
        }
        if(input =='2')
        {
            playNote(494);
        }
        if(input =='3')
        {
            playNote(523);
        }
        if(input =='4')
        {
            playNote(587);
        }
        if(input =='5')
        {
            playNote(659);
        }
        if(input=='6')
        {
            playNote(698);
        }
        if(input =='7')
        {
            playNote(784);
        }
    }

    return 0;
}