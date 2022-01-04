 /*
 Haris Ahsan
 Software Engineer

 UserName: Haris
 Password: 182

 */



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>


struct record
{
    char id[10];
    char age[6];
    char name[30];
    char crime[40];
    char gender[10];
    char height[20];
    char weight[20];

    struct record *next;
};


int count = 0;

struct record *start = NULL;



void a();
void b();
void c();
void d();
void e();
void f();
void red();
void cyne();

void viewrecord(struct record *start);
struct record *addRecord(struct record *start);
struct record *searchRecord(struct record *start);
struct record *editRecord(struct record *start);
struct record *deleterecord(struct record *start);

int main()
{
    
      
    cyne();  
    printf("\t\t\t\t\t **************************** ");
    printf("\n\t\t\t\t\t|       Software Engineer   |");
    printf("\n\t\t\t\t\t|      Haris Ahsan          |");
    
    printf("\n\t\t\t\t\t ****************************\n");

    char userName[100], Password[100];

    red();
    printf("\n\t\t\t\t\t **************************** ");
    printf("\n\t\t\t\t\t|           LOGIN           |");
    printf("\n\t\t\t\t\t ****************************\n");
    printf("\n\t\t\t\t\tEnter Username :");
    gets(userName);
    printf("\t\t\t\t\tEnter Password :");
    gets(Password);
    system("cls");
    printf("\n***************************************************************************************************************");

    if (strcmp(userName, "Haris") == 0 && strcmp(Password, "182") == 0)
    {

        printf("\n\n\t\t\t\t\t********SUCCESSFULLY LOGIN***********\n");
        int ch;

        do
        {   
            e();
            printf("\n\t\t\t\t\t**************************************\n");
            printf("\t\t\t\t\t****POLICE FIR RECORD MANAGEMENT*****\n");
            printf("\t\t\t\t\t**************************************");
            printf("\n\n\t\t\t\t\t\t::MAIN MENU::");
            printf("\n\n\t\t\t\t\tADD FIR RECORD\t[ENTER-1]");
            printf("\n\t\t\t\t\tSEARCH RECORD\t[ENTER-2]");
            printf("\n\t\t\t\t\tLIST RECORD\t[ENTER-3]");
            printf("\n\t\t\t\t\tDELETE RECORD\t[ENTER-4]");
            printf("\n\t\t\t\t\tEDIT RECORD\t[ENTER-5]");
            printf("\n\t\t\t\t\tEXIT\t\t[ENTER-6]");
            printf("\n\n\t\t\t\t=> ENTER YOUR CHOICE:");
            scanf("%d", &ch);
            printf("\n\n\t\t\t\t=> PRESS ENTER TO.....:");
            getch();
            system("cls");

            switch (ch)
            {
            case 1:
                start = addRecord(start);
                break;

            case 2:
                start = searchRecord(start);
                break;
            case 3:
                viewrecord(start);
                break;
            case 4:
                start = deleterecord(start);
                break;
            case 5:
                start = editRecord(start);
                break;
            case 6:
                exit(0);
            default:
                printf("\n\t\tYOU ENTERED WRONG CHOICE.");
            }
        } while (ch != 6);
    }
    else
    {
        printf("\n\t\t\tWrong Username Password\n");
    }
    return 0;
}




/******************ADD NEW RECORD***************/



struct record *addRecord(struct record *start)
{
    struct record *new_record, *ptr;
    int c = 0;
    char a[10], z[10];

    e();
    printf("\n\t\t\t\t********Enter Name And Id To Search Record**********\n");
    printf("\n\t\t\t\t\tEnter the Name of Criminal :");
    scanf("%s", &a);
    printf("\n\t\t\t\t\tEnter ID Of The Criminal   :");
    scanf("%s", &z);

    printf("\n\t\t\t\t****************Press Enter To Continue**************\n");
    getch();
    system("cls");
    printf("\n    ******************************************************************************************************************\n");
    
    new_record = (struct record *)malloc(sizeof(struct record));
    new_record->next = NULL;
    ptr = start;

