// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// // https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1

// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// class node {
// public:
//     int data;
//     node* left;
//     node* right;

//     node(int d) {
//         data = d;
//         left = NULL;
//         right = NULL;
//     }
// };

// class cmp {
// public:
//     bool operator()(node* a, node* b) {
//         return a->data > b->data;
//     }
// };

// class Solution {
// public:
//     void traverse(node* root, vector<string>& ans, string temp) {
//         if (root->left == NULL && root->right == NULL) {
//             ans.push_back(temp);
//             return;
//         }
//         traverse(root->left, ans, temp + '0');
//         traverse(root->right, ans, temp + '1');
//     }

//     vector<string> huffmanCodes(string S, vector<int> f, int N) {
//         priority_queue<node*, vector<node*>, cmp> pq;
//         for (int i = 0; i < N; i++) {
//             node* temp = new node(f[i]);
//             pq.push(temp);
//         }

//         while (pq.size() > 1) {
//             node* left = pq.top();
//             pq.pop();

//             node* right = pq.top();
//             pq.pop();

//             node* newnode = new node(left->data + right->data);
//             newnode->left = left;
//             newnode->right = right;
//             pq.push(newnode);
//         }

//         node* root = pq.top();
//         vector<string> ans;
//         string temp = "";
//         traverse(root, ans, temp);
//         return ans;
//     }
// };

// int main() {
//     Solution ob;
//     vector<int> frequencies = {5, 9, 12, 13, 16, 45};
//     vector<string> result = ob.huffmanCodes("", frequencies, frequencies.size());

//     cout << "Huffman Codes:\n";
//     for (int i = 0; i < result.size(); i++) {
//         cout << "Character " << i << ": " << result[i] << endl;
//     }

//     return 0;
// }

// #include <algorithm>
// #include <iostream>
// using namespace std;

// struct Job {
// 	char id;
// 	int dead;
// 	int profit;
// };

// bool comparison(Job a, Job b) {
// 	return (a.profit > b.profit);
// }

// void printJobScheduling(Job arr[], int n) {
// 	sort(arr, arr + n, comparison);
// 	int result[n];
// 	bool slot[n];
// 	for (int i = 0; i < n; i++)
// 		slot[i] = false;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
// 			if (slot[j] == false) {
// 				result[j] = i;
// 				slot[j] = true;
// 				break;
// 			}
// 		}
// 	}
// 	for (int i = 0; i < n; i++)
// 		if (slot[i])
// 			cout << arr[result[i]].id << " ";
// }

// int main() {
// 	Job arr[] = { { 'a', 4, 70 },
// 				{ 'b', 2, 90 },
// 				{ 'c', 2, 20 },
// 				{ 'd', 3, 30 },
// 				{ 'e', 1, 80 } };

// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	cout << "Max profit sequence of jobs: ";

// 	printJobScheduling(arr, n);
// 	return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // Function to assign interviewers to candidates
// vector<vector<pair<double, double>>> assignInterviewers(vector<pair<double, double>>& candidateInterviews) {
//     // Sort candidate interviews by start time
//     sort(candidateInterviews.begin(), candidateInterviews.end());

//     // Initialize list of interviewers
//     vector<vector<pair<double, double>>> interviewers(1);

//     // Assign first three candidates to the first interviewer
//     interviewers[0].push_back(candidateInterviews[0]);

//     // Iterate through sorted list of candidate interviews
//     for (int i = 1; i < candidateInterviews.size(); ++i) {
//         bool assigned = false;
//         // Try to assign candidate to existing interviewer
//         for (int j = 0; j < interviewers.size(); ++j) {
//             if (!interviewers[j].empty() && interviewers[j].back().second <= candidateInterviews[i].first) {
//                 interviewers[j].push_back(candidateInterviews[i]);
//                 assigned = true;
//                 break;
//             }
//         }
//         // If candidate couldn't be assigned, create new interviewer
//         if (!assigned) {
//             interviewers.push_back({candidateInterviews[i]});
//         }
//     }

//     return interviewers;
// }

