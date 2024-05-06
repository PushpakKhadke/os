#include <stdio.h>
#include <conio.h>

int main(void)
{
    int buffer[10], bufsize, in, out, produce, consume,choice;
    choice = 0;
    in = 0;
    out = 0;
    bufsize = 10;

    while (choice != 3)
    {
        puts("\n1. Produce");
        puts("2. Consume");
        puts("3. Exit");

        printf("Enter Choice = ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            if((in + 1) % bufsize == out)
                puts("Buffer is Full");
            else
            {
                printf("Enter Value = ");
                scanf("%d",&produce);
                buffer[in] = produce;
                in = (in + 1) % bufsize;
            }
            break;
        
        case 2:
            if (in == out)
                puts("Buffer Is Empty");
            else
            {
                consume = buffer[out];
                printf("Consume Value is = %d\n",consume);
                out = (out + 1) % bufsize;
            }
            
        
        case 3:
            break;
        }
    }
    
}