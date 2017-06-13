#include <iostream>
#include <fstream>
#include <client_info.h>
#include <vector>
#include <string>
#include <movies.h>
#include <video_games.h>
#include <VIP_client_info.h>
#include <series.h>
#include <cstring>
#include <rent_info.h>
#include <cmath>

using namespace std;

void addGame(vector<video_games>& GamesVector)
{
    int num_of_vgames=0;
    video_games newGame;
    newGame.Setconsole_name();
    newGame.Settitle();
    newGame.Settype();
    newGame.SetID();
    newGame.Setserial_number();
    newGame.Setyear_pub();
    newGame.Setnum_of_copies();
    GamesVector.push_back(newGame);
    ofstream outGfile;
    outGfile.open("video_games.txt",ios::app);
    outGfile << GamesVector[GamesVector.size()-1].Gettitle()<<endl;
    outGfile << GamesVector[GamesVector.size()-1].Gettype()<<endl;
    outGfile << GamesVector[GamesVector.size()-1].Getconsole_name()<<endl;
    outGfile << GamesVector[GamesVector.size()-1].GetID()<<endl;
    outGfile << GamesVector[GamesVector.size()-1].Getserial_number()<<endl;
    outGfile << GamesVector[GamesVector.size()-1].Getyear_pub()<<endl;
    outGfile << GamesVector[GamesVector.size()-1].Getnum_of_copies()<<endl;
    ifstream numberFile; //αρχή ενημέρωσης του αριθμού των παιχνιδιών
    numberFile.open("number_of_vg.txt");
    numberFile >> num_of_vgames;
    num_of_vgames++;
    numberFile.close();
    ofstream outnumberFile;
    outnumberFile.open("number_of_vg.txt");
    outnumberFile<<num_of_vgames;
    outnumberFile.close();

    outGfile.close();
    return;
}

void addSeries(vector<series>& SeriesVector)
{
    int num_of_series=0;
    series newSeries;
    newSeries.Setdirector();
    newSeries.SetID();
    newSeries.Settitle();
    newSeries.Setnum_of_copies();
    newSeries.Setactors();
    newSeries.Setpub_year();
    newSeries.Setserial_number();
    newSeries.Settype();
    newSeries.Setfirst_ep();
    newSeries.Setfinal_ep();
    newSeries.Setseason();
    SeriesVector.push_back(newSeries);
    ofstream outSfile;
    outSfile.open("series.txt",ios::app);
    outSfile << SeriesVector[SeriesVector.size()-1].Gettitle()<<endl;
    outSfile << SeriesVector[SeriesVector.size()-1].Gettype()<<endl;
    outSfile << SeriesVector[SeriesVector.size()-1].Getdirector()<<endl;
    outSfile << SeriesVector[SeriesVector.size()-1].Getactors()<<endl;
    outSfile << SeriesVector[SeriesVector.size()-1].GetID()<<endl;
    outSfile << SeriesVector[SeriesVector.size()-1].Getserial_number()<<endl;
    outSfile << SeriesVector[SeriesVector.size()-1].Getpub_year()<<endl;
    outSfile << SeriesVector[SeriesVector.size()-1].Getseason()<<endl;
    outSfile << SeriesVector[SeriesVector.size()-1].Getfirst_ep()<<endl;
    outSfile << SeriesVector[SeriesVector.size()-1].Getfinal_ep()<<endl;
    outSfile << SeriesVector[SeriesVector.size()-1].Getnum_of_copies()<<endl;
    ifstream numberFile; //αρχή ενημέρωσης του αριθμού των σειρών
    numberFile.open("number_of_s.txt");
    numberFile >> num_of_series;
    num_of_series++;
    numberFile.close();
    ofstream outnumberFile;
    outnumberFile.open("number_of_s.txt");
    outnumberFile<<num_of_series;
    outnumberFile.close();

    outSfile.close();
    return;
}

void deleteMovie(vector<movies>& MoviesVector) //διαγραφή ταινιών
{
    int num_of_movies=0,er,id;

    cout<<"Give the ID of the movie that you wish to remove: "<<endl;
    cin>>id;
    ifstream numberFile;
    numberFile.open("number_of_m.txt");
    numberFile >> num_of_movies;
    numberFile.close();
    for(unsigned int i=0;i<MoviesVector.size();i++)
    {
        if(id==MoviesVector.at(i).GetID())
        {

            er=i;
            break;
        }
    }
    MoviesVector.erase(MoviesVector.begin()+er);
    ofstream Mfile;
    Mfile.open("movies.txt");
    for(unsigned int k=0; k<MoviesVector.size()-1;k++) //γραφή του vector στο αρχείο χωρίς την ταινία που διαγράφηκε
    {
        Mfile << MoviesVector[k].Gettitle()<<endl;
        Mfile << MoviesVector[k].Gettype()<<endl;
        Mfile << MoviesVector[k].Getdirector()<<endl;
        Mfile << MoviesVector[k].Getactors()<<endl;
        Mfile << MoviesVector[k].GetID()<<endl;
        Mfile << MoviesVector[k].Getserial_number()<<endl;
        Mfile << MoviesVector[k].Getpub_year()<<endl;
        Mfile << MoviesVector[k].Getduration()<<endl;
        Mfile << MoviesVector[k].num_of_copies<<endl;
    }
    Mfile.close();
    num_of_movies--;
    ofstream outnumberFile;//ενημέρωσης του αριθμού των ταινιών
    outnumberFile.open("number_of_m.txt");
    outnumberFile << num_of_movies;
    outnumberFile.close();

    return;
}

void deleteSeries(vector<series>& SeriesVector)//διαγραφή σειρών
{
    int num_of_series=0,er,id;
    cout<<"Give the ID of the series that you wish to remove: "<<endl;
    cin>>id;
    ifstream numberFile;
    numberFile.open("number_of_s.txt");
    numberFile >> num_of_series;
    numberFile.close();
    for(unsigned int i=0;i<SeriesVector.size();i++)
    {
        if(id==SeriesVector.at(i).GetID())
        {

            er=i;
            break;
        }
    }
    SeriesVector.erase(SeriesVector.begin()+er);
    ofstream Sfile;
    Sfile.open("series.txt");
    for(unsigned int k=0;k<SeriesVector.size()-1;k++)
    {
        Sfile << SeriesVector[k].Gettitle()<<endl;
        Sfile << SeriesVector[k].Gettype()<<endl;
        Sfile << SeriesVector[k].Getdirector()<<endl;
        Sfile << SeriesVector[k].Getactors()<<endl;
        Sfile << SeriesVector[k].GetID()<<endl;
        Sfile << SeriesVector[k].Getserial_number()<<endl;
        Sfile << SeriesVector[k].Getpub_year()<<endl;
        Sfile << SeriesVector[k].Getseason()<<endl;
        Sfile << SeriesVector[k].Getfirst_ep()<<endl;
        Sfile << SeriesVector[k].Getfinal_ep()<<endl;
        Sfile << SeriesVector[k].num_of_copies<<endl;
    }
    Sfile.close();
    num_of_series--;
    ofstream outnumberFile;
    outnumberFile.open("number_of_s.txt");
    outnumberFile << num_of_series;
    outnumberFile.close();
    return;
}

void deleteVGame(vector<video_games>& GamesVector)//διαγραφή παιχνιδιών
{
    int num_of_vgames=0;
    unsigned int er,id;
    cout<<"Give the ID of the video game that you wish to remove: "<<endl;
    cin>>id;
    ifstream numberFile;
    numberFile.open("number_of_vg.txt");
    numberFile >> num_of_vgames;
    numberFile.close();
    for(unsigned int i=0;i<GamesVector.size();i++)
    {
        if(id==GamesVector.at(i).GetID())
        {
            cout<<"yo";
            er=i;
            break;
        }
    }
    GamesVector.erase(GamesVector.begin()+er);
    ofstream Gfile;
    Gfile.open("video_games.txt");
    for(unsigned k=0;k<GamesVector.size()-1;k++)
    {
        Gfile << GamesVector[k].Gettitle()<<endl;
        Gfile << GamesVector[k].Gettype()<<endl;
        Gfile << GamesVector[k].Getconsole_name()<<endl;
        Gfile << GamesVector[k].GetID()<<endl;
        Gfile << GamesVector[k].Getserial_number()<<endl;
        Gfile << GamesVector[k].Getyear_pub()<<endl;
        Gfile << GamesVector[k].num_of_copies<<endl;
    }
    Gfile.close();

    num_of_vgames--;
    ofstream outnumberFile;
    outnumberFile.open("number_of_vg.txt");
    outnumberFile << num_of_vgames;
    outnumberFile.close();
    return;
}

