#include <iostream>
#include <queue>
#include <cassert>
 using namespace std;

class RecentCounter {
private:
    queue<int> q;
public:

    RecentCounter() {}
    
    int ping(int t) {
        q.push(t);
        // Remove timestamps older than t - 3000
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};