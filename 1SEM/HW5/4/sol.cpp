#include "scorpionList.h"
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace scorpion;
using namespace std;



enum userCommand{
	uexit,
	uadd,
	uuser,
	uphone
};

bool exists(const char *filename)
{
	return ifstream(filename) != nullptr;
}

const int maxn = 1111;

int main(){

	List *userData = createList();
	userData->head = createElement("", "");
	if (exists( "phonedata.txt" )){
		FILE * input = fopen("phonedata.txt", "r");
		while ( !feof (input) ){
			char *user = new char[maxn];
			char *phone = new char[maxn];    
			memset(user, '\0', maxn);
			memset(phone, '\0', maxn);
			fgets(user, maxn, input);
			fgets(phone, maxn, input);
			if (strlen(user) < maxn && strlen(user) > 0)
			insertInData(userData, user, phone);
		}
		fclose ( input );
	}
	
	int command = 0;

	while (true){
		printf("Enter the command!\n 0 - exit \n 1 - add user and phone \n 2 - find user's phone\n 3 - find phone's user\n");		
		char *com = new char[maxn];
		memset(com, '\0', maxn);
		fgets(com, maxn, stdin);
		command = com[0] - '0';
		if (command == uexit){
			delete[] com;
			break;
		}
		if (command == uadd){
			printf("Enter the user!\n");
			printf("Enter the phone!\n");
			char *user = new char[maxn];
			char *phone = new char[maxn];
			memset(user, '\0', maxn);
			memset(phone, '\0', maxn);
			fgets(user, maxn, stdin);
			fgets(phone, maxn, stdin);
			insertInData(userData, user, phone);        		
		}
		if (command == uuser){
			printf("Enter the user!\n");
			char *user = new char[maxn];
			memset(user, '\0', maxn);
			fgets(user, maxn, stdin);
			print(findElement(userData, user));
			delete[] user;
			printf("\n");       	 		
		}
		if (command == uphone){
			printf("Enter the phone!\n");
			char *phone = new char[maxn];
			memset(phone, '\0', maxn);
			fgets(phone, maxn, stdin);
			print(findElement(userData, phone));
			delete[] phone;
			printf("\n"); 
		}
		delete[] com;
	}
	freopen ("phonedata.txt","w",stdout);
	printList(userData);
	deleteList(userData);
	return 0;
}
