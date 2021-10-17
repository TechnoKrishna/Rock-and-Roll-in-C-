// ROCK AND ROLL MANAGEMENT SYSTEM

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

// CLASS

class Rock_Roll
{
public:
};

class Cart : public Rock_Roll
{
public:
    string Item_Name[10] = {"NONE", "PANNEER TIKKA", "ALOO TIKKI", "SEEKH KEBAB", "CHICKEN TIKKA", "HARA KEBAB"};
    int Item_Price[10] = {0, 189, 99, 149, 199, 149};
    int Select_Item[10];
    int qxt[10];
    int Total[10];

    int t_Select_Item[10];
    int t_qxt[10];
    int t_Total[10];

    int Final[10] = {0, 0};

    int j = 1;
    int i = 1;
    int k;
    char yn;

    // ADMIN SECTION

    void Admin()
    {

        int ch;

        do
        {
            system("cls");

            cout << "\n\n\t1 > ADD ITEM";
            cout << "\n\n\t2 > SHOW ITEM";
            cout << "\n\n\t3 > SEARCH ITEM";
            cout << "\n\n\t4 > UPDATE ITEM";
            cout << "\n\n\t5 > DELETE ITEM";
            cout << "\n\n\t6 > BACK";
            cout << "\n\n\tENTER YOUR CHOICE : ";
            cin >> ch;

            switch (ch)
            {
            case 1:
                Add_Item();
                break;
            case 2:
                Show_Item();
                break;
            case 3:
                Search_Item();
                break;
            case 4:
                Update_Item();
                break;
            case 5:
                Delete_Item();
                break;
            case 6:
                cout << "\n\n\tBACKING.....";
                getch();
                break;
            default:
                cout << "\n\n\tINVALID CHOICE";
                getch();
                break;
            }

        } while (ch < 6 || ch > 6);
    }

    void Add_Item()
    {
        system("cls");
    }

    void Show_Item()
    {
        system("cls");

        for (int i = 1; i <= 5; i++)
        {
            cout << "\n\t"
                 << "<" << i << ">"
                 << "\t\t\t" << Item_Name[i] << "\t\t\t" << Item_Price[i];
        }


    }

    void Search_Item()
    {
        system("cls");
    }

    void Update_Item()
    {
        system("cls");
    }

    void Delete_Item()
    {
        system("cls");
    }

    // USER SECTION

    void Menu()
    {
    more:

        system("cls");

        cout << "\n\t\t\t\t// MENU //\n\n";

        cout << "\tNO :\t\t\tITEM NAME : \t\t\tITEM PRICE\n";

        for (int i = 1; i <= 5; i++)
        {
            cout << "\n\t"
                 << "<" << i << ">"
                 << "\t\t\t" << Item_Name[i] << "\t\t\t" << Item_Price[i];
        }

        cout << "\n\n\tENTER WHICH ITEM YOU WANT : ";
        cin >> t_Select_Item[j];

        cout << "\n\t" << Item_Name[t_Select_Item[j]] << " "
             << " ENTER QUANTITY : ";
        cin >> t_qxt[j];

        t_Total[j] = (Item_Price[t_Select_Item[j]] * t_qxt[j]);

        cout << "\n\tITEM : " << Item_Name[t_Select_Item[j]] << "\tPRICE : " << Item_Price[t_Select_Item[j]] << "\tQUANTITY : " << t_qxt[j] << "\tTOTAL : " << t_Total[j];

        cout << "\n\n\tDO YOU WANT TO ADD ITEM TO CART(Y/N) : ";
        cin >> yn;

        if (yn == 'y' || yn == 'Y')
        {

            Select_Item[j] = t_Select_Item[j];
            qxt[j] = t_qxt[j];
            Total[j] = t_Total[j];

            cout << "\n\tADDED TO CART";

            j++;

            cout << "\n\n\tDO YOU WANT TO ADD MORE ITEM (Y/N): ";
            cin >> yn;
            if (yn == 'y' || yn == 'Y')
            {
                goto more;
            }
            else
            {
                cout << "\n\n\tOk, Sure";
            }
        }
        else if (yn == 'n' || yn == 'N')
        {
            cout << "\n\t OK, SURE";
        }
        else
        {
            cout << "\n\tINVALID CHOICE";
        }

        cout << "\n\n\tPRESS ENTER TO EXIT :";

        getch();
    }

    void cart()
    {
        system("cls");

        if (j <= 1)
        {
            cout << "\n\n\t\t!! NO ITEM !!";
        }
        else
        {

            cout << "\n\n\t\t\t\tCART\n\n";

            for (int i = 1; i < j; i++)
            {
                cout << "\n\n\tITEM : " << Item_Name[Select_Item[i]] << "\tPRICE : " << Item_Price[Select_Item[i]] << "\tQUANTITY : " << qxt[i] << "\tTOTAL : " << Total[i];
            }

            for (int i = 1; i < j; i++)
            {
                Final[i] = Final[i - 1] + Total[i];
                k = i;
            }

            cout << "\n\n\tTOTAL : " << Final[k];

            cout << "\n\n\tARE YOU SURE TO ORDER(Y/N) : ";
            cin >> yn;

            if (yn == 'y' || yn == 'Y')
            {
                purchase();
            }
            else if (yn == 'n' || yn == 'N')
            {
                cout << "\n\tOK, SURE";
            }
            else
            {
                cout << "\n\n\tINVALID CHOICE";
            }
        }
        cout << "\n\n\tPRESS ENTER TO BACK : ";
        getch();
    }

    void purchase()
    {

        system("cls");

        char temp[50], name[50], ph[50], address[50];

        cout << "\n\n\t\t\t\\ PURCHASE \\";

        cin.getline(temp, 50);

        cout << "\n\n\t\tNAME : ";
        cin.getline(name, 50);

        cout << "\n\n\t\tPHONE NO : ";
        cin.getline(ph, 50);

        cout << "\n\n\t\tADDRESS : ";
        cin.getline(address, 50);

        system("cls");

        cout << "\n\n\t\t/////////////////////////////////////////////";

        cout << "\n\n\t\tNAME : " << name;
        cout << "\n\t\tPHONE NO : " << ph;
        cout << "\n\t\tADDRESS : " << address;
        cout << "\n\t\tPRICE : " << Final[k];

        cout << "\n\n\t\t/////////////////////////////////////////////";

        cout << "\n\n\t\tORDER IS COMPLETED";

        cout << "\n\n\t\tYOUR ORDER WILL SOON AT YOUR DOOR";

        cout << "\n\n\t\tPRESS ENTER TO BACK : ";

        getch();
    }
};

int main()
{
    Rock_Roll rr;
    Cart c;

    int ch;

    do
    {

        system("cls");

        cout << "\t\t\t// WELCOME TO ROCK AND ROLL //";

        cout << "\n\n\t\t\t\t// OPTION //\n";

        cout << "\n\t<1> BUY : ";

        cout << "\n\t<2> CART : ";

        cout << "\n\t<3> EXIT : ";

        cout << "\n\n\tENTER YOUR CHOICE : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            c.Menu();
            break;
        case 2:
            c.cart();
            break;
        case 3:
            cout << "\n\n\t....EXITED....";
            exit(0);
            break;
        case 911:
            cout << "\n\n\tADMIN IS LOADING";
            getch();
            c.Admin();
            break;
        default:
            cout << "\n\n\tINVALID CHOICE";
            getch();
            break;
        }

    } while (ch < 3 || ch > 3);

    return 0;
}