int modifyMenu()
{
    int ap;
    cout<<"1. Press 1 to modify title."<<endl;
    cout<<"2. Press 2 to modify director."<<endl;
    cout<<"3. Press 3 to modify actors." <<endl;
    cout<<"4. Press 4 to modify the number of copies."<<endl;
    cout<<"(if series) Press 5 to modify the final episode."<<endl;
    cout<<"(if series) Press 6 to modify current season."<<endl;
    cin>>ap;
    return ap;
}

void modifySeries(vector<series>& SeriesVector)//τροποποίηση σειρών
{

    int ap,id,number;
    string d_name;
    cout<<"Type the ID of the series that you wish to modify: "<<endl;
    cin>>id;
    for (unsigned int i=0;i<SeriesVector.size();i++)
    {
        if(SeriesVector.at(i).GetID()==id)
        {
            ap=modifyMenu();
            if (ap==1)
            {
                cout<<"Type the modified name of the series: "<<endl;
                cin.ignore();
                getline(cin,d_name);
                SeriesVector.at(i).Copytitle(d_name);
            }
            else if(ap==2)
            {
                cout<<"Type the modified director's name: "<<endl;
                cin.ignore();
                getline(cin,d_name);
                SeriesVector.at(i).Copydirector(d_name);
            }
            else if(ap==3)
            {
                cout<<"Type the modified actors' names: "<<endl;
                cin.ignore();
                getline(cin,d_name);
                SeriesVector.at(i).Copyactors(d_name);
            }
            else if(ap==4)
            {
                cout<<"Type the modified number of copies: "<<endl;
                cin>>number;
                SeriesVector.at(i).num_of_copies=number;
            }
            else if(ap==5)
            {
                cout<<"Type the modified number of the current final episode: "<<endl;
                cin>>number;
                SeriesVector.at(i).Copyfinal_ep(number);
            }
            else if(ap==6)
            {
                cout<<"Type the modified number of the current season: "<<endl;
                cin>>number;
                SeriesVector.at(i).Copyseason(number);
            }
            break;
        }
    }
    ofstream Sfile;
    Sfile.open("series.txt");
    for(unsigned int k=0;k<SeriesVector.size()-1;k++)
    {
        Sfile << SeriesVector[k].Gettitle()<<endl;
        Sfile << SeriesVector[k].Gettype()<<endl;
        Sfile << SeriesVector[k].Getdirector()<<endl;
        Sfile << SeriesVector[k].Getactors()<<endl;
        Sfile << SeriesVector[k].GetID()<<endl;
        Sfile << SeriesVector[k].Getserial_number()<<endl;
        Sfile << SeriesVector[k].Getpub_year()<<endl;
        Sfile << SeriesVector[k].Getseason()<<endl;
        Sfile << SeriesVector[k].Getfirst_ep()<<endl;
        Sfile << SeriesVector[k].Getfinal_ep()<<endl;
        Sfile << SeriesVector[k].num_of_copies<<endl;
    }
    Sfile.close();

    return;
}

void modifyMovie(vector<movies>& MoviesVector)//τροποποίηση ταινιών
{
    int ap,id,number;
    string d_name;
    cout<<"Type the ID of the movie that you wish to modify: "<<endl;
    cin>>id;
    for (unsigned int i=0;i<MoviesVector.size();i++)
    {
        if(MoviesVector.at(i).GetID()==id)
        {
            ap=modifyMenu();
            if (ap==1)
            {
                cout<<"Type the modified name of the movie: "<<endl;
                cin.ignore();
                getline(cin,d_name);
                MoviesVector.at(i).Copytitle(d_name);
            }
            else if(ap==2)
            {
                cout<<"Type the modified director's name: "<<endl;
                cin.ignore();
                getline(cin,d_name);
                MoviesVector.at(i).Copydirector(d_name);
            }
            else if(ap==3)
            {
                cout<<"Type the modified actors' names: "<<endl;
                cin.ignore();
                getline(cin,d_name);
                MoviesVector.at(i).Copyactors(d_name);
            }
            else if(ap==4)
            {
                cout<<"Type the modified number of copies: "<<endl;
                cin>>number;
                MoviesVector.at(i).num_of_copies=number;
            }
            break;
        }
    }
    ofstream Mfile;
    Mfile.open("movies.txt");
    for(unsigned int k=0; k<MoviesVector.size()-1;k++)
    {
        Mfile << MoviesVector[k].Gettitle()<<endl;
        Mfile << MoviesVector[k].Gettype()<<endl;
        Mfile << MoviesVector[k].Getdirector()<<endl;
        Mfile << MoviesVector[k].Getactors()<<endl;
        Mfile << MoviesVector[k].GetID()<<endl;
        Mfile << MoviesVector[k].Getserial_number()<<endl;
        Mfile << MoviesVector[k].Getpub_year()<<endl;
        Mfile << MoviesVector[k].Getduration()<<endl;
        Mfile << MoviesVector[k].num_of_copies<<endl;
    }
    Mfile.close();
    return;
}
int modifyMenu_vg()
{
    int ap;
    cout<<"1. Press 1 to modify title."<<endl;
    cout<<"2. Press 2 to modify console name."<<endl;
    cout<<"3. Press 3 to modify the number of copies."<<endl;
    cout<<"4. Press 4 to modify the game type. "<<endl;
    cin >> ap;
    return ap;
}

void modifyVGame(vector<video_games>& GamesVector)//τροποποίηση παιχνιδιών
{
    int ap,id,number;
    string d_name;
    cout<<"Type the ID of the video game that you wish to modify: "<<endl;
    cin>>id;
    for (unsigned int i=0;i<GamesVector.size();i++)
    {
        if(GamesVector.at(i).GetID()==id)
        {
            ap=modifyMenu_vg();
            if (ap==1)
            {
                cout<<"Type the modified title of the vigeo game: "<<endl;
                cin.ignore();
                getline(cin,d_name);
                GamesVector.at(i).Copytitle(d_name);
            }
            else if(ap==2)
            {
                cout<<"Type the modified console name: "<<endl;
                cin.ignore();
                getline(cin,d_name);
                GamesVector.at(i).Copyconsole_name(d_name);
            }
            else if(ap==3)
            {
                cout<<"Type the modified number of copies: "<<endl;
                cin>>number;
                GamesVector.at(i).num_of_copies=number;
            }
            else if(ap==4)
            {
                cout<<"Type the modified type of the video game: "<<endl;
                cin.ignore();
                getline(cin,d_name);
                GamesVector.at(i).Copytype(d_name);
            }
            break;
        }
    }
    ofstream Gfile;
    Gfile.open("video_games.txt");
    for(unsigned k=0;k<GamesVector.size()-1;k++)
    {
        Gfile << GamesVector[k].Gettitle()<<endl;
        Gfile << GamesVector[k].Gettype()<<endl;
        Gfile << GamesVector[k].Getconsole_name()<<endl;
        Gfile << GamesVector[k].GetID()<<endl;
        Gfile << GamesVector[k].Getserial_number()<<endl;
        Gfile << GamesVector[k].Getyear_pub()<<endl;
        Gfile << GamesVector[k].num_of_copies<<endl;
    }
    Gfile.close();
    return;
}

void addMovie(vector<movies>& MoviesVector)//προσθήκη ταινιών
{
    int num_of_movies=0;
    movies newMovie;
    newMovie.Setdirector();
    newMovie.Setduration();
    newMovie.SetID();
    newMovie.Settitle();
    newMovie.Setnum_of_copies();
    newMovie.Setactors();
    newMovie.Setpub_year();
    newMovie.Setserial_number();
    newMovie.Settype();
    MoviesVector.push_back(newMovie);
    ofstream outMfile;
    outMfile.open("movies.txt",ios::app);
    outMfile << MoviesVector[MoviesVector.size()-1].Gettitle()<<endl;
    outMfile << MoviesVector[MoviesVector.size()-1].Gettype()<<endl;
    outMfile << MoviesVector[MoviesVector.size()-1].Getdirector()<<endl;
    outMfile << MoviesVector[MoviesVector.size()-1].Getactors()<<endl;
    outMfile << MoviesVector[MoviesVector.size()-1].GetID()<<endl;
    outMfile << MoviesVector[MoviesVector.size()-1].Getserial_number()<<endl;
    outMfile << MoviesVector[MoviesVector.size()-1].Getpub_year()<<endl;
    outMfile << MoviesVector[MoviesVector.size()-1].Getduration()<<endl;
    outMfile << MoviesVector[MoviesVector.size()-1].Getnum_of_copies()<<endl;
    outMfile.close();
    ifstream numberFile;//αρχή ενημέρωσης του αριθμού των ταινιών
    numberFile.open("number_of_m.txt");
    numberFile >> num_of_movies;
    num_of_movies++;
    numberFile.close();
    ofstream outnumberFile;
    outnumberFile.open("number_of_m.txt");
    outnumberFile<<num_of_movies;
    outnumberFile.close();
    return;
}

