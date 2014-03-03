/*
 Anton Gulikov
*/

#include <stdio.h>
#include <string.h>

bool canStep(int x, int y, int n){
	return (x >= 0 && y >= 0 && x < n && y < n);
}

int main(){
	printf("Hi, Druzhok!!!!! Enter the size of the matrix and matrix, of course!");
	int n = 0;
	scanf("%d", &n);

	int **a = new int* [n];
	int **pos = new int* [n];
	bool **used = new bool* [n];
	for (int i = 0; i < n; i++){
		a[i] = new int [n];
		used[i] = new bool [n];
		pos[i] = new int[n];
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			a[i][j] = 0;
			scanf("%d", &a[i][j]);
			used[i][j] = false;
			pos[i][j] = 0;
		}
	}

	int currentX = 0;
	int currentY = 0;
	int dx[4] = { 0, 1, 0, -1};
	int dy[4] = { 1, 0, -1, 0};
	int currentPosition = 0;
	int currentTime = 0;


	while (true){
		currentTime++;
		int iterations = 0;						
		while (!canStep(currentX + dx[currentPosition], currentY + dy[currentPosition], n) || used[currentX + dx[currentPosition]][currentY + dy[currentPosition]]){
			iterations++;
			if (iterations > 5)
				break;
			currentPosition = (currentPosition + 1) % 4;
		}
		pos[currentX][currentY] = currentTime;
		used[currentX][currentY] = true;
		if (iterations > 5)
			break;
		currentX += dx[currentPosition];
		currentY += dy[currentPosition];
	}

	int *answer = new int[n*n];

	for (int i = 0; i < n;  i++)
		for (int j = 0; j < n; j++)
			answer[pos[i][j] - 1] = a[i][j];

	for (int i = n * n - 1; i >= 0; i--)
		printf("%d ", answer[i]);

	delete[] answer;

	for (int i = 0; i < n; i++){
		delete[] a[i];
		delete[] used[i];
		delete[] pos[i];
	}

	delete[] a;
	delete[] pos;
	delete[] used;

	return 0;
}