#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define WHITE "\033[1;37m"
#define NC "\033[0m"
#define dbg(x) cerr << RED << #x << " = " << x << NC << endl
typedef long long ll;
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &pair)
{
    return out << '(' << pair.first << ", " << pair.second << ')';
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec)
{
    if (vec.empty())
        return out << "[]";
    out << '[';
    for (size_t i = 0; i < vec.size() - 1; i++)
        out << vec.at(i) << ", ";
    return out << vec.back() << ']';
}

bool isGreater(double a, double b)
{
    return (a - b) > (1e-9);
}

struct point
{
    double x;
    double y;
};

vector<point> vect;
vector<double> angles;

// Function to calculate the dot product of two vectors
double dotProduct(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

// Function to calculate the magnitude of a vector
double magnitude(point a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

// Function to calculate the angle BAC in radians
double angleBAC(point a, point b, point c)
{
    // Calculate the vectors AB and AC
    point ab = {b.x - a.x, b.y - a.y};
    point ac = {c.x - a.x, c.y - a.y};

    // Calculate the dot product and magnitudes of the vectors
    double dot = dotProduct(ab, ac);
    double mag_ab = magnitude(ab);
    double mag_ac = magnitude(ac);

    // Calculate the angle using the dot product and magnitudes
    double cos_theta = dot / (mag_ab * mag_ac);

    // Return the angle in radians
    return acos(cos_theta);
}

void printVect()
{
    cerr << BLUE;
    cerr << "size: " << vect.size() << endl;
    for (int i = 0; i < vect.size(); i++)
    {
        cerr << vect[i].x << " " << vect[i].y << " ";
    }
    cerr << endl
         << NC;
}

int pIndex = 0;
double currMinAng = 0.0;
double lastMinAng = 0.0;
point lastMinP;
bool weDone = false;

void adjust()
{
    if (vect.size() == 3)
    {
        weDone = true;
        return;
    }
    lastMinAng = currMinAng;

    auto it = find(angles.begin(), angles.end(), currMinAng);

    pIndex = distance(angles.begin(), it);
    lastMinP = vect[pIndex];
    // angles.erase(angles.begin() + pIndex);

    vect.erase(vect.begin() + pIndex);
}

void calcAngs()
{

    angles.clear();
    // can optimize later if this times out
    point firstP = vect.front();
    point lastP = vect.back();
    double minAng = 1e18;

    int n = vect.size();

    double tempAng = angleBAC(firstP, lastP, vect[1]);
    angles.push_back(tempAng);
    minAng = min(tempAng, minAng);

    for (int i = 1; i < n - 1; i++)
    {
        tempAng = angleBAC(vect[i], vect[i - 1], vect[i + 1]);
        angles.push_back(tempAng);
        minAng = min(tempAng, minAng);
    }

    tempAng = angleBAC(lastP, vect[n - 2], firstP);
    angles.push_back(tempAng);
    minAng = min(tempAng, minAng);

    currMinAng = minAng;
}

void printpoints()
{
    cout << vect.size() << " ";
    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect[i].x << " " << vect[i].y << " ";
    }
    cout << endl;
}

void soln()
{
    int n = 0;

    // int l = 0, r = 0;
    point temp;

    while (true)
    {
        cin >> n;

        if (!n)
            return;

        vect.clear();
        vect.resize(n);

        for (int i = 0; i < n; i++)
        {
            cin >> temp.x >> temp.y;
            vect[i] = temp;
        }
        angles.clear();
        angles.resize(n);

        calcAngs();

        double imBi = 0.0;
        point last;
        last.x = 0; last.y = 0;
        int lastIndex = 0;

        while (true)
        {
            double myMin = 1e18;
            int myMindex = 0;
            
            for(int i = 0; i < angles.size(); i++){
                if(angles[i] < myMin){
                    myMindex = i;
                    myMin = angles[i]; 
                }
            }

            if(myMin < imBi){
                vect.insert(vect.begin() + lastIndex, last);
                break;
            }

            if(angles.size() == 3)
                break;

            last = vect.at(myMindex);
            vect.erase(vect.begin() + myMindex);
            imBi = myMin;
            lastIndex = myMindex;

            calcAngs();
        }
        printpoints();
    }
}

int main()
{
    soln();
}