// int main() {
//     // Example candidate interviews
//     vector<pair<double, double>> candidateInterviews = {
//         {9, 10}, {9.5, 10.5}, {10, 11},
//         {10.5, 11.5}, {11, 12}, {11.5, 12.5},
//         {12, 13}, {12.5, 13.5}, {13, 14},
//         {13.5, 14.5}, {14, 15}, {14.5, 15.5}
//     };

//     // Assign interviewers
//     vector<vector<pair<double, double>>> interviewers = assignInterviewers(candidateInterviews);

//     // Output the candidate list for each interviewer
//     for (int i = 0; i < interviewers.size(); ++i) {
//         cout << "Interviewer " << i + 1 << " candidates:" << endl;
//         for (auto& candidate : interviewers[i]) {
//             cout << "Start: " << candidate.first << ", End: " << candidate.second << endl;
//         }
//         cout << endl;
//     }

//     return 0;
// }

// struct job{
// 	char id;
// 	int dead;
// 	int profit;
// };

// bool comparison(job a,job b){
// 	return (a.profit>b.profit);
// }

// void jobschequencing(job *arr,int n){
// 	sort(arr,arr+n,comparison);
// 	int r[n];
// 	bool slot[n];
// 	for(int i=0;i<n;i++){
// 		slot[i]=false;
// 	}
// 	for (int i=0;i<n;i++){
// 		for(int j=min(n,arr[i].dead)-1;j>=0;j--){
// 			if(slot[j]==false){
// 				r[j]=i;
// 				slot[j]=true;
// 				break;
// 			}
// 		}
// 	}
// 	for(int i=0;i<n;i++){
// 		if(slot[i]){
// 			cout<<arr[r[i]].id<<" ";
// 	}

// }
// }

// int main(){
// 	job arr[]={{'a',4,70},{'b',2,90},{'c',2,20},{'d',3,30}};
// 	int n=sizeof(arr)/sizeof(arr[0]);
// 	cout<<"Max job scequencing"<<endl;

// 	jobschequencing(arr,n);
// 	return 0;

// }

// struct item{
// 	int value;
// 	int weight;
// };

// bool comp(item a,item b){
// 	double p=a.value/a.weight;
// 	double q=b.value/b.weight;
// 	return p>q;
// }

// void knapsack(int w,item *arr,int n){
// 	sort(arr,arr+n,comp);
// 	int r[n];
// 	for(int i=0;i<n;i++){
// 		r[i]=0;
// 	}
// 	double profit=0;
// 	for(int i=0;i<n;i++){
// 		if(arr[i].weight<=w){
// 			w-=arr[i].weight;
// 			profit+=arr[i].value;
// 			r[i]=1;
// 		}

// 	else{
// 		profit+=arr[i].value*(w/arr[i].weight);
// 		break;
// 	}
// 	for(int i=0;i<n;i++){
// 		cout<<"resulting index is"<<r[i]<<endl;
// 	}
// 	cout<<"profit is "<<profit<<endl;

// }

// int main(){
// 	int w=50;
// 	item arr[]={{60,10},{100,20},{120,30}};
// 	int n=sizeof(arr)/sizeof(arr[0]);
// 	knapsack(w,arr,n);

// }

// struct meeting{
// 	int start;
// 	int end;
// };

// bool comp(meeting a,meeting b){
// 	return a.end<b.end;
// }

// void activity(meeting *arr,int n){
// 	sort(arr,arr+n,comp);
// 	int r=0;
// 	for(int i=0;i<n-1;i++){
// 		for(int j=1;j<n;j++)
// 		if(arr[i].start>arr[j].end){
// 			r++;
// 		}
// 	}

// 	cout<<"the no. of meeting is :"<<r;

// }

// int main(){
// 	meeting arr[]={{1,2},{3,4},{5,7},{5,9},{8,9},{5,9}};
// 	int n=sizeof(arr)/sizeof(arr[0]);

// 	cout<<"the meeting schedule is :-"<<endl;

// 	activity(arr,n);

// }

// void lcs(string a,string b){
// 	int m=a.size();
// 	int n=b.size();
// 	string s;
// 	int size[m+1][n+1];

