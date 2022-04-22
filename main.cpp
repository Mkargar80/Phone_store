#include <iostream>
#include <string>

using namespace std;

enum OS {IOS,android,WindowsPhone};
const char* _os[] = {"IOS","android","WindowsPhone"};
enum RAM {two,four,six,eight,twelve,sixteen,thirty_two,sixty_four};
const char* _ram[] = {"2 GB","4 GB","6 GB","8 GB","12 GB","16 GB","32 GB","64 GB"};
enum storage {_sixteen,_thirty_two,_sixty_four,OTE,TFS,FOT,oneTB,twoTB};//OTE=128,TFS=256,FOT=512
const char* _storage[]={"16 GB","32 GB","64 GB","128 GB","256 GB","512 GB","1 TB","2 TB"};
enum color {black,white,gold,gray,blue,green};
const char* _color[]={"black","white","gold","gray","blue","green"};
struct phones
{
    string name;
    string company;
    OS os;
    RAM ram;
    storage storage;
    unsigned long int price;
    color color;
    int number;
    int sold_number=0;
};

void extend_array(phones **ptr_Phone,int &number);
void add_phone(string name,string company,phones **ptr_phone,int &number);
int search_phone(phones *phone,int number,string name,string company);
void swap(phones &a,phones &b);
void add_phone(phones **ptr_phone,int index,int new_inventory);
void remove_phone(phones **ptr_phone,int &number,int removed_index);
void sort_by_price(phones **ptr_phone,int number);
void print_index(phones *p,int index);
void change_mobile_info(phones **ptr_phone,int number);
void sell_a_phone(phones **ptr_phone,int number);
void print_phone(phones *phone,int number);
void most_sold_item(phones **ptr_phone,int number);
int main()
{
    phones *phone=0;
    int number=0;
    int inventory;

bool flag=true;

int menu_entery;
string name;
string company;
int search_index;


while (flag)
{
    system("cls");
    cout<<"1- Add a phone\n"
        <<"2- Remove a phone\n"
        <<"3- Sort phone by price\n"
        <<"4- Search a phone\n"
        <<"5- Change mobile info\n"
        <<"6- Sell a phone\n"
        <<"7- Print phones\n"
        <<"8- Print phones sorted by the most sold to the least\n"
        <<"9- Quit\n";

    cin>>menu_entery;
//if (menu_entery)
    switch (menu_entery)
    {
    case 1:
        getchar();
        cout<<"Enter name:\n";
        getline(cin,name);
        cout<<"Enter company:\n";
        getline(cin,company);
        search_index=search_phone(phone,number,name,company);
       if  (search_index==-1)
           add_phone(name,company,&phone,number);
       else
       {
           cout<<"Enter new inventory:\n";
           cin>>inventory;
           add_phone(&phone,search_index,inventory);
       }
        break;
    case 2:
        cin.sync();
        cout<<"Enter name:\n";
        getline(cin,name);
        cout<<"Enter company:\n";
        getline(cin,company);
        search_index=search_phone(phone,number,name,company);
       if  (search_index!=-1)
       {
           remove_phone(&phone,number,search_index);
           cout<<"Phone removed.\n";
       }
       else
       {
           cout<<"Invalid entery.\n";

       }
     cout<< "Press any key to continue...\n";
     getchar();
        break;
    case 3:
        sort_by_price(&phone,number);
        cout<<"Sorting successful.\nPress any key to continue...\n";
        getchar();
        getchar();
        break;
    case 4:
        getchar();
        cout<<"Enter name:\n";
        getline(cin,name);
        cout<<"Enter company:\n";
        getline(cin,company);
        search_index=search_phone(phone,number,name,company);
       if  (search_index!=-1)
       {
           print_index(phone,search_index);
       }
       else {
           cout<<"Information not found.\n";
       }
       cout<<"Press any key to continue...\n";
       getchar();
        break;
    case 5:
          change_mobile_info(&phone,number);
        break;
    case 6:        
        sell_a_phone(&phone,number);
        break;
    case 7:
        print_phone(phone,number);
        cout<<endl<<"Press any key to continue...\n";
        getchar();
        getchar();
        break;
    case 8:
        most_sold_item(&phone,number);
        break;
    case 9:
        flag=false;
        break;
    default:
        cout<<"Invalid number\n"<<"Press any key to continue...\n";
        getchar();
        getchar();
        break;
    }
}


    return 0;
}

