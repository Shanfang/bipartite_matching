# include <iostream>
#include <string>

#define M 6
#define N 6

using namespace std;

//do DFS and return true if there is a matching for vertex u
//try all jobs that u is interested in until we find a job, or all jobs are tried without luck
bool bipartite_matching(bool bGraph[M][N], int u, bool visited[], int matchR[]) {
	//try every job one by one
	for(int v = 0; v < N; v++) {
		//if applicant u is interested in job v and it is not visited
		if(bGraph[u][v] && !visited[v]) {
			visited[v] = true;

			//if job v is not assigned to an applicant or 
			//previously assigned applicant for job v (which is matchR[v])has an alternate job available
			//since v is marked as visited, matchR[v] is the following recursive call wil not get job v again
			if(matchR[v] < 0 || bipartite_matching(bGraph, matchR[v], visited, matchR)) {
				matchR[v] = u;
				return true;
			}
		}
	}

return false;
}

//return max number of matching from M to N
int maxBPM(bool bGraph[M][N]) {

	//an array to keep track of the applicants assigned to jobs
	//the value of matchR[v] is the applicant number assigned to job v,
	//the value -1 indicates that nobody is assigned to job v
	int matchR[N];
	for(int v= 0; v < N; v++) {
		matchR[v] = -1;
	}

	int result = 0;
	for(int u = 0; u < M; u++) {
		bool visited[N];
		for(int v= 0; v < N; v++) {
		visited[v] = false;
		}

		//find if the applicant u can get a job
		if(bipartite_matching(bGraph, u, visited, matchR)) {
			result ++;
	}
	return result;
}