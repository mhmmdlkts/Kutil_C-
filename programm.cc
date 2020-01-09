#include "teil.h"
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    //char *geordnetPath = "geordnet.dat";
    char *teilPath = /*"teil.dat"*/argv[1];
    char *schrittPath = /*"schritt.dat"*/argv[2];

    TeilList tl (teilPath);

    return 0;
}
