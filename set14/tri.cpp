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

struct point
{
    double x;
    double y;
};

bool sameSegment(point p, point q, point r)
{
    if (q.x <= max(r.x, p.x) && q.x >= min(p.x, r.x) && q.y <= max(r.y, p.y) && q.y >= min(p.y, r.y))
        return true;

    return false;
}

int orientation(point p, point q, point r)
{
    double ori = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    // if (!ori)
    //     return 0;
    if(abs(ori) < 1e-9)
        return 0;

    if (ori > 0)
    {
        return 1;
    }
    return 2;
}

bool shitInter(point p1, point q1, point p2, point q2)
{
    int a = orientation(p1, q1, p2);
    int b = orientation(p1, q1, q2);
    int c = orientation(p2, q2, p1);
    int d = orientation(p2, q2, q1);

    if (a != b && c != d)
        return true;

    if (d == 0 && sameSegment(p2, q1, q2))
        return true;

    if (c == 0 && sameSegment(p2, p1, q2))
        return true;

    if (b == 0 && sameSegment(p1, q2, q1))
        return true;

    if (a == 0 && sameSegment(p1, p2, q1))
        return true;

    return false;
}

void soln()
{
    int n = -1;
    int cnt = 0;
    point x;
    point y;
    vector<pair<point, point>> vect;
    while (cin >> n)
    {
        if (!n)
        {
            break;
        }
        vect.clear();
        // vect.resize(n);
        for (int l = 0; l < n; l++)
        {
            cin >> x.x >> x.y >> y.x >> y.y;
            vect.push_back({x, y});
        }
        for (int i = 0; i < vect.size(); i++)
        {

            for (int j = i + 1; j < vect.size(); j++)
            {

                for (int k = j + 1; k < vect.size(); k++)
                {
                    if (shitInter(vect[i].first, vect[i].second, vect[j].first, vect[j].second))
                    {

                        if (shitInter(vect[j].first, vect[j].second, vect[k].first, vect[k].second))
                        {

                            if (shitInter(vect[k].first, vect[k].second, vect[i].first, vect[i].second))
                            {
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
        cout << cnt << endl; cnt = 0;
    }
}

int main()
{
    soln();
}