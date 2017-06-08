#include "ClassInvertedIndex.h"
#include <iostream>

using namespace std;

int main()
{

    char a[30],b[30];
    ifstream f,d;
    int x,y;
    bool k = false;
    ClassInvertedIndex cii;


    f.open("commands.txt");
    if (!f)
    {
        cout<<"could not open file"<<endl;
        return 1;
    }
    f>>a>>b;

    d.open(a)
    if(!d)
    {
        cout<<"Could not open the file"<<endl;
        return 1;
    }

    while(!d.eof())
    {
        f>>x>>y;
        root = cii.insert_x_y_intoTheTree(x,y,root);
    }
    d.close();
    while(!k){
        f>>b;
        if (strcmp(b,"INSERT_LINK")==0)
        {
            f>>x>>y;
            cii.insert_x_y_intoTheTree(x,y,root);
        }
        else if (strcmp(b,"DELETE_LINK")==0)
        {
            f>>x>>y;
            cii.delete_x_value(x,y,root);
        }
        else
        {

            f>>a;
            k = true;
            out.open(a,ios::in);
            cii.writeIndex(root);
        }
    }
    f.close();
}
