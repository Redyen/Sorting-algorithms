
using namespace std;

#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <fstream>
#include <string>

random_device rd;
std::mt19937 generator(rd());
std::uniform_int_distribution<> dist(1, 1000000);

vector<int> vec1;
vector<int> vec2;
vector<int> vec3;
vector<int> vec4;
vector<int> vec5;

vector<int> ranVec(int num){
    vector<int> vec;
    int x;
    for(int i = 0; i < num;i++ ){
        x = dist(generator);
        vec.push_back(x);
        //bub.push_back(x);
        //bubC.push_back(x);
    }
    return vec;

}

vector<int> selectionSort(vector<int> x){

    int minInd = 0;
    int minVal = 0;
    int temp = 0;


    for(int i = 0; i < (x.size() -1); i++){
        minInd = i;
        minVal = x[i];

        for(int j = i+1; j < x.size(); j++){
            if(x[j] < minVal){
                minVal = x[j];
                minInd = j;
            }
        }

        if(i!=minInd){
            temp = x[i];
            x[i] = minVal;
            x[minInd] = temp;
        }

    }

    return x;
}

vector<int> bubbleSort(vector<int> x){
    int temp = 0;
    for(int i = (x.size()); i > 0; i--){
        for(int j = 0; j < i - 1; j++){
            if(x[j] > x[j+1]){
                temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }
    }

    return x;

}

vector<int> bubbleCSort(vector<int> x){
    int temp = 0;

    int i= x.size();
    bool sorting = true;
    bool swapped;

    while(i >= 1 && sorting == true){
        swapped = false;
        for(int j =0; j< i - 1; j++){
            if(x[j] > x[j+1]){
                temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
                swapped = true;
            }
        }
        if (swapped == false){
            sorting = false;
        }
        else{
            i = i-1;
        }
    }

    return x;
}

vector<int> insertSort(vector<int> x){

    int temp = 0;
    int y = 0;
    int j = 0;

    int n  = x.size();

    for(int i = 0; i < n; i++){
        y = x[i];
        j = i-1;
        while(j >= 0 && x[j] > y){
           x[j+1] = x[j];
           j = j-1;
        }
        x[j+1] = y;
    }

    return x;


}



void Merge(vector<int>& x, int left, int mid, int right) {
	vector<int> temp;

	int i, j;
	i = left;
	j = mid + 1;

	while (i <= mid && j <= right) {

		if (x[i] <= x[j]) {
			temp.push_back(x[i]);
			++i;
		}
		else {
			temp.push_back(x[j]);
			++j;
		}
	}
	while (i <= mid) {
		temp.push_back(x[i]);
		++i;
	}

	while (j <= right) {
		temp.push_back(x[j]);
		++j;
	}

	for (int i = left; i <= right; ++i)
		x[i] = temp[i - left];
}
void MergeSort(vector<int>& x, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(x, left, mid);
		MergeSort(x, mid + 1, right);
		Merge(x, left, mid, right);
	}
}

int Partition(vector<int> &x, int start, int fin){

	int f = fin;
	int s = start;
	int temp;

	for(int i=start;i<fin;++i){
		if(x[i]<x[f]){
            temp = x[i];
            x[i] = x[s];
            x[s] = temp;
			++s;
		}
	}

	temp = x[f];
    x[f] = x[s];
    x[s] = temp;
	return s;

}

void Quicksort(vector<int> &x, int start, int fin ){

	if(start<fin){
		int p = Partition(x,start,fin);
		Quicksort(x,start,p-1);
		Quicksort(x,p+1,fin);
	}

}


int main(){
    //sort 1vd
    long long selecAve = 0;
    long long bubbleAve =0;
    long long bubbleCAve =0;

    string select = "";
    string bubble = "";
    string bubblec = "";

    //sort 2
    long long insertAve = 0;
    long long mergeAve =0;
    long long quickAve =0;

    string insertS = "";
    string mergeS = "";
    string quick = "";

    // Create and open a text file
    ofstream MyFile("data2.txt");
    ofstream open("data2.txt", std::ofstream::out | std::ofstream::trunc);

    for(int i = 1000; i<=20000; i+= 1000){

        vector<int> vec1 = ranVec(i);
        vector<int> vec2 = ranVec(i);
        vector<int> vec3 = ranVec(i);
        vector<int> vec4 = ranVec(i);
        vector<int> vec5 = ranVec(i);

        vector<vector<int>> vectors{vec1, vec2, vec3, vec4, vec5};

        vector<int> temp;

        //selectionsort
        long long selectSum = 0;
        for (int j = 0; j<5;j++){
            auto start = chrono::high_resolution_clock::now();

            temp = selectionSort(vectors[j]);

            auto finish = chrono::high_resolution_clock::now();

            selectSum += chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
        }
        long long selectAve = selectSum/5;

        select += to_string(selectAve);
        select += ", ";
        //bubble sort

        long long bubbleSum = 0;
        for (int j = 0; j<5;j++){
            auto start = chrono::high_resolution_clock::now();

            temp = bubbleSort(vectors[j]);

            auto finish = chrono::high_resolution_clock::now();

            bubbleSum += chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
        }
        long long bubbleAve = bubbleSum/5;

        bubble += to_string(bubbleAve);
        bubble += ", ";

        //bubble C

        long long bubbleCSum = 0;
        for (int j = 0; j<5;j++){
            auto start = chrono::high_resolution_clock::now();

            temp = bubbleCSort(vectors[j]);

            auto finish = chrono::high_resolution_clock::now();

            bubbleCSum += chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
        }
        long long bubbleCAve = bubbleCSum/5;

        bubblec += to_string(bubbleCAve);
        bubblec += ", ";

        //insert

        long long insertSum = 0;
        for (int j = 0; j<5;j++){
            auto start = chrono::high_resolution_clock::now();

            temp = insertSort(vectors[j]);

            auto finish = chrono::high_resolution_clock::now();

            insertSum += chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
        }
        long long insertAve = insertSum/5;

        insertS += to_string(insertAve);
        insertS += ", ";

        //merge

        long long mergeSum = 0;

        for (int j = 0; j<5;j++){
            auto start = chrono::high_resolution_clock::now();

            temp = vectors[j];
            MergeSort(temp, 0, i -1);

            auto finish = chrono::high_resolution_clock::now();

            mergeSum += chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
        }

        long long mergeAve = mergeSum/5;

        mergeS += to_string(mergeAve);
        mergeS += ", ";

        //quick

        long long quickSum = 0;

        for (int j = 0; j<5;j++){
            auto start = chrono::high_resolution_clock::now();

            temp = vectors[j];
            Quicksort(temp, 0, i -1);

            auto finish = chrono::high_resolution_clock::now();

            quickSum += chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
        }

        long long quickAve = quickSum/5;

        quick += to_string(quickAve);
        quick += ", ";

    }





    MyFile << select << "\n" << bubble << "\n" << bubblec << "\n" << insertS << "\n" << mergeS << "\n" << quick;

    MyFile.close();



}
