/*Build Tower by the following given argument :
number of floors(integerand always greater than 0).

Tower block is represented as*
C++: returns a vector<string>;

for example, a tower of 3 floors looks like below
[
  '  *  ',
  ' *** ',
  '*****'
]
*/
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::endl;
using std::cout;

vector<string> towerBuilder(int nFloors) {
    int width = (nFloors * 2) - 1; //the first floor of tower(width of field)
    int pos = 0, count = 1;
    bool mark = false;
    vector<string> tower;
    for (int i = 0, stars = 1; i < nFloors; i++, stars += 2) {
        tower.push_back("");
        pos = (width - stars) / 2; //position for placing stars
        count = stars;
        for (int j = 0; j < width; j++) {
            if (j == pos)
                mark = true;
            if (mark && count) {
                tower[i] += "*";
                count--;
                continue;
            }
            tower[i] += " ";
        }
        mark = false;
    }
    return tower;
}

int main() {
    vector<string> tower;
    tower = towerBuilder(6);
    for (int i = 0;i < tower.size();i++)
        cout << tower[i] << endl;
}