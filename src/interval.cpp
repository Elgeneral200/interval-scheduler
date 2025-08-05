#include "interval.hpp"
#include <vector>
#include <algorithm>
using namespace std;

Interval::Interval(int s, int e) {
    start = s;
    end = e;
}

void Interval::display() {
    cout << "[" << start << ", " << end << "]";
}

int Scheduler::intervalPartitioning(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
        return a.start < b.start;
    });

    for (int i = 0; i < intervals.size(); i++) {
        bool assigned = false;
        for (int j = 0; j < rooms.size(); j++) {
            if (rooms[j] <= intervals[i].start) {
                rooms[j] = intervals[i].end;
                assigned = true;
                break;
            }
        }
        if (!assigned) {
            rooms.push_back(intervals[i].end);
        }
    }

    return rooms.size();
}