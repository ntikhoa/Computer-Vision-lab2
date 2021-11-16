#include "Harris.h"
#include "Blob.h"
#include "DoG.h"
#include "SiftDescriptor.h"
#include "SiftHarris.h"
#include "SiftDoG.h"
#include "SiftBlob.h"
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
            /*
            cout << "\'" << cmd << "\'" << " command not found" << endl;
            cout << "\'h\' for help" << endl;
            cout << "or \'end\' to exit" << endl;
            */
            vector<String> arg = split(cmd);
            cout << arg.size() << endl;
            for (int i = 0; i < arg.size(); i++) {
                cout << arg[i] << endl;
            }
        }
    }

    //performHarris("headpat_rem.jpg");
    //performHarris("");
    //performDoG("headpat_rem.jpg");
    //performDoG("");
    //performBlob("headpat_rem.jpg");
    //performBlob("");

    //harrisDetectorWithSiftDescriptor("text_in_scene.jpg", "headpat_rem.jpg");
    //DoGdetectorWithSiftDescriptor("text_in_scene.jpg", "headpat_rem.jpg");
    //blobDetectorWithSiftDescriptor("headpat_rem_croped.jpg", "headpat_rem.jpg");
    
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