// 	for(int i=0;i<=m;i++){
// 		for(int j=0;j<=n;j++){
// 			if(i==0 || j==0) {
// 				size[i][j]=0;
// 			}
// 			else if(a[i-1]==b[j-1]){
// 				size[i][j]=size[i-1][j-1]+1;
// 				s.push_back(a[i-1]);
// 			}
// 			else{
// 				size[i][j]=max(size[i-1][j],size[i][j-1]);
// 			}
// 		}
// 	}

// cout<<"size of lcs"<<size[m][n]<<" ";
// cout<<"common string "<<s;
// }

// int main(){

// 	string s1="aush";
// 	string s2="ayushi";

// 	lcs(s1,s2);

// }

// int matrixchain(int *arr,int i,int j){
// 	if(i==j){
// 		return 0;
// 	}

// 	int mini=INT_MAX;
// 	int ans;

// 	for(int k=i;k<j;k++){
// 		ans=matrixchain(arr,i,k)+matrixchain(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
// 		mini=min(ans,mini);
// 	}

// 	return mini;

// }

// int main(){
// 	int arr[]={10,20,30,40};
// 	int n=sizeof(arr)/sizeof(arr[0]);
// 	cout<<"matrix chain multiplication"<<matrixchain(arr,1,n-1);
// }

// int knap(int *wt,int *p,int w,int n){
// 	if( n==0){
// 		if(wt[0]<=w){
// 			return p[0];
// 		}
// 		else
// 		return 0;

// 	}

// 	int include=0;

// 	if(wt[n]<=w){
// 		include=p[n]+knap(wt,p,w-wt[n],n-1);
// 	}
// 	int exclude=0+knap(wt,p,w,n-1);

// 	int ans=max(include,exclude);
// 	return ans;

// }

// int main(){
// 	int wt[]={10,20,30};
// 	int p[]={60,100,120};
// 	int w=50;
// 	int n=sizeof(wt)/sizeof(wt[0]);
// 	cout<<knap(wt,p,w,n-1);
// }

// int noofcoins(int n,int *coin){
// 	int ways[n+1];
// 	int size=sizeof(coin)/sizeof(coin[0]);
// 	for(int i=0;i<=n;i++){
// 		ways[i]=0;
// 	}
// 	ways[0]=1;
// 	for (int i=0;i<3;i++){
// 		for(int j=coin[i];j<=n;j++){
// 			ways[j]+=ways[j-coin[i]];
// 		}
// 	}
// 	return ways[n];
// }

// int main(){
// 	int coin[]={1,5,10};
// 	cout<<noofcoins(12,coin)<<endl;
// }

// bool issafe(int row,int col,vector<vector<int>>&board,int n){
// 	for(int i=0;i<row;i++){
// 		if(board[i][col]==1)
// 		return false;
// 	}

// 	for(int i=row, j=col;i>=0 && j>=0;--i,--j){
// 		if(board[i][j]==1)
// 		return false;
// 	}

// 	for(int i=row, j=col;i>=0 && j<n;--i,++j){
// 		if(board[i][j]==1)
// 		return false;
// 	}

// 	return true;

// }

// bool solveutl(int row,vector<vector<int>>&board,int n){
// 	if(row==n){
// 		return true;
// 	}

// 	for(int col=0;col<n;col++){
// 		if(issafe(row,col,board,n)){
// 			board[row][col]=1;

// 		if(solveutl(row+1,board,n))
// 		return true;
// 		board[row][col]=0;

// 		}
// 	}
// 	return false;
// }

// vector<vector<string>>solvequeen(int n){
// 	vector<vector<int>>board(n,vector<int>(n,0));
// 	vector<vector<string>>ans;

// 	if(solveutl(0,board,n)){
// 		for(int i=0;i<n;i++){
// 			vector<string>sol;
// 			for(int j=0;j<n;j++){
// 				string str=(board[i][j]==1)?"Q" :".";
// 				sol.push_back(str);
// 			}
// 			ans.push_back(sol);
// 		}
// 	}
// 	return ans;

// }

// int main(){
// 	int n=4;
// 	vector<vector<string>>solution=solvequeen(n);
// 	for(int i=0;i<solution.size();i++){
// 		for(int j=0;j<solution[i].size();j++){
// 			cout<<solution[i][j]<<" ";
// 		}
// 			cout<<endl;

// }
// }