void load_msvg(vector<movies>& MoviesVector, vector<series>& SeriesVector, vector<video_games>& GamesVector,int ap)//φόρτωση vector ταινιών, σειρών, παιχνιδιών
{
    char choice;
    if (ap==1)
    {
        cout<<"Press m if you want to add a movie, s if you want to add a series or v if you want to add a video game: "<<endl;
        cin>>choice;
    }
    if (choice=='m' || ap==7 || ap==8 || ap==9 || ap==3 || ap==2)
    {
        bool first_time=false;
        ifstream Mfile;//έλεγχος για το αν είναι άδειο το αρχείο
        Mfile.open("movies.txt");
        streampos current=Mfile.tellg();
        Mfile.seekg(0,Mfile.end);
        bool emptm=0;
        emptm= !Mfile.tellg();//αν emptm!=1 τότε το αρχείο δεν είναι άδειο, ενώ αν emptm==1 τότε είναι άδειο
        Mfile.close();
        ifstream mfile;//το ξανανοίγω για να γυρίσει ο δείκτης ανάγνωσης στην αρχή του αρχείου
        mfile.open("movies.txt");
        if (emptm!=1)
        {
            while(!mfile.eof())//επανάληψη κατά την οποία διαβάζονται από το αρχείο οι μεταβλητές των αντικειμένων του vector
            {
                movies newMovie;
                int ID,serial_number,year_pub,duration,num_of_copies;
                string title,type,actors,director;
                if(first_time==false)
                    cin.ignore();
                else
                    mfile.ignore();

                getline(mfile,title);
                if (first_time==false)
                    mfile.ignore();
                getline(mfile,type);
                getline(mfile,director);
                getline(mfile,actors);
                newMovie.Copytitle(title);
                newMovie.Copytype (type);
                newMovie.Copyactors(actors);
                newMovie.Copydirector(director);

                mfile >> ID >> serial_number >> year_pub >> duration >>num_of_copies ;
                newMovie.CopyID(ID);
                newMovie.Copyserial_number(serial_number);
                newMovie.Copypub_year(year_pub);
                newMovie.Copyduration(duration);
                newMovie.Copynum_of_copies(num_of_copies);
                MoviesVector.push_back(newMovie);
                first_time=true;
            }
            mfile.close();
        }
        if(ap==1)
            addMovie(MoviesVector);
    }

    if(choice=='s' || ap==7 || ap==8 || ap==9 || ap==3 || ap==2)
    {
        bool first_time=false;
        ifstream Sfile; //έλεγχος για το αν είναι άδειο το αρχείο
        Sfile.open("series.txt");
        streampos current=Sfile.tellg();
        Sfile.seekg(0,Sfile.end);
        bool empts=0;
        empts= !Sfile.tellg();
        Sfile.close();
        ifstream sfile;
        sfile.open("series.txt");
        if (empts!=1)
        {
            while(!sfile.eof())
            {
                series newSeries;
                int ID,serial_number,year_pub,num_of_copies,season,first_ep,final_ep;
                string title,type,actors,director;
                if (first_time==false)
                    cin.ignore();
                else
                    sfile.ignore();
                getline(sfile,title);
                if (first_time==false)
                    sfile.ignore();
                getline(sfile,type);
                getline(sfile,director);
                getline(sfile,actors);
                newSeries.Copytitle(title);
                newSeries.Copytype (type);
                newSeries.Copyactors(actors);
                newSeries.Copydirector(director);

                sfile >> ID >> serial_number >> year_pub >> season >> first_ep >>final_ep >> num_of_copies;
                newSeries.CopyID(ID);
                newSeries.Copyserial_number(serial_number);
                newSeries.Copypub_year(year_pub);
                newSeries.Copynum_of_copies(num_of_copies);
                newSeries.Copyfirst_ep(first_ep);
                newSeries.Copyfinal_ep(final_ep);
                newSeries.Copyseason(season);
                SeriesVector.push_back(newSeries);
                first_time=true;
            }
            sfile.close();
        }
        if (ap==1)
            addSeries(SeriesVector);
    }
    if(choice=='v' || ap==7 || ap==8 || ap==9 || ap==3 || ap==2)
    {
        bool first_time=false;
        ifstream Gfile; //έλεγχος για το αν είναι άδειο το αρχείο
        Gfile.open("video_games.txt");
        streampos current=Gfile.tellg();
        Gfile.seekg(0,Gfile.end);
        bool emptg=0;
        emptg= !Gfile.tellg();
        Gfile.close();
        ifstream gfile;
        gfile.open("video_games.txt");
        if (emptg!=1)
        {
            while(!gfile.eof())
            {
                video_games newGame;
                int ID,serial_number,year_pub,num_of_copies;
                string title,type,console_name;
                if(first_time==false)
                    cin.ignore();
                else
                    gfile.ignore();
                getline(gfile,title);
                if (first_time==false)
                    gfile.ignore();
                getline(gfile,type);
                getline(gfile,console_name);

                newGame.Copytitle(title);
                newGame.Copytype (type);
                newGame.Copyconsole_name(console_name);

                gfile >> ID >> serial_number >> year_pub >> num_of_copies ;
                newGame.CopyID(ID);
                newGame.Copyserial_number(serial_number);
                newGame.Copyyear_pub(year_pub);
                newGame.Copynum_of_copies(num_of_copies);
                GamesVector.push_back(newGame);
                first_time=true;
            }
            gfile.close();
        }
        if(ap==1)
            addGame(GamesVector);
    }
}

void load_rents(vector<rent_info>& RentVector, char ap) //φόρτωση των δανεισμών του Video Club στον vector
{                                                       //λειτουργεί κατά τον ίδιον τρόπο με τις άλλες load συναρτήσεις
    if (ap=='m')
    {
        ifstream RMfile;
        RMfile.open("rented_m.txt");
        streampos current=RMfile.tellg();
        RMfile.seekg(0,RMfile.end);
        bool emptRM=0;
        emptRM= !RMfile.tellg();
        RMfile.close();
        ifstream rmfile;
        rmfile.open("rented_m.txt");
        if (emptRM!=1)
        {
            while(!rmfile.eof())
            {
                rent_info newRent;
                int identity ,d,m,number;
                rmfile >> identity >> number >> d >> m;
                newRent.SetID(identity);
                newRent.day=d;
                newRent.month=m;
                newRent.Setserial_number(number);
                RentVector.push_back(newRent);
            }
            rmfile.close();
        }

    }
    else if(ap=='s')
    {
        ifstream RSfile;
        RSfile.open("rented_s.txt");
        streampos current=RSfile.tellg();
        RSfile.seekg(0,RSfile.end);
        bool emptRS=0;
        emptRS= !RSfile.tellg();
        RSfile.close();
        ifstream rsfile;
        rsfile.open("rented_s.txt");
        if (emptRS!=1)
        {
            while(!rsfile.eof())
            {
                rent_info newRent;
                int identity ,d,m,number;
                rsfile >> identity >> number >> d >> m;
                newRent.SetID(identity);
                newRent.day=d;
                newRent.month=m;
                newRent.Setserial_number(number);
                RentVector.push_back(newRent);
            }
            rsfile.close();
        }
    }
    else
    {
        ifstream RGfile;
        RGfile.open("rented_vg.txt");
        streampos current=RGfile.tellg();
        RGfile.seekg(0,RGfile.end);
        bool emptRG=0;
        emptRG= !RGfile.tellg();
        RGfile.close();
        ifstream rgfile;
        rgfile.open("rented_vg.txt");
        if (emptRG!=1)
        {
            while(!rgfile.eof())
            {
                rent_info newRent;
                int identity ,d,m,number;
                rgfile >> identity >> number >> d >> m;
                newRent.SetID(identity);
                newRent.day=d;
                newRent.month=m;
                newRent.Setserial_number(number);
                RentVector.push_back(newRent);
            }
            rgfile.close();
        }
    }
    return;
}

bool isVIP(vector<VIP_client_info>& VIPClientsVector,int id) //συνάρτηση ελέγχου για το αν ο πελάτης είναι VIP
{
    bool found=false;                                       //αν επιστραφεί false τότε είναι κανονικός πελάτης, αντίθετα είναι VIP
    for (unsigned int i=0;i<VIPClientsVector.size();i++)
    {
        if (VIPClientsVector.at(i).Getclient_ID()==id)
        {
            found=true;
            return found;
        }
    }
    return found;
}

