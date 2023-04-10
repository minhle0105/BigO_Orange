#include <iostream>
#include <limits>
#include <vector>

#define INF 1e9;

using namespace std;

struct Point
{
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

bool xCompare(const Point &p1, const Point &p2)
{
    return p1.x < p2.x;
}

bool yCompare(const Point &p1, const Point &p2)
{
    return p1.y < p2.y;
}

double distance(const Point &p1, const Point &p2)
{
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    return x * x + y * y;
}

double bruteForce(vector<Point> &point_set, int left, int right)
{
    double min_dist = INF;
    for (int i = left; i < right; ++i)
    {
        for (int j = i + 1; j < right; ++j)
        {
            min_dist = min(min_dist, distance(point_set[i], point_set[j]));
        }
    }
    return min_dist;
}

double stripCloset(vector<Point> &point_set, int left, int right, int mid, double dist_min)
{
    Point point_mid = point_set[mid];
    vector<Point> splitted_points;
    for (int i = left; i < right; ++i)
    {
        if (abs(point_set[i].x - point_mid.x) <= dist_min)
        {
            splitted_points.push_back(point_set[i]);
        }
    }
    sort(splitted_points.begin(), splitted_points.end(), yCompare);
    double smallest = INF;
    int l = splitted_points.size();
    for (int i = 0; i < l; ++i)
    {
        for (int j = i + 1; j < l && (splitted_points[j].y - splitted_points[i].y) < dist_min; ++j)
        {
            smallest = min(smallest, distance(splitted_points[i], splitted_points[j]));
        }
    }
    return smallest;
}

double minimalDistance(vector<Point> &point_set, int left, int right)
{
    if (right - left <= 3)
    {
        return bruteForce(point_set, left, right);
    }
    int mid = (right + left) / 2;
    double dist_left = minimalDistance(point_set, left, mid);
    double dist_right = minimalDistance(point_set, mid + 1, right);
    double dist_min = min(dist_left, dist_right);
    return min(dist_min, stripCloset(point_set, left, right, mid, dist_min));
}

vector<int> prefix_sum(const vector<int> &nums)
{
    vector<int> pre_sum;
    pre_sum.reserve(nums.size() + 1);
    pre_sum.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i)
    {
        pre_sum.push_back(pre_sum[i - 1] + nums[i]);
    }
    return pre_sum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    nums.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    vector<int> pre_sum = prefix_sum(nums);
    vector<Point> points;
    for (int i = 0; i < n; ++i)
    {
        points.emplace_back(Point{static_cast<double>(i), static_cast<double>(pre_sum[i])});
    }
    sort(points.begin(), points.end(), xCompare);
    int res = minimalDistance(points, 0, n);
    cout << res << endl;
}