// void setsum(int *set, int pos, int sum, int tmpsum, int size, bool &f, vector<int> &subset)
// {
// 	if (sum == tmpsum)
// 	{
// 		f = true;
// 	}

// 	for (int i = pos; i < size; i++)
// 	{
// 		if (tmpsum + set[i] <= sum)
// 		{
// 			tmpsum += set[i];
// 			subset.push_back(set[i]);

// 			setsum(set, i + 1, sum, tmpsum, size, f, subset);

// 			if (f)
// 			{
// 				return;
// 			}
// 			tmpsum -= set[i];
// 			subset.pop_back();
// 		}
// 	}
// }

// int main()
// {
// 	int set[] = {1,2,1};
// 	int sum = 3;
// 	int n = sizeof(set) / sizeof(set[0]);
// 	bool f = false;
// 	vector<int> subset;
// 	setsum(set, 0, sum, 0, n, f, subset);
// 	if (f)
// 	{
// 		cout << "Subset with the given sum found: ";
// 		for (int i = 0; i < subset.size(); ++i)
// 			cout << subset[i] << " ";
// 		cout << endl;
// 	}
// 	else
// 	{
// 		cout << "No required subset found" << endl;
// 	}
// 	return 0;
// }

// #define v 4
// void printcolor(int color[])
// {
//  cout << "Valid coloring exists. Assigned colors are:" << endl;
//  for (int i = 0; i < v; i++)
//  cout << " " << color[i];
//  cout << endl;
// }
// bool colsafe(bool graph[v][v],int col,int *colour,int c){
// 	for(int i=0;i<v;i++){
// 		if(graph[col][i] && c==colour[i]){
// 			return false;
// 		}
// 	}
// 	return true;
// }

// bool colorutl(bool graph[v][v],int col,int *colour,int e){
// 	if(e==v){
// 		return true;
// 	}

// 	for(int i=1;i<=col;i++){
// 		if(colsafe(graph,e,colour,i)){
// 			colour[e]=i;
// 			if(colorutl(graph,col,colour,e+1)==true){
// 				return true;
				
// 			}
// 			colour[e]=0;
			
// 		}
// 	}
// 	return false;
// }

// bool colorgraph(bool graph[v][v],int col){

// 	int colour[v];

// 	for(int i=0;i<v;i++){
// 		colour[i]=0;
// 	}

// 	if(colorutl(graph,col,colour,0)==false){
// 		cout<<"no valid coloring"<<endl;
// 		return false;
// 	}

// 	printcolor(colour);
// 	return true;

// }

// int main(){
// 	bool graph[v][v]={
// 		{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}
// 	};

// 	int col=3;
// 	colorgraph(graph,col);
// }
// bool binary(int *arr,int t,int size){
	
// 	int s=0;
// 	int e=size-1;

// 	while(s<=e){
// 		int mid=(s+e)/2;
// 		if(arr[mid]==t){
// 			return true;
// 		}

// 		if(arr[mid]>t){
// 			e=mid-1;
// 		}
// 		else{
// 			s=mid+1;
// 		}
// 	}
// 	return false;


// }

// int main(){
// 	int arr[]={1,2,3,6,7,8};
// 	int target=3;
// int size=sizeof(arr)/sizeof(arr[0]);
// 	if(binary(arr,target,size)){
// 		cout<<"found"<<endl;
// 	}
// 	else{
// 		cout<<"not found";
// 	}
// }

// void merge(int *arr,int n,int s,int mid,int e){
// 	int len1=mid-s+1;
// 	int len2=e-mid;
// 	int *arr1=new int[len1];
// 	int *arr2=new int[len2];

// int k=s;
// 	for(int i=0;i<len1;i++){
// 		arr1[i]=arr[k++];
		
// 	}

// 	 k=mid+1;
// 	for(int i=0;i<len2;i++){
// 		arr2[i]=arr[k++];
		
		
// 	}

// 	int index1=0;
// 	int index2=0;
// 	int key=s;

// 	while(index1<len1 && index2<len2 ){
// 		if(arr1[index1]<arr2[index2]){
// 			arr[key]=arr1[index1];
// 			index1++;
// 			key++;
// 		}
// 		else{
// 			arr[key]=arr2[index2];
// 			index2++;
// 			key++;
// 		}
// 	}

