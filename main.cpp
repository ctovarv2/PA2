/*
 * main.cpp
 *
 *  Created on: Sep 15, 2016
 *      Author: Chris
 */
// edit
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<ctime>
#include<sys/time.h>
#include<math.h>
#include<fstream>
//test

using namespace std;

void insertsort(vector<int> &A, int s){
	int temp;
	for(int i = 1; i <= s-1; ++i){
		int X = i;
		while(X > 0 && A.at(X-1) > A.at(X)){
			temp = A.at(X);
			A.at(X) = A.at(X-1);
			A.at(X-1) = temp;
			--X;
		}
	}
}

void bubblesort(vector<int> &A, int s){
	for(int i = 0; i < s-1; ++i){
			for(int x =  0; x < s-1; ++x){
				if(A.at(x+1) < A.at(x)){
					//swap
					int temp = A.at(x);
					A.at(x) = A.at(x+1);
					A.at(x+1) = temp;
				}
			}
		}
}


int main(){
	int n = 5;//change between 2, 3, 4, 5
	int size = pow(10, n);
	int order = 2; //0 = decreasing, 1 = increasing, 2 = random



	vector<int> vec;
	srand (time(NULL));

	struct timeval t1, t2;
	double t;

	ofstream myfile;
	myfile.open("Sorted List.txt");

	switch(order){
	case 0:
		for(int i = size; i >= 0; --i){//populates vector in backwards order
			int dec = i;
			vec.push_back(i);
			myfile << dec;
			myfile << "\n";
		}
		break;
	case 1:
		for(int i = 1; i <= size; ++i){//populates vector in order
			int inc = i;
			vec.push_back(i);
			myfile << inc;
			myfile << "\n";
		}
		break;
	case 2:
		for(int i = 1; i <= size; ++i){//populates vector in random order
			int ran = rand()%100 +1;
			vec.push_back(ran);
			myfile << ran;
			myfile << "\n";
		}
		break;
	default:
		break;
	}
	myfile.close();
	vector<int> vec2 = vec;

	gettimeofday(&t1, NULL);
	insertsort(vec, vec.size());


	//bubblesort(vec2, vec2.size());
	ofstream myfile2;
	myfile2.open("Insert Sort list.txt");





	cout << endl;
	cout << "Vector sorted Contents." << endl;
		for(int j = 0; j < size; ++j){
			cout << vec.at(j) << " ";
			myfile2 << vec.at(j);
			myfile2 << "\n";
		}
	myfile2.close();
	cout << endl;
	//cout << "Vector2 sorted Contents." << endl;
	//for(int j = 0; j < size; ++j){
	//cout << vec2.at(j) << " ";
	//}
	cout << endl;
	gettimeofday(&t2, NULL);
	t = (double) ((t2.tv_sec * 1000000 + t2.tv_usec) - (t1.tv_sec * 1000000 + t1.tv_usec)) / 1000000.0;
	cout << "Time:  " << t << " seconds."<<endl;
	return 0;
}
