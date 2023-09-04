#include <bits/stdc++.h>
using namespace std;
 
// int soln(){

// }
 
int main(){
    // put in a vector and sort the vector
    // two pointers: l and r
    // set l to index 0, and r to l + 2 (if l + 2 is within range)
    // check if it looks good, add the l - r to the output string
    /*
    - if l + 2 doesn't look good: then put everything from l to r (or l + 2) in the string normally and set
    l to l + 2 and then r to l + 2
    */
   int size = 0;
   int entry = 0; // will use to input the numbers into vect
   cin >> size;
   vector<int> vect(size);

   for(int i = 0; i < size; i++){
        cin >> entry;
        vect.at(i) = entry;
   }

   sort(vect.begin(), vect.end());

   vector<string> strVect(size);

   for(int i = 0; i < size; i++){
        strVect.at(i) = to_string(vect.at(i));
   }
   
//    for(int i = 0; i < size; i++){
//         cout << strVect.at(i) << " ";
//    }
//    cout << "\n";
   int l = 0; int r = 2; // our two pointers
   string output = ""; 
//    int count = 0; // will help us know if we need to print out the last number after we're done (in the case where l points
   // to the )
   int tempR = 0; int tempL = 0; // will be used to find the right end of ranges amongst our input

   while(l < size - 2){ // the moment l hits size - 2, we just have to print the rest as is
        if(vect.at(r) - vect.at(l) != 2){
            output += strVect.at(l) + /*" " + strVect.at(l + 1) + */" ";
            // l = r;
            l = l + 1;
            r = l + 2;
        }
        else{
            output += strVect.at(l) + "-";
            tempL = l;
            tempR = r;
            while(tempR - tempL == vect.at(tempR) - vect.at(tempL)){
                tempR++;
                if(tempR >= size){
                    tempR--;
                    output += strVect.at(tempR);
                    cout << output; 
                    return 0;
                }
            }
            tempR--;
            output += strVect.at(tempR) + " ";
            r = tempR; 
            l = r + 1;
            r = l + 2;
        }
        
   }
    if(l == size - 2){
        output += strVect.at(l) + " " + strVect.at(l + 1);
    }
    else if(l == size - 1){
        output += strVect.at(l);
    }

    cout << output;
    cout << "\n";
}