    while (ptr != NULL)
    {
        if ((strcmp(a, ptr->name) == 0) && (strcmp(z, ptr->id) == 0))
        {   
            f();
            printf("\n\t\t\t\t  ******RECORD ALREADY EXIST*******");
            printf("\n\t\t\t|Name\tID\tAGE\tGENDER\tHEIGHT\tWEIGHT\tOFFENCE");
            printf("\n\t\t\t|%s\t%s\t%s\t%s\t%s\t%s\t%s", ptr->name, ptr->id, ptr->age, ptr->gender, ptr->height, ptr->weight, ptr->crime);
            printf("\n\t\t\t USE DIFFERENT ID AND NAME");
            printf("\n\t\t\t PRESS ENTER TO CONTINUE..");
            getch();
            system("cls");
            printf("\n***************************************************************************************************\n\n");
            c++;
        }
        ptr = ptr->next;
    }
    ptr = start;

    if (start == NULL)
    {   
        cyne();
        printf("\n\t\t\t********NO RECORD WITH THIS ID NAME FOUND CONTINUE ADDING RECORD ***********\n");
        printf("    Enter Name of Criminal          :");
        scanf("%s", new_record->name);
        printf("    Assign ID for Criminal          :");
        scanf("%s", new_record->id);
        printf("    Enter Age of Criminal           :");
        scanf("%s", new_record->age);
        printf("    Enter Gender of Criminal        :");
        scanf("%s", new_record->gender);
        printf("    Enter Height in feet            :");
        scanf("%s", new_record->height);
        printf("    Enter Weight of Criminal in Kgs :");
        scanf("%s", new_record->weight);
        printf("    Enter offence of Criminal       :");
        scanf("%s", new_record->crime);
        start = new_record;
    
        FILE *ihsan;
        ihsan = fopen("Ihsan.csv", "a");
        fprintf(ihsan, "%s,%s,%s,%s,%s,%s,%s\n", new_record->name, new_record->id, new_record->age, new_record->gender, new_record->height, new_record->weight, new_record->crime);
        fclose(ihsan);
        count++;
        f();
        printf("\n\t\t\t\t**********Record Added Successfully*************");
        printf("\n\t\t\t\t************************************************");
        printf("\t\t\t\t\t\t\t\t\t\tEnter Any Key To Continue\n");
        getch();
        system("cls");
        printf("\n\n*****************************************************************************************************\n");
    
    }

    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
    
        cyne();
        printf("\t\t\t\t\t******** CONTINUE ADDING RECORD ***********");
        printf("\n     Enter Name of Criminal          :");
        scanf("%s", new_record->name);
        printf("     Assign ID for Criminal          :");
        scanf("%s", new_record->id);
        printf("     Enter Age of Criminal           :");
        scanf("%s", new_record->age);
        printf("     Enter Gender of Criminal        :");
        scanf("%s", new_record->gender);
        printf("     Enter Height in feet            :");
        scanf("%s", new_record->height);
        printf("     Enter Weight of Criminal in Kgs :");
        scanf("%s", new_record->weight);
        printf("     Enter offence of Criminal       :");
        scanf("%s", new_record->crime);
        ptr->next = new_record;

        FILE *ihsan;
        ihsan = fopen("Ihsan.csv", "a");
        fprintf(ihsan, "%s,%s,%s,%s,%s,%s,%s\n", new_record->name, new_record->id, new_record->age, new_record->gender, new_record->height, new_record->weight, new_record->crime);
        fclose(ihsan);
        count++;

        f();
        printf("\n\t\t\t\t**********Record Added Successfully*************");
        printf("\n\t\t\t\t************************************************");
        printf("\t\t\t\t\t\t\t\t\t\t\tEnter Any Key To Continue\n");
        getch();
        system("cls");
    }

    return start;
}



/*****************SEARCH RECORD**************/



struct record *searchRecord(struct record *start)
{
    struct record *ptr;
    int d = 0;
    char a[10];
    
    e();
    printf("\n\t\t\tEnter ID of Crime File to be searched: \t");
    scanf("%s", &a);
    ptr = start;


