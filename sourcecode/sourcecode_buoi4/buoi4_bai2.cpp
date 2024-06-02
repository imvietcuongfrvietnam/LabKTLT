// #include <iostream> 
// #include <cmath> 
// #include <iomanip> 
// #include <utility> 
// using namespace std; 
// using Point = pair<double, double>; 
double area(Point a, Point b, Point c) { 
double det = (c.first-a.first) * (b.second-a.a.second) - (b.first - a.first) * (c.second - a.second);
double area = abs(det)/2;
return area;
} 
// int main() { 
//     cout << setprecision(2) << fixed; 
//     cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl; 
//     return 0; 
// }
