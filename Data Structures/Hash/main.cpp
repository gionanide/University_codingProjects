#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <time.h>
#include <limits.h>
#include <Hash_table.h>
#include <SortedChain.h>
#include <SortedChainNode.h>
#include <minHeap.h>

using namespace std;

int findn(char A[10],int j) 
{
    if(A[j]=='0') return 0;
    if(A[j]=='1') return 1;
    if(A[j]=='2') return 2;
    if(A[j]=='3') return 3;
    if(A[j]=='4') return 4;
    if(A[j]=='5') return 5;
    if(A[j]=='6') return 6;
    if(A[j]=='7') return 7;
    if(A[j]=='8') return 8;
    if(A[j]=='9') return 9;
}

int *find_V(int *V_table, Hash_table &table, int &sizeof_V) 
{
    int i=0,j=0,last_f=0;
    sizeof_V=0;
    for (i=0;i<100000;i++)
    {
        if(table.empt[i]==false)
        {
            sizeof_V++;
            last_f=i;
        }
    }
    V_table=new int[sizeof_V-1];
    for(i=0;i<=last_f;i++)
    {
        if(table.empt[i]==false)
        {
            V_table[j]=i;
            j++;
        }
    }
    return V_table;
}

void printMST(int prev[],Hash_table &table,int *V_table,int sizeof_V,int key[],int diff) {
    int sum=0; 

    for(int i=1;i<sizeof_V;i++)
    {
        sum+=key[i];
    }
    ofstream fpo;
    fpo.open("output.txt",ios::app);
    if(!fpo)
    {
        cerr<<"Could not open output file."<<endl;
        return;
    }
    fpo<<"MST cost is: "<<sum<<endl;
    fpo<<"Execution time of MST cost calculation (in seconds) is: "<<diff/CLOCKS_PER_SEC<<endl;     fpo.close();
}

void prim_MST(int *V_table,int sizeof_V, Hash_table table) 
{
    int color[sizeof_V]; //-1=WHITE, 0=GRAY, 1=BLACK
    int key[sizeof_V];
    int prev[sizeof_V];
    int i,j,k,u;
    clock_t clk1;
    clock_t clk2;

    clk1=clock();

    for(i=0;i<sizeof_V;i++)
    {
        color[i]=-1;
        key[i]=INT_MAX;
        prev[i]=NULL;
    }

    minHeap Q;
    color[0]=0;
    Q.insert_e(table.h_array[V_table[0]].Getf_data());
    key[0]=0;
    while(Q.Getcurr_size()!=0)
    {
        u=Q.extractMin();

        for(j=0;j<sizeof_V;j++)
        {
            if (u==table.h_array[V_table[j]].Getf_data())             {
                k=j;
                break;
            }
        }
        SortedChainNode *p=table.h_array[V_table[k]].first;

        while(p!=NULL)
        {
            for(j=0;j<sizeof_V;j++) //για κάθε γείτονα της u
            {
                if (p->Get_data()==table.h_array[V_table[j]].Getf_data())
                    break;
            }
            if (color[j]==-1) //j=κορυφή γείτονας της u
            {
                color[j]=0;
                Q.insert_e(table.h_array[V_table[j]].Getf_data());
                key[j]=p->Get_key();
                prev[j]=u;
            }
            else
                if (key[j]>p->Get_key())
                {
                    key[j]=p->Get_key();
                    prev[j]=u;
                }
            color[k]=1;
            p=p->link;
        }
    }

    clk2=clock();
    float diff;
    diff=(float)clk2-(float)clk1; 
    printMST(prev,table,V_table,sizeof_V, key,diff);
}

void insert_link(vector<string>& IO_V,int sum1,int sum2, int sum3, Hash_table &table, SortedChain &chain) 
{                                                                                                         //vector αλλά και των νέων links από τις εντολές INSERT_LINK
    unsigned int i=0;
    string result1;
    string result2;
    string result3;
    string line;
    int pos=0;

    chain.Setf_data(sum1);
    pos=table.insert_e(chain);
    table.h_array[pos].insert_chainLink(sum2,sum3);
    chain.Setf_data(sum2);
    pos=table.insert_e(chain);
    table.h_array[pos].insert_chainLink(sum1,sum3);

        ostringstream convert1;
    convert1 << sum1;
    result1=convert1.str();

    ostringstream convert2;
    convert2 << sum2;
    result2=convert2.str();

    ostringstream convert3;
    convert3 << sum3;
    result3=convert3.str();

    line=result1 + '\t' + result2 + '\t' + result3;

    IO_V.push_back(line);
    ofstream fpout; INSERT_LINK
    fpout.open("input.txt");
    for (i=0;i<IO_V.size();i++)
        fpout << IO_V.at(i) << endl;

    fpout.close();
}

