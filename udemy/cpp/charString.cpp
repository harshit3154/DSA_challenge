#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

int main(){
	char ch1[20],ch2[20];
	
	/*	cin.get() is used to store the whole content inclding the space and line.
		when used consecutively it take new line as input
		So use cin.ignore() to remove the problem.
	*/
	
//	cout<<"\n\n\t\tEnter the value of ch1 : ";
//	cin.get(ch1,20);
//	cout<<"\n\n\t\t\t\tThe value of ch1 is : "<<ch1<<endl;
//	cin.ignore();
//	
//	cout<<"\n\n\t\tEnter the value of ch2 : ";
//	cin.get(ch2,20);
//	cout<<"\n\n\t\t\t\tThe value of ch2 is : "<<ch2<<endl;

	
	cout<<endl<<"\n\n\t\tThe result of strlen(ch1) is : "<<strlen(ch1)<<endl;
	cout<<endl<<"\n\n\t\tThe result of strlen(ch2) is : "<<strlen(ch2)<<endl;
	
	cout<<endl<<"\n\n\t\tThe result of strcat(ch1,ch2) is : "<<strcat(ch1,ch2);
	cout<<"\n\n\t\t\t\tThe value of ch1 is : "<<ch1<<endl;
	cout<<endl<<"\n\n\t\tThe result of strncat(ch1,ch2,2) is : "<<strncat(ch1,ch2,2);
	
	cout<<endl<<"\n\n\t\t\tThe result of strcpy(ch1,ch2) is : "<<strcpy(ch1,ch2);
	cout<<"\n\n\t\t\t\tThe value of ch1 is : "<<ch1<<endl;
	cout<<endl<<"\n\n\t\t\tThe result of strncpy(ch1,ch2,2) is : "<<strcpy(ch1,ch2,2);
	cout<<"\n\n\t\t\t\tThe value of ch1 is : "<<ch1<<endl;
	return 0;
}
