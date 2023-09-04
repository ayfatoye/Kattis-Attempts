#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl
typedef long long ll;
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& pair) {
    return out << '(' << pair.first << ", " << pair.second << ')';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    if(vec.empty()) return out << "[]";
    out << '[';
    for(size_t i = 0; i < vec.size()-1; i++) out << vec.at(i) << ", ";
    return out << vec.back() << ']';
}
 
void soln(){
    string str = ""; // for the current line of input
    string x = ""; // for adding new definitions
    string currStr = "";
    string currStr2 = "";
    string currStr3 = "";
    string backupStr = "";

    int y = 0; // for adding new definitions
    auto tempy = 0;
    map<string, int> mapy;
    map<int, string> mapy2;

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
        // dbg(backupStr);

        outputStr = "";
        sum = 0;
        ss.clear();
        validOp = true;
        
        ss.str(str);
        // dbg(str);
        ss >> command;
        // dbg(command);
        // backupStr = ss.str();
       
        if(command == "def"){
            ss >> x;
            ss >> y;
            mapy[x] = y;
            mapy2[y] = x;
            
            ss.clear();
        }
        else if(command == "calc"){
            // STOPPED HERE (01/31/2023 @ 11:11AM)
            // it's either every variable will be in mapy, or 1+ will be missing...
            
            ss >> currStr >> currStr2; 
            // dbg(currStr); dbg(currStr2);
            if(currStr2 == "="){
                // tempy = mapy[currStr];
                // ity = find_if(mapy.begin(), mapy.end(), [&tempy](const auto& item){return item.second == tempy;});
                // if(ity == mapy.end()){
                    
                //     cout << backupStr << " unknown"; cout << "\n";
                // }
                // else{
                
                //     cout << currStr << "= " << ity->first; cout << "\n";
                // }
                // continue;
                if(mapy.find(currStr) != mapy.end()){
                    cout << currStr << " = " << currStr << "\n";
                }
                else{
                    cout << backupStr << " unknown" << "\n";
                }
                continue;
            }
            ss >> currStr3;
           
            
            
           
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