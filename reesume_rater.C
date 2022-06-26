#include <stdio.h>
#include <string.h>

#define keyword 150
#define words 50

int main()
{

    FILE *fp;

    int r = 0, num = 0, resume = 0, compNum = 0;
    char temp;
    char lines[keyword][words];
    char resumeTwo[keyword][words];
    fp = fopen("./keyword.txt", "r");
    if (fp == NULL)
    {
        // If keyword file is not found
        printf("\n\nFile Not Found\n\n");
        return 0;
    }

    while ((temp = fgetc(fp)) != EOF)
    {
        if (temp != ',')
        {
            lines[num][r] = temp;
            r++;
        }
        else
        {
            lines[num][r] = '\0';
            printf("%s\n", lines[num]);
            r = 0;
            num++;
        }
    }
    fclose(fp);
    printf("total words: %d ", num);
    fp = fopen("./resume.txt", "r");
    r = 0;
    if (fp == NULL)
    {
        // If resume file is not found
        printf("\n\nFile Not Found\n\n");
        return 0;
    }
    while ((temp = fgetc(fp)) != EOF)
    {
        if (temp != ' ' && temp != '\n')
        {
            resumeTwo[resume][r] = temp;
            r++;
        }
        else
        {
            resumeTwo[resume][r] = '\0';
            printf("%s\n", resumeTwo[resume]);
            r = 0;
            resume++;
        }
    }
    printf("%d %d", resume, r);
    for (r = 0; r < resume; r++)
    {
        for (int j = 0; j < num; j++)
        {
            int comp = strcmp(resumeTwo[r], lines[j]);
            if (comp == 0)
            {
                printf("%s\n", resumeTwo[r]);
                compNum++;
            }
        }
    }
    fclose(fp);
    printf("\nTotal Number of words present in resume are: %d", resume);
    printf("\nTotal Number of keywords are: %d", num);
    printf("\nTotal count of keywords that have matched are: %d", compNum);
    return 0;
}
