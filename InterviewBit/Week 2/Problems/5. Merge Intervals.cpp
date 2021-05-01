bool isOverlap(Interval int1, Interval int2) {
    return max(int1.start, int2.start) < min(int1.end, int2.end);
}

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> result;
    int n = intervals.size();

    int idx = n;
    for (int i = 0; i < n; i++) {
        if (newInterval.start < intervals[i].start) {
            idx = i;
            break;
        }
    }
    intervals.insert(intervals.begin() + idx, newInterval);

    int i = 0;
    int j = 1;
    bool door = false;
    while (j <= n) {
        if (isOverlap(intervals[i], intervals[j])) {
            intervals[i].start = min(intervals[i].start, intervals[j].start);
            intervals[i].end   = max(intervals[i].end,   intervals[j].end);
            intervals[j].start = -1;
            intervals[j].end   = -1;
            door = true;
            j++;
        } else {
            if (door) break;
            i++;
            j++;
        }
    }

    for (int m = 0; m <= n; m++) {
        if (intervals[m].start != -1) {
            result.push_back(intervals[m]);
        }
    }

    return result;
}


int main() {
    vector<Interval> A = {Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 14)};

    vector<Interval> result = insert(A, Interval(4, 9));

    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i].start << ", " << result[i].end << "]";
    }

    return 0;
}
