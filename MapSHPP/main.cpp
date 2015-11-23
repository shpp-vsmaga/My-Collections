#include <iostream>
#include "mapshpp.h"
#include <string>

using namespace std;
int main(){
    MapSHPP<int, string> map;
    map.put(1, "Vlad");
    map.put(2, "SV");
    map.put(3, "Ser");

    for(int i = 0; i < map.size(); i++){
        cout << map.getKey(i) << " - " << map.get(map.getKey(i)) << endl;
    }


}
