#include <iostream>
#include <string>

using namespace std;

struct collection {
    int count;
    string name;

    collection(int c, string n):count(c), name(n){}
    ~collection(){}

    void operator +=(collection& cl)
    {
        this->count += cl.count;
        this->name += (" " + cl.name);
    }
};

ostream& operator<<(ostream &c, collection &cl)
{
    c << "count "<< cl.count << endl;
    c << "name  "<< cl.name << endl;
    return c;
}

collection& operator +(collection& cla, collection& clb)
{
    collection* clc = new collection(0, "");

    clc->count = cla.count + clb.count;
    clc->name = cla.name + " " + clb.name;

    return *clc;
}

int main(int argc, const char* argv[])
{
    collection* cla = new collection(100, "students");
    collection* clb = new collection(20 , "teachers");

    cout << *cla << *clb;

    *cla += *clb; 

    cout << *cla;

    collection clc = *cla + *clb;

    cout << clc;

    return 0;
}
