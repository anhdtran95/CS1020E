//=====================================================================
// FILE: penguin.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: Tran Duy Anh
// MATRIC NO.  : A0144185E
// NUS EMAIL   : e0008216@u.nus.edu
// COMMENTS TO GRADER:
// <comments to grader, if any>
//  I have made some comments to identify each variable
//=====================================================================

#include <iostream>
#include <queue>
#include <utility>  // for pair class.
using namespace std;


class BestDive {
private:
    queue< pair<bool, int> > _units; // <risk, fishes>
    int _currFishes;//curr no of fish caught
    int _currRisk;//curr no of risk
    int _maxFishes;//max no of fish can caught
    int _riskThreshold;//currrisk <= riskthreshold

public:
    // Constructor.
    BestDive( int riskThreshold ) 
        : _units(), _currFishes(0), _currRisk(0),
        _maxFishes(0), _riskThreshold(riskThreshold) {} // no dive


    int getMaxFishes() { return _maxFishes; }


    void considerUnit( bool isRisky, int unitFishes ) 
    {
        _units.push( make_pair( isRisky, unitFishes ) );

        // Add your code here.
        
        queue< pair<bool, int> > unitsCopy1 = _units;// a copy of _units 
        queue< pair<bool, int> > unitsCopy2 = _units; 
        bool endOfQueue = false;
        bool reachMaxRisk = false;

        while(!endOfQueue){

            if(reachMaxRisk){
                reachMaxRisk = false;
                unitsCopy1.pop();
            }
            
            unitsCopy2 = unitsCopy1;
            int tempFish = 0;
            int tempRisk = 0;

            
            while(tempRisk <= _riskThreshold){
                if(unitsCopy2.empty()){
                    endOfQueue = true;
                    break;
                }
                if(get<0>(unitsCopy2.front())){// get risk out of the pair
                    tempRisk++;
                    if(tempRisk > _riskThreshold){// only when risk exceeds threshold do u break
                        reachMaxRisk = true;
                        break;
                    }
                }
       
                tempFish += get<1>(unitsCopy2.front());// get fish out of the pair

                cout << "currently at " <<  get<1>(unitsCopy2.front()) << endl;
                unitsCopy2.pop();

            }
            if(tempFish > _maxFishes){
                _maxFishes = tempFish;
            }
            // cout << "max fish is: " << _maxFishes << endl;

            unitsCopy1.pop();//remove first element
        }
    }
};


int main() {
    int riskThreshold;
    cin >> riskThreshold; // T

    BestDive dive( riskThreshold );

    char unitRisk;
    int unitFishes;

    while ( cin >> unitRisk >> unitFishes ) // read risk and Fi
        dive.considerUnit( (unitRisk == 'R'), unitFishes );

    cout << dive.getMaxFishes() << endl;;

    return 0;
}
