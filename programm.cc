#include "teil.h"
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    string geordnetPath = "geordnet.dat";
    char *teilPath = argv[1];
    char *schrittPath = argv[2];

    TeilList tl (teilPath);

    return 0;
}

