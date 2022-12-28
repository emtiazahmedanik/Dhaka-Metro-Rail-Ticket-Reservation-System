#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int id;
    char name[20];
    char gender[20];
    char from[20];
    char to[20];
    char train[25];
    int time;
    int Seat;
    int rent;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

int sit[20][2];

int amount;
char F[20];
char T[20];

void Home();
void searchtrain();
void Bijoy();
void mohanagor();
void add_node(char name[20], char gen[10], char from[20], char to[10], int time, char train[25], int seat, int phone, int r);
void bill(char Name[20], char Gen[10], char From[20], char To[10], int Time, char Train[25], int seat, int phone, int r);

void showticket();
void cancelticket();
int seat();

void destination_mohanagor();
void destination_bijoy();
void du();
void farmgate();
void agargaon();
void shewrapara();
void kazipara();
void Mirpur10();
void Mirpur11();
void from_pallabi();
void from_U_south();
void from_U_centre();
void from_U_north();
void komlapur_to();
void du_to();
void farmgate_to();
void agargaon_to();
void shewrapara_to();
void kazipara_to();
void Mirpur10_to();
void Mirpur11_to();
void pallabi_to();
void uttara_centre_to();
void uttara_south_to();
void traininformation();

int main()
{
    int n = 10;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sit[i][j] = n;
            n++;
        }
    }

    system("cls");
    printf("\t\t=================================================\n");
    printf("\t\t|                                               |\n");
    printf("\t\t|        -----------------------------          |\n");
    printf("\t\t|       DHAKA METRO TICKET RERS. SYSTEM         |\n");
    printf("\t\t|        -----------------------------          |\n");
    printf("\t\t|                                               |\n");
    printf("\t\t|                                               |\n");
    printf("\t\t|                                               |\n");
    printf("\t\t|              BROUGHT TO YOU BY                |\n");
    printf("\t\t|           |  MD. Emtiaz Ahmed   |             |\n");
    printf("\t\t|                                               |\n");
    printf("\t\t=================================================\n\n\n");

    printf(" \n Press any key to continue:");

    getchar();
    system("cls");

    int ch;

    while (1)
    {

        system("cls");

        printf("\t\t=================================================\n");
        printf("\t\t|         1.Home                                |\n");
        printf("\t\t|        -----------------------------          |\n");
        printf("\t\t|         2.Train Information                   |\n");
        printf("\t\t|        -----------------------------          |\n");
        printf("\t\t|         3.Showticket                          |\n");
        printf("\t\t|        -----------------------------          |\n");
        printf("\t\t|         4.Cancel Ticket                       |\n");
        printf("\t\t|        -----------------------------          |\n");
        printf("\t\t|         5.Exit                                |\n");
        printf("\t\t|        -----------------------------          |\n");
        printf("\t\t|                                               |\n");
        printf("\t\t|              BROUGHT TO YOU BY                |\n");
        printf("\t\t|           |  MD. Emtiaz Ahmed   |             |\n");
        printf("\t\t|                                               |\n");
        printf("\t\t=================================================\n\n\n");

        printf("\nEnter choice:");
        scanf("%d", &ch);
        system("cls");
        switch (ch)
        {
        case 1:
            Home();
            break;
        case 2:
            traininformation();
            break;
        case 3:
            showticket();
            break;
        case 4:
            cancelticket();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nWrong Input! (:");
            break;
        }
    }

    return 0;
}

void Home()
{
    int ch;
    printf("\n1.Search Train\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        searchtrain();
        break;

    default:
        printf("\nWrong Input\n");
        break;
    }
}
void searchtrain()
{
    system("cls");
    printf("\n1.Dhaka Metro Bijoy [Komlapur to Uttara-North]\n");
    printf("\n2.Dhaka Metro Mohanagor [Uttara-North to Komlapur\n");
    int ch;
    int choice;
    printf("\nEnter choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("\nDo you want to buy ticket? Y(1)/N(0)\n");
        scanf("%d", &choice);

        if (choice == 0)
        {
            return;
        }
        else if (choice == 1)
        {
            Bijoy();
        }
        break;
    case 2:
        printf("\nDo you want to buy ticket? Y(1)/N(0)\n");
        scanf("%d", &choice);

        if (choice == 0)
        {
            return;
        }
        else if (choice == 1)
        {
            mohanagor();
        }
        break;

    default:
        printf("\nWrong Input!\n");
        break;
    }
}