// 	while(index1<len1){
// 		arr[key]=arr1[index1];
// 		index1++;
// 		key++;
// 	}
// 	while(index2<len2){
// 		arr[key]=arr2[index2];
// 		key++;
// 		index2++;
// 	}

	

// 	}

// void mergesort(int *arr,int n,int s,int e){
// 	if(s>=e){
// 		return;
// 	}
	
// 	int mid=s+(e-s)/2;

// 	mergesort(arr,n,s,mid);
// 	mergesort(arr,n,mid+1,e);

// 	merge(arr,n,s,mid,e);
// }

// int main(){
// 	int arr[]={3,2,78,5,67,3,4};
// 	int size=sizeof(arr)/sizeof(arr[0]);
//     int s=0;
// 	int e=size-1;
// 	mergesort(arr,size,s,e);

// 	for(int i=0;i<size;i++){
// 		cout<<arr[i]<<" ";
// 	}

// }

// int maxsubarray(int *arr,int n){
// 	int sum=0;
// 	int maxi=arr[0];
// 	for(int i=0;i<n;i++){
// 		sum=sum+arr[i];
// 		maxi=max(maxi,sum);
// 		if(sum<0){
// 			sum=0;
// 		}


// 	}
// 	return sum;
// 	}

// int main(){
// 	int arr[]={-1,-5,0,12,2,-5};
//     int size=sizeof(arr)/sizeof(arr[0]);
// 	int result=maxsubarray(arr,size-1);
// 	cout<<result;
// }


// int max(int a, int b, int c) { 
// 	return max(max(a, b), c); 
// } 

// int maxCrossingSum(int arr[], int l, int m, int h) { 

// 	int sum = 0; 
// 	int left_sum = INT_MIN; 
// 	for (int i = m; i >= l; i--) { 
// 		sum = sum + arr[i]; 
// 		if (sum > left_sum) 
// 			left_sum = sum; 
// 	} 
// 	sum = 0; 
// 	int right_sum = INT_MIN; 
// 	for (int i = m; i <= h; i++) { 
// 		sum = sum + arr[i]; 
// 		if (sum > right_sum) 
// 			right_sum = sum; 
// 	} 
// 	return max(left_sum + right_sum - arr[m], left_sum, right_sum); 
// } 


// int maxSubArraySum(int arr[], int l, int h) { 

// 	if (l > h) 
// 		return INT_MIN; 
// 	if (l == h) 
// 		return arr[l]; 
// 	int m = (l + h) / 2; 

// 	return max(maxSubArraySum(arr, l, m - 1), 
// 			maxSubArraySum(arr, m + 1, h), 
// 			maxCrossingSum(arr, l, m, h)); 
// } 

// int main() { 
// 	int arr[] = { 2, 3, 4, 5, 7 }; 
// 	int n = sizeof(arr) / sizeof(arr[0]); 
// 	int max_sum = maxSubArraySum(arr, 0, n - 1); 
// 	cout << "Maximum contiguous sum is " << max_sum; 
// 	return 0; 
// } 

#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
void addEdge(vector<vector<int>> &adj, int v, int w) 
{ 
 adj[v].push_back(w); 
 adj[w].push_back(v); 
} 
void util(vector<vector<int>> &adj, int v, vector<bool> &visited) { 
 visited[v] = true; 
 for (size_t i = 0; i < adj[v].size(); ++i) 
 { 
 int u = adj[v][i]; 
 if (!visited[u]) 
 util(adj, u, visited); 
 } 
} 
bool isConnected(vector<vector<int>> &adj, int V) 
{ 
 vector<bool> visited(V, false); 
 int i; 
 for (i = 0; i < V; ++i) 
 { 
 if (!adj[i].empty()) 
 break; 
 } 
 util(adj, i, visited); 
 for (i = 0; i < V; ++i) 
 { 
 if (!visited[i] && !adj[i].empty()) 
 return false;
 } 
 return true; 
} 
int countodd(vector<vector<int>> &adj, int V) { 
 int odd = 0; 
 for (int i = 0; i < V; ++i) 
 { 
 if (adj[i].size() % 2 != 0) 
 odd++; 
 } 
 return odd; 
} 
int isEulerian(vector<vector<int>> &adj, int V) { 
 if (!isConnected(adj, V)) 
 return 0; 
 int odd = countodd(adj, V); 
 return odd == 0 ? 2 : (odd == 2 ? 1 : 0); } 
