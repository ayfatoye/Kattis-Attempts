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
    // q1: what's diff btw "not sure" and "stack" example?
    /*
    - first thing that comes to mind: 
        - if the input is only one line: return impossible
        - if the input is only of one of the two types: return impossible
    */
   string str = "";
   string str2 = "";
   stringstream ss;
   int command = 0; 
   int io = 0; // what the mystery ds returns
   bool isStack = true;
   bool isQueue = true;
   bool isPq = true;
   stack<int> stacky;
   queue<int> que;
   priority_queue<int> pq;

   while(getline(cin, str)){
        ss.clear();
        isStack = true;
        isQueue = true;
        isPq = true;
        while(!stacky.empty()){
            stacky.pop();
        }
        while(!que.empty()){
            que.pop();
        }
        while(!pq.empty()){
            pq.pop();
        }

       if(str == "1"){
        
        getline(cin, str); 
        ss.str(str);
        ss >> str2;
        dbg(str2);
        if(str2 == "1"){
            cout << "not sure" << "\n"; 
        }
        else{
            cout << "impossible" << "\n"; 
        }        
        continue;
        }
        

        for(int i = 0; i < stoi(str); i++){
            ss.clear();
            dbg(str2);
            getline(cin, str2);

            ss.str(str2);
            // cout << "\nstr: " << str2; cout << "\n";

            ss >> command;
            ss >> io;
            // cout << "command: " << command; cout << "\n";

            if(command == 1){
                stacky.push(io);
                que.push(io);
                pq.push(io);
            }
            else if(command == 2){
                if(stacky.empty() || que.empty() || pq.empty()){
                    isStack = false;
                    isQueue = false;
                    isPq = false;
                    continue;
                }
                //stack
                // cout << "io: " << io; cout << "\n";
                // cout << "stacky top: " << stacky.top(); cout << "\n";
                if(stacky.top() != io){
                    isStack = false;
                }
                stacky.pop();

                // queue
                if(que.front() != io){
                    isQueue = false;
                }
                que.pop();

                if(pq.top() != io){
                    isPq = false;
                }
                pq.pop();

                // pq
            }
            
        }
// cout << "isQ: " << isQueue << " isPq: " << isPq << " isStack: " <<isStack; cout << "\n";
        if(isQueue || isPq || isStack){
            // cout << "isQ: " << isQueue << " isPq: " << isPq << " isStack: " <<isStack; cout << "\n";
                if((isQueue && isPq) || (isQueue && isStack) || (isPq && isStack)){
                    cout << "not sure"; cout << "\n";
                }
                else{
                    if(isQueue){
                        cout << "queue"; cout << "\n";
                    }
                    else if(isPq){
                        cout << "priority queue"; cout << "\n";
                    }
                    else if(isStack){
                        cout << "stack"; cout << "\n";
                    }
                }
            }
            else{
                cout << "impossible"; cout << "\n";
            }

            
            
   }


}
 
int main(){
    soln();
}