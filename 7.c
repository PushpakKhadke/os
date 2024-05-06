#include <stdio.h>
#include <conio.h>
main()
{
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n;
    printf("\n Enter the length of reference string -- ");
    scanf("%d", &n);
    printf("\n Enter the reference string -- ");
    for (i = 0; i < n; i++)
        scanf("%d", &rs[i]);
    printf("\n Enter no. of frames -- ");
    scanf("%d", &f);
    for (i = 0; i < f; i++)
        m[i] = -1;
    printf("\n The Page Replacement Process is -- \n");
    for (i = 0; i < n; i++)
    {
        for (k = 0; k < f; k++)
        {
            if (m[k] == rs[i])
                break;
        }
        if (k == f)
        {
            m[count++] = rs[i];
            pf++;
        }
        for (j = 0; j < f; j++)
            printf("\t%d", m[j]);
        if (k == f)
            printf("\tPF No. %d", pf);
        printf("\n");
        if (count == f)
            count = 0;
    }
    printf("\n The number of Page Faults using FIFO are %d", pf);
    getch();
}

/*
Enter the length of reference string -- 12
Enter the reference string -- 1 2 3 4 5 1 2 3 4 5 6 7
Enter no. of frames -- 3
The Page Replacement Process is -- 
        1       -1      -1      PF No. 1
        1       2       -1      PF No. 2
        1       2       3       PF No. 3
        4       2       3       PF No. 4
        4       5       3       PF No. 5
        1       5       3       PF No. 6
        1       2       3       PF No. 7
        4       2       3       PF No. 8
        4       5       3       PF No. 9
        4       5       6       PF No. 10
        4       5       6       PF No. 11
        4       5       7       PF No. 12

The number of Page Faults using FIFO are 12
*/