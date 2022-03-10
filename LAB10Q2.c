#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Name: Jeremiah Rallos
   ID: 34454127
   Purpose: String Vowel Machine */


const int MAXSIZE = 30;

void getInput(char string[], int MAXSIZE);
void stringCopier(char string[], char vowels[]);
void vowelIndex(char vowels[]);                        //Prototype declarations. I hate those strange errors.
void vowelCounter(char vowels[], char letter);
void vowelAmount(char vowels[]);

int main()
{
     system("color 3");

     char string[30] = {'\0'};
     char vowels[30] = {'\0'};

     header();

     getInput(string, MAXSIZE);

     stringCopier(string, vowels);  //Copying original array into second array with only its vowels.

     vowelIndex(vowels);     //Display index positions of each vowel.

     vowelCounter(vowels, 'a');
     vowelCounter(vowels, 'e');
     vowelCounter(vowels, 'i');     // All functions check for each vowel frequency.
     vowelCounter(vowels, 'o');
     vowelCounter(vowels, 'u');

     vowelAmount(vowels);         // A total, because why not?


    return 0;
}


void getInput(char string[], int MAXSIZE)
{
    printf("Enter a string of characters! Maybe a food you're craving (max characters: 30): \n\n");
    printf("Make sure they're lowercase too..... or beware O__O:\n\n");

      if(fgets(string, MAXSIZE, stdin) != NULL)

             string[strlen(string) - 1] = '\0'; //Removing \n caused by Enter key.


    printf("\nYour string of characters is: %s\n", string);
}


void stringCopier(char string[], char vowels[])
{
    int stringsize;
    int j = 0;

    stringsize = strlen(string); //Assigning length of string to stringsize.

   for(int i = 0; i < stringsize; i++)
   {
       if(string[i] == 'a' || string[i] == 'e' ||
          string[i] == 'i' || string[i] == 'o' ||    //A new way of indenting my if statement. Questionable, but I'll take the risk. Also extracts the vowels.
          string[i] == 'u')
       {
          vowels[j] = string[i];
          j++;

       }

   }
       printf("\nVowels extracted, take a look: \n");
       puts(vowels);
}


void vowelIndex(char vowels[])
{
   int stringsize;

    stringsize = strlen(vowels);
   for(int i = 0; i < stringsize; i++)
   {
       if(vowels[i] == 'a' || vowels[i] == 'e' ||
          vowels[i] == 'i' || vowels[i] == 'o' ||
          vowels[i] == 'u')
       {
			//Display vowel found in string and its location
			printf("\nVowel: [ %c ] at index position: ( %d )\n\n",vowels[i], i );
       }
   }
            printf("\n-----------------------------------------------------\n");
}

void vowelCounter(char vowels[], char letter)
{
       int count = 0;

    for(int i = 0; vowels[i] != '\0'; i++)
    {
        if(vowels[i] == letter)      //While looping through the string, check if equal to parameter sent to function.

                  count++;
    }
           printf("\nFrequency of [ %c ] = ( %d )\n", letter, count);
}




void vowelAmount(char vowels[])
{
    int voweltotal = 0;

    for(int i = 0; vowels[i] != '\0'; i++)
    {
        if(vowels[i] == 'a' || vowels[i] == 'e' ||
           vowels[i] == 'i' || vowels[i] == 'o' ||
           vowels[i] == 'u')


            voweltotal++;

    }

    printf("\nThe total amount of vowels: %d\n\n", voweltotal);
    printf("Why would you not WANT to know how many there were anyway? ;)\n");

}


void header()
{
    printf("Name: Jeremiah Rallos\n");
    printf("Unit code: ICT159 Foundations of Programming\n\n");

}
