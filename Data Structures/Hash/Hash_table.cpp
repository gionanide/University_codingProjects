#include "Hash_table.h"

Hash_table::Hash_table() //ctor
{
    d=100001;
    for (unsigned int i=0; i<d; i++)
        empt[i]=true;
}

Hash_table::~Hash_table() //dtor
{
    delete[] h_array;
    delete[] empt;
}

int Hash_table::search_table(int a)
{
    int i= a%d;
    int j=i,found=-1;

    do
    {
        if(empt[j] || h_array[j].f_data == a)
        {
            found=j;
            return found;
        }
        j=(j+1)%d;
    }
    while(j!= i);
    return j;
}

int Hash_table::insert_e(SortedChain e)
{
    int f=search_table(e.f_data);

    if (empt[f])
    {
        empt[f]=false;
        h_array[f].f_data=e.f_data;
        h_array[f].first=e.first;
        return f;
    }
    if (h_array[f].f_data == e.f_data)
        cout<<"Element already in hash table."<<endl;
    return f;
}
