#include "Harris.h"
#include "Blob.h"
#include "DoG.h"

#include "SiftHarris.h"
#include "SiftDoG.h"
#include "SiftBlob.h"

#include "LbpHarris.h"
#include "LbpBlob.h"
#include "LbpDoG.h"

#include "StringHelper.h"
#include <fstream>


void cryForHelp();

int main(int argc, char* argv[])
{
    cout << "\'h\' for help" << endl;

    while (true) {
        String cmd;
        getline(cin, cmd);
        if (cmd == "h") {
            cryForHelp();
        }
        else if (cmd == "end") {
            break;
        }
        else {

            vector<String> args = split(cmd);

            if (args[0] == "harris") {
                String fileName = "";
                if (args.size() > 1) {
                    fileName = args[1];
                }
                cout << fileName;
                performHarris(fileName);
            }
            else if (args[0] == "blob") {
                String fileName = "";
                if (args.size() > 1) {
                    fileName = args[1];
                }
                performBlob(fileName);
            }
            else if (args[0] == "dog") {
                String fileName = "";
                if (args.size() > 1) {
                    fileName = args[1];
                }
                performDoG(fileName);
            }
            else if (args[0] == "m" && args.size() >= 4) {
                String fileName1 = args[3];
                String fileName2 = "";
                if (args.size() == 5) {
                    fileName2 = args[4];
                }

                if (args[1] == "harris" && args[2] == "sift") {
                    harrisDetectorWithSiftDescriptor(fileName1, fileName2);
                }

                if (args[1] == "blob" && args[2] == "sift") {
                    blobDetectorWithSiftDescriptor(fileName1, fileName2);
                }

                if (args[1] == "dog" && args[2] == "sift") {
                    DoGdetectorWithSiftDescriptor(fileName1, fileName2);
                }

                if (args[1] == "harris" && args[2] == "lbp") {
                    harrisDetectorWithLbpDescriptor(fileName1, fileName2);
                }

                if (args[1] == "blob" && args[2] == "lbp") {
                    blobDetectorWithLbpDescriptor(fileName1, fileName2);
                }

                if (args[1] == "dog" && args[2] == "lbp") {
                    DoGdetectorWithLbpDescriptor(fileName1, fileName2);
                }
            }
            else {
                cout << "\'" << cmd << "\'" << " command not found" << endl;
                cout << "\'h\' for help" << endl;
                cout << "or \'end\' to exit" << endl;
            }
        }
    }

    return 0;
}

void cryForHelp() {
    ifstream fin("help.txt");
    string myText;
    cout << endl;
    while (getline(fin, myText)) {
        cout << myText << endl;
    }
    cout << endl;
    fin.close();
}