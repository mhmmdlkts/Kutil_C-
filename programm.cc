#include "teil.h"
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    string geordnetPath = "geordnet.dat";
    char *teilPath = /*"teil.dat"*/argv[1];
    char *schrittPath = /*"schritt.dat"*/argv[2];

    TeilList tl (teilPath, schrittPath);
    TeilList sorted_tl = tl.getSorted();
    //cout << tl<<"\n\n\n";
    
    
    ofstream out(geordnetPath);
    out << sorted_tl;
    out.close();
 
    return 0;
}
