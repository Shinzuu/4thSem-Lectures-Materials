#include <bits/stdc++.h>
using namespace std;
unordered_map<char, vector<pair<int, char>>> graph = {
    {'A', {{2, 'B'}, {4, 'C'}, {6, 'D'}}},
    {'B', {{2, 'A'}, {8, 'E'}, {10, 'F'}}},
    {'C', {{4, 'A'}, {12, 'G'}}},
    {'D', {{6, 'A'}, {14, 'H'}}},
    {'E', {{8, 'B'}, {10, 'F'}}},
    {'F', {{10, 'B'}, {10, 'E'}, {12, 'G'}}},
    {'G', {{12, 'C'}, {12, 'F'}, {16, 'H'}}},
    {'H', {{14, 'D'}, {16, 'G'}}},
    {'I', {{6, 'J'}, {10, 'K'}}},
    {'J', {{6, 'I'}, {12, 'L'}}},
    {'K', {{10, 'I'}, {14, 'M'}}},
    {'L', {{12, 'J'}, {16, 'N'}}},
    {'M', {{14, 'K'}, {18, 'O'}}},
    {'N', {{16, 'L'}, {18, 'P'}}},
    {'O', {{18, 'M'}, {20, 'Q'}}},
    {'P', {{18, 'N'}, {22, 'R'}}},
    {'Q', {{20, 'O'}, {22, 'S'}}},
    {'R', {{22, 'P'}, {24, 'T'}}},
    {'S', {{22, 'Q'}, {26, 'U'}}},
    {'T', {{24, 'R'}, {26, 'V'}}},
    {'U', {{26, 'S'}, {28, 'W'}}},
    {'V', {{26, 'T'}, {30, 'X'}}},
    {'W', {{28, 'U'}, {32, 'Y'}}},
    {'X', {{30, 'V'}, {34, 'Z'}}},
    {'Y', {{32, 'W'}, {36, 'A'}}},
    {'Z', {{34, 'X'}, {36, 'B'}}}};
unordered_map<char, int> dijkstra(char src) {
    unordered_map<char, int> dist;
    for (auto node : graph) dist[node.first] = INT_MAX;
    dist[src] = 0;
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        int d = pq.top().first;
        char node = pq.top().second;
        pq.pop();
        if (d > dist[node]) continue;
        for (auto edge : graph[node]) {
            int new_dist = d + edge.first;
            if (new_dist < dist[edge.second]) {
                dist[edge.second] = new_dist;
                pq.push({new_dist, edge.second});
            }}}return dist;}
struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode *left, *right;
    HuffmanNode(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}};
struct compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->freq > right->freq;}};
void storeCodes(HuffmanNode* root, string code, unordered_map<char, string> &huffmanCode) {
    if (!root) return;
    if (root->ch != '#') huffmanCode[root->ch] = code;
    storeCodes(root->left, code + "0", huffmanCode);
    storeCodes(root->right, code + "1", huffmanCode);}
unordered_map<char, string> buildHuffmanTree(unordered_map<char, int> freq, HuffmanNode*& root) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> pq;
    for (auto pair : freq) pq.push(new HuffmanNode(pair.first, pair.second));
    while (pq.size() != 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        HuffmanNode* sum = new HuffmanNode('#', left->freq + right->freq);
        sum->left = left;
        sum->right = right;
        pq.push(sum);}
    root = pq.top();
    unordered_map<char, string> huffmanCode;
    storeCodes(root, "", huffmanCode);
    return huffmanCode;}
string encodeMessage(const string &message, unordered_map<char, string> huffmanCode) {
    string encodedMsg = "";
    for (char ch : message) {
        if (huffmanCode.find(ch) != huffmanCode.end()) {
            encodedMsg += huffmanCode[ch];}}return encodedMsg;}
string decodeMessage(const string &encodedMsg, HuffmanNode* root) {
    string decodedMsg = "";
    HuffmanNode* curr = root;
    for (char bit : encodedMsg) {
        if (bit == '0') curr = curr->left;
        else curr = curr->right;
        if (!curr->left && !curr->right) {
            decodedMsg += curr->ch;
            curr = root;}}return decodedMsg;}
int calculateTotalCost(unordered_map<char, int>& freq, const string& message) {
    long long totalCost = 0;
    for (char ch : message) {
        if (freq.find(ch) != freq.end()) {
            totalCost += freq[ch];}}return totalCost;}
int main() {
    char sourceCity, destinationCity;
    string message;
    cout << "Enter the source city: ";
    cin >> sourceCity;
    cout << "Enter the destination city: ";
    cin >> destinationCity;
    cout << "Enter the message (valid characters: A-Z no spaces): ";
    cin.ignore(); 
    getline(cin, message);
    sourceCity = toupper(sourceCity);
    destinationCity = toupper(destinationCity);
    transform(message.begin(), message.end(), message.begin(), ::toupper);
    if (graph.find(sourceCity) == graph.end() || graph.find(destinationCity) == graph.end()) {
        cout << "Invalid source or destination city." << endl;return 1;}
    for (char ch : message) {
        if (graph.find(ch) == graph.end()) {
            cout << "Message contains invalid characters." << endl;return 1;}}
    unordered_map<char, int> shortestPath = dijkstra(sourceCity);
    unordered_map<char, int> freq;
    for (char ch : message) {freq[ch] = shortestPath[ch];}
    if (freq.empty()) {cout << "No valid characters in the message." << endl; return 1;}
    HuffmanNode* root = nullptr;
    unordered_map<char, string> huffmanCode = buildHuffmanTree(freq, root);
    string encodedMessage = encodeMessage(message, huffmanCode);
    cout << "Encoded Message: " << encodedMessage << endl;
    string decodedMessage = decodeMessage(encodedMessage, root);
    cout << "Decoded Message: " << decodedMessage << endl;
    long long totalCost = calculateTotalCost(freq, message);
    cout << "Total Cost (Frequency): " << totalCost << endl;
    return 0;
}
