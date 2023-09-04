#include <bits/stdc++.h>
using namespace std;
 
void soln(){
    string str = ""; // for the current line of input
    string x = ""; // for adding new definitions
    string currStr = "";
    string currStr2 = "";
    string currStr3 = "";
    string backupStr = "";

    int y = 0; // for adding new definitions
    map<string, int> mapy;
    stringstream ss("");
    string command = "";
    string outputStr = "";
    size_t space = 0;

    bool validOp = true;
    int sum = 0;
    auto ity = mapy.end();

    while(getline(cin, str)){
        backupStr = str;
        space = backupStr.find(" ");
        if(space != std::string::npos){
            backupStr.erase(0, space + 1);
        }

        outputStr = "";
        sum = 0;
        ss.clear();
        validOp = true;
        
        ss.str(str);
        ss >> command;
        // backupStr = ss.str();
       
        if(command == "def"){
            ss >> x;
            ss >> y;
            if(mapy.find(x) != mapy.end()){
                mapy[x] = y;
            }
            else{
                mapy.insert({x, y});
            }
            
            ss.clear();
        }
        else if(command == "calc"){
            // STOPPED HERE (01/31/2023 @ 11:11AM)
            // it's either every variable will be in mapy, or 1+ will be missing...
            
            ss >> currStr >> currStr2 >> currStr3;
           
            
            
           
            if((mapy.find(currStr) == mapy.end()) || (mapy.find(currStr3) == mapy.end())){ // if not in mapy, this is true
                
                cout << backupStr << " unknown"; cout << "\n";
                validOp = false;
                
                continue;
            }
            else{
                if(currStr2 == "+"){
                    sum += (mapy[currStr] + mapy[currStr3]);
                }
                else if(currStr2 == "-"){
                    sum += (mapy[currStr] - mapy[currStr3]);
                }
                
            }
            // check if currStr and currStr3 is in mapy:
                // if not:
                    // set validOp to false
                // if it is: 
                    // if currStr2 is +: add, else subtract, update sum


            //add all 3 to output string
            outputStr += currStr; outputStr += " "; outputStr += currStr2; outputStr += " "; outputStr += currStr3; outputStr += " ";
            
            while(!(ss.str().empty())){
                // use currStr2 and currStr3 to take two strings from input at a time
                // take currStr2 first and check that it's not "="
                ss >> currStr2;
               
                if(currStr2 == "="){
                    
                    break;
                }
                ss >> currStr3;
                
                if(/*(mapy.find(currStr) == mapy.end()) ||*/ (mapy.find(currStr3) == mapy.end())){
                   
                    cout << backupStr << " unknown"; cout << "\n";
                    validOp = false;
                    // return;
                    // continue;
                    break;
                    
                    
                }
                else {
                    if(currStr2 == "+"){
                       
                        sum += (mapy[currStr3]);
                    }
                else if(currStr2 == "-"){
                        sum -= mapy[currStr3];
                    }
                   
                }
                outputStr += (currStr2 + " " + currStr3 + " ");
                // if either not in mapy: 
                    // set validOp to false
                // else: 
                    // if currStr2 is +: add, else subtract, update sum
                
                // add both strings to outputStr appropriately
                
            }
            //if(validOp){
                // cout << outputStr << "= " << sum; cout << "\n";
            //}
            // else{
            //     cout << outputStr << "= " << "unknown"; cout << "\n";
            // }
            if(!validOp){continue;}
            ity = find_if(mapy.begin(), mapy.end(), [&sum](const auto& item){return item.second == sum;});
            if(ity == mapy.end()){
                
                cout << backupStr << " unknown"; cout << "\n";
            }
            else{
               
                cout << outputStr << "= " << ity->first; cout << "\n";
            }
            
        }
        else if(command == "clear"){
            mapy.clear();
        }
        
    } 
 
}
 
int main(){
    // string a = "show";
    // cout << "\033[1;31mHello, World!\033[0m" << '\033[1;31m'a '\033[0m' << endl;

    //q1: do I have to check that the inputs are all lowercase?

    soln();
}