void extend_array(phones **ptr_Phone,int &number)
{
    phones *phone=*ptr_Phone;
    phones *temp=new phones[number+1];

    for (int i=0;i<number;i++)
    {
        temp[i]=phone[i];
    }

    *ptr_Phone=temp;
    delete [] phone;
    number=number+1;
}

void add_phone(string name,string company,phones **ptr_phone,int &number)
{
phones *phones=*ptr_phone;

//int return_index=-1;

//for (int i=0;i<number;i++)
//{
// if (name.compare(phones[i].name)==0 && company.compare(phones[i].company)==0)
// {
//     return_index=i;
// }
//}
//if (return_index>-1)
//{
//    cout<<"This phone has been already added.\n"
//       <<"Enter new added inventory number:\n";
//    int new_inventory;
//    cin>>new_inventory;
//    cout<<"new inventory added.press any key to return to menu...\n";
//    getchar();
//    return;
//}
extend_array(&phones,number);
phones[number-1].name=name;
phones[number-1].company=company;

bool flag=true;
while(flag)
{
    system("cls");
    cout<<"Choose OS:\n"
       <<"1- IOS\n"
      <<"2- Adnroid\n"
     <<"3- Windowsphone\n";
    unsigned  int os;
    cin>>os;
    if (os<4 && os>0 )
    {
        if (os==1)
          phones[number-1].os=IOS;
       else if (os==2)
           phones[number-1].os=android;
        else if (os==3)
            phones[number-1].os=WindowsPhone;
        flag=false;
    }
    else
    {
        cout<<"Invalid number\n"<<"Press any key to continue...\n";
        getchar();
        getchar();
    }
    }
flag=true;
int RAM_capacity;
while(flag)
{
    system("cls");
    cout
            <<"1- 2GB\n"
           <<"2- 4GB\n"
          <<"3- 6GB\n"
         <<"4- 8GB\n"
        <<"5- 12GB\n"
       <<"6- 16GB\n"
      <<"7- 32GB\n"
     <<"8- 64GB\n"
    <<"Choose RAM capacity:\n";
    cin>>RAM_capacity;
    if (RAM_capacity>0 && RAM_capacity<9)
    {  flag=false;

        if (RAM_capacity==1)
            phones[number-1].ram=two;
        else if (RAM_capacity==2)
            phones[number-1].ram=four;
        else if (RAM_capacity==3)
            phones[number-1].ram=six;
        else if (RAM_capacity==4)
            phones[number-1].ram=eight;
        else if (RAM_capacity==5)
            phones[number-1].ram=twelve;
        else if (RAM_capacity==6)
            phones[number-1].ram=sixteen;
        else if (RAM_capacity==7)
            phones[number-1].ram=thirty_two;
        else if (RAM_capacity==8)
            phones[number-1].ram=sixty_four;
    }
    else
    {
        cout<<"Invalid number\n"<<"Press any key to continue...\n";
        getchar();
        getchar();
    }
}



flag=true;

int storag_capacity;

while(flag)
{
        system("cls");
    cout
            <<"1- 16GB\n"
           <<"2- 32GB\n"
          <<"3- 64GB\n"
         <<"4- 128GB\n"
        <<"5- 256GB\n"
       <<"6- 512GB\n"
      <<"7- 1TB\n"
     <<"8- 2TB\n"
    <<"Choose storage capacity:\n";
    cin>>storag_capacity;

    if (storag_capacity>0 && storag_capacity<9)
    {
        if (storag_capacity==1)
            phones[number-1].storage=_sixteen;
       else if (storag_capacity==2)
            phones[number-1].storage=_thirty_two;
       else if (storag_capacity==3)
            phones[number-1].storage=_sixty_four;
       else if (storag_capacity==4)
            phones[number-1].storage=OTE;//128GB
       else if (storag_capacity==5)
            phones[number-1].storage=TFS;//256GB
       else if (storag_capacity==6)
            phones[number-1].storage=FOT;//512GB
       else if (storag_capacity==7)
            phones[number-1].storage=oneTB;
       else if (storag_capacity==8)
            phones[number-1].storage=twoTB;
        flag=false;
    }
    else
    {
        cout<<"Invalid number\n"<<"Press any key to continue...\n";
        getchar();
        getchar();
    }

}

flag=true;
unsigned long int price_value;
while (flag)
{
    system("cls");
 cout<<"Enter price value:\n";
 cin>>price_value;

 if (price_value>0)
 {
     flag=false;
     phones[number-1].price=price_value;
 }
 else
 {
     cout<<"Invalid value.\n"<<"Press any key to continue...\n";
     getchar();
     getchar();
 }
}

flag=true;
int phone_color;
while (flag)
{
 system("cls");

cout
       << "1- black\n"
     <<"2- white\n"
    <<"3- gold\n"
   <<"4- gray\n"
  <<"5- blue\n"
 <<"6- green\n"
<<"Choose color:\n";

cin>>phone_color;
if (phone_color>0 && phone_color<7)
{
    if (phone_color==1)
        phones[number-1].color=black;
    else if (phone_color==2)
        phones[number-1].color=white;
    else if (phone_color==3)
        phones[number-1].color=gold;
    else if (phone_color==4)
        phones[number-1].color=gray;
    else if (phone_color==5)
        phones[number-1].color=blue;
    else if (phone_color==6)
        phones[number-1].color=green;
    flag=false;
}
else
{
    cout<<"Invalid number.\n"<<"Press any key to continue...\n";
    getchar();
    getchar();
}
}
flag=true;
int inventory;
while (flag)
{
    system("cls");
 cout<<"Enter inventory:\n";
 cin>>inventory;

 if (inventory>0)
 {
     phones[number-1].number=inventory;
     flag=false;
 }
 else
 {
     cout<<"Invalid number.\n"<<"Press any key to continue...\n";
     getchar();
     getchar();
 }
}

*ptr_phone=phones;
cout<<"new phone adding succesfully!\n"
   <<"press any key to return to menu...\n";
getchar();
getchar();


}