int main() 
{ 
 int V = 5; 
 vector<vector<int>> adj(V); 
 addEdge(adj, 1, 0); 
 addEdge(adj, 0, 2); 
 addEdge(adj, 2, 1); 
 addEdge(adj, 0, 3); 
 addEdge(adj, 3, 4); 
 int res = isEulerian(adj, V); 
 cout << "Graph 1: "; 
 if (res == 0) 
 cout << "not Eulerian\n"; 
 else if (res == 1) 
 cout << "has a Euler path\n";  else 
 cout << "has a Euler cycle\n"; 
 }



const int V = 5; 
bool Safe(const vector<vector<int>>& adjMatrix, vector<int>& path, int vertex, int position) { 
 if (adjMatrix[path[position - 1]][vertex] == 0) 
 return false; 
 for (int i = 0; i < position; ++i) { 
 if (path[i] == vertex) 
 return false; 
 } 
 return true; 
} 
bool hamiltonianCycleUtil(const vector<vector<int>>& adjMatrix, vector<int>& path, int position) { 
 if (position == V) { 
 if (adjMatrix[path[position - 1]][path[0]] == 1) 
 return true; 
 else 
 return false;
 } 
 for (int vertex = 0; vertex < V; vertex++) { 
 if (Safe(adjMatrix, path, vertex, position)) {  path[position] = vertex; 
 if (hamiltonianCycleUtil(adjMatrix, path, position + 1))  return true; 
 path[position] = -1; 
 } 
 } 
 return false; 
} 
void findHamiltonianCycle(const vector<vector<int>>& adjMatrix) {  vector<int> path(V, -1); 
 path[0] = 0; 
 if (!hamiltonianCycleUtil(adjMatrix, path, 1)) {  cout << "\nSolution does not exist"; 
 return; 
 } 
 cout << "Solution Exists: Following is one Hamiltonian Cycle\n";  for (int i = 0; i < V; i++) 
 cout << path[i] << " "; 
 cout << path[0] << " "; 
 cout << endl; 
} 
int main() { 
 vector<vector<int>> graph1 = {{0, 1, 0, 1, 0}, 
 {1, 0, 1, 1, 1}, 
 {0, 1, 0, 0, 1}, 
 {1, 1, 0, 0, 1}, 
 {0, 1, 1, 1, 0}};  findHamiltonianCycle(graph1); 
 vector<vector<int>> graph2 = {{0, 1, 0, 1, 0}, 
 {1, 0, 1, 1, 1}, 
 {0, 1, 0, 0, 1}, 
 {1, 1, 0, 0, 0}, 
 {0, 1, 1, 0, 0}};  findHamiltonianCycle(graph2);
 return 0; 
} 
 return 0; 
} 
#include <bits/stdc++.h>
using namespace std;

void findMajority(int arr[], int n)
{
    int maxCount = 0;
    int index = -1;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > maxCount) {
            maxCount = count;
            index = i;
        }
    }

    if (maxCount > n / 2)
        cout << arr[index] << endl;
    else
        cout << "No Majority Element" << endl;
}

int main()
{
    int arr[] = { 1, 1, 2, 1, 3, 5, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    findMajority(arr, n);
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;
const int N = 4;

int tsp(vector<vector<int>>& graph, int mask, int pos, vector<vector<int>>& dp) {
    if (mask == (1 << N) - 1)
        return graph[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;

    for (int i = 0; i < N; i++) {
        if ((mask & (1 << i)) == 0) {
            int newAns = graph[pos][i] + tsp(graph, mask | (1 << i), i, dp);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int solveTSP(vector<vector<int>>& graph) {
    vector<vector<int>> dp(1 << N, vector<int>(N, -1));
    return tsp(graph, 1, 0, dp);
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int minCost = solveTSP(graph);
    cout << "Minimum cost for TSP is: " << minCost << endl;

    return 0;
}