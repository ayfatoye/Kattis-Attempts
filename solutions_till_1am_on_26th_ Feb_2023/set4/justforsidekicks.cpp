#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define WHITE   "\033[1;37m"
#define NC      "\033[0m"
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
 
inline int LSOne(const int x){
    return x & (-x);
}

class FT{
    vector<long long> a;
    int n;

    public:
    
    FT(int x){
        n = x;
        a.resize(x+1, 0);
    }

    void incr(int elem, long long val){
        while(elem <= n){
            a[elem] += val;
            elem = elem + LSOne(elem);
        }
    }

    long long rsq(int elem){
        long long summation = 0;
        while(elem){
            summation += a[elem];
            elem -= LSOne(elem);
        }
        return summation;
    }
    
    long long rsq(int i, int j){
        return rsq(j) - rsq(i - 1);
    }
};

void soln(){
   ll n = 0; ll q = 0;
   string str = ""; string command = ""; int x = 0; int y = 0; string z = ""; ll newPrice = 0;
   map<string, ll> mapy;
   ll temp = 0;
   ll sum = 0;
   string tempStr = "";

//    mapy["1"] = 420;

//    cout << "here: " << mapy[string(1, '1')] << endl;
   

   cin >> n >> q;
   FT* ft1 = new FT(n + 1);
   FT* ft2 = new FT(n + 1);
   FT* ft3 = new FT(n + 1);
   FT* ft4 = new FT(n + 1);
   FT* ft5 = new FT(n + 1);
   FT* ft6 = new FT(n + 1);

//    for(int i = 0; i < 6; i++){
//         cin >> temp;
//         mapy['1' + i] = temp;
//    }
    cin >> temp;
    mapy["1"] = temp;
    cin >> temp;
    mapy["2"] = temp;
    cin >> temp;
    mapy["3"] = temp;
    cin >> temp;
    mapy["4"] = temp;
    cin >> temp;
    mapy["5"] = temp;
    cin >> temp;
    mapy["6"] = temp;


    // cerr << "first: " << mapy["3"] << endl;
    cin >> str;

    for(int i = 0; i < str.length(); i++){

        if(str[i] == '1'){
            ft1->incr((i + 1), 1); // 
        }
        else if(str[i] == '2'){
            ft2->incr((i + 1), 1); 
        }
        else if(str[i] == '3'){
            ft3->incr((i + 1), 1); 
        }
        else if(str[i] == '4'){
            ft4->incr((i + 1), 1); 
        }
        else if(str[i] == '5'){
            ft5->incr((i + 1), 1); 
        }
        else if(str[i] == '6'){
            ft6->incr((i + 1), 1); 
        }
    }

    // cerr << "all good: " << ft->rsq(2, 6) << endl;
    for(ll i = 0; i < q; i++){
        sum = 0;
        cin >> command;
        if(command == "3"){
            cin >> x >> y;
            // cout << ft->rsq(x, y) << endl;
            sum += (ft1->rsq(x, y) * mapy["1"]);
            sum += (ft2->rsq(x, y) * mapy["2"]);
            sum += (ft3->rsq(x, y) * mapy["3"]);
            sum += (ft4->rsq(x, y) * mapy["4"]);
            sum += (ft5->rsq(x, y) * mapy["5"]);
            sum += (ft6->rsq(x, y) * mapy["6"]);
            // cerr << RED << sum << NC << endl;
            cout << sum << endl;
            
        }
        else if(command == "1"){
            cin >> x >> z;
            tempStr = string(1, str[x-1]);

            if(tempStr == "1"){
                ft1->incr(x, -1);
            }
            else if(tempStr == "2"){
                ft2->incr(x, -1);
            }
            else if(tempStr == "3"){
                ft3->incr(x, -1);
            }
            else if(tempStr == "4"){
                ft4->incr(x, -1);
            }
            else if(tempStr == "5"){
                ft5->incr(x, -1);
            }
            else if(tempStr == "6"){
                ft6->incr(x, -1);
            }         


            // ft->incr(x, (-1 * mapy[string(1, str[x-1])]));
            str[x-1] = z.at(0);
            // cout << "str[x]: " << str[x] << endl;
            // dbg(str[x]);
            // ft->incr(x, (mapy[string(1, str[x-1])]));
             if(z == "1"){
                ft1->incr(x, 1);
            }
            else if(z == "2"){
                ft2->incr(x, 1);
            }
            else if(z == "3"){
                ft3->incr(x, 1);
            }
            else if(z == "4"){
                ft4->incr(x, 1);
            }
            else if(z == "5"){
                ft5->incr(x, 1);
            }
            else if(z == "6"){
                ft6->incr(x, 1);
            }  

        }
        else if(command == "2"){
            // cout << "HERE0: " <<  ft->rsq(2, 6) << endl;
            // delete ft1; delete ft2; delete ft3; delete ft4; delete ft5; delete ft6;
            cin >> z >> newPrice;
            mapy[z] = newPrice;
            // ft = new FT(n + 1);
            // for(int i = 0; i < str.length(); i++){
            //     ft->incr((i + 1), mapy[string(1, str[i])]);
            // }

            // cout << "HERE: " <<  ft->rsq(2, 6) << endl;
        }
    }
    delete ft1; delete ft2; delete ft3; delete ft4; delete ft5; delete ft6;

}
 
int main(){
    soln();
}