#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Object {
    double profit;
    double weight;
    double ratio;
};

bool compare(Object a, Object b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(vector<double>& profit, vector<double>& weights, double capacity) {
    int n = profit.size();
    vector<Object> objects(n);

    // Initialize the objects with profit, weight, and their ratio
    for (int i = 0; i < n; ++i) {
        objects[i].profit = profit[i];
        objects[i].weight = weights[i];
        objects[i].ratio = (double)profit[i] / weights[i];
    }
    //compare based on ratio
    sort(objects.begin(), objects.end(), compare);

    double maxProfit = 0.0;

    for (int i = 0; i < n; ++i) {
        if (capacity > 0 && objects[i].weight <= capacity) {
            maxProfit += objects[i].profit;
            capacity -= objects[i].weight;
        } else {
            maxProfit += (capacity * objects[i].ratio);
            break;
        }
    }
    
    return maxProfit;
}

int main() {
    vector<double> profit = {10, 5, 15, 7, 6, 18, 3};
    vector<double> weights = {2, 3, 5, 7, 1, 4, 1};
    double capacity = 15;

    cout << fixed << "Maximum value: " << fractionalKnapsack(profit, weights, capacity) << endl;

    return 0;
}
