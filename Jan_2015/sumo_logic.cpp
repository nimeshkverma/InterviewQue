#include <iostream>
#include <algorithm>
#include <strings>
#include <time.h>
#include <map>

using namespace std;      


class Solution {

private:
  map<string,string> travel_map;
  int count = 0;

public:
  int getTime(){
    return count++;
  }

  void put(string person, string place){
    travel_map[person + to_string(getTime) ] = place;
  }


  string get(string person, int t){
    if ( travel_map.find(person + to_string(t)) == travel_map.end() ) {
      return travel_map.at(person + to_string(t));
    } 
    else {
      return NULL
    }
  }


    
};

int main(){
  Solution s1;
  s1.put('vipul','sumo');
  s1.put('vipul','logic');
  s1.put('anuj','noida');
  
  cout<< s1.get('vipul',0); << "  " << s1.get('vipul',1); << "  " << s1.get('vipul',100); << "  " << s1.get('anuj',2); << "  "<< s1.get('anuj',3); << "  ";

  return 0;
}