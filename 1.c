#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file;
    char filename[50], newFilename[50], text[500];
    int choice  = 0;

    while (choice != 5) 
    {
        puts("\n1. Create File");
        puts("2. Write Text In File");
        puts("3. Rename File");
        puts("4. Read Text Of File");
        puts("5. Exit");

        printf("Enter Choice = ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                printf("Enter Filename = ");
                scanf("%s",filename);

                file = fopen(filename, "w");
                if(file == NULL)
                {
                    puts("Error Creating File");
                    exit(-1);
                }

                puts("File Create Successfully");
                fclose(file);
                break;
            
            case 2:
                printf("Enter File Name = ");
                scanf("%s",filename);

                file = fopen(filename, "a");
                if(file == NULL)
                {
                    puts("Error Writing Data in File");
                }

                printf("Enter File Data = ");
                scanf(" %[^\n]", text);
                fprintf(file, "%s", text);
                puts("Data Added In File Successfully");
                fclose(file);
                break;

            case 3:
                printf("Enter File Name = ");
                scanf("%s",filename);

                printf("Enter Newfile Name = ");
                scanf("%s",newFilename);

                if(rename(filename, newFilename) != 0)
                {
                    puts("Error Rename File");
                    exit(-1);
                }
                puts("File Rename Successfully");
                break;

            case 4:
                printf("Enter Filename = ");
                scanf("%s",filename);

                file = fopen(filename, "r");
                if(file == NULL)
                {
                    puts("Error Reading Data Of File");
                    exit(-1);
                }

                puts("File Data is");
                while (fgets(text, sizeof(text), file) != NULL)
                {
                    printf("%s\n",text);
                }

                fclose(file);
                break;
            
            case 5:
                break;
                


            default:
            break;
        }
    }
    
}