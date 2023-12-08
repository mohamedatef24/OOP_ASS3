// File name: A3_Sheet2Pb1_20220282.cpp
// Purpose: Problem (NUMBER)--> Label Generator , Creates a series of names to label files in a sequential pattern or uses the names existing in a file on the device.  
// Author(s): Mohamed Islam Khaled
// ID(s): 20220282
// Section: S24
// Date:7/12/2023
//TA: Eng. Mohammed talaat

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
class LabelGenerator{
protected:
string name;
int count;

public:
    LabelGenerator():name(""),count(0){}
    LabelGenerator(string Name,int Count=0) {
        name = Name;
        count = Count;
    }


    string nextLabel(){
        return name+to_string(count++);
    }
};

class FileLabelGenerator :public LabelGenerator{

    string fname;
    vector<string>files;
    int i=0;
public:
    FileLabelGenerator():LabelGenerator(),fname(""){}
    FileLabelGenerator(string Name,int Count,string Fname) {
        name = Name;
        count = Count;
        fname = Fname;
    }

    void readfile(){
        ifstream Fin(fname);
        string filename;
        if(Fin.fail()){
            cout<<"This File Does Not Exist!";
            return;
        }
        while (getline(Fin,filename)) {
            files.push_back(filename);
        }
    }
    string nextLabel()
    {
        if(!files.empty()&&i+1>files.size()) return name+to_string(count++)+" "+".........";
        if(!files.empty()) return name+to_string(count++)+" "+files[i++];
    }




};

int main() {
    LabelGenerator figureNumbers("Figure ", 1);
    LabelGenerator pointNumbers("P", 0);
    cout << "Figure numbers: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", "[1+i==3];
    }
    cout << endl << "Point numbers: ";
    for (int i = 0; i < 5; i++) {
        cout << pointNumbers.nextLabel() << ", "[1+i==5];
    }
    cout<<endl;
    FileLabelGenerator figureLabels ("Figure ", 1, "labels.txt");
    figureLabels.readfile();
    cout <<endl<< "Figure labels: \n";
    for (int i = 0; i < 3; i++)
        cout << figureLabels.nextLabel() << '.'<<endl;
    return 0;
}