int search_phone(phones *phone,int number,string name,string company)
{
    int return_index=-1;
    for (int i=0;i<number;i++)
    {
        if (name.compare(phone[i].name)==0 && company.compare(phone[i].company)==0)
            return_index=i;
    }
    return return_index;
}

void add_phone(phones **ptr_phone,int index,int new_inventory)
{
    phones *phone=*ptr_phone;
  phone[index].number=(phone[index].number)+new_inventory;
         cout<<"Information added.\nPress any key to continue...\n";
         getchar();
         getchar();
         *ptr_phone=phone;
}

void remove_phone(phones **ptr_phone,int &number,int removed_index)
{
    phones *phone=*ptr_phone;
    phones *temp=new phones[number-1];

    for (int i=0;i<number-1;i++)
    {
        if (i<removed_index)
          temp[i]=phone[i];
        else if (i==removed_index)
        {
            temp[i]=phone[removed_index+1];
        }
        else
        {
            temp[i]=phone[i+1];
        }
    }

    *ptr_phone=temp;
    delete [] phone;
    number=number-1;
}

void sort_by_price(phones **ptr_phone,int number)
{
    phones *phone=*ptr_phone;

    for (int i=0;i<number;i++)
    {
        for (int j=0;j<number-i;j++)
        {
            if(phone[j].price>phone[j+1].price)
                swap(phone[j],phone[j+1]);
        }
    }
   *ptr_phone=phone;
}
void swap(phones &a,phones &b)
{
    phones temp=a;
    a=b;
    b=temp;
}


