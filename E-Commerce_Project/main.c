#include <stdio.h>
#include <stdlib.h>
#include "e-commerce.h"
#include <stddef.h>

int main()
{
    const percent=20;
    USER user;
    ORDER order;
    ITEM* itemTable= NULL;
    USER* userTable= NULL;
    ITEM* ptr = NULL;
    USER* ptr2 = NULL;
    int idMostExpensiveItem,idUser,topBuyingClient,choice=1;
    float priceAfterPromo;
    int i,itemTableSize,userTableSize;
    int result[5][5];
    printf("-----------MENU------------ \n");
    printf("This is list of our choices : \n");
    printf("1: Fill tables \n");
    printf("2:Best Selling product \n");
    printf("3:Most expensive product \n");
    printf("4:User's list product \n");
    printf("5:Total price after promotion \n");
    printf("6:Top buying client \n");
    printf("-------------------------- \n");
    printf("Select an option : \n");
    scanf("%d",&choice);
    while (choice!=0)
    {

        switch (choice)
        {
        case 1 :
        {
            printf("Filling Tables : \n");
            printf("-------------------------- \n");
            printf("Enter Item table size : \n");
            scanf("%d",&itemTableSize);
            printf("Enter User table size : \n");
            scanf("%d",&userTableSize);
            itemTable=(ITEM*)malloc(itemTableSize*sizeof(ITEM));
            userTable=(USER*)malloc(userTableSize*sizeof(USER));
            for (i =0; i<itemTableSize; i++)
            {
                fillItem(itemTable+i);
            }
            //call the dislpay
            for (i =0; i<itemTableSize; i++)
            {
                displayItem(*(itemTable+i));
            }
            // Call the fillUser function to fill in user information
            for(i=0; i<userTableSize; i++)
            {
                fillUser(userTable+i,itemTable,itemTableSize,result[i]);
            }
        }
        break;
        case 2 :
        {
            if(itemTable!=ptr || userTable!=ptr2)
            {
                bestSellingProduct(result,userTableSize,itemTable);
                printf("\n----------------------------------\n");
            }
            else
            {
                printf("You should fill the tables first \n \n");
            }
        }
        break;
        case 3 :
        {
            if(itemTable!=ptr && userTable!=ptr2)
            {
                idMostExpensiveItem=findMostExpensiveProduct(itemTable,itemTableSize);
                printf("The name of the Most expensive item is %s \n",itemTable[idMostExpensiveItem].label);
                printf("\n----------------------------------\n");
            }
            else
            {
                printf("You should fill the tables first \n \n");
            }
        }
        break;
        case 4 :
        {
            if(itemTable!=ptr && userTable!=ptr2)
            {
                printf("Enter the ID of the user you wish to see its lists of products \n");
                scanf("%d",&idUser);
                listUserProducts(userTable,userTableSize,idUser);
                printf("\n----------------------------------\n");
            }
            else
            {
                printf("You should fill the tables first \n \n");
            }
        }
        break;
        case 5 :
        {
            if(itemTable!=ptr && userTable!=ptr2)
            {
                printf("Enter user's ID you wish to calculate their total price for \n");
                scanf("%d",&idUser);
                priceAfterPromo = getPriceAfterPromotion(userTable,userTableSize,idUser,percent);

                printf("After promotion, the total price is %2.f \n",priceAfterPromo);
                printf("\n----------------------------------\n");
            }
            else
            {
                printf("You should fill the tables first \n \n");
            }
        }
        break;
        case 6 :
        {
            if(itemTable!=ptr && userTable!=ptr2)
            {
                topBuyingClient =findTopBuyingClient(userTable,userTableSize);
                printf("\n-----------------------------\n");
                printf("Top buying Client is :\n");
                displayUser(userTable[topBuyingClient]);
                printf("\n----------------------------------\n");
            }
            else
            {
                printf("You should fill the tables first \n \n");
            }
        }
        break;



        }
        printf("-----------MENU------------ \n");
        printf("This is list of our choices : \n");
        printf("1: Fill tables \n");
        printf("2:Best Selling product \n");
        printf("3:Most expensive product \n");
        printf("4:User's list product \n");
        printf("5:Total price after promotion \n");
        printf("6:Top buying client \n");
        printf("-------------------------- \n");
        printf("Select another option (enter 0 to exit):\n");
        scanf("%d",&choice);
    }


    printf("\n----------------------------------\n");
    //call the dislpay user
    /*for (i =0; i<userTableSize; i++)
    {
        displayUser(*(userTable+i));
    }*/




    return 0;
}