void Bijoy()
{
    char Name[20], Gen[10];
    char From[20], To[20];
    int Time, phone;
    char Train[25] = "Dhaka Metro Bijoy";

    destination_bijoy();
    strcpy(From, F);
    strcpy(To, T);

    system("cls");

    printf("\nTime:");
    scanf("%d", &Time);
    printf("\nEnter name:");
    getchar();
    gets(Name);
    printf("\nEnter Phone Number:");
    scanf("%d", &phone);
    printf("\nEnter gender: ");
    getchar();
    gets(Gen);
    int s = seat();
    int r = amount;
    add_node(Name, Gen, From, To, Time, Train, s, phone, r);
    bill(Name, Gen, From, To, Time, Train, s, phone, r);
}
void mohanagor()
{
    char Name[20], Gen[10];
    char From[20], To[20];
    int Time, phone;
    char Train[25] = "Dhaka Metro Mohanagor";

    destination_mohanagor();

    strcpy(From, F);
    strcpy(To, T);

    system("cls");

    printf("\nTime:");
    scanf("%d", &Time);
    printf("\nEnter name:");
    getchar();
    gets(Name);
    printf("\nEnter Phone Number:");
    scanf("%d", &phone);
    printf("\nEnter gender: ");
    getchar();
    gets(Gen);
    int s = seat();
    int r = amount;
    add_node(Name, Gen, From, To, Time, Train, s, phone, r);
    bill(Name, Gen, From, To, Time, Train, s, phone, r);
}

void add_node(char Name[20], char Gen[10], char From[20], char To[10], int Time, char Train[25], int seat, int phone, int r)
{
    struct node *newptr = NULL, *ptr;
    newptr = (struct node *)malloc(sizeof(struct node));
    strcpy(newptr->name, Name);
    strcpy(newptr->gender, Gen);
    strcpy(newptr->from, From);
    strcpy(newptr->to, To);
    strcpy(newptr->train, Train);
    newptr->time = Time;
    newptr->Seat = seat;
    newptr->id = phone;
    newptr->rent = r;
    newptr->next = NULL;
    newptr->prev = NULL;
    if (head == NULL)
        head = newptr;
    else
    {
        ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newptr;
        newptr->prev = ptr;
    }
}

void bill(char Name[20], char Gen[10], char From[20], char To[10], int Time, char Train[25], int seat, int phone, int r)

{
    getchar();
    system("cls");
    int amount = r;

    printf("\t\t=================================================\n");
    printf("\t\t|                                ID: %d    \n", phone);
    printf("\t\t|Name : %s                                  \n", Name);
    printf("\t\t|Gender: %s                                    \n", Gen);
    printf("\t\t|From: %s                                      \n", From);
    printf("\t\t|To: %s                                        \n", To);
    printf("\t\t|Time: %d                                      \n", Time);
    printf("\t\t|Train: %s                                     \n", Train);
    printf("\t\t|Seat: %d                                      \n", seat);
    printf("\t\t|Amount:%d                                     \n", amount);
    printf("\t\t|                                              \n");
    printf("\t\t|           |  DHAKA METRO   |                 \n");
    printf("\t\t|                                               \n");
    printf("\t\t=================================================\n\n\n");

    printf("Press Any Key To Continue:");
    getchar();
}

void showticket()
{
    // system("cls");
    int idnum;
    printf("\nEnter id:");
    scanf("%d", &idnum);
    struct node *ptr = head;
    if(ptr!=NULL)
    {
    while (ptr->id != idnum)
    {
        ptr = ptr->next;

    }
   
        printf("\t\t=================================================\n");
        printf("\t\t|                                ID: %d    \n", ptr->id);
        printf("\t\t|Name : %s                                  \n", ptr->name);
        printf("\t\t|Gender: %s                                    \n", ptr->gender);
        printf("\t\t|From: %s                                      \n", ptr->from);
        printf("\t\t|To: %s                                        \n", ptr->to);
        printf("\t\t|Time: %d                                      \n", ptr->time);
        printf("\t\t|Train: %s                                     \n", ptr->train);
        printf("\t\t|Seat: %d                                      \n", ptr->Seat);
        printf("\t\t|Amount:%d                                     \n", ptr->rent);
        printf("\t\t|                                              \n");
        printf("\t\t|           |  DHAKA METRO   |                 \n");
        printf("\t\t|                                               \n");
        printf("\t\t=================================================\n\n\n");
        printf("\nPress any key to continue:");
        getchar();
        getchar();
    }
    else
    { 
    printf("\nNot Found\n");
    printf("\nPress any key to continue:");
    getchar();
    getchar();
    }
   
}

void cancelticket()
{
    system("cls");
    int idnum;
    printf("\nEnter id:");
    scanf("%d", &idnum);
    struct node *ptr = head;
    if (head->id == idnum)
    {
        head = NULL;
    }
    else
    {
        while (ptr->id != idnum)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = ptr->next;
    }
    printf("\nTicket Cancelled!\n");
    printf("\nPress any key to continue:");
    getchar();
    getchar();
}

int seat()
{

    system("cls");
    printf("\nSeat Layout:\n");
    printf("\n");
    int choice;
    int s = 0;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 2; j++)
        {

            printf("%d ", sit[i][j]);
        }

        printf("\n");
    }

    printf("\nSelect seat:");
    scanf("%d", &choice);

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 2; j++)
        {

            if (sit[i][j] == choice)
            {

                s = sit[i][j];
                sit[i][j] = 0;
                printf("\nBooked %d\n", s);
                return s;
            }
        }
    }
    if (s == 0)
    {

        printf("\nNot available!\n");
        printf("\nSelect set again:\n");
        printf("\nPress any key to continue:");
        getchar();
        getchar();

        seat();
    }
    
}