void change_mobile_info(phones **ptr_phone,int number)
{
    cin.sync();
    cout<<"Enter name:\n";
    string name;
    getline(cin,name);
    cout<<"Enter company:\n";
    string company;
    getline(cin,company);
    phones *phone=*ptr_phone;
    int index=search_phone(phone,number,name,company);
    int temp;
    bool flag,while_check=true;
        if (index!=-1)
            while(while_check)
    {  
        system("cls");

        cout <<"1- name\n"
             <<"2- company\n"
             <<"3- RAM\n"
             <<"4- storage\n"
             <<"5- OS\n"
             <<"6- price\n"
             <<"7- color\n"
             <<"8- number\n"
             <<"Which information change:\n";
        int entery_change;
        cin>>entery_change;

        switch (entery_change)
        {
        case 1:
            cin.sync();
            cout<<"Enter name:\n";
            getline(cin,name);
            phone[index].name=name;
            while_check=false;
            break;
        case 2:
            cin.sync();
            cout<<"Enter company name:\n";
            getline(cin,company);
            phone[index].company=company;
            while_check=false;
            break;
        case 3:
            while_check=false;
            flag=true;
            while(flag)
            {
                system("cls");
                cout
                        <<"1- 2GB\n"
                       <<"2- 4GB\n"
                      <<"3- 6GB\n"
                     <<"4- 8GB\n"
                    <<"5- 12GB\n"
                   <<"6- 16GB\n"
                  <<"7- 32GB\n"
                 <<"8- 64GB\n"
                <<"Choose RAM capacity:\n";
                cin>>temp;
                if (temp>0 && temp<9)
                {  flag=false;

                    if (temp==1)
                        phone[index].ram=two;
                    else if (temp==2)
                        phone[index].ram=four;
                    else if (temp==3)
                        phone[index].ram=six;
                    else if (temp==4)
                        phone[index].ram=eight;
                    else if (temp==5)
                        phone[index].ram=twelve;
                    else if (temp==6)
                        phone[index].ram=sixteen;
                    else if (temp==7)
                        phone[index].ram=thirty_two;
                    else if (temp==8)
                        phone[index].ram=sixty_four;
                }
                else
                {
                    cout<<"Invalid number\n"<<"Press any key to continue...\n";
                    getchar();
                    getchar();
                }
            }

            break;
        case 4:
            while_check=false;
            flag=true;
            while(flag)
            {
                    system("cls");
                cout
                        <<"1- 16GB\n"
                       <<"2- 32GB\n"
                      <<"3- 64GB\n"
                     <<"4- 128GB\n"
                    <<"5- 256GB\n"
                   <<"6- 512GB\n"
                  <<"7- 1TB\n"
                 <<"8- 2TB\n"
                <<"Choose storage capacity:\n";
                cin>>temp;

                if (temp>0 && temp<9)
                {
                    if (temp==1)
                        phone[index].storage=_sixteen;
                   else if (temp==2)
                        phone[index].storage=_thirty_two;
                   else if (temp==3)
                        phone[index].storage=_sixty_four;
                   else if (temp==4)
                        phone[index].storage=OTE;//128GB
                   else if (temp==5)
                        phone[index].storage=TFS;//256GB
                   else if (temp==6)
                        phone[index].storage=FOT;//512GB
                   else if (temp==7)
                        phone[index].storage=oneTB;
                   else if (temp==8)
                        phone[index].storage=twoTB;
                    flag=false;
                }
                else
                {
                    cout<<"Invalid number\n"<<"Press any key to continue...\n";
                    getchar();
                    getchar();
                }

            }

            break;
        case 5:
            while_check=false;
            flag=true;
            while(flag)
            {
                system("cls");
                cout<<"Choose OS:\n"
                   <<"1- IOS\n"
                  <<"2- Adnroid\n"
                 <<"3- Windowsphone\n";
                cin>>temp;
                if (temp<4 && temp>0 )
                {
                    if (temp==1)
                      phone[index].os=IOS;
                   else if (temp==2)
                       phone[index].os=android;
                    else if (temp==3)
                        phone[index].os=WindowsPhone;
                    flag=false;
                }
                else
                {
                    cout<<"Invalid number\n"<<"Press any key to continue...\n";
                    getchar();
                    getchar();
                }
                }
            break;
        case 6:
            while_check=false;
            cout<<"Enter price:\n";
            unsigned long int _temp;
            cin>>_temp;
            phone[index].price=_temp;
            break;
        case 7:
            while_check=false;
            flag=true;
            while (flag)
            {
             system("cls");

            cout
                   << "1- black\n"
                 <<"2- white\n"
                <<"3- gold\n"
               <<"4- gray\n"
              <<"5- blue\n"
             <<"6- green\n"
            <<"Choose color:\n";

            cin>>temp;
            if (temp>0 && temp<7)
            {
                if (temp==1)
                    phone[index].color=black;
                else if (temp==2)
                    phone[index].color=white;
                else if (temp==3)
                    phone[index].color=gold;
                else if (temp==4)
                    phone[index].color=gray;
                else if (temp==5)
                    phone[index].color=blue;
                else if (temp==6)
                    phone[index].color=green;
                flag=false;
            }
            else
            {
                cout<<"Invalid number.\n"<<"Press any key to continue...\n";
                getchar();
                getchar();
            }
            }
            break;
        case 8:
            while_check=false;
            cout<<"Enter inventory:\n";
            cin>>temp;
            if (temp<0)
                temp=temp*-1;
            phone[index].number=temp;
            break;
        default:
            cout<<"Invalid entery.\n";
            cin.sync();
            getchar();
        }


}
        else
        {
            cin.sync();
           cout<<"Invalid entery.\nPress any key to continue...\n";
           getchar();
           return;
        }
*ptr_phone=phone;
        cin.sync();
cout<<"Edditing successful!\n"
   <<"press any key to continue...\n";
getchar();
}

