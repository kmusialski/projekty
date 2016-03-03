#include "PROJECT.h"

//------------------ WYBOR MODULU -------------------


int PROJECT::switch_project(int &wybor)
{
    switch(wybor)
        {
        case 1:
            show_project();
            break;
        case 2:
            add_project();
            break;
        case 3:
            delete_project();
            break;
        case 5:
            load();
            break;
        default:
            cout<<"Podaj wartosc z zakresu"<<endl;
            break;
        }

}


void PROJECT::add_project()
{
cout<<"Podaj nazwe projektu"<<endl;
cin>>project_name;
projects_names.push_back(project_name);
cout<<"Podaj opis projektu"<<endl;
cin>>project_description;
projects_descriptions.push_back(project_description);
cout<<"Podaj deadline"<<endl;
cin>>project_deadline;
projects_deadlines.push_back(project_deadline);
n+1;
system("CLS");

}

void PROJECT::save_quit()
{
  fstream plik( "plik.txt", ios::out );
    if( plik.good() )
   {
            j=1;
            for(list<string>::iterator i=projects_names.begin(); i!= projects_names.end(); ++i,j++)
            {
              plik << *i<< endl;
            }
            j=1;
            for(list<string>::iterator i=projects_descriptions.begin(); i!= projects_descriptions.end(); ++i,j++)
            {
            plik << *i<< endl;
            }
            j=1;
            for(list<string>::iterator i=projects_deadlines.begin(); i!= projects_deadlines.end(); ++i,j++)
            {
            plik << *i << endl;
            }
      plik.close();
   }

}

void PROJECT::load()
{

	ifstream infile;
	infile.open ("plik.txt");
  while (!infile.eof())
    {
    getline(infile, STRING);
        cout << STRING << endl;

    }

  }



void PROJECT::delete_project()
{
cout<<"Ktory wpis chcesz usunac?"<<endl;
}

void PROJECT::show_project()
{
fstream plik( "plik.txt", ios::out );
system("CLS");
set_color_default();
//SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY ) ;
//WYSWIETL OPISY
gotoxy(10,1);  cout<<"Nazwa projektu";
gotoxy(30,1); cout<<"Opis projektu";
gotoxy(50,1); cout<<"Deadline projektu";
cout<<endl;
set_color_hit();

j=1;
for(list<string>::iterator i=projects_names.begin(); i!= projects_names.end(); ++i,j++)
       {
       gotoxy(10,(2*j));
       cout<<*i;
       }
j=1;
for(list<string>::iterator i=projects_descriptions.begin(); i!= projects_descriptions.end(); ++i,j++)
       {
       gotoxy(30,(2*j));
       cout<<*i;
       }
j=1;
for(list<string>::iterator i=projects_deadlines.begin(); i!= projects_deadlines.end(); ++i,j++)
       {
       gotoxy(50,(2*j));
       cout<<*i;
       }


//for (int i =1; i <= n; i++) {
    //gotoxy(10,(2*i));
   // gotoxy(30,(2*i)); cout<<project_description;
    //gotoxy(50,(2*i)); cout<<project_deadline;


//gotoxy(10,3);  cout<<project_name;
//gotoxy(30,3); cout<<project_description;
//gotoxy(50,3); cout<<project_deadline;
cout<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);


}

void PROJECT::set_color_default()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
}

void PROJECT::gotoxy(int x, int y)
{
  COORD c;
  c.X=x-1;
  c.Y=y-1;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void PROJECT::set_color_hit()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
}
