#include "search.h"
#include<string>
#include<vector>
#include<filesystem>
#include<sstream>
#include<unordered_map>
using namespace std;



vector<int>bruteForce(const string &T,string &P){
    vector<int> result;

    const unordered_map<string, int> word_map = {
        {"zero",0}, {"one",1}, {"two",2}, {"three",3}, {"four",4},
        {"five",5}, {"six",6}, {"seven",7}, {"eight",8}, {"nine",9},
        {"ten",10}, {"eleven",11}, {"twelve",12}, {"thirteen",13},
        {"fourteen",14}, {"fifteen",15}, {"sixteen",16}, {"seventeen",17},
        {"eighteen",18}, {"nineteen",19}, {"twenty",20}, {"thirty",30},
        {"forty",40}, {"fifty",50}, {"sixty",60}, {"seventy",70},
        {"eighty",80}, {"ninety",90}
    };

    for(int i=0;i<int(T.size()-P.size()+1);i++){
        bool isOK =true;
        for(int j=0;j<int(P.size());j++){
            if(T[i+j]!=P[j]){
                isOK=false;
                break;
            }
        }
        if(isOK) result.push_back(i);
    }
    return result;
}
