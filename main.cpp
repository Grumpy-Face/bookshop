#include<iostream>
#include<string>
#include<windows.h>
#include<mysql.h>
#include<iomanip>
#include<conio.h>
using namespace std;
void sqin();
void sqdis();
void seasq();
void delent();
void title();
void seabook();
void update();
class book {
	string author;
	string title, publisher;
	float price;
	int stock;
public:
	static int t_count, succ_trans, unsucc_trans;
	book() {
		title = "Alchemist";
		author = "Paulo Coelho";
		publisher = "Paulo Coelho";
		price = 1000;
		stock = 3;
	}
	void add();
	void showdata();
	void search();
	void searbook();
	void upd();
	void delentr();
};
void book::add()
{
    sqin();

}
void book::delentr()
{
    delent();

}
void book::search()
{
	seasq();
}
void book::searbook()
{
    seabook();
}
void book::upd()
{

    update();
}
void book::showdata()
{
    sqdis();
}
int main()
{

    title();
    book b[20];
	int i = 0, choice, t;
	do {
		cout << "\n\n\n\t\t\t\t\t    ||||-=-=-=-MENU-=-=-=-||||\n\n\n";
		cout << "1. Entry of New Book" << endl;
		cout << "2. Display" << endl;
		cout << "3. Search" << endl;
		cout << "4. Update" << endl;
		cout << "5. Delete Book" << endl;
		cout << "6. Exit\n" << endl;
		cout << "Enter Your Choice : ";
		cin >> choice;
		if (choice == 1)
		{
            b[i].add();
            i++;
		}
		if (choice == 2)
		{
            b[i].showdata();
            i++;
		}
		if (choice == 3)
		{
		    cout<<"\nHow do you want to search : \n1)Serial No \n2)Title\n";
		    cout<<"Enter your choice : ";
		    int xz;
		    cin>>xz;
		    cout<<endl;
		    if(xz==1)
            {
			b[i].search();
			i++;
            }
            else if (xz==2)
            {
            b[i].searbook();
            i++;
            }
            else
                cout<<"Wrong choice......."<<endl;
		}
		if(choice ==4)
        {
            b[i].upd();
            i++;
        }
		if (choice == 5)
		{
                    b[i].delentr();
                    i++;
		}
		if (choice == 6)
		{
			cout << endl << "Program Terminated Successfully.......";
		}
	} while (choice < 6);
	return 0;
}
void sqin()
{
     MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
     conn = mysql_real_connect(conn,"localhost","root","","bookshop",0,NULL,0);
            string  serial,author,publisher,stock,title,price;
			cout<<"Enter Serial No : ";
			cin>>serial;
			cout<<"Enter Author Name : ";
			cin>>author;
			cout<<"Enter Book Name : ";
			cin>>title;
			cout<<"Enter Publisher Name : ";
			cin>>publisher;
			cout<<"Enter Quantity : ";
			cin>>stock;
			cout<<"Enter Price : ";
			cin>>price;
			string query="insert into books(serial,title,author,publisher,price,stock) values('"+serial+"','"+title+"','"+author+"','"+publisher+"','"+price+"','"+stock+"')";
			const char* q=query.c_str();
			cout<<"Query is : "<<q<<endl;
			qstate=mysql_query(conn,q);
			if(!qstate)
            {
                cout<<"Record Inserted Successfully..."<<endl;
            }
            else
                cout<<"Query Problem: "<<mysql_error(conn)<<endl;

}
void sqdis()
{
     MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
        conn = mysql_real_connect(conn,"localhost","root","","bookshop",0,NULL,0);
     if(conn)
     {
        cout<<"Connection to database ok "<<conn<<endl;
        qstate = mysql_query(conn,"select * from books");
        if(!qstate)
        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                cout<<"Sr: "<<row[0]<<" "
                    <<"Author: "<<row[1]<<"   "
                    <<"Title: "<<row[2]<<"   "
                    <<"Publisher: "<<row[3]<<"   "
                    <<"Quantity: "<<row[5]<<"   "
                    <<"Price: "<<row[4]<<endl;
            }
        }
        else
        {
            cout<<"Query Rxecution Problem "<<mysql_error(conn)<<endl;
        }
     }

}
void seasq()
{
 MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
     conn = mysql_real_connect(conn,"localhost","root","","bookshop",0,NULL,0);
                                string Sr;
                                cout<<"Enter Serial No to Search : ";
                                cin>>Sr;
                                string findbysr_query="select * from books where Serial like '%"+Sr+"%'";
                                const char * qn=findbysr_query.c_str();
                                qstate=mysql_query(conn, qn);
                                cout<<endl;
                                cout<<"Showing Book Record"<<endl<<endl;
                                if(!qstate)
        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                cout<<"Sr: "<<row[0]<<" "
                    <<"Author: "<<row[1]<<"   "
                    <<"Title: "<<row[2]<<"   "
                    <<"Publisher: "<<row[3]<<"   "
                    <<"Quantity: "<<row[4]<<"   "
                    <<"Price: "<<row[5]<<endl;
            }
        }
        else
        {
            cout<<"Query Rxecution Problem "<<mysql_error(conn)<<endl;
        }
}
void seabook()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
     conn = mysql_real_connect(conn,"localhost","root","","bookshop",0,NULL,0);
                                string bo;
                                cout<<"Enter book's name to Search book : ";
                                cin>>bo;
                                string findbysr_query="select * from books where title like '%"+bo+"%'";
                                const char * qn=findbysr_query.c_str();
                                qstate=mysql_query(conn, qn);
                                cout<<endl;
                                cout<<"Showing Book Record"<<endl<<endl;
                                if(!qstate)
        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                cout<<"Sr: "<<row[0]<<" "
                    <<"Author: "<<row[1]<<"   "
                    <<"Title: "<<row[2]<<"   "
                    <<"Publisher: "<<row[3]<<"   "
                    <<"Price: "<<row[4]<<"   "
                    <<"Stock: "<<row[5]<<endl;
            }
        }
        else
        {
            cout<<"Query Rxecution Problem "<<mysql_error(conn)<<endl;
        }
}
void delent()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;
     conn = mysql_real_connect(conn,"localhost","root","","bookshop",0,NULL,0);
     char ch;
     cout<<"Do You Want To Delete Any Record(y/n)"<<endl;
        cin>>ch;
        if(ch=='y'||ch=='Y')
                {
                string Serial;
                cout<<"Enter Record Serial No to Delete"<<endl;
                cin>>Serial;
                string delete_query="delete from books where Serial='"+Serial+"'";
                const char* qd=delete_query.c_str();
                qstate=mysql_query(conn,qd);
                if(!qstate)
                {
                                cout<<"Record Deleted Successfully"<<endl;
                }
                else
                {
                                cout<<"Failed to Delete Record!"<<mysql_error(conn)<<endl;
                }
     }
}
void update()
{
     MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    int qstate;

     conn = mysql_real_connect(conn,"localhost","root","","bookshop",0,NULL,0);

      string  serial,author,title,publisher,price,stock;
                                cout<<"Enter Serial No to Update : ";

                                cin>>serial;
                                cin.ignore(1,'\n');
			cout<<"Enter new Book Name : "; getline(cin,title);
			cout<<"Enter new Author Name : "; getline(cin,author);
			cout<<"Enter new Publisher Name : "; getline(cin,publisher);
			cout<<"Enter new Quantity : "; cin>>stock;
			cout<<"Enter new Price : "; cin>>price;
            string findbyup_query="UPDATE books SET serial='"+serial+"',title='"+title+"',author='"+author+"',publisher='"+publisher+"',stock='"+stock+"',price='"+price+"' WHERE serial like '%"+serial+"%'";

            const char * qu=findbyup_query.c_str();
            qstate=mysql_query(conn, qu);
            cout<<endl;
            cout<<"Record Updated Successfully"<<endl<<endl;

}


