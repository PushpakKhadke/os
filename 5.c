#include <stdio.h>
#include <string.h>

struct FileTable
{
    char fileName[20];
    int startBlock, numBlocks;
};

int main()
{
    struct FileTable files[30];
    int i, j, numFiles;
    char searchFileName[20];

    printf("Enter the number of files: ");
    scanf("%d", &numFiles);

    for (i = 0; i < numFiles; i++)
    {
        printf("\nEnter file name %d: ", i + 1);
        scanf("%s", files[i].fileName);
        printf("Enter starting block of file %d: ", i + 1);
        scanf("%d", &files[i].startBlock);
        printf("Enter number of blocks in file %d: ", i + 1);
        scanf("%d", &files[i].numBlocks);
    }

    printf("\nEnter the file name to be searched: ");
    scanf("%s", searchFileName);

    for (i = 0; i < numFiles; i++)
    {
        if (strcmp(searchFileName, files[i].fileName) == 0)
            break;
    }

    if (i == numFiles)
    {
        printf("\nFile Not Found\n");
    }
    else
    {
        printf("\nFILE NAME\tSTART BLOCK\tNO OF BLOCKS\tBLOCKS OCCUPIED\n");
        printf("%s\t\t%d\t\t%d\t\t", files[i].fileName, files[i].startBlock, files[i].numBlocks);

        for (j = 0; j < files[i].numBlocks; j++)
        {
            printf("%d, ", files[i].startBlock + j);
        }
    }

    return 0;
}
