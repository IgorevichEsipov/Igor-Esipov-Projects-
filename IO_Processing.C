#include <stdio.h>
#include <stdlib.h>

// method dump to read file

void dump(char filename[], char c[][100], int *i)

{

    FILE *fp;

    fp = fopen(filename, "r");

    int k = *i;

    if (fp == NULL)

        printf("Can't open %s for reading.\n", filename);

    else

    {

        while (fscanf(fp, "%s", c[k]) != EOF)

        {

            // printf("%s\n",c[k]);

            k = k + 1;
        }

        fclose(fp);
    }

    (*i) = k + 1;
}

// method to display all words in array

void display(char c[][100], int s)

{

    int i = 0;

    printf("\nContents:\n");

    while (i < s)

    {

        printf("%s\n", c[i]);

        i++;
    }
}

// method to write all words to file

void add_to_file(char filename[], char c[][100], int s)

{

    int i = 0;

    FILE *fptr;

    // opening file

    fptr = fopen(filename, "w");

    if (fptr == NULL)

    {

        printf("Error!");

        exit(1);
    }

    while (i < s)

    {

        fprintf(fptr, "%s\n", c[i]); // writing to file

        i++;
    }

    fclose(fptr);
}

int main()

    char filename[80] = "Users/newuser/Documents/IO Processing/words.tx"; // change file path as per ur requirement

char word[50];

char contents[1000][100]; // can store at max 1000 words

int size = 0;

// reading file

dump(filename, contents, &size);

// displaying menu

int y = 0;

while (1)

{

    printf("1:Add_word\n2:show_contents\n3:read_file\n4:write_to_file\n5:exit\nEnter :");

    scanf("%d", &y);

    if (y == 1)

    {

        if (size + 1 < 1000)

        {

            printf("Enter word to add:");

            scanf("%s", contents[size]);

            size++;
        }

        else

        {

            printf("\nCan't add max size reached\n");
        }
    }

    else if (y == 2)

    {

        display(contents, size);
    }

    else if (y == 3)

    {

        dump(filename, contents, &size);
    }

    else if (y == 4)

    {
        add_to_file(filename, contents, size);
    }

    else
        break;
}

return 0;
}
