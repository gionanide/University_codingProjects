#include "help.h"

class HelpData : public QSharedData
{
public:
String s;
ofstream myoffile;

};


Help::Help() : data(new HelpData)
{
s="xzyphs";
myfile.open ("example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();
}

Help::Help(const Help &rhs) : data(rhs.data)
{

}

Help &Help::operator=(const Help &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Help::~Help()
{

}