void calc_cost(vector<rent_info>& RentsVector,vector<VIP_client_info>& VIPClientsVector,vector<movies>& MoviesVector,vector<series>& SeriesVector, vector<video_games>& GamesVector, char choice)
{ //υπολογισμός της χρέωσης του πελάτη
    int id,sn,r_day,r_month,day,month,calc_d,calc_month,sum_days,er; //r_day=ημέρα ενοικίασης, r_month=μήνας ενοικίασης
    float cost;
    bool VIP=false;
    char type,year;
    cout<<"Type the ID of the client that is returning the rented product: "<<endl;
    cin>>id;
    if(choice=='m' || choice=='s')
        VIP=isVIP(VIPClientsVector,id);
    if(choice=='m')
    {
        cout<<"Type the serial number of the movie returned: "<<endl;
        cin>>sn;
        for (unsigned int i=0;i<RentsVector.size();i++)
        {
            if(RentsVector.at(i).Getserial_number()==sn)
            {
                er=i;
                r_day=RentsVector.at(i).day;
                r_month=RentsVector.at(i).month;
                cout<<"Type b if the movie is BluRay type or d if its DVD type: "<<endl;
                cin>>type;
                cout<<"Type the day that the movie is returned: "<<endl;
                cin>>day;
                cout<<"Type the month that the movie is returned: "<<endl;
                cin>>month;
                calc_d=day-r_day;
                calc_d=abs(calc_d);
                calc_month=month-r_month;
                calc_month=abs(calc_month);
                for(unsigned int k=0;k<MoviesVector.size();k++)
                {
                    if(sn==MoviesVector.at(k).Getserial_number())
                    {
                        cout<<"The movie was published in "<<MoviesVector.at(k).Getpub_year()<<endl;//έλεγχος για το αν η ταινία είναι καινούρια μαζι με τις γραμμές 773,774
                        MoviesVector.at(k).num_of_copies++; //ενημέρωση του αριθμού αντιγράφων αφού επιστρέφεται ένα αντίγραφο
                        break;
                    }
                }
                cout<<"Is it returned the same year? (y/n)"<<endl;
                cin>>year;
                sum_days=calc_d + calc_month*30; //υπολογισμός συνολικών μερών ενοικίασης της ταινίας
                if(sum_days<=3 && type=='d' && year=='n') //ακολουθεί υπολογισμός χρέωσης ανά περίπτωση
                {
                    cost=1;
                    if(VIP==true)
                        cost=cost-cost*(5/100);
                    cout<<"The client's cost is $"<< cost <<"."<<endl;
                }
                else if(sum_days<=3 && type=='d' && year=='y')
                {
                    cost=1.5;
                    if(VIP==true)
                        cost=cost-cost*(5/100);
                    cout<<"The client's cost is $"<< cost <<"."<<endl;
                }
                else if(sum_days<=3 && type=='b' && year=='n')
                {
                    cost=sum_days*2;
                    if(VIP==true)
                        cost=cost-cost*(5/100);
                    cout<<"The client's cost is $"<< cost <<"."<<endl;
                }
                else if(sum_days<=3 && type=='b' && year=='y')
                {
                    cost=sum_days*2+sum_days;
                    if(VIP==true)
                        cost=cost-cost*(5/100);
                    cout<<"The client's cost is $"<< cost <<"."<<endl;
                }
                else if(sum_days>3 && type=='d' && year=='n')
                {
                    cost=1+(sum_days-3)*0.5;
                    if(VIP==true)
                        cost=cost-cost*(5/100);
                    cout<<"The client's cost is $"<< cost <<"."<<endl;
                }
                else if(sum_days>3 && type=='d' && year=='y')
                {
                    cost=1+(sum_days-3)*0.5;
                    cost=cost+cost/2;
                    if(VIP==true)
                        cost=cost-cost*(5/100);
                    cout<<"The client's cost is $"<< cost <<"."<<endl;
                }
                else if(sum_days>3 && type=='b' && year=='n')
                {
                    cost=sum_days*2;
                    if(VIP==true)
                        cost=cost-cost*(5/100);
                    cout<<"The client's cost is $"<<cost<<endl;
                }
                else if(sum_days>3 && type=='b' && year=='y')
                {
                    cost=sum_days*2;
                    cost=cost+cost/2;
                    if(VIP==true)
                        cost=cost-cost*(5/100);
                    cout<<"The client's cost is $"<<cost<<endl;
                }
            }

            break;
        }
        ofstream Mfile; //γραφή του MoviesVector στο αρχείο με τον ενημερωμένο αριθμό αντιγράφων
        Mfile.open("movies.txt");
        for(unsigned int k=0;k<MoviesVector.size()-1;k++)
        {
            Mfile << MoviesVector[k].Gettitle()<<endl;
            Mfile << MoviesVector[k].Gettype()<<endl;
            Mfile << MoviesVector[k].Getdirector()<<endl;
            Mfile << MoviesVector[k].Getactors()<<endl;
            Mfile << MoviesVector[k].GetID()<<endl;
            Mfile << MoviesVector[k].Getserial_number()<<endl;
            Mfile << MoviesVector[k].Getpub_year()<<endl;
            Mfile << MoviesVector[k].Getduration()<<endl;
            Mfile << MoviesVector[k].num_of_copies<<endl;
        }
        Mfile.close();
        RentsVector.erase(RentsVector.begin()+er); //διαγραφή του δανεισμού από τον RentsVector
        ofstream Rfile;
        Rfile.open("rented_m.txt");
        for (unsigned int l=0;l<RentsVector.size()-1;l++) //γραφή του ενημερωμένου RentsVector στο αρχείο
        {
            Rfile << RentsVector.at(l).GetID() << endl;
            Rfile << RentsVector.at(l).Getserial_number() << endl;
            Rfile << RentsVector.at(l).day << endl;
            Rfile << RentsVector.at(l).month << endl;
        }
        Rfile.close();
    }
    else if(choice=='s') //υπολογισμός χρέωσης πελάτη για σειρές
    {
        cout<<"Type the serial number of the series returned: "<<endl;
        cin>>sn;
        for (unsigned int i=0;i<RentsVector.size();i++)
        {
            if(RentsVector.at(i).Getserial_number()==sn)
            {
                er=i;
                r_day=RentsVector.at(i).day;
                r_month=RentsVector.at(i).month;
                cout<<"Type b if the series is BluRay type or d if its DVD type: "<<endl;
                cin>>type;
                cout<<"Type the day that the series is returned: "<<endl;
                cin>>day;
                cout<<"Type the month that the series is returned: "<<endl;
                cin>>month;
                calc_d=day-r_day;
                calc_d=abs(calc_d);
                calc_month=month-r_month;
                calc_month=abs(calc_month);
                for(unsigned int k=0;k<SeriesVector.size();k++)
                {
                    if(sn==SeriesVector.at(k).Getserial_number())
                    {
                        SeriesVector.at(k).num_of_copies++;
                        break;
                    }
                }
                sum_days=calc_d + calc_month*30;
                if(sum_days<=3 && type=='d')
                {
                    cost=2;
                    if(VIP==true)
                        cost=cost-cost*(5/100);
                    cout<<"The client's cost is $"<< cost <<"."<<endl;
                }
                else if(sum_days<=3 && type=='b')
                {
                    cost=3;
                    if(VIP==true)
                        cost=cost-cost*(5/100);
                    cout<<"The client's cost is $"<< cost <<"."<<endl;
                }
                else if(sum_days>3 && type=='d')
                {
                    cost=2+(sum_days-3)*0.5;
                    if(VIP==true)
                        cost=cost-cost*(5/100);
                    cout<<"The client's cost is $"<< cost <<"."<<endl;
                }
                else if(sum_days>3 && type=='b')
                {
                    cost=2+(sum_days-3)*0.5+1;
                    if(VIP==true)
                        cost=cost-cost*(5/100);
                    cout<<"The client's cost is $"<<cost<<endl;
                }
            }

            break;
        }
        ofstream Sfile;
        Sfile.open("series.txt");
        for(unsigned int k=0;k<SeriesVector.size()-1;k++)
        {
            Sfile << SeriesVector[k].Gettitle()<<endl;
            Sfile << SeriesVector[k].Gettype()<<endl;
            Sfile << SeriesVector[k].Getdirector()<<endl;
            Sfile << SeriesVector[k].Getactors()<<endl;
            Sfile << SeriesVector[k].GetID()<<endl;
            Sfile << SeriesVector[k].Getserial_number()<<endl;
            Sfile << SeriesVector[k].Getpub_year()<<endl;
            Sfile << SeriesVector[k].Getseason()<<endl;
            Sfile << SeriesVector[k].Getfirst_ep()<<endl;
            Sfile << SeriesVector[k].Getfinal_ep()<<endl;
            Sfile << SeriesVector[k].num_of_copies<<endl;
        }
        Sfile.close();
        RentsVector.erase(RentsVector.begin()+er);
        ofstream Rfile;
        Rfile.open("rented_s.txt");
        for (unsigned int l=0;l<RentsVector.size()-1;l++)
        {
            Rfile << RentsVector.at(l).GetID() << endl;
            Rfile << RentsVector.at(l).Getserial_number() << endl;
            Rfile << RentsVector.at(l).day << endl;
            Rfile << RentsVector.at(l).month << endl;
        }
        Rfile.close();
    }
    else if(choice=='v') //υπολογισμός χρέωσης πελάτη για παιχνίδια
    {
        cout<<"Type the serial number of the video game returned: "<<endl;
        cin>>sn;
        for (unsigned int i=0;i<RentsVector.size();i++)
        {
            if(RentsVector.at(i).Getserial_number()==sn)
            {
                er=i;
                r_day=RentsVector.at(i).day;
                r_month=RentsVector.at(i).month;
                cout<<"Type the day that the series is returned: "<<endl;
                cin>>day;
                cout<<"Type the month that the series is returned: "<<endl;
                cin>>month;
                calc_d=day-r_day;
                calc_d=abs(calc_d);
                calc_month=month-r_month;
                calc_month=abs(calc_month);
                for(unsigned int k=0;k<GamesVector.size();k++)
                {
                    if(sn==GamesVector.at(k).Getserial_number())
                    {
                        GamesVector.at(k).num_of_copies++;
                        break;
                    }
                }
                sum_days=calc_d + calc_month*30;
                if(sum_days<=2)
                {
                    cost=3;
                    if(VIP==true)
                        cost=cost-cost*(5/100);
                    cout<<"The client's cost is $"<< cost <<"."<<endl;
                }
                else if(sum_days>3)
                {
                    cost=3+(sum_days-3)*0.5;
                    if(VIP==true)
                        cost=cost-cost*(5/100);
                    cout<<"The client's cost is $"<< cost <<"."<<endl;
                }
            }

            break;
        }
        ofstream Vfile;
        Vfile.open("video_games.txt");
        for(unsigned int k=0;k<GamesVector.size()-1;k++)
        {
            Vfile << GamesVector[k].Gettitle()<<endl;
            Vfile << GamesVector[k].Gettype()<<endl;
            Vfile << GamesVector[k].Getconsole_name()<<endl;
            Vfile << GamesVector[k].GetID()<<endl;
            Vfile << GamesVector[k].Getserial_number()<<endl;
            Vfile << GamesVector[k].Getyear_pub()<<endl;
            Vfile << GamesVector[k].num_of_copies<<endl;
        }
        Vfile.close();
        RentsVector.erase(RentsVector.begin()+er);
        ofstream Rfile;
        Rfile.open("rented_vg.txt");
        for (unsigned int l=0;l<RentsVector.size()-1;l++)
        {
            Rfile << RentsVector.at(l).GetID() << endl;
            Rfile << RentsVector.at(l).Getserial_number() << endl;
            Rfile << RentsVector.at(l).day << endl;
            Rfile << RentsVector.at(l).month << endl;
        }
        Rfile.close();
    }
    return;
}

