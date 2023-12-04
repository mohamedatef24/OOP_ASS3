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
    LabelGenerator(string Name,int Count=0) {
        name = Name;
        count = Count;
    }
    string nextLabel(){
        return name+to_string(count++);
    }
};

int main() {
    LabelGenerator figureNumbers("Figure ", 1);
    LabelGenerator pointNumbers("P", 0);
    cout << "Figure numbers: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }
    cout << endl << "Point numbers: ";
    for (int i = 0; i < 5; i++) {
        cout << pointNumbers.nextLabel() << ", ";
    }
    cout<<endl;
    return 0;
}
