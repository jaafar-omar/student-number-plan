#include "project2.h"
using namespace std;

int main() {
    string arrString[6];
    ifstream readFile;
    CPStudentPlan studPlan;
    string readline;
    size_t found;
    char action = ' ';
    int idNumber;
    string lastName, firstName, address, birthDate;
    readFile.open(TEXT_INPUT);

    if(readFile.is_open()) {
        while(getline(readFile, readline)) {
            int i = 0;
            string line;
            stringstream ssLine(readline);
            while(getline(ssLine, line, ':')) {
                arrString[i++] = line;
            }

            found = arrString[0].find("apply");
            if(found != string::npos) {
                action = 'a';
                string toInt = arrString[1];
                toInt.erase(0, toInt.find_first_not_of('0'));
                idNumber = stoi(toInt);
                lastName = arrString[2];
                firstName = arrString[3];
                address = arrString[4];
                birthDate = arrString[5];
            }

            found = arrString[0].find("lineup");
            if(found != string::npos) {
                action = 'l';
                idNumber = stoi(arrString[1]);
            }

            found = arrString[0].find("serve");
            if(found != string::npos) {
                action = 's';
            }

            switch(action) {
                case 'a':
                    studPlan.apply(idNumber, lastName, firstName, address, birthDate);
                    break;

                case 'l':
                    studPlan.lineup(idNumber);
                    break;

                case 's':
                    studPlan.serve();
                    break;
            }
        }
    }

    return 0;
}