void destination_mohanagor()
{
    system("cls");
    int ch;
    printf("\n1.From Uttara North To----\n");
    printf("\n2.From Uttara Center To----\n");
    printf("\n3.From Uttara South To----\n");
    printf("\n4.From Pallabi To----\n");
    printf("\n5.From Mirpur 11 To----\n");
    printf("\n6.From Mirpur 10 To----\n");
    printf("\n7.From Kazipara To----\n");
    printf("\n8.From Shewrapara To----\n");
    printf("\n9.From Agargaon To----\n");
    printf("\n10.From Farmgate To----\n");
    printf("\n11.From Dhaka University To----\n");
    printf("\nEnter choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        from_U_north();
        break;
    case 2:
        from_U_centre();
        break;
    case 3:
        from_U_south();
        break;
    case 4:
        from_pallabi();
        break;
    case 5:
        Mirpur11();
        break;
    case 6:
        Mirpur10();
        break;
    case 7:
        kazipara();
        break;
    case 8:
        shewrapara();
        break;
    case 9:
        agargaon();
        break;
    case 10:
        farmgate();
        break;
    case 11:
        du();
        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void from_U_north()
{
    system("cls");
    int ch;
    printf("\n1.From Uttara North To Uttara Centre\n");
    printf("\n2.From Uttara North To Uttara South\n");
    printf("\n3.From Uttara North To Pallabi\n");
    printf("\n4.From Uttara North To Mirpur 11\n");
    printf("\n5.From Uttara North To Mirpur 10\n");
    printf("\n6.From Uttara North To Kazipara\n");
    printf("\n7.From Uttara North To Shewrapara\n");
    printf("\n8.From Uttara North To Agargaon\n");
    printf("\n9.From Uttara North To Farmgate\n");
    printf("\n10.From Uttara North To Dhaka University\n");
    printf("\n11.From Uttara North To Motijheel\n");
    printf("\n12.From Uttara North To Komlapur\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 1:
        amount = 20;
        strcpy(F, "Uttara North");
        strcpy(T, "Uttara Centre");
        break;
    case 2:
        amount = 20;
        strcpy(F, "Uttara North");
        strcpy(T, "Uttara South ");
        break;
    case 3:
        amount = 30;
        strcpy(F, "Uttara North");
        strcpy(T, "Pallabi");
        break;
    case 4:
        amount = 30;
        strcpy(F, "Uttara North");
        strcpy(T, "Mirpur 11");
        break;
    case 5:
        amount = 40;
        strcpy(F, "Uttara North");
        strcpy(T, "Mirpur 10");
        break;
    case 6:
        amount = 40;
        strcpy(F, "Uttara North");
        strcpy(T, "Kazipara");
        break;
    case 7:
        amount = 50;
        strcpy(F, "Uttara North");
        strcpy(T, "Shewrapara");
        break;
    case 8:
        amount = 60;
        strcpy(F, "Uttara North");
        strcpy(T, "Agargaon");
        break;
    case 9:
        amount = 70;
        strcpy(F, "Uttara North");
        strcpy(T, "Farmgate");
        break;
    case 10:
        amount = 90;
        strcpy(F, "Uttara North");
        strcpy(T, "Dhaka_University");
        break;
    case 11:
        amount = 100;
        strcpy(F, "Uttara North");
        strcpy(T, "Motijheel");
        break;
    case 12:
        amount = 100;
        strcpy(F, "Uttara North");
        strcpy(T, "Komlapur");
        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void from_U_centre()
{
    system("cls");
    int ch;

    printf("\n13.From Uttara centre To Uttara South\n");
    printf("\n14.From Uttara centre To Pallabi\n");
    printf("\n15.From Uttara centre To Mirpur 11\n");
    printf("\n16.From Uttara centre To Mirpur 10\n");
    printf("\n17.From Uttara centre To Kazipara\n");
    printf("\n18.From Uttara centre To Shewrapara\n");
    printf("\n19.From Uttara centre To Agargaon\n");
    printf("\n20.From Uttara centre To Farmgate\n");
    printf("\n21.From Uttara centre To Dhaka University\n");
    printf("\n22.From Uttara centre To Motijheel\n");
    printf("\n23.From Uttara centre To Komlapur\n");

    scanf("%d", &ch);
    switch (ch)
    {
    case 13:
        amount = 20;
        strcpy(F, "Uttara centre");
        strcpy(T, "Uttara south");

        break;
    case 14:
        amount = 20;
        strcpy(F, "Uttara centre");
        strcpy(T, "Pallabi");

        break;
    case 15:
        amount = 30;
        strcpy(F, "Uttara centre");
        strcpy(T, "Mirpur 11");

        break;
    case 16:
        amount = 30;
        strcpy(F, "Uttara centre");
        strcpy(T, "Mirpur 10");

        break;
    case 17:
        amount = 40;

        strcpy(F, "Uttara centre");
        strcpy(T, "Kazipara");

        break;
    case 18:
        amount = 40;
        strcpy(F, "Uttara centre");
        strcpy(T, "Shewrapara");

        break;
    case 19:
        amount = 50;
        strcpy(F, "Uttara centre");
        strcpy(T, "Agargaon");

        break;
    case 20:
        amount = 60;
        strcpy(F, "Uttara centre");
        strcpy(T, "Farmgate");
        break;
    case 21:
        amount = 80;
        strcpy(F, "Uttara centre");
        strcpy(T, "Dhaka University");
        break;
    case 22:
        amount = 90;
        strcpy(F, "Uttara centre");
        strcpy(T, "Motijheel");

        break;
    case 23:
        amount = 100;
        strcpy(F, "Uttara centre");
        strcpy(T, "Komlapur");

        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void from_U_south()
{
    system("cls");
    int ch;
    printf("\n24.From Uttara south To Pallabi\n");
    printf("\n25.From Uttara south To Mirpur 11\n");
    printf("\n26.From Uttara south To Mirpur 10\n");
    printf("\n27.From Uttara south To Kazipara\n");
    printf("\n28.From Uttara south To Shewrapara\n");
    printf("\n29.From Uttara south To Agargaon\n");
    printf("\n30.From Uttara south To Farmgate\n");
    printf("\n31.From Uttara south To Dhaka University\n");
    printf("\n32.From Uttara south To Motijheel\n");
    printf("\n33.From Uttara south To Komlapur\n");

    scanf("%d", &ch);
    switch (ch)
    {
    case 24:
        amount = 20;
        strcpy(F, "Uttara south");
        strcpy(T, "Pallabi");

        break;
    case 25:
        amount = 20;
        strcpy(F, "Uttara south");
        strcpy(T, "Mirpur 11");

        break;
    case 26:
        amount = 30;
        strcpy(F, "Uttara south");
        strcpy(T, "Mirpur 10");

        break;
    case 27:
        amount = 30;
        strcpy(F, "Uttara south");
        strcpy(T, "Kazipara");

        break;
    case 28:
        amount = 40;
        strcpy(F, "Uttara south");
        strcpy(T, "Shewrapara");

        break;
    case 29:
        amount = 50;
        strcpy(F, "Uttara south");
        strcpy(T, "Agargaon");
        break;
    case 30:
        amount = 60;
        strcpy(F, "Uttara south");
        strcpy(T, "Farmgate");

        break;
    case 31:
        amount = 70;
        strcpy(F, "Uttara south");
        strcpy(T, "Dhaka University");

        break;
    case 32:
        amount = 90;
        strcpy(F, "Uttara south");
        strcpy(T, "Motijheel");

        break;
    case 33:
        amount = 90;
        strcpy(F, "Uttara south");
        strcpy(T, "Komlapur");

        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void from_pallabi()
{
    system("cls");
    int ch;
    printf("\n34.From Pallabi To Mirpur 11\n");
    printf("\n35.From Pallabi To Mirpur 10\n");
    printf("\n36.From Pallabi To Kazipara\n");
    printf("\n37.From Pallabi To Shewrapara\n");
    printf("\n38.From Pallabi To Agargaon\n");
    printf("\n39.From Pallabi To Farmgate\n");
    printf("\n40.From Pallabi To Dhaka University\n");
    printf("\n41.From Pallabi To Motijheel\n");
    printf("\n42.From Pallabi North To Komlapur\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 34:
        amount = 20;
        strcpy(F, "Pallabi");
        strcpy(T, "Mirpur 11");

        break;
    case 35:
        amount = 20;
        strcpy(F, "Pallabi");
        strcpy(T, "Mirpur 10");

        break;
    case 36:
        amount = 20;
        strcpy(F, "Pallabi");
        strcpy(T, "Kazipara");

        break;
    case 37:
        amount = 30;
        strcpy(F, "Pallabi");
        strcpy(T, "Shewrapara");

        break;
    case 38:
        amount = 30;
        strcpy(F, "Pallabi");
        strcpy(T, "Agargaon");

        break;
    case 39:
        amount = 50;
        strcpy(F, "Pallabi");
        strcpy(T, "Farmgate");

        break;
    case 40:
        amount = 60;
        strcpy(F, "Pallabi");
        strcpy(T, "Dhaka University");

        break;
    case 41:
        amount = 80;
        strcpy(F, "Pallabi");
        strcpy(T, "Motijheel");

        break;
    case 42:
        amount = 80;
        strcpy(F, "Pallabi");
        strcpy(T, "Komlapur");

        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void Mirpur11()
{
    system("cls");
    int ch;
    printf("\n43.From Mirpur 11 To Mirpur 10\n");
    printf("\n44.From Mirpur 11 To Kazipara\n");
    printf("\n45.From Mirpur 11 To Shewrapara\n");
    printf("\n46.From Mirpur 11 To Agargaon\n");
    printf("\n47.From Mirpur 11 To Farmgate\n");
    printf("\n48.From Mirpur 11 To Dhaka University\n");
    printf("\n49.From Mirpur 11 To Motijheel\n");
    printf("\n50.From Mirpur 11 To Komlapur\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 43:
        amount = 20;
        strcpy(F, "Mirpur 11");
        strcpy(T, "Mirpur 10");

        break;
    case 44:
        amount = 20;
        strcpy(F, "Mirpur 11");
        strcpy(T, "Kazipara");

        break;
    case 45:
        amount = 20;
        strcpy(F, "Mirpur 11");
        strcpy(T, "Shewrapara");

        break;
    case 46:
        amount = 30;
        strcpy(F, "Mirpur 11");
        strcpy(T, "Agargaon");

        break;
    case 47:
        amount = 50;
        strcpy(F, "Mirpur 11");
        strcpy(T, "Farmgate");

        break;
    case 48:
        amount = 60;
        strcpy(F, "Mirpur 11");
        strcpy(T, "Dhaka University");

        break;
    case 49:
        amount = 70;
        strcpy(F, "Mirpur 11");
        strcpy(T, "Motijheel");

        break;
    case 50:
        amount = 80;
        strcpy(F, "Mirpur 11");
        strcpy(T, "Komlapur");

        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void Mirpur10()
{
    system("cls");
    int ch;

    printf("\n51.From Mirpur 10 To Kazipara\n");
    printf("\n52.From Mirpur 10 To Shewrapara\n");
    printf("\n53.From Mirpur 10 To Agargaon\n");
    printf("\n54.From Mirpur 10 To Farmgate\n");
    printf("\n55.From Mirpur 10 To Dhaka University\n");
    printf("\n56.From Mirpur 10 To Motijheel\n");
    printf("\n57.From Mirpur 10 To Komlapur\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 51:
        amount = 20;
        strcpy(F, "Mirpur 10");
        strcpy(T, "Kazipara");

        break;
    case 52:
        amount = 20;
        strcpy(F, "Mirpur 10");
        strcpy(T, "Shewrapara");

        break;
    case 53:
        amount = 20;
        strcpy(F, "Mirpur 10");
        strcpy(T, "Agargaon");

        break;
    case 54:
        amount = 30;
        strcpy(F, "Mirpur 10");
        strcpy(T, "Farmgate");

        break;
    case 55:
        amount = 60;
        strcpy(F, "Mirpur 10");
        strcpy(T, "Dhaka University");

        break;
    case 56:
        amount = 60;
        strcpy(F, "Mirpur 10");
        strcpy(T, "Motijheel");

        break;
    case 57:
        amount = 70;
        strcpy(F, "Mirpur 10");
        strcpy(T, "Komlapur");

        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void kazipara()
{
    system("cls");
    int ch;
    printf("\n58.From Kazipara To Shewrapara\n");
    printf("\n59.From Kazipara To Agargaon\n");
    printf("\n60.From Kazipara To Farmgate\n");
    printf("\n61.From Kazipara To Dhaka University\n");
    printf("\n62.From Kazipara To Motijheel\n");
    printf("\n63.From Kazipara To Komlapur\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 58:
        amount = 20;
        strcpy(F, "Kazipara");
        strcpy(T, "Shewrapara");

        break;
    case 59:
        amount = 20;
        strcpy(F, "Kazipara");
        strcpy(T, "Agargaon");

        break;
    case 60:
        amount = 30;
        strcpy(F, "Kazipara");
        strcpy(T, "Farmgate");

        break;
    case 61:
        amount = 50;
        strcpy(F, "Kazipara");
        strcpy(T, "Dhaka University");

        break;
    case 62:
        amount = 60;
        strcpy(F, "Kazipara");
        strcpy(T, "Motijheel");

        break;
    case 63:
        amount = 70;
        strcpy(F, "Kazipara");
        strcpy(T, "Komlapur");

        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void shewrapara()
{
    system("cls");
    int ch;

    printf("\n64.From Shewrapara To Agargaon\n");
    printf("\n65.From Shewrapara To Farmgate\n");
    printf("\n66.From Shewrapara To Dhaka University\n");
    printf("\n67.From Shewrapara To Motijheel\n");
    printf("\n68.From Shewrapara To Komlapur\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 64:
        amount = 20;
        strcpy(F, "Shewrapara");
        strcpy(T, "Agargaon");

        break;
    case 65:
        amount = 20;
        strcpy(F, "Shewrapara");
        strcpy(T, "Farmgate");

        break;
    case 66:
        amount = 50;
        strcpy(F, "Shewrapara");
        strcpy(T, "Dhaka University");

        break;
    case 67:
        amount = 50;
        strcpy(F, "Shewrapara");
        strcpy(T, "Motijheel");

        break;
    case 68:
        amount = 60;
        strcpy(F, "Shewrapara");
        strcpy(T, "Komlapur");

        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void agargaon()
{
    system("cls");
    int ch;
    printf("\n69.From Agargaon To Farmgate\n");
    printf("\n70.From Agargaon To Dhaka University\n");
    printf("\n71.From Agargaon To Motijheel\n");
    printf("\n72.From Agargaon To Komlapur\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 69:
        amount = 20;
        strcpy(F, "Agargaon");
        strcpy(T, "Farmgate");

        break;
    case 70:
        amount = 40;
        strcpy(F, "Agargaon");
        strcpy(T, "Dhaka University");

        break;
    case 71:
        amount = 50;
        strcpy(F, "Agargaon");
        strcpy(T, "Motijheel");

        break;
    case 72:
        amount = 50;
        strcpy(F, "Agargaon");
        strcpy(T, "Komlapur");

        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void farmgate()
{
    system("cls");
    int ch;
    printf("\n73.From Farmgate To Dhaka University\n");
    printf("\n74.From Farmgate To Motijheel\n");
    printf("\n75.From Farmgate To Komlapur\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 73:
        amount = 20;
        strcpy(F, "Farmgate");
        strcpy(T, "Dhaka University");

        break;
    case 74:
        amount = 30;
        strcpy(F, "Farmgate");
        strcpy(T, "Motijheel");

        break;
    case 75:
        amount = 40;
        strcpy(F, "Farmgate");
        strcpy(T, "Komlapur");

        break;
    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void du()
{
    system("cls");
    int ch;
    printf("\n76.From Dhaka University To Motijheel\n");
    printf("\n77.From Dhaka University To Komlapur\n");

    scanf("%d", &ch);
    switch (ch)
    {
    case 76:
        amount = 20;
        strcpy(F, "Dhaka University");
        strcpy(T, "Motijheel");

        break;
    case 77:
        amount = 20;
        strcpy(F, "Dhaka University");
        strcpy(T, "Komlapur");

        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void destination_bijoy()
{
    system("cls");
    int ch;
    printf("\n1.From Komlapur To----\n");
    printf("\n2.From Dhaka University To----\n");
    printf("\n3.From Farmgate To----\n");
    printf("\n4.From Agargaon To----\n");
    printf("\n5.From Shewrapara To----\n");
    printf("\n6.From Kazipara To----\n");
    printf("\n7.From Mirpur 10 To----\n");
    printf("\n8.From Mirpur 11 To----\n");
    printf("\n9.From Pallabi To----\n");
    printf("\n10.From Uttara Center To----\n");
    printf("\n11.From Uttara South To----\n");

    printf("\nEnter choice:");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        komlapur_to();
        break;
    case 2:
        du_to();
        break;
    case 3:
        farmgate_to();
        break;
    case 4:
        agargaon_to();
        break;
    case 5:
        shewrapara_to();
        break;
    case 6:
        kazipara_to();
        break;
    case 7:
        Mirpur10_to();
        break;
    case 8:
        Mirpur11_to();
        break;
    case 9:
        pallabi_to();
        break;
    case 10:
        uttara_centre_to();
        break;
    case 11:
        uttara_south_to();
        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void komlapur_to()
{
    system("cls");
    int ch;
    printf("\n1.From Komlapur To Uttara North\n");
    printf("\n2.From Komlapur To Uttara South\n");
    printf("\n3.From Komlapur To Pallabi\n");
    printf("\n4.From Komlapur To Mirpur 11\n");
    printf("\n5.From Komlapur To Mirpur 10\n");
    printf("\n6.From Komlapur To Kazipara\n");
    printf("\n7.From Komlapur To Shewrapara\n");
    printf("\n8.From Komlapur To Agargaon\n");
    printf("\n9.From Komlapur To Farmgate\n");
    printf("\n10.From Komlapur To Dhaka University\n");
    printf("\n11.From Komlapur To Motijheel\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 1:
        amount = 100;
        strcpy(F, "Komlapur");
        strcpy(T, "Uttara North");
        break;
    case 2:
        amount = 90;
        strcpy(F, "Komlapur");
        strcpy(T, "Uttara South ");
        break;
    case 3:
        amount = 90;
        strcpy(F, "Komlapur");
        strcpy(T, "Pallabi");
        break;
    case 4:
        amount = 80;
        strcpy(F, "Komlapur");
        strcpy(T, "Mirpur 11");
        break;
    case 5:
        amount = 70;
        strcpy(F, "Komlapur");
        strcpy(T, "Mirpur 10");
        break;
    case 6:
        amount = 70;
        strcpy(F, "Komlapur");
        strcpy(T, "Kazipara");
        break;
    case 7:
        amount = 60;
        strcpy(F, "Komlapur");
        strcpy(T, "Shewrapara");
        break;
    case 8:
        amount = 50;
        strcpy(F, "Komlapur");
        strcpy(T, "Agargaon");
        break;
    case 9:
        amount = 40;
        strcpy(F, "Komlapur");
        strcpy(T, "Farmgate");
        break;
    case 10:
        amount = 20;
        strcpy(F, "Komlapur");
        strcpy(T, "Dhaka_University");
        break;
    case 11:
        amount = 20;
        strcpy(F, "Komlapur");
        strcpy(T, "Motijheel");
        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void du_to()
{
    system("cls");
    int ch;
    printf("\n1.From Dhaka University To Uttara North\n");
    printf("\n2.From Dhaka University To Uttara South\n");
    printf("\n3.From Dhaka University To Pallabi\n");
    printf("\n4.From Dhaka University To Mirpur 11\n");
    printf("\n5.From Dhaka University To Mirpur 10\n");
    printf("\n6.From Dhaka University To Kazipara\n");
    printf("\n7.From Dhaka University To Shewrapara\n");
    printf("\n8.From Dhaka University To Agargaon\n");
    printf("\n9.From Dhaka University Farmgate\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 1:
        amount = 90;
        strcpy(F, "Dhaka University");
        strcpy(T, "Uttara North");
        break;
    case 2:
        amount = 80;
        strcpy(F, "Dhaka University");
        strcpy(T, "Uttara South ");
        break;
    case 3:
        amount = 70;
        strcpy(F, "Dhaka University");
        strcpy(T, "Pallabi");
        break;
    case 4:
        amount = 60;
        strcpy(F, "Dhaka University");
        strcpy(T, "Mirpur 11");
        break;
    case 5:
        amount = 50;
        strcpy(F, "Dhaka University");
        strcpy(T, "Mirpur 10");
        break;
    case 6:
        amount = 50;
        strcpy(F, "Dhaka University");
        strcpy(T, "Kazipara");
        break;
    case 7:
        amount = 40;
        strcpy(F, "Dhaka University");
        strcpy(T, "Shewrapara");
        break;
    case 8:
        amount = 30;
        strcpy(F, "Dhaka University");
        strcpy(T, "Agargaon");
        break;
    case 9:
        amount = 20;
        strcpy(F, "Dhaka University");
        strcpy(T, "Farmgate");
        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void farmgate_to()
{
    system("cls");
    int ch;
    printf("\n1.From Farmgate To Uttara North\n");
    printf("\n2.From Farmgate To Uttara South\n");
    printf("\n3.From Farmgate To Pallabi\n");
    printf("\n4.From Farmgate To Mirpur 11\n");
    printf("\n5.From Farmgate To Mirpur 10\n");
    printf("\n6.From Farmgate To Kazipara\n");
    printf("\n7.From Farmgate To Shewrapara\n");
    printf("\n8.From Farmgate To Agargaon\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 1:
        amount = 70;
        strcpy(F, "Farmgate");
        strcpy(T, "Uttara North");
        break;
    case 2:
        amount = 60;
        strcpy(F, "Farmgate");
        strcpy(T, "Uttara South ");
        break;
    case 3:
        amount = 60;
        strcpy(F, "Farmgate");
        strcpy(T, "Pallabi");
        break;
    case 4:
        amount = 50;
        strcpy(F, "Farmgate");
        strcpy(T, "Mirpur 11");
        break;
    case 5:
        amount = 30;
        strcpy(F, "Farmgate");
        strcpy(T, "Mirpur 10");
        break;
    case 6:
        amount = 30;
        strcpy(F, "Farmgate");
        strcpy(T, "Kazipara");
        break;
    case 7:
        amount = 20;
        strcpy(F, "Farmgate");
        strcpy(T, "Shewrapara");
        break;
    case 8:
        amount = 20;
        strcpy(F, "Farmgate");
        strcpy(T, "Agargaon");
        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void agargaon_to()
{
    system("cls");
    int ch;
    printf("\n1.From Agargaon To Uttara North\n");
    printf("\n2.From Agargaon To Uttara South\n");
    printf("\n3.From Agargaon To Pallabi\n");
    printf("\n4.From Agargaon To Mirpur 11\n");
    printf("\n5.From Agargaon To Mirpur 10\n");
    printf("\n6.From Agargaon To Kazipara\n");
    printf("\n7.From Agargaon To Shewrapara\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 1:
        amount = 60;
        strcpy(F, "Agargaon");
        strcpy(T, "Uttara North");
        break;
    case 2:
        amount = 50;
        strcpy(F, "Agargaon");
        strcpy(T, "Uttara South ");
        break;
    case 3:
        amount = 40;
        strcpy(F, "Agargaon");
        strcpy(T, "Pallabi");
        break;
    case 4:
        amount = 30;
        strcpy(F, "Agargaon");
        strcpy(T, "Mirpur 11");
        break;
    case 5:
        amount = 20;
        strcpy(F, "Agargaon");
        strcpy(T, "Mirpur 10");
        break;
    case 6:
        amount = 20;
        strcpy(F, "Agargaon");
        strcpy(T, "Kazipara");
        break;
    case 7:
        amount = 20;
        strcpy(F, "Agargaon");
        strcpy(T, "Shewrapara");
        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void shewrapara_to()
{
    system("cls");
    int ch;
    printf("\n1.From Shewrapara To Uttara North\n");
    printf("\n2.From Shewrapara To Uttara South\n");
    printf("\n3.From Shewrapara To Pallabi\n");
    printf("\n4.From Shewrapara To Mirpur 11\n");
    printf("\n5.From Shewrapara To Mirpur 10\n");
    printf("\n6.From Shewrapara To Kazipara\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 1:
        amount = 50;
        strcpy(F, "Shewrapara");
        strcpy(T, "Uttara North");
        break;
    case 2:
        amount = 40;
        strcpy(F, "Shewrapara");
        strcpy(T, "Uttara South ");
        break;
    case 3:
        amount = 40;
        strcpy(F, "Shewrapara");
        strcpy(T, "Pallabi");
        break;
    case 4:
        amount = 30;
        strcpy(F, "Shewrapara");
        strcpy(T, "Mirpur 11");
        break;
    case 5:
        amount = 20;
        strcpy(F, "Shewrapara");
        strcpy(T, "Mirpur 10");
        break;
    case 6:
        amount = 20;
        strcpy(F, "Shewrapara");
        strcpy(T, "Kazipara");
        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void kazipara_to()
{
    system("cls");
    int ch;
    printf("\n1.From Kazipara To Uttara North\n");
    printf("\n2.From Kazipara To Uttara South\n");
    printf("\n3.From Kazipara To Pallabi\n");
    printf("\n4.From Kazipara To Mirpur 11\n");
    printf("\n5.From Kazipara To Mirpur 10\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 1:
        amount = 40;
        strcpy(F, "Kazipara");
        strcpy(T, "Uttara North");
        break;
    case 2:
        amount = 40;
        strcpy(F, "Kazipara");
        strcpy(T, "Uttara South ");
        break;
    case 3:
        amount = 30;
        strcpy(F, "Kazipara");
        strcpy(T, "Pallabi");
        break;
    case 4:
        amount = 20;
        strcpy(F, "Kazipara");
        strcpy(T, "Mirpur 11");
        break;
    case 5:
        amount = 20;
        strcpy(F, "Kazipara");
        strcpy(T, "Mirpur 10");
        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void Mirpur10_to()
{
    system("cls");
    int ch;
    printf("\n1.From Mirpur 10 To Uttara North\n");
    printf("\n2.From Mirpur 10 To Uttara South\n");
    printf("\n3.From Mirpur 10 To Pallabi\n");
    printf("\n4.From Mirpur 10 To Mirpur 11\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 1:
        amount = 40;
        strcpy(F, "Mirpur 10");
        strcpy(T, "Uttara North");
        break;
    case 2:
        amount = 30;
        strcpy(F, "Mirpur 10");
        strcpy(T, "Uttara South ");
        break;
    case 3:
        amount = 20;
        strcpy(F, "Mirpur 10");
        strcpy(T, "Pallabi");
        break;
    case 4:
        amount = 20;
        strcpy(F, "Mirpur 10");
        strcpy(T, "Mirpur 11");
        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void Mirpur11_to()
{
    system("cls");
    int ch;
    printf("\n1.From Mirpur 11 To Uttara North\n");
    printf("\n2.From Mirpur 11 To Uttara South\n");
    printf("\n3.From Mirpur 11 To Pallabi\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 1:
        amount = 30;
        strcpy(F, "Mirpur 11");
        strcpy(T, "Uttara North");
        break;
    case 2:
        amount = 30;
        strcpy(F, "Mirpur 11");
        strcpy(T, "Uttara South ");
        break;
    case 3:
        amount = 20;
        strcpy(F, "Mirpur 11");
        strcpy(T, "Pallabi");
        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void pallabi_to()
{
    system("cls");
    int ch;
    printf("\n1.From Pallabi To Uttara North\n");
    printf("\n2.From Pallabi To Uttara South\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 1:
        amount = 30;
        strcpy(F, "Pallabi");
        strcpy(T, "Uttara North");
        break;
    case 2:
        amount = 20;
        strcpy(F, "Pallabi");
        strcpy(T, "Uttara South ");
        break;

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void uttara_centre_to()
{
    system("cls");
    int ch;
    printf("\n1.From Uttara centre To Uttara North\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 1:
        amount = 20;
        strcpy(F, "Uttara centre");
        strcpy(T, "Uttara North");

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void uttara_south_to()
{
    system("cls");
    int ch;
    printf("\n1.From Uttara South To Uttara North\n");

    scanf("%d", &ch);
    switch (ch)
    {

    case 1:
        amount = 20;
        strcpy(F, "Uttara South");
        strcpy(T, "Uttara North");

    default:
        printf("\nWrong Input !\n");
        break;
    }
}

void traininformation()
{
    system("cls");
    printf("\nDhaka Metro Bijoy - Start From Komlapur At 8:00 AM\n\n");
    printf("\nDhaka Metro Mohanagor - Start From Uttara North At 8:00 AM\n\n");
    getchar();
    getchar();
}