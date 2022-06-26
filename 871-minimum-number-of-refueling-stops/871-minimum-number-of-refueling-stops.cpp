class Solution {
public:
    // the idea is to get to the max fuel avl station in the current range
    // lets say we have x fuel currently and we can reach three stops. whichever stop has max fuel(found using pq), we will refuel at that stop
    //if we cannot reach any station or the destination, we will return -1
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int minStops=0;
        int currentStationIndex = 0;
        int totalStations = size(stations);
        while(startFuel<target)
        {
            while(currentStationIndex < totalStations and stations[currentStationIndex][0]<=startFuel)
            {
                pq.push(stations[currentStationIndex][1]);
                currentStationIndex++;
            }
            if(pq.empty())
                return -1;
            startFuel+=pq.top();
            pq.pop();
            minStops++;
        }
        return minStops;

    }
};