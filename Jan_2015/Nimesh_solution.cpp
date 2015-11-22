#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>    
using namespace std;      


class Solution {

private:
  
  
  int count;

  map<string, vector<string> > travel_place;
  map<string, vector<int> > travel_time;

public:
  int getTime(){
    return count++;
  }

  void put(string person, string place){
  	cout << count << " " << person << " "<< place<< "\n";
    travel_place[person].push_back(place);
    travel_time[person].push_back(getTime());

  }


  string get(string person, int t){
    // Binary implementaion
    
    // if ( travel_time.find(person) != travel_time.end() ) {
    //   if(binary_search(travel_time[person].begin(), travel_time[person].end(), t))
    //     return travel_place[person][binary_search(travel_time[person].begin()];
    //   else{

    //     if(lower_bound(travel_time[person].begin(), travel_time[person].end(), t))
    //       return travel_place[person][travel_time.begin() - lower_bound(travel_time[person].begin(), travel_time[person].end(), t)];
    //     else
    //       return NULL;
    //   }

    if ( travel_time.count(person) >0 ) {

      int min =-1, max =0;
      for (int i =0;i<travel_time[person].size();i++){
        if(travel_time[person][i]<= t){
          min++;
          max++;
        }
        else
          break;}
      if((min == -1)&&(travel_time[person][0]== t))
         return travel_place[person][0];

      if((min == -1)&&(travel_time[person][0] != t))
          return "NILL";

        return travel_place[person][min];    
      
    
  }
    else 
      return "NILL";
  
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
  cout<< s1.get("nim",0)<<" "<< s1.get("vipul",0) << "  " << s1.get("vipul",1) << "  " << s1.get("vipul",100) << "  " << s1.get("anuj",1) << "  " << s1.get("anuj",2) << "  "<< s1.get("anuj",3) << "  ";

  return 0;
}