    while (ptr != NULL)
    {
        if (strcmp(a, ptr->id) == 0)
        {
            f();
            printf("\n\t\t\t|Name\tID\tAGE\tGENDER\tHEIGHT\tWEIGHT\tOFFENCE");
            printf("\n\t\t\t|%s\t%s\t%s\t%s\t%s\t%s\t%s", ptr->name, ptr->id, ptr->age, ptr->gender, ptr->height, ptr->weight, ptr->crime);
            d++;
            printf("\n\t\t\t***************************************************************\n");
        }
        ptr = ptr->next;
    }

    if (d == 0)
    {   
        f();
        printf("\t\t\t==========================");
        printf("\n\t\t\tThe File does not Exists.");
        printf("\n\t\t\t==========================");
    }
    
    e();
    printf("\n\t\t\t\t\tPress Enter To Continue\n");
    getch();
    system("cls");
    return start;
}



/***********************Edit Record***********************/



struct record *editRecord(struct record *start)
{
    struct record *ptr;
    int flag = 0;
    char a[10];
    int select;
   
    cyne();
    printf("\n\t\t\tEnter ID of Crime File to be Edit: \t");
    scanf("%s", &a);
    ptr = start;

    while (ptr != NULL)
    {
        if (strcmp(a, ptr->id) == 0)
        {
            f();
            printf("\n\t\t\t\t\t***********RECORD TO BE UPDATED IS***********");
            printf("\n\t\t\t|Name\tID\tAGE\tGENDER\tHEIGHT\tWEIGHT\tOFFENCE");
            printf("\n\t\t\t|%s\t%s\t%s\t%s\t%s\t%s\t%s", ptr->name, ptr->id, ptr->age, ptr->gender, ptr->height, ptr->weight, ptr->crime);
            printf("\n\t\t\t******************************************************************************");
            
            d();
            printf("\n\t\t\tWhat You Want To Edit:\n");
            printf("\t\t\t1.Name\n\t\t\t2.Id\n\t\t\t3.Age\n\t\t\t4.Gender\n\t\t\t5.Height\n\t\t\t6.Weight\n\t\t\t7.Offence\n");
            scanf("\t\t\t\t\t\t%d", &select);
            system("cls");
            
            cyne();
            if (select == 1)
            {
                printf("\t\t\tEnter New Name:");
                scanf("%s", ptr->name);
                printf("\t\t\t\t**************\n");
                printf("\t\t\t\tNAME UPDATED\n");
                printf("\t\t\t\t**************");

            }
            else if (select == 2)
            {
                printf("\n\t\t\tEnter New Id\n");
                scanf("%s", ptr->id);
                printf("\t\t\t\t**************\n");
                printf("\t\t\t\tID UPDATED\n");
                printf("\t\t\t\t**************");

            }
            else if (select == 3)
            {
                printf("\n\t\t\tEnter New Age:\n");
                scanf("\t\t\t%s", ptr->age);
                printf("\t\t\t\t**************\n");
                printf("\t\t\t\tAGE UPDATED\n");
                printf("\t\t\t\t**************");

            }
            else if (select == 4)
            {
                printf("\n\t\t\tEnter New Gender:\n");
                scanf("\t\t\t%s", ptr->gender);
                printf("\t\t\t\t**************\n");
                printf("\t\t\t\tGENDER UPDATED\n");
                printf("\t\t\t\t**************");

            }
            else if (select == 5)
            {
                printf("\n\t\t\tEnter New Height:\n");
                scanf("\t\t\t%s", ptr->height);
                printf("\t\t\t\t**************\n");
                printf("\t\t\t\tHEIGHT UPDATED\n");
                printf("\t\t\t\t**************");

            }
            else if (select == 6)
            {
                printf("\n\t\t\tEnter New Weight:\n");
                scanf("\t\t\t%s", ptr->weight);
                printf("\t\t\t**************\n");
                printf("\t\t\tWEIGHT UPDATED\n");
                printf("\t\t\t**************");

            }
            else if (select == 7)
            {
                printf("\n\t\t\tEnter New Offence:\n");
                scanf("\t\t\t%s", ptr->crime);
                printf("\t\t\t**************\n");
                printf("\t\t\tCRIME UPDATED\n");
                printf("\t\t\t**************");

            }

            flag++;
        }

        ptr = ptr->next;
    }

