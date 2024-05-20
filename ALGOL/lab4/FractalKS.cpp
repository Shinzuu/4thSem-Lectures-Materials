#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Object {
    int index;
    double profit;
    double weight;
    double ratio;
};

bool compare(Object a, Object b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(vector<double>& profit, vector<double>& weights, double capacity, int n) {
    vector<Object> objects(n);

    for (int i = 0; i < n; ++i) {
        objects[i].index = i; 
        objects[i].profit = profit[i];
        objects[i].weight = weights[i];
        objects[i].ratio = (double)profit[i] / weights[i];
    }

    double maxProfit = 0.0;
    vector<double> used(n, 0.0); //for outputting table

    // Sort objects based on ratio
    sort(objects.begin(), objects.end(), compare);

    for (int i = 0; i < n; ++i) {
        int originalIndex = objects[i].index; 
        if (capacity > 0 && objects[i].weight <= capacity) {
            maxProfit += objects[i].profit;
            used[originalIndex] = 1.0; 
            capacity -= objects[i].weight;
        } else if (capacity > 0) {
            maxProfit += (capacity * objects[i].ratio);
            used[originalIndex] = capacity / objects[i].weight;
            capacity = 0;
        } else {
            break;
        }
    }

    cout << "Items Used Table:" << endl;
    cout << "Item\tUsed" << endl;
    for (int i = 0; i < n; ++i) {

        cout << objects[i].index + 1 << "\t";

        if (used[objects[i].index] == 1.0) {
            cout << "1" << endl;
        } else {
            cout << fixed << setprecision(2) << used[objects[i].index] << endl;
        }
    }
    cout << "Maximum value: " ;
    return maxProfit;
}

int main() {
    int n;
    double capacity;

    cout << "Enter the number of objects: ";
    cin >> n;

    vector<double> profit(n);
    vector<double> weights(n);

    cout << "Enter the profit each object and weight:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> profit[i] >> weights[i];
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    cout << fixed << setprecision(2) << fractionalKnapsack(profit, weights, capacity, n) << endl;
    return 0;
}
