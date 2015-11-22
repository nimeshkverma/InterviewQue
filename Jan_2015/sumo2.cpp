#include <iostream>
#include <algorithm>
#include <string>
#include <time.h>
#include <map>
#include <vector>
using namespace std;      


class Solution {

private:
  
  
  int count;

  struct visit {
    string place;
    int time;
  };

  map<string, vector<visit> > travel_map;

public:
  int getTime(){
    return count++;
  }

  void put(string person, string place){
    visit v;
    v.place = place;
    v.time = getTime();
    travel_map[person].push_back(v);

  }


  string get(string person, int t){
    if ( travel_map.find(person) != travel_map.end() ) {

      int min =-1, max =0;
      for (int i =0;i<travel_map[person].size();i++){
        if(travel_map[person][i].time <= t){
          min++;
          max++;
        }
        else{
          break;

        if((min == -1)&&(travel_map[person][0].time == t))
          return travel_map[person][0].place;

        if((min == -1)&&(travel_map[person][0].time != t))
          return NULL;

        return travel_map[person][min].place;    
      } 
    }
  }
    else 
      return NULL;
  
}

  Solution(){
    count = 0;
  }
};

int main(){
  Solution s1;
  s1.put("vipul","sumo");
  s1.put("vipul","logic");
  s1.put("anuj","noida");
  
  cout<< s1.get("vipul",0); << "  " << s1.get("vipul",1); << "  " << s1.get("vipul",100); << "  " << s1.get("anuj",2); << "  "<< s1.get("anuj",3); << "  ";

  return 0;
}