void title()
{
   int a=0;
    char b=203;
    char b1=202;
    char c=206;
    cout<<"                                                                                    "<<endl;
    for(int i=0;i<36;i++)
    {
        cout<<"\r";
        cout<<setw(40);
        cout<<c;
        for(int j=0;j<i;j++)
            cout<<b;
        for(int s=i;s<35;s++)
            cout<<" ";
        if(i==35)
            cout<<c;
    }
    cout<<endl;
    for(int i=0;i<36;i++)
    {
        cout<<"\r";
        cout<<setw(40);
        cout<<c;
        for(int j=0;j<i;j++)
            cout<<b1;
        for(int s=i;s<35;s++)
            cout<<" ";
        if(i==35)
            cout<<c;
    }
    cout<<endl;
    for(int i=0;i<36;i++)
    {
        cout<<"\r";
        cout<<setw(40);
        cout<<c;
        for(int j=0;j<i;j++)
        {
            if(j<=10)
            cout<<"-";
            switch(j)
            {
            case 11:
                cout<<" ";
                break;
            case 12:
                cout<<" ";
                break;
            case 13:
                cout<<" ";
                break;
            case 14:
                cout<<"B";
                break;
            case 15:
                cout<<"O";
                break;
            case 16:
                cout<<"O";
                break;
            case 17:
                cout<<"K";
                break;
            case 18:
                cout<<"S";
                break;
            case 19:
                cout<<"H";
                break;
            case 20:
                cout<<"O";
                break;
            case 21:
                cout<<"P";
                break;
            case 22:
                cout<<" ";
                break;
            case 23:
                cout<<" ";
                break;
            case 24:
                cout<<" ";
                break;
            }
            if(j>=25&&j<=35)
            cout<<"-";
        }
        for(int s=i;s<35;s++)
            cout<<" ";
        if(i==35)
            cout<<c;
    }
    cout<<endl;
    for(int i=0;i<36;i++)
    {
        cout<<"\r";
        cout<<setw(40);
        cout<<c;
        for(int j=0;j<i;j++)
            cout<<b;
        for(int s=i;s<35;s++)
            cout<<" ";
        if(i==35)
            cout<<c;
    }
    cout<<endl;
    for(int i=0;i<36;i++)
    {
        cout<<"\r";
        cout<<setw(40);
        cout<<c;
        for(int j=0;j<i;j++)
            cout<<b1;
        for(int s=i;s<35;s++)
            cout<<" ";
        if(i==35)
            cout<<c;
    }
    cout<<"                                                                                    "<<endl;
    cout<<"\n\n\n";
    for(int i=0;i<70;i++)
    {
        for(int j=0;j<i;j++)
            cout<<"-";
        for(int s=i;s<75;s++)
            cout<<" ";
        cout<<"\r";
    }

    cout<<setw(20)<<"\nDESIGN BY:-\n\t\MOMIN MUBASHAR\n"<<endl;
    for(int i=0;i<70;i++)
        {

            for(int j=0;j<i;j++)
            {cout<<"-";}
            for(int s=i;s<75;s++)
            {cout<<" ";}
            cout<<"\r";
        }
    cout<<endl;
}
