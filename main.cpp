#include "link.h"                                                                        
#include "audio.h"
#include <cstring>
#include <iostream>
 
using namespace std;

string dtab = "\t\t";

bool leave = false;
bool reserved[3];

LinkedList list1, list2, list3;

void input(char x[]);
void input(int &x);

void header(string option);

void update();
bool menu();
void createMenu();
void manageMenu();
void playMenu();

void createList(LinkedList& li);
void manageList(LinkedList& li);
void playerList(LinkedList& li);

int main() {

    while(leave == false)
    {
        update(); 
        leave = menu();

    }
}

void update()
{
    reserved[0] = list1.taken;
    reserved[1] = list2.taken;
    reserved[2] = list3.taken;
}

void input(char x[])
{                                                                                        
   cout<<dtab<<"ENTER VALUE: ";                                                                    
   cin.ignore();                                                                          
   cin.getline(x, 30);                                                                    
}

void Input(char x[])
{
    strcpy(x, "");
    cin.ignore();
    cin.getline(x, 30);
}

void input(int &x)
{                                                                                        
   cout<<dtab<<"ENTER VALUE/CHOICE: ";                                                                       
   cin>>x;                                                                                
}    

void header(string option)
{
    system("clear");
    cout << dtab;
    for (int i = 0; i < 40; ++i)
        cout << '*';
    cout << endl;
    cout << "\t\t\t" << option << endl << dtab;
    for (int i = 0; i < 40; ++i)
        cout << '*';
    cout << endl;
}

bool menu()
{
    bool exit = true;
    int choice;
    char escape;

    header("MAIN MENU");

    cout << dtab << "1. CREATE NEW LIST" << endl;
    cout << dtab << "2. MANAGE LISTS" << endl;
    cout << dtab << "3. EXIT" << endl;
    input(choice);

    switch(choice) {

    case 1:
        createMenu();
        break;

    case 2:
        manageMenu();
        break;

    case 3:
        exit = true;
        break;
    }
   
    if (choice != 3)
    {
        cout << "\t\tGO BACK TO MAIN MENU? Y or N: "; 
        cin >> escape;
      
     if (escape == 'Y' || escape == 'y')
        exit = false;
    }


    return exit;
}

void createMenu()
{
    header("NEW LIST");

    int current = -1;
    
    for (int i = 0; i < 3; ++i)
    {
        if (reserved[i] == false)
        {
            current = i;
            break;
        }
    }

    if (current == -1)
    {
        cout << dtab << "YOU HAVE USED UP ALL THE AVAILABLE LISTS." << endl;

    }

    else
    {
        if (current == 0)
        {
            createList(list1);
        }
        else if (current == 1)
            createList(list2);
        else if (current == 2)
            createList(list3);
    }   

}

void createList(LinkedList& li)
{
    cout << dtab << "ENTER NAME OF LIST: "; 
    
    char song_name[30];
    char artist_name[30];

    cin.ignore();
    cin.getline(li.listName, 30);
    

    cout << dtab << "ENTER THREE SONGS TO LIST." << endl;

    for (int i = 0; i < 3; ++i)
    {
        cout << dtab << "ENTER SONG NAME: ";
        cin.getline(song_name, 30);

        cout << dtab << "ENTER ARTIST NAME: ";
        cin.getline(artist_name, 30);

        li.add_end(song_name, artist_name);
    }

    li.taken = true;

    header("NEW LIST");
    cout << dtab << "LIST CREATED SUCCESSFULLY." << endl;
    cout << dtab << "LIST NAME: ";
    li.display();
}

void manageMenu()
{
    int choice;
    int count = 0;
    char next;

    header("MANAGE LISTS");

    
    
    for (int i = 0; i < 3; ++i)
    {
        if (reserved[i] == true)
        {
            count++;
        }
    }

    if (count == 0)
    {
        cout << dtab << "THERE ARE NO LISTS CURRENTLY." << endl;
        cout << "\n\t\tENTER A KEY TO MOVE TO NEXT MENU: ";
        cin.ignore();
        cin >> next;
    }

    else 
    {
        cout << dtab << "AVAILABLE LISTS:" << endl;
        cout << dtab << "====================================" << endl;
        
        switch (count)
        {
        case 1:
            cout << "\t\t1. " << list1.listName << endl;
            break;

        case 2:
            cout << "\t\t1. " << list1.listName << endl;
            cout << "\t\t2. " << list2.listName << endl;
            break;

        case 3:
            cout << "\t\t1. " << list1.listName << endl;
            cout << "\t\t2. " << list2.listName << endl;
            cout << "\t\t3. " << list3.listName << endl;
            break;

        }

        cout << endl << dtab << "ENTER YOUR CHOICE: "; 
        cin >> choice;

        if (choice == 1)
            manageList(list1);
        else if (choice == 2)
            manageList(list2);
        else if (choice == 3)
            manageList(list3);
    }
}

void manageList(LinkedList& li)
{
    int choice, pos;
    char data1[30], data2[30];
    
    header("MANAGE LIST");
    
    cout << dtab << "LIST NAME: " << li.listName << endl;
    cout << dtab << "========================================" << endl;
    
    cout << dtab << "1. ADD VALUE TO BEGINNING OF LIST" << endl; 
    cout << dtab << "2. ADD VALUE OF THE END OF LIST" << endl;
    cout << dtab << "3. ADD VALUE TO THE MIDDLE OF LIST" << endl;
    cout << dtab << "4. DELETE A SONG AT THE BEGINING" << endl;
    cout << dtab << "5. DELETE A SONG AT THE END OF LIST" << endl;
    cout << dtab << "6. DELETE A SONG AT THE MIDDLE OF LIST" << endl;
    cout << dtab << "7. DISPLAY THE LIST" << endl;
    cout << dtab << "8. PLAY THE LIST (REPEAT LIST)" << endl;
    cout << dtab << "9. PLAY THE LIST (REVERSE)" << endl;
    cout << dtab << "10. MAIN MENU" << endl;

    input(choice);

    switch (choice)
    {
    case 1:
        cout << dtab << "ENTER SONG: ";
        input(data1);
        cout << dtab << "ENTER ARTIST: ";
        input(data2);
        li.add_beg(data1, data2);
        break;

    case 2:
        cout << dtab << "ENTER SONG: ";
        cin.ignore();
        cin.getline(data1, 30); 
        cout << dtab << "ENTER ARTIST: ";
        
        cin.getline(data2, 30);

        li.add_end(data1, data2);
        break;

    case 3:
        cout << dtab << "ENTER SONG: ";
        input(data1);
        cout << dtab << "ENTER ARTIST: ";
        input(data2);
        cout << dtab << "ENTER POSITION: ";
        cin >> pos;
        li.add_at(data1, data2, pos);
        break;

    case 4:
        li.del_beg();
        break;

    case 5:
        li.del_end();
        break;

    case 6:
        cout << dtab << "ENTER POSITION: ";
        cin >> pos;
        li.del_at(pos);

    case 7:
        header("DISPLAY");
        li.display();
        break;
    case 8:
        header("PLAY LIST");
        repeat(li);
        break;

    case 9:
        reverse(li);
        break;
    case 10:
        break;
   
   }

}