void rent_msvg(vector<movies>& MoviesVector,vector<series>& SeriesVector,vector<video_games>& GamesVector, vector<rent_info>& RentVector) //δανεισμός ενός προιόντος
{
    char choice;
    int id,i=0,m_ID,d,m,s_number,s_ID,vg_ID;
    bool found=false;
    cout<<"Press m to rent a movie, s to rent a series, v to rent a video game: "<<endl;
    cin>>choice;
    if(choice=='m') //δανεισμός ταινίας
    {
        load_rents(RentVector,choice);
        cout<<"Type the ID of the movie that the client is interested in: "<<endl;
        cin>>m_ID;
        cout<<"Type the client's ID :"<<endl;
        cin>>id;
        do
        {
            if (MoviesVector.at(i).GetID()==m_ID)//εύρεση της ταινίας
            {
                found=true;
                if(MoviesVector.at(i).num_of_copies>0) //αν υπάρχουν διαθέσιμα αντίγραφα ο δανεισμός επιτρέπεται
                {
                    MoviesVector.at(i).num_of_copies--;
                    ofstream Mfile;
                    Mfile.open("movies.txt");
                    for(unsigned int k=0;k<MoviesVector.size()-1;k++)
                    {
                        Mfile << MoviesVector[k].Gettitle()<<endl;
                        Mfile << MoviesVector[k].Gettype()<<endl;
                        Mfile << MoviesVector[k].Getdirector()<<endl;
                        Mfile << MoviesVector[k].Getactors()<<endl;
                        Mfile << MoviesVector[k].GetID()<<endl;
                        Mfile << MoviesVector[k].Getserial_number()<<endl;
                        Mfile << MoviesVector[k].Getpub_year()<<endl;
                        Mfile << MoviesVector[k].Getduration()<<endl;
                        Mfile << MoviesVector[k].num_of_copies<<endl;
                    }
                    Mfile.close();
                    cout<<"Type the day the movie is rented: "<<endl;
                    cin>>d;
                    cout<<"Type the month the movie is rented: "<<endl;
                    cin>>m;
                    s_number=MoviesVector.at(i).Getserial_number();

                    rent_info newRent;
                    newRent.day=d;
                    newRent.month=m;
                    newRent.SetID(id);
                    newRent.Setserial_number(s_number);
                    RentVector.push_back(newRent);
                    ofstream rent; //γράφεται στο τέλος του αρχείου με τους δανεισμούς ταινιών, ο καινούριος δανεισμός που πραγματοποιήθηκε
                    rent.open("rented_m.txt",ios::app);
                    rent << RentVector.at(RentVector.size()-1).GetID()<<endl;
                    rent << RentVector.at(RentVector.size()-1).Getserial_number()<<endl;
                    rent << RentVector.at(RentVector.size()-1).day<<endl;
                    rent << RentVector.at(RentVector.size()-1).month<<endl;
                    rent.close();
                }
                else
                    cout<<"Sorry no copies available!"<<endl;
            }
            i++;
        }
        while(found==false && i<RentVector.size() );
    }
    else if(choice=='s') //δανεισμός σειράς
    {
        load_rents(RentVector,choice);
        cout<<"Type the ID of the series that the client is interested in: "<<endl;
        cin>>s_ID;
        cout<<"Type the client's ID :"<<endl;
        cin>>id;
        do
        {
            if (SeriesVector.at(i).GetID()==s_ID)
            {
                found=true;
                if(SeriesVector.at(i).num_of_copies>0)
                {
                    SeriesVector.at(i).num_of_copies--;
                    ofstream Sfile;
                    Sfile.open("series.txt");
                    for(unsigned int k=0;k<SeriesVector.size()-1;k++)
                    {
                        Sfile << SeriesVector[k].Gettitle()<<endl;
                        Sfile << SeriesVector[k].Gettype()<<endl;
                        Sfile << SeriesVector[k].Getdirector()<<endl;
                        Sfile << SeriesVector[k].Getactors()<<endl;
                        Sfile << SeriesVector[k].GetID()<<endl;
                        Sfile << SeriesVector[k].Getserial_number()<<endl;
                        Sfile << SeriesVector[k].Getpub_year()<<endl;
                        Sfile << SeriesVector[k].Getseason()<<endl;
                        Sfile << SeriesVector[k].Getfirst_ep()<<endl;
                        Sfile << SeriesVector[k].Getfinal_ep()<<endl;
                        Sfile << SeriesVector[k].num_of_copies<<endl;
                    }
                    Sfile.close();
                    cout<<"Type the day the series is rented: "<<endl;
                    cin>>d;
                    cout<<"Type the month the series is rented: "<<endl;
                    cin>>m;
                    s_number=SeriesVector.at(i).Getserial_number();

                    rent_info newRent;
                    newRent.day=d;
                    newRent.month=m;
                    newRent.SetID(id);
                    newRent.Setserial_number(s_number);
                    RentVector.push_back(newRent);
                    ofstream rent;
                    rent.open("rented_s.txt",ios::app);

                    rent << RentVector.at(RentVector.size()-1).GetID()<<endl;
                    rent << RentVector.at(RentVector.size()-1).Getserial_number()<<endl;
                    rent << RentVector.at(RentVector.size()-1).day<<endl;
                    rent << RentVector.at(RentVector.size()-1).month<<endl;

                    rent.close();
                }
                else
                    cout<<"Sorry no copies available!"<<endl;
            }
            i++;
        }
        while(found==false && i<RentVector.size() );
    }
    else //δανεισμός παιχνιδιού
    {
        load_rents(RentVector,choice);
        cout<<"Type the ID of the video game that the client is interested in: "<<endl;
        cin>>vg_ID;
        cout<<"Type the client's ID :"<<endl;
        cin>>id;
        do
        {
            if (GamesVector.at(i).GetID()==vg_ID)
            {
                found=true;
                if(GamesVector.at(i).num_of_copies>0)
                {
                    GamesVector.at(i).num_of_copies--;
                    ofstream Gfile;
                    Gfile.open("video_games.txt");
                    for(unsigned k=0;k<GamesVector.size()-1;k++)
                    {
                        Gfile << GamesVector[k].Gettitle()<<endl;
                        Gfile << GamesVector[k].Gettype()<<endl;
                        Gfile << GamesVector[k].Getconsole_name()<<endl;
                        Gfile << GamesVector[k].GetID()<<endl;
                        Gfile << GamesVector[k].Getserial_number()<<endl;
                        Gfile << GamesVector[k].Getyear_pub()<<endl;
                        Gfile << GamesVector[k].num_of_copies<<endl;
                    }
                    Gfile.close();
                    cout<<"Type the day the video game is rented: "<<endl;
                    cin>>d;
                    cout<<"Type the month the video game is rented: "<<endl;
                    cin>>m;
                    s_number=GamesVector.at(i).Getserial_number();

                    rent_info newRent;
                    newRent.day=d;
                    newRent.month=m;
                    newRent.SetID(id);
                    newRent.Setserial_number(s_number);
                    RentVector.push_back(newRent);
                    ofstream rent;
                    rent.open("rented_vg.txt",ios::app);


                    rent << RentVector.at(RentVector.size()-1).GetID()<<endl;
                    rent << RentVector.at(RentVector.size()-1).Getserial_number()<<endl;
                    rent << RentVector.at(RentVector.size()-1).day<<endl;
                    rent << RentVector.at(RentVector.size()-1).month<<endl;

                    rent.close();
                }
                else
                    cout<<"Sorry no copies available!"<<endl;
            }
            i++;
        }
        while(found==false && i<RentVector.size() );
    }

}