    if (flag == 0)
    {   
        f();
        printf("\t\t\t*************************");
        printf("\n\t\t\tThe File does not Exists.\n");
        printf("\t\t\t*************************");
    }
    printf("\n\t\t\t***********************************************************************");
    printf("\n\t\t\t\t\t\tPress Enter To continue\n");
    getch();
    system("cls");
    return start;
}



/***************VIEW RECORDS LIST****************/



void viewrecord(struct record *start)
{
    struct record *ptr;
    ptr = start;

        FILE *ihsan;
        ihsan = fopen("Ihsan.csv", "w");

    if(ptr!=NULL){  

    while (ptr != NULL)
    {
        f();
        printf("\n\t\t\t|Name\tID\tAGE\tGENDER\tHEIGHT\tWEIGHT\tOFFENCE");
        printf("\n\t\t\t|%s\t%s\t%s\t%s\t%s\t%s\t%s", ptr->name, ptr->id, ptr->age, ptr->gender, ptr->height, ptr->weight, ptr->crime);
        fprintf(ihsan, "%s,%s,%s,%s,%s,%s,%s\n", ptr->name, ptr->id, ptr->age, ptr->gender, ptr->height, ptr->weight, ptr->crime);
        ptr = ptr->next;
        printf("\n\t\t\t================================================================\n");
    }}
    else if (ptr==NULL)
    {
        printf("\t\t\t********************");
        printf("\n\t\t\tFILE DOES NOT FOUND..");
        printf("\n\t\t\t********************");
    }
    

    fclose(ihsan);

    printf("\n\t\t\t\t\tEnter Any Key To Continue");
    getch();
    
}



/*************** DELETE RECORDS ***************/



struct record *deleterecord(struct record *start)
{
    struct record *ptr, *pre_ptr;
    char a[10];
    
    c();
    printf("\n\t\t\tEnter the ID of File to be Deleted:\t");
    scanf("%s", &a);
    ptr = start;

    if ((strcmp(a, start->id) == 0))
    {
        start = start->next;
        
        f();
        printf("\t\t\t************ DELETED RECORD IS **************");
        printf("\n\t\t\t|Name\tID\tAGE\tGENDER\tHEIGHT\tWEIGHT\tOFFENCE");
        printf("\n\t\t\t|%s\t%s\t%s\t%s\t%s\t%s\t%s", ptr->name, ptr->id, ptr->age, ptr->gender, ptr->height, ptr->weight, ptr->crime);
        free(ptr);
        printf("\n\t\t\tPRESS ENTER TO CONTINUE..");
        getch();
        system("cls");

        return start;
    }
    else if (count > 1)
    {
        while (ptr != NULL)
        {
            pre_ptr = ptr;
            ptr = ptr->next;
            if (strcmp(a, ptr->id) == 0)
            {
                pre_ptr->next = ptr->next;
                printf("\t\t\t************ DELETED RECORD IS **************");
                printf("\n\t\t\t|Name\tID\tAGE\tGENDER\tHEIGHT\tWEIGHT\tOFFENCE");
                printf("\n\t\t\t|%s\t%s\t%s\t%s\t%s\t%s\t%s", ptr->name, ptr->id, ptr->age, ptr->gender, ptr->height, ptr->weight, ptr->crime);
                free(ptr);
                printf("\n\t\t\tPRESS ENTER TO CONTINUE..");
                getch();
                system("cls");

                return start;
            }
        }
    }
    return start;
}

void cyne(){
    printf("\033[0;36m");
}

void red(){
    printf("\033[0;33m");
}
void a(){
    printf("\033[0;31m");
}

void c(){
    printf("\033[0;32m");
}
void d(){
    printf("\033[0;34m");
}
void e(){
    printf("\033[0;35m");
}
void f(){
    printf("\033[1;33m");
}
