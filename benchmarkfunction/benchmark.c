#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

// n.b. We want elapsed time (hence gettimeofday here rather than clock)
main() {

	// This measures accuracy in seconds only
	// time_t start, end;
	// double timeTaken;
	// start = time(&start);
	// sleep(1.5);
	// end = time(&end);
	// timeTaken = (double) difftime(end, start);

	struct timeval start, end;
	gettimeofday(&start, NULL);	
	gettimeofday(&end, NULL);

	// We have to add the seconds (converted to ms) + us (converted to ms)
	double elapsedTime = (end.tv_sec - start.tv_sec) * 1000.0;
	elapsedTime += (end.tv_usec - start.tv_usec) / 1000.0;

	printf("Time taken is %.2f ms \n", elapsedTime);	
}