void re_copies(vector<movies>& MoviesVector,vector<series>& SeriesVector,vector<video_games>& GamesVector) //εμφανίζει πόσα διαθέσιμα αντίγραφα υπάρχουν
{
    char choice;
    int id;
    string name;
    cout<<"Do you want to search a movie (m), a series (s) or a video game (v) ?"<<endl;
    cin>>choice;
    if(choice=='m')
    {
        cout<<"Do you want to search the movie by title (t) or ID (i) ?"<<endl;
        cin>>choice;
        if(choice=='i')
        {
            cout<<"Type the movie's ID: "<<endl;
            cin>>id;
            for (unsigned int i=0;i<=MoviesVector.size();i++)
            {
                if(MoviesVector.at(i).GetID()==id)
                {
                    cout<<"The remaining copies of the movie are: "<< MoviesVector.at(i).num_of_copies <<"."<<endl;
                    break;
                }
            }
        }
        else
        {
            cout<<"Type the movie's name: "<<endl;
            cin.ignore();
            getline(cin,name);
            for (unsigned int i=0;i<MoviesVector.size();i++)
            {
                if(name.compare(MoviesVector.at(i).Gettitle())==0)
                {
                    cout<<"The remaining copies of the movie are: "<< MoviesVector.at(i).num_of_copies <<"."<<endl;
                    break;
                }
            }

        }
    }
    else if (choice=='s')
    {
        cout<<"Do you want to search the series by title (t) or ID (i) ?"<<endl;
        cin>>choice;
        if(choice=='i')
        {
            cout<<"Type the series' ID: "<<endl;
            cin>>id;
            for (unsigned int i=0;i<=SeriesVector.size();i++)
            {
                if(SeriesVector.at(i).GetID()==id)
                {
                    cout<<"The remaining copies of the series are: "<< SeriesVector.at(i).num_of_copies <<"."<<endl;
                    break;
                }
            }
        }
        else
        {
            cout<<"Type the series' name: "<<endl;
            cin.ignore();
            getline(cin,name);
            for (unsigned int i=0;i<SeriesVector.size();i++)
            {
                if(name.compare(SeriesVector.at(i).Gettitle())==0)
                {
                    cout<<"The remaining copies of the series are: "<< SeriesVector.at(i).num_of_copies <<"."<<endl;
                    break;
                }
            }

        }
    }
    else if(choice=='v')
    {
        cout<<"Do you want to search the video game by title (t) or ID (i) ?"<<endl;
        cin>>choice;
        if(choice=='i')
        {
            cout<<"Type the game's ID: "<<endl;
            cin>>id;
            for (unsigned int i=0;i<=GamesVector.size();i++)
            {
                if(GamesVector.at(i).GetID()==id)
                {
                    cout<<"The remaining copies of the video game are: "<< GamesVector.at(i).num_of_copies <<"."<<endl;
                    break;
                }
            }
        }
        else
        {
            cout<<"Type the game's name: "<<endl;
            cin.ignore();
            getline(cin,name);
            for (unsigned int i=0;i<GamesVector.size();i++)
            {
                if(name.compare(GamesVector.at(i).Gettitle())==0)
                {
                    cout<<"The remaining copies of the movie are: "<< GamesVector.at(i).num_of_copies <<"."<<endl;
                    break;
                }
            }

        }
    }
    return;
}

void addClient(vector<client_info>& ClientsVector) //προσθήκη πελάτη
{
    int num_of_clients=0;
    client_info newClient;

    newClient.Setfirst_name();
    newClient.Setlast_name();
    newClient.Setclient_ID();
    newClient.Setgen();
    newClient.Setb_date();
    newClient.Setphone_number();
    newClient.Setaddress();
    ClientsVector.push_back(newClient);
    ofstream outCfile;
    outCfile.open("clients.txt",ios::app);
    outCfile << ClientsVector[ClientsVector.size()-1].Getfirst_name()<<endl;
    outCfile << ClientsVector[ClientsVector.size()-1].Getlast_name()<<endl;
    outCfile << ClientsVector[ClientsVector.size()-1].Getclient_ID()<<endl;
    outCfile << ClientsVector[ClientsVector.size()-1].Getb_day()<<endl;
    outCfile << ClientsVector[ClientsVector.size()-1].Getb_month()<<endl;
    outCfile << ClientsVector[ClientsVector.size()-1].Getb_year()<<endl;
    outCfile << ClientsVector[ClientsVector.size()-1].Getphone_number()<<endl;
    outCfile << ClientsVector[ClientsVector.size()-1].Getgen()<<endl;
    outCfile << ClientsVector[ClientsVector.size()-1].Getaddress()<<endl;
    outCfile.close();
    ifstream numberFile;
    numberFile.open("num_of_cl.txt");
    numberFile >> num_of_clients;
    num_of_clients++;
    numberFile.close();
    ofstream outnumberFile;
    outnumberFile.open("num_of_cl.txt");
    outnumberFile<<num_of_clients;
    outnumberFile.close();
    return;
}

void addVIP_client(vector<VIP_client_info>& VIPClientsVector) //προσθήκη VIP πελάτη
{
    int num_of_VIPclients=0;
    VIP_client_info newClient;

    newClient.Setfirst_name();
    newClient.Setlast_name();
    newClient.Setclient_ID();
    newClient.Setgen();
    newClient.Setb_date();
    newClient.Setphone_number();
    newClient.Setbank_name();
    newClient.Setcard_number();
    newClient.SetCVN();
    newClient.Setaddress();
    VIPClientsVector.push_back(newClient);
    ofstream outVCfile;
    outVCfile.open("VIP_clients.txt",ios::app);
    outVCfile << VIPClientsVector[VIPClientsVector.size()-1].Getfirst_name()<<endl;
    outVCfile << VIPClientsVector[VIPClientsVector.size()-1].Getlast_name()<<endl;
    outVCfile << VIPClientsVector[VIPClientsVector.size()-1].Getclient_ID()<<endl;
    outVCfile << VIPClientsVector[VIPClientsVector.size()-1].Getb_day()<<endl;
    outVCfile << VIPClientsVector[VIPClientsVector.size()-1].Getb_month()<<endl;
    outVCfile << VIPClientsVector[VIPClientsVector.size()-1].Getb_year()<<endl;
    outVCfile << VIPClientsVector[VIPClientsVector.size()-1].Getphone_number()<<endl;
    outVCfile << VIPClientsVector[VIPClientsVector.size()-1].Getgen()<<endl;
    outVCfile << VIPClientsVector[VIPClientsVector.size()-1].Getcard_number()<<endl;
    outVCfile << VIPClientsVector[VIPClientsVector.size()-1].GetCVN()<<endl;
    outVCfile << VIPClientsVector[VIPClientsVector.size()-1].Getbank_name()<<endl;
    outVCfile << VIPClientsVector[VIPClientsVector.size()-1].Getaddress()<<endl;
    outVCfile.close();
    ifstream numberFile;
    numberFile.open("number_of_VIP.txt");
    numberFile >> num_of_VIPclients;
    num_of_VIPclients++;
    numberFile.close();
    ofstream outnumberFile;
    outnumberFile.open("number_of_VIP.txt");
    outnumberFile<<num_of_VIPclients;
    outnumberFile.close();
    return;
}

