#include <iostream>
#include "mapshpp.h"
#include <string>

using namespace std;
int main(){
    MapSHPP<int, string> map;
    map.put(1, "Vlad");
    map.put(2, "SV");
    map.put(3, "Ser");

    cout << map[1] << endl;
    cout << map[3] << endl;
    cout << map[2] << endl;

    map[1] = "Olya";

    cout << map[1] << endl;
    return 0;
}
