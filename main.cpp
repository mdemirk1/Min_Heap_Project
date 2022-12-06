//Mustafa Dora Demirkir - HW2
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include "vehicle.cpp"

using namespace std;

//string splitter.
vector<string> splitstr(string str, string deli = " ")
{
    vector<string> v;
    int start = 0;
    int end = str.find(deli);
    while (end != -1) {
        v.push_back(str.substr(start, end - start));
        start = end + deli.size();
        end = str.find(deli, start);
    }
    v.push_back(str.substr(start, end - start));
    return v;
}

//hash functions
template <typename T>
void min_heapify(vector<T>& A, int i, int heapSize)
{
    int l = 2*i;
    int r = 2*i+1;
    int smallest = i;
    
    if(l <= heapSize && A[l] < A[i])
    {
        smallest = l;
    }
    else 
    {
        smallest = i;
    }
    if(r <= heapSize && A[r] < A[smallest])
    {
        smallest = r;
    }
    if(smallest != i)
    {
        swap(A[i], A[smallest]);
        min_heapify(A, smallest, heapSize);
    }
}

template <typename T>
void build_min_heap(vector<T>& A)
{
    int heapSize = A.size()-1;
    for(int i = int(heapSize/2); i>=1; i--)
    {
        min_heapify(A, i, heapSize);
    }
}

void heap_decrease_key(vector<Vehicle>&A, int i, int heapSize, Vehicle key)
{
    // heap_decrease_key(vehicles, lucky number, vehicles.size()-1, vehicles[1] as key);
    if(key > A[i])
    {
        cerr << "New key is greater!" << endl;
    
    }
    A[i].setTime(key.getDistance(), key.getSpeed());
    while(i>1 && (A[int(i/2)] >= A[i]))
    {
        swap(A[i], A[int(i/2)]);
        i = int(i/2);
    }
}

template <typename T>
Vehicle heap_extract_min(vector<T>& A, int heapSize)
{
    if(heapSize < 1)
    {
        cerr << "Heap underflow!" << endl;
    }
    Vehicle min = A[1];
    A[1] = A[heapSize];
    heapSize --;
    min_heapify(A, 1, heapSize);
    return min;
}

template <typename T>
void min_heap_insert(vector<T>&A, int heapSize, Vehicle key)
{
    heapSize ++;
    A[heapSize] = key;
    heap_decrease_key(A, heapSize, heapSize, key);
}

template <typename T>
void print_arr(vector<T> A)
{
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << endl;
    }
}

int main(int argc, char *argv[]) {
    
    int cntr = 0;
    int N = atoi(argv[1]);

    vector<Vehicle> vehicles;
    int size = 0;
    
    // dummy variable to set 0th index in heap.
    Vehicle empty;
    empty.setTime(-1, 1);
    vehicles.push_back(empty);

    //vehicle file.
    ifstream file;
    string line;

    file.open("vehicles.txt");

    if (!file)
	{
		cerr << "File cannot be opened!" << endl;
		exit(1);
	}
    //for getting rid of the first line.
    getline(file, line);
    
    //vector to split line.
    vector<string> reader;

    // creating vehicle obj.
    while (getline(file, line)) {
        Vehicle temp;
        reader = splitstr(line, "\t");
        temp.setID(stoi(reader.at(0)));
        temp.setLoc(reader.at(1));
        temp.setDist(stod(reader.at(2)));
        temp.setSpeed(stod(reader.at(3)));
        temp.setTime(stod(reader.at(2)), stod(reader.at(3)));
        vehicles.push_back(temp);
        size++;
    }

    build_min_heap(vehicles);

    ofstream out;
    ifstream r_file;
    string r_line;

    r_file.open("requests.txt");
    out.open("call_history.txt");

    if (!r_file)
	{
		cerr << "File cannot be opened!" << endl;
		exit(1);
	}

    //to get rid of first line
    getline(r_file, r_line);
    vector<string> r_reader;
    // reader.at(0) = location
    // reader.at(1) = distance
    // reader.at(2) = lucky number
    Vehicle v;
    while (getline(r_file, r_line) && N > cntr) {
        r_reader = splitstr(r_line, "\t");
        if (stoi(r_reader.at(2)) == 0) {
            v = heap_extract_min(vehicles, size);
            size--;
            cntr++;
            out << v.getID() << endl;
            v.setLoc(r_reader.at(0));
            v.setDist(stod(r_reader.at(1)));
            v.setTime(stod(r_reader.at(1)), v.getSpeed());
            min_heap_insert(vehicles, size, v);
            size ++;
        }
        else {
            heap_decrease_key(vehicles, stoi(r_reader.at(2)) + 1, size, vehicles[1]);
            v = heap_extract_min(vehicles, size);
            size --;
            cntr = cntr + 2;
            out << v.getID() << endl;
            v.setLoc(r_reader.at(0));
            v.setDist(stod(r_reader.at(1)));
            v.setTime(stod(r_reader.at(1)), v.getSpeed());
            min_heap_insert(vehicles, size, v);
            size ++;
        }
        cntr++;
    }
    
    return 0;
}