void sell_a_phone(phones **ptr_phone,int number)
{
    phones *phone=*ptr_phone;
    string name,company;
    bool flag=true;
    while(flag)
    {
        cout<<"Enter name:\n";
        cin.sync();
        getline(cin,name);
        cout<<"Enter company name:\n";
        getline(cin,company);
        int index=search_phone(phone,number,name,company);
        if (index!=-1)
        {
            flag=false;
            if (phone[index].number!=0)
            {

                phone[index].number=phone[index].number-1;
                phone[index].sold_number=(phone[index].sold_number)+1;
            }
            else {
                cout<<"Empty invertory.\nPress any key to continue...\n";
                cin.sync();
                getchar();
                return;
            }
        }
        else
        {
            cout<<"Invalid entery.\nPress any key to continue...\n";
            cin.sync();
            getchar();
            return;
        }


    }
    cout<<"Selling successfuly.\nPress any key to continue...\n";
    getchar();

}

void print_phone(phones *phone,int number)
{
    int i;
    for ( i=number-1;i>=0;i--)
    {
      if (i==number-1)
      {
          cout<<"name: "<<phone[i].name<<"***";

      }
      else
      {
          cout<<" "<<phone[i].name<<"***";
      }
    }
    cout<<endl;
    for ( i=number-1;i>=0;i--)
    {
      if (i==number-1)
      {
          cout<<"company: "<<phone[i].company<<"***";

      }
      else
      {
          cout<<" "<<phone[i].company<<"***";
      }
    }
    cout<<endl;
    for ( i=number-1;i>=0;i--)
    {
      if (i==number-1)
      {
          cout<<"os: "<<_os[phone[i].os]<<"***";

      }
      else
      {
          cout<<" "<<_os[phone[i].os]<<"***";
      }
    }
    cout<<endl;
    for ( i=number-1;i>=0;i--)
    {
      if (i==number-1)
      {
          cout<<"RAM: "<<_ram[phone[i].ram]<<"***";

      }
      else
      {
          cout<<" "<<_ram[phone[i].ram]<<"***";
      }
    }
    cout<<endl;
    for ( i=number-1;i>=0;i--)
    {
      if (i==number-1)
      {
          cout<<"storage: "<<_storage[phone[i].storage]<<"***";

      }
      else
      {
          cout<<" "<<_storage[phone[i].storage]<<"***";
      }
    }
    cout<<endl;
    for ( i=number-1;i>=0;i--)
    {
      if (i==number-1)
      {
          cout<<"price: "<<phone[i].price<<"***";

      }
      else
      {
          cout<<" "<<phone[i].price<<"***";
      }
    }
    cout<<endl;
    for ( i=number-1;i>=0;i--)
    {
      if (i==number-1)
      {
          cout<<"color: "<<_color[phone[i].color]<<"***";

      }
      else
      {
          cout<<" "<<_color[phone[i].color]<<"***";
      }
    }
    cout<<endl;
    for ( i=number-1;i>=0;i--)
    {
      if (i==number-1)
      {
          cout<<"inventory: "<<phone[i].number<<"***";

      }
      else
      {
          cout<<" "<<phone[i].number<<"***";
      }
    }
}


void most_sold_item(phones **ptr_phone,int number)
{
    phones * phone=*ptr_phone;
    for (int i=0;i<number;i++)
    {
        for (int j=0;j<number-i;j++)
        {
            if(phone[j].sold_number>phone[j+1].sold_number)
                swap(phone[j],phone[j+1]);
        }
    }

    print_phone(phone,number);
    int i;
    cout<<endl;
    for ( i=number-1;i>=0;i--)
    {
      if (i==number-1)
      {
          cout<<"Sold number: "<<phone[i].sold_number<<"***";

      }
      else
      {
          cout<<" "<<phone[i].sold_number<<"***";
      }
    }
    cout<<endl;
    cin.sync();
    cout<<endl<<"press any key to continue...\n";
    getchar();
}

void print_index(phones *p,int index)
{
   cout<<"name: "<<p[index].name<<endl;
   cout<<"company: "<<p[index].company<<endl;
   cout<<"OS: "<<_os[p[index].os]<<endl;
   cout<<"RAM: "<<_ram[p[index].ram]<<endl;
   cout<<"storage: "<<_storage[p[index].storage]<<endl;
   cout<<"price: "<<p[index].price<<endl;
   cout<<"color: "<<_color[p[index].color]<<endl;
   cout<<"Inventory: "<<p[index].number<<endl;

}