void delete_link(vector<string>& IO_V,long int sum1,long int sum2, Hash_table &table{                                                                                   insert_link()
    string result1;
    string result2;
    string f_num;
    string s_num;
    int i=0,j=0;
    bool found1=false, found2=false;
    int pos=0;

    SortedChain chain;

    chain.Setf_data(sum1);
    pos=table.insert_e(chain    table.h_array[pos].Delete(sum2);

    chain.Setf_data(sum2);
    pos=table.insert_e(chain);
    table.h_array[pos].Delete(sum1);

    //διαχείρηση αρχείου
    ostringstream convert1;
    convert1 << sum1;
    result1=convert1.str();

    ostringstream convert2;
    convert2 << sum2;
    result2=convert2.str();

    do     {
        while(IO_V.at(i)[j]!='\t')
        {
            f_num=f_num+IO_V.at(i)[j];
            j++;
        }

        if (result1.compare(f_num)==0)
        {
            found1=true;
            j++;
            while(IO_V.at(i)[j]!='\t')
            {
                s_num=s_num+IO_V.at(i)[j];
                j++;
            }

            if (result2.compare(s_num)==0)
                found2=true;
        }
        f_num.clear();
        s_num.clear();
        j=0;
        i++;
    }
    while(found1==false || found2==false);
    i--;
    IO_V.erase(IO_V.begin()+i);
    ofstream fp;
    fp.open("input.txt");

    for (i=0;i<IO_V.size();i++)
        fp << IO_V.at(i) << endl;
    fp.close();
}

void load_vector(vector<string>& IO_V, Hash_table &table, SortedChain &chain) {
    string line;
    int sum1=0,sum2=0,sum3=0;
    char A[10];
    int i=0,j=0,ps=1,n=0;

    ifstream fpin ("input.txt");//διαβάζω το input file.
    cout<<"Reading Data complete."<<endl;
    if (fpin.is_open())
    {
        cout <<"Input file is open."<<endl;
        while (getline(fpin,line))
        {
            for(i=0;i<10;i++)
                A[i]='0';
            i=0;
            while(line[j]!='\t')
            {
                A[j]=line[i];
                i++;
                j++;
            }
            j--;
            i++;
            do
            {
                n=findn(A,j);
                sum1=sum1+(n*ps);
                ps=ps*10;
                j--;
            }
            while(j>=0);

            n=0;
            ps=1;
            for(j=0;j<10;j++)
                A[j]='0';
            j=0;
            while(line[i]!='\t')
            {
                A[j]=line[i];
                i++;
                j++;
            }
            j--;
            i++;
            do
            {
                n=findn(A,j);
                sum2=sum2+(n*ps);
                ps=ps*10;
                j--;
            }
            while(j>=0);

            n=0;
            ps=1;
            for(j=0;j<10;j++)
                A[j]='0';
            j=0;
            while(line[i]!='\0')
            {
                A[j]=line[i];
                i++;
                j++;
            }
            j--;
            do
            {
                n=findn(A,j);
                sum3=sum3+(n*ps);
                ps=ps*10;
                j--;
            }
            while(j>=0);
            insert_link(IO_V, sum1, sum2, sum3, table, chain);
            sum1=sum2=sum3=n=j=i=0;
            ps=1;
        }
        fpin.close();
    }
}

void NCN(int x,int y, Hash_table &table,int *V_table, int sizeof_V) 
{
    int amount_of_adj=0, i, pos1=0, pos2=0;
    bool f1=false, f2=false;

    for(i=0;i<sizeof_V;i++)     {
        if(x==table.h_array[V_table[i]].Getf_data() && f1==false)
        {
            pos1=V_table[i];
            f1=true;
        }

        if(y==table.h_array[V_table[i]].Getf_data() && f2==false)
        {
            pos2=V_table[i];
            f2=true;
        }

        if(f1==true && f2==true) break;
    }
    SortedChainNode *p1=table.h_array[pos1].first;
    SortedChainNode *p2=table.h_array[pos2].first;

    while(p1!=NULL)     {
        while(p2!=NULL)
        {
            if(p1->Get_data()==p2->Get_data())
            {
                amount_of_adj++; //πλήθος κοινών γειτόνων
                break;
            }
            p2=p2->link;
        }
        p2=table.h_array[pos2].first;
        p1=p1->link;
    }

    ofstream fpo;
    fpo.open("output.txt",ios::app); 
    if(!fpo)
    {
        cerr<<"Could not open output file."<<endl;
        return;
    }
    fpo << "The amount of the mutual adjacent nodes between "<<x<<" and "<<y<<" is: "<<amount_of_adj<<endl;
    fpo.close();

}

void f_management(Hash_table &table, SortedChain &chain, int *V_table, int sizeof_V) 
{                                                                                    //ανάλογα με τις εντολές του commands.txt
    char A[10]; 
    vector<string> IO_V
    int i=12,k=0,j=0,n=0,h=0,m=0,old_i=0;
    long int sum1=0,sum2=0,sum3=0,ps=1;
    string command;
    ifstream fpcom ("commands.txt");

    if (fpcom.is_open())
    {
        cout<<"Commands file is open."<<endl;

        while(getline(fpcom,command))
        {
            if(command[0]=='R') //αντιστοιχεί στην εντολή READ_DATA
            {
              load_vector(IO_V,table,chain);               V_table=find_V(V_table,table,sizeof_V);             }
            else
                if (command[0]=='I' || command[0]=='D')                 {                                       
                    i=12;
                    ps=1;
                    for(j=0;j<10;j++)
                        A[j]='0';
                    j=0;
                    do
                    {
                        if(command[i+k]!=' ')
                            k++;
                    }
                    while(command[i+k]!=' ');
                    while(command[i]!=' ')
                    {
                        A[j]=command[i];
                        i++;
                        j++;
                    }
                    j--;
                    i=14+j;
                    do
                    {
                        n=findn(A,j);
                        sum1=sum1+(n*ps);
                        ps=ps*10;
                        j--;
                    }
                    while(j>=0);

                    old_i=i+1;
                    j=0;
                    for(h=0;h<10;h++)
                        A[h]='0';
                    while(command[i]!=' ')
                    {
                        A[j]=command[i];
                        i++;
                        j++;
                    }
                    ps=1;
                    old_i=old_i+j;
                    j--;
                    n=0;
                    do
                    {
                        n=findn(A,j);
                        sum2=sum2+(n*ps);
                        ps=ps*10;
                        j--;
                    }
                    while(j>=0);

                    i=old_i;
                    j=0;
                    for(m=0;m<10;m++)
                        A[m]='0';
                    while(command[i]!='\0')
                    {
                        A[j]=command[i];
                        i++;
                        j++;
                    }
                    ps=1;
                    j--;
                    n=0;
                    do
                    {
                        n=findn(A,j);
                        sum3=sum3+(n*ps);
                        ps=ps*10;
                        j--;
                    }
                    while(j>=0);


                    ps=1;
                    i=12;
                    k=j=n=0;
                    if (command[0]=='I                    {
                        cout<<"Inserting link: "<<sum1<<" "<<sum2<<endl;
                        insert_link(IO_V,sum1,sum2,sum3, table, chain);                        V_table=find_V(V_table,table,sizeof_V);
                    }
                    else //υλοποιεί την DELELE_LINK
                    {
                        cout<<"Deleting link: "<<sum1<<" "<<sum2<<endl;
                        delete_link(IO_V, sum1, sum2, table);
                        V_table=find_V(V_table,table,sizeof_V);
                    }
                    sum1=sum2=sum3=0;
                }
                else if (command[0]=='N') 
                {                                             i=4;
                    ps=1;
                    for(j=0;j<10;j++)
                        A[j]='0';
                    j=0;
                    do
                    {
                        if(command[i+k]!=' ')
                            k++;
                    }
                    while(command[i+k]!=' ');
                    while(command[i]!=' ')
                    {
                        A[j]=command[i];
                        i++;
                        j++;
                    }
                    j--;
                    i++;
                    do
                    {
                        n=findn(A,j);
                        sum1=sum1+(n*ps);
                        ps=ps*10;
                        j--;
                    }
                    while(j>=0);


                    j=0;
                    for(h=0;h<10;h++)
                        A[h]='0';
                    while(command[i]!='\0')
                    {
                        A[j]=command[i];
                        i++;
                        j++;
                    }
                    ps=1;
                    j--;
                    n=0;
                    do
                    {
                        n=findn(A,j);
                        sum2=sum2+(n*ps);
                        ps=ps*10;
                        j--;
                    }
                    while(j>=0);

                    cout<<"Calculating amount of common nodes between: "<<sum1<<" "<<sum2<<endl;
                    NCN(sum1,sum2,table,V_table,sizeof_V);
                    ps=1;
                    i=4;
                    k=j=n=m=0;
                    sum1=sum2=sum3=0;
                    cout<<"NCN function completed."<<endl;
                }
                else if (command[0]=='M')                 {
                    cout<<"Calculating MST."<<endl;
                    prim_MST(V_table, sizeof_V, table);//συναρτηση prim_MST
                    cout<<"MST cost calculated."<<endl;
                }
        }
        IO_V.clear();
        delete[] V_table;
        table.~Hash_table();
        chain.~SortedChain();
    }
    fpcom.close();
    return;
}

int main()
{
    Hash_table table; 
    SortedChain chain; 
    int *V_table, sizeof_V=0; 
    f_management(table,chain,V_table,sizeof_V);     cout<<"Exiting program."<<endl;
    return 0;
}
