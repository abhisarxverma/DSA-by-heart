#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*
PROBLEM - Given an array of integers, which are the coordinates of the gas stations, Minimise the maximum distance between the coordinates by placing the given "k" number of integers.

EXAMPLE INPUT - [2, 8, 16, 25, 40], n = 4
EXAMPLE OUTPUT - 6
*/

/*
Brute Force Approach
---------------------
LOGIC - Linear search
Initialize tracking → Create how_many[] to store the number of additional gas stations in each gap.
Iteratively place k stations:
Find the largest gap between consecutive stations.
Insert a gas station in that gap, reducing its size.
Repeat for all k stations.
Calculate final max section length:
Recompute the biggest remaining section length after placing all stations.
Return this value as the minimum possible largest gap after placement.

TIME COMPLEXITY - O(N x K) 
SPACE COMPLEXITY - O(1)
*/

long double gas_stations_brute( vector<int> array, int k ){
    int n = array.size();
    vector<int> how_many(n-1, 0);

    for (int gas_station = 1; gas_station<= k; gas_station++){
        long double max_section = -1;
        int max_section_index = -1;

        for ( int i = 0; i < n-1; i++ ){
            long double diff = array[i+1] - array[i];
            long double section_length = diff / (long double)(how_many[i]+1);

            if (section_length > max_section){
                max_section = section_length;
                max_section_index = i;
            }
        }
        how_many[max_section_index]++;
    }

    int max_section = -1;

    for ( int i = 0; i < n-1; i ++){
        long double diff = array[i+1] - array[i];
        long double section_length = diff/ (long double)(how_many[i]+1);

        if (section_length > max_section){
            max_section = section_length;
        }
    }

    return max_section;
}

/*
Better Approach
---------------------
LOGIC - Binary search
Initialize a max heap (priority queue)
Store gaps between consecutive gas stations.
Always keep track of the largest gap.
Greedy station placement
Extract the largest gap from the heap.
Insert a gas station in this gap.
Recalculate the new gap and push it back into the heap.
Repeat for k stations
Continue splitting the largest gap iteratively, ensuring it reduces over time.
Final result
The top element of the heap gives the minimum possible largest gap after placing all stations.

TIME COMPLEXITY - O(K x LogN) 
SPACE COMPLEXITY - O(1)
*/

int gas_stations_better( vector<int> array, int k ){
    int n = array.size();
    vector<int> how_many(n-1, 0);
    priority_queue<pair <long double, int>> pq;

    for (int i = 0; i < n-1; i++){
        pq.push({array[i+1] - array[i], i});
    }

    for (int gas_station = 1; gas_station <= k; gas_station++){
        auto tp = pq.top(); pq.pop();
        int section_index = tp.second;
        how_many[section_index]++;
        long double initial_difference = array[section_index+1] - array[section_index];
        long double new_section_length = initial_difference / (long double) (how_many[section_index]+1);
        pq.push({new_section_length, section_index});
    }

    return pq.top().first;
}

/*
Optimal Approach
---------------------
LOGIC - Binary search
Define Search Space → low = 0 (smallest possible max gap)
high = max(arr[i+1] - arr[i]) (largest initial gap)
Binary Search on Maximum Gap (mid) → Try mid as a possible maximum distance
Calculate needed stations (get_number_of_gas_stations())
Adjust Search Based on Station Count → If more than k stations are required, increase low (current mid is too small).
Else, reduce high to get a smaller maximum gap.
Precision Condition (1e-6) → Stop when high - low is small enough, ensuring accuracy.
Final Result → high holds the minimum possible largest gap after placing k stations optimally.

TIME COMPLEXITY - O(N x LogS) 
SPACE COMPLEXITY - O(1)
*/

int get_number_of_gas_stations(long double distance, vector<int> &array){
    int n = array.size();
    int count = 0;
    for (int i = 1; i < n; i++){
        int stations_in_between = (array[i]-array[i-1])/distance;
        if (array[i]-array[i-1] == stations_in_between * distance) stations_in_between--;
        count += stations_in_between;
    }
    return count;
}

long double gas_stations_optimal(vector<int> array , int k) {
    int n = array.size();
    long double low = 0, high = 0; 

    for (int i = 0; i < n-1; i++){
        high = max(high, (long double)(array[i+1]-array[i]));
    }

    long double diff = 1e-6;
    while (high - low > diff){
        long double mid = low + (high - low) / 2.0;
        int stations = get_number_of_gas_stations(mid, array);
        
        if (stations > k) low = mid;
        else high = mid; 
    }

    return high;
}

int main() {
    vector<int> array = {2, 8, 16, 25, 40};
    int stations = 4;
    cout << "Minimum Maximum distance : " << gas_stations_optimal(array, stations) << endl;
}