void load_clients(vector<client_info>& ClientsVector,vector<VIP_client_info>& VIPClientsVector, int ap) //φόρτωση των πελατών στους vectors
{
    char choice='n';
    if(ap==4)
    {
        cout<<"Do you want to add a VIP client? (y/n)"<<endl;
        cin>> choice;
    }
    if (choice=='n' && (ap==4 || ap==5 || ap==6))
    {
        ifstream Cfile;
        Cfile.open("clients.txt");
        streampos current=Cfile.tellg();
        Cfile.seekg(0,Cfile.end);
        bool emptC=0;
        emptC= !Cfile.tellg();
        Cfile.close();
        ifstream cfile;
        cfile.open("clients.txt");
        if (emptC!=1)
        {
            while(!cfile.eof())
            {
                client_info newClient;
                int ID,day,month,year ,number;
                char gen;
                string fname;
                string lname;
                string ad;
                cfile  >> fname >> lname >> ID >> day >> month >> year >> number >> gen;
                char *name=new char[fname.size()+1]; //μετατροπή του string fname σε char* για να περαστεί στην Copy συνάρτηση
                copy(fname.begin(),fname.end(),name);
                name[fname.size()]='\0';
                newClient.Copyfirst_name(name);
                char *sname=new char[lname.size()+1]; //μετατροπή του string lname σε char* για να περαστεί στην Copy συνάρτηση
                copy(lname.begin(),lname.end(),sname);
                sname[lname.size()]='\0';
                cfile.ignore();
                getline(cfile,ad);
                newClient.Copylast_name(sname);
                newClient.Copyclient_ID(ID);
                newClient.Copyphone_number(number);
                newClient.Copyb_day(day);
                newClient.Copyb_month(month);
                newClient.Copyb_year(year);
                newClient.Copygen(gen);
                newClient.Copyaddress(ad);
                ClientsVector.push_back(newClient);
            }
            cfile.close();
        }
        if (ap==4)
            addClient(ClientsVector); //κλήση συνάρτησης προσθήκης πελάτη
    }

    if(choice=='y' || ap==5 || ap==6 || ap==8)
    {
        ifstream VCfile;
        VCfile.open("VIP_clients.txt");
        streampos current=VCfile.tellg();
        VCfile.seekg(0,VCfile.end);
        bool emptVC=0;
        emptVC= !VCfile.tellg();
        VCfile.close();
        ifstream Vfile;
        Vfile.open("VIP_clients.txt");
        if (emptVC!=1)
        {
            while(!Vfile.eof())
            {
                VIP_client_info newVClient;
                int ID,day,month,year ,number,c_number,CVN_number;
                char gen;
                string fname,lname,bank,ad;
                Vfile  >>fname >>lname >> ID >> day >>month>> year >> number >> gen >> c_number >> CVN_number >>bank;
                char *name=new char[fname.size()+1]; //μετατροπή του string fname σε char* για να περαστεί στην Copy συνάρτηση
                copy(fname.begin(),fname.end(),name);
                name[fname.size()]='\0';
                newVClient.Copyfirst_name(name);
                char *nname=new char[lname.size()+1]; //μετατροπή του string lname σε char* για να περαστεί στην Copy συνάρτηση
                copy(lname.begin(),lname.end(),nname);
                nname[lname.size()]='\0';
                Vfile.ignore();
                getline(Vfile,ad);
                newVClient.Copylast_name(nname);
                newVClient.Copyclient_ID(ID);
                newVClient.Copyphone_number(number);
                newVClient.Copyb_day(day);
                newVClient.Copyb_month(month);
                newVClient.Copyb_year(year);
                newVClient.Copygen(gen);
                newVClient.Copyaddress(ad);
                char *bname=new char[bank.size()+1];
                copy(bank.begin(),bank.end(),bname);
                bname[bank.size()]='\0';
                newVClient.Copybank_name(bname);
                newVClient.Copycard_number(c_number);
                newVClient.CopyCVN(CVN_number);

                VIPClientsVector.push_back(newVClient);
            }
            VCfile.close();
        }
        if (ap==4)
            addVIP_client(VIPClientsVector); //κλήση συνάρτησης προσθήκης VIP πελάτη
    }
}

void deleteClients(vector<client_info>& ClientsVector, vector<VIP_client_info>& VIPClientsVector) //διαγραφή πελατών
{
    char choice;
    int er;
    cout<<"Do you want to delete a VIP client? (y/n)"<<endl;
    cin>> choice;

    if (choice=='n')
    {
        unsigned int i=0,identity=0,n_of_clients;
        bool found=false;

        cout<<"Type the client's ID that you want to erase: "<<endl;
        cin>>identity;

        do
        {
            if(identity==ClientsVector.at(i).Getclient_ID())
            {
                found=true;
                er=i;
            }
            i++;
        }
        while (i<ClientsVector.size() && found==false);
        ClientsVector.erase(ClientsVector.begin()+er); //διαγραφή του πελάτη από τον vector
        ofstream outCfile;
        outCfile.open("clients.txt");
        for(i=0;i<ClientsVector.size()-1;i++) //γραφή του vector στο αντίστοιχο αρχείο χωρίς τον διαγραμμένο πελάτη
        {
            outCfile << ClientsVector.at(i).Getfirst_name()<<endl;
            outCfile << ClientsVector.at(i).Getlast_name()<<endl;
            outCfile << ClientsVector.at(i).Getclient_ID()<<endl;
            outCfile << ClientsVector.at(i).Getb_day()<<endl;
            outCfile << ClientsVector.at(i).Getb_month()<<endl;
            outCfile << ClientsVector.at(i).Getb_year()<<endl;
            outCfile << ClientsVector.at(i).Getphone_number()<<endl;
            outCfile << ClientsVector.at(i).Getgen()<<endl;
            outCfile << ClientsVector.at(i).Getaddress()<<endl;
        }
        outCfile.close();
        ifstream nfile;
        nfile.open("num_of_cl.txt");
        nfile >> n_of_clients;
        nfile.close();
        n_of_clients--;
        ofstream outnfile;
        outnfile.open("num_of_cl.txt");
        outnfile << n_of_clients;
        outnfile.close();
    }
    else
    {
         unsigned int i=0,identity=0,n_of_VIPs;
         bool found=false;

         cout<<"Type the VIP client's ID that you want to erase: "<<endl;
         cin>>identity;

         do
         {
             if(identity==VIPClientsVector.at(i).Getclient_ID())
             {
                 found=true;
                 er=i;
             }
             i++;
         }
         while (i<VIPClientsVector.size() && found==false);
         VIPClientsVector.erase(VIPClientsVector.begin()+er);//διαγραφή του πελάτη από τον vector
         ofstream outVCfile;
         outVCfile.open("VIP_clients.txt");
         for(i=0;i<VIPClientsVector.size()-1;i++)
         {
             outVCfile << VIPClientsVector.at(i).Getfirst_name()<<endl;
             outVCfile << VIPClientsVector.at(i).Getlast_name()<<endl;
             outVCfile << VIPClientsVector.at(i).Getclient_ID()<<endl;
             outVCfile << VIPClientsVector.at(i).Getb_day()<<endl;
             outVCfile << VIPClientsVector.at(i).Getb_month()<<endl;
             outVCfile << VIPClientsVector.at(i).Getb_year()<<endl;
             outVCfile << VIPClientsVector.at(i).Getphone_number()<<endl;
             outVCfile << VIPClientsVector.at(i).Getgen()<<endl;
             outVCfile << VIPClientsVector.at(i).Getcard_number()<<endl;
             outVCfile << VIPClientsVector.at(i).GetCVN()<<endl;
             outVCfile << VIPClientsVector.at(i).Getbank_name()<<endl;
             outVCfile << VIPClientsVector.at(i).Getaddress()<<endl;
         }
         outVCfile.close();
         ifstream nVfile;
         nVfile.open("num_of_VIP.txt");
         nVfile >> n_of_VIPs;
         nVfile.close();
         n_of_VIPs--;
         ofstream outnVfile;
         outnVfile.open("number_of_VIP.txt");
         outnVfile << n_of_VIPs;
         outnVfile.close();
    }
}

int c_modify_menu(char choice)
{
    int ap;
    cout<<"Press 1 to modify client's first name."<<endl;
    cout<<"Press 2 to modify client's last name."<<endl;
    cout<<"Press 3 to modify client's phone number."<<endl;
    cout<<"Press 4 to modify client's address."<<endl;
    if(choice=='y')
    {
        cout<<"Press 5 to modify client's bank name."<<endl;
        cout<<"Press 6 to modify client's CVN code."<<endl;
        cout<<"Press 7 to modify client's credit card number."<<endl;
    }
    cin>>ap;
    return ap;
}

void modifyClients(vector<client_info>& ClientsVector, vector<VIP_client_info>& VIPClientsVector) //τροποποίηση αντικειμένου στον vector
{
    char choice;
    int ap, identity,i=0;
    bool found=false;
    cout<<"Do you want to modify a VIP client? (y/n)"<<endl;
    cin>>choice;
    ap=c_modify_menu(choice);
    cout<<"Type the client's ID: "<<endl;
    cin>>identity;
    do
    {
        if(identity==ClientsVector.at(i).Getclient_ID() || identity==VIPClientsVector.at(i).Getclient_ID() )
        {
            found=true;
            if (ap==1)
            {
                char A[10];
                for(i=0;i<10;i++)
                    A[10]=' ';
                i=0;
                cout<<"Type the modified first name of the client: "<<endl;
                cin>>A;
                if(choice=='n')
                    ClientsVector.at(i).Copyfirst_name(A);
                else
                    VIPClientsVector.at(i).Copyfirst_name(A);
            }
            else
                if(ap==2)
                {
                    char B[10];
                    for(i=0;i<10;i++)
                        B[10]=' ';
                    i=0;
                    cout<<"Type the modified last name of the client: "<<endl;
                    cin>>B;
                    if(choice=='n')
                        ClientsVector.at(i).Copylast_name(B);
                    else
                        VIPClientsVector.at(i).Copylast_name(B);
                }
                else
                    if(ap==3)
                    {
                        int number;
                        cout<<"Type the modified phone number of the client: "<<endl;
                        cin>>number;
                        if(choice=='n')
                            ClientsVector.at(i).Copyphone_number(number);
                        else
                            VIPClientsVector.at(i).Copyphone_number(number);
                    }
                    else if(ap==4)
                    {
                        string ad;
                        cout<<"Type the modified address of the client: "<<endl;
                        cin.ignore();
                        getline(cin,ad);
                        if (choice=='n')
                            ClientsVector.at(i).Copyaddress(ad);
                        else
                            VIPClientsVector.at(i).Copyaddress(ad);
                    }
                    else
                        if(ap==5)
                        {
                            char C[10];
                            for(i=0;i<10;i++)
                                C[10]=' ';
                            i=0;
                            cout<<"Type the modified bank name of the client: "<<endl;
                            cin>>C;
                            VIPClientsVector.at(i).Copybank_name(C);
                        }
                        else
                            if(ap==6)
                            {
                                int number;
                                cout<<"Type the modified CVN code number of the client: "<<endl;
                                cin>>number;
                                VIPClientsVector.at(i).CopyCVN(number);
                            }
                            else if(ap==7)
                            {
                                int number;
                                cout<<"Type the modified credit card number of the client: "<<endl;
                                cin>>number;
                                VIPClientsVector.at(i).Copycard_number(number);
                            }
        }
        i++;
    }
    while (i<ClientsVector.size() && found==false);
    if(choice=='n') //γραφή του τροποποιημένου vector στο αντίστοιχο αρχείο
    {
        ofstream outCfile;
        outCfile.open("clients.txt");
        for(i=0;i<ClientsVector.size()-1;i++)
        {
            outCfile << ClientsVector.at(i).Getfirst_name()<<endl;
            outCfile << ClientsVector.at(i).Getlast_name()<<endl;
            outCfile << ClientsVector.at(i).Getclient_ID()<<endl;
            outCfile << ClientsVector.at(i).Getb_day()<<endl;
            outCfile << ClientsVector.at(i).Getb_month()<<endl;
            outCfile << ClientsVector.at(i).Getb_year()<<endl;
            outCfile << ClientsVector.at(i).Getphone_number()<<endl;
            outCfile << ClientsVector.at(i).Getgen()<<endl;
            outCfile << ClientsVector.at(i).Getaddress()<<endl;
        }
        outCfile.close();
    }
    else
    {
        ofstream outVCfile;
        outVCfile.open("VIP_clients.txt");
        for(i=0;i<VIPClientsVector.size()-1;i++)
        {
            outVCfile << VIPClientsVector.at(i).Getfirst_name()<<endl;
            outVCfile << VIPClientsVector.at(i).Getlast_name()<<endl;
            outVCfile << VIPClientsVector.at(i).Getclient_ID()<<endl;
            outVCfile << VIPClientsVector.at(i).Getb_day()<<endl;
            outVCfile << VIPClientsVector.at(i).Getb_month()<<endl;
            outVCfile << VIPClientsVector.at(i).Getb_year()<<endl;
            outVCfile << VIPClientsVector.at(i).Getphone_number()<<endl;
            outVCfile << VIPClientsVector.at(i).Getgen()<<endl;
            outVCfile << VIPClientsVector.at(i).Getcard_number()<<endl;
            outVCfile << VIPClientsVector.at(i).GetCVN()<<endl;
            outVCfile << VIPClientsVector.at(i).Getbank_name()<<endl;
            outVCfile << VIPClientsVector.at(i).Getaddress()<<endl;
        }
        outVCfile.close();
    }
}

int menu()
{
    int ap;
    do
    {
        cout<<"1. Add new movies, series or video games."<<endl;
        cout<<"2. Delete movies, series or video games."<<endl;
        cout<<"3. Modify information on movies,series or video games."<<endl;
        cout<<"4. Add new clients."<<endl;
        cout<<"5. Remove existing clients."<<endl;
        cout<<"6. Modify existing clients."<<endl;
        cout<<"7. Rent movies,series or video games."<<endl;
        cout<<"8. Return movies, series or video games."<<endl;
        cout<<"9. Search movies, series or video games."<<endl;
        cin>>ap;
    }
    while(ap<=0 || ap>9);
    return ap;
}

int main()
{
    int ap;
    char choice;
    vector<movies> MoviesVector;
    vector<series> SeriesVector;
    vector<video_games> GamesVector;
    vector<client_info> ClientsVector;
    vector<VIP_client_info> VIPClientsVector;
    vector<rent_info> RentVector;

    cout<<"Welcome to the Video Club. What do you wish to do?"<<endl<<endl;
    ap=menu();
    if (ap==1)
        load_msvg(MoviesVector,SeriesVector,GamesVector,ap);
    else
        if(ap==2)
        {
            cout<<"Press m if you want to delete a movie, s for series and v for video game: "<<endl;
            cin>>choice;
            if (choice=='m')
            {
                load_msvg(MoviesVector,SeriesVector,GamesVector,ap);
                deleteMovie(MoviesVector);
            }
            else
                if (choice=='s')
                {
                    load_msvg(MoviesVector,SeriesVector,GamesVector,ap);
                    deleteSeries(SeriesVector);
                }
                else
                {
                    load_msvg(MoviesVector,SeriesVector,GamesVector,ap);
                    deleteVGame(GamesVector);
                }

        }
        else
            if (ap==3)
            {
                cout<<"Press m if you want to modify a movie, s for series and v for video game: "<<endl;
                cin>>choice;
                if (choice=='m')
                {
                    load_msvg(MoviesVector,SeriesVector,GamesVector,ap);
                    modifyMovie(MoviesVector);
                }
                else
                    if(choice=='s')
                    {
                        load_msvg(MoviesVector,SeriesVector,GamesVector,ap);
                        modifySeries(SeriesVector);
                    }
                    else
                    {
                        load_msvg(MoviesVector,SeriesVector,GamesVector,ap);
                        modifyVGame(GamesVector);
                    }
            }
            else
                if (ap==4)
                    load_clients(ClientsVector,VIPClientsVector,ap);
                else
                    if (ap==5)
                    {
                        load_clients(ClientsVector,VIPClientsVector,ap);
                        deleteClients(ClientsVector,VIPClientsVector);
                    }
                    else
                        if(ap==6)
                        {
                            load_clients(ClientsVector,VIPClientsVector,ap);
                            modifyClients(ClientsVector,VIPClientsVector);
                        }
                        else
                            if(ap==7)
                            {
                                load_msvg(MoviesVector,SeriesVector,GamesVector,ap);
                                rent_msvg(MoviesVector,SeriesVector,GamesVector,RentVector);
                            }
                            else
                                if(ap==8)
                                {
                                    cout<<"Press m to return a movie,s to return a series or v to return a video game."<<endl;
                                    cin>>choice;
                                    load_rents(RentVector,choice);
                                    load_clients(ClientsVector,VIPClientsVector,ap);
                                    load_msvg(MoviesVector,SeriesVector,GamesVector,ap);
                                    calc_cost(RentVector,VIPClientsVector,MoviesVector,SeriesVector,GamesVector,choice);
                                }
                                else if(ap==9)
                                {
                                    load_msvg(MoviesVector,SeriesVector,GamesVector,ap);
                                    re_copies(MoviesVector,SeriesVector,GamesVector);
                                }
    return 0;
}
