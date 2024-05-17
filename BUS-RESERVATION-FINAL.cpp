#include <iostream>
#include <cctype>
#include <limits>
#include <string>
#include <iomanip>

using namespace std;

string bus [2][11]={{"  ","D2","o","o","o","[CR]","o","o","o","o","x"},{"D1","o","o","o","o","o","o","o","o","o","x"}};
string bus2 [2][11]={{"  ","D2","#02","#04","#06","#08","#10","#12","#14","#16","#18"},{"D1","#01","#03","#05","#07","#09","#11","#13","#15","#17","#18"}};

int reserve();
void display();

int main(){
	char res, upres;
	
	cout<<"Welcome to Bus'inc."<<endl;
	cout<<"These are the available seats for our bus!"<<endl;
	cout<<"\n#18 is a backrow which is occupied";
	cout<<"\n#8 is a Comfort Room\n"<<endl;
	display ();
	
	while (true){
		cout<<"Would you like to make a reservation? (Y/N)  ";
		cin>>res;

		upres = toupper(res);
		switch (upres){
			case 'Y':
				reserve ();
				break;
			case 'N':
				cout<<"\nThank you for your time!";
				return 0;
			default:
				cout<<"\nThat was not an option...\nPlease try again"<<endl;
				continue;
		}
		break;
	}
	system("cls");
	cout<<"This is the final update!\n"<<endl;
	display ();
	cout<<"\nThank you for trusting our services!";
	cout<<"\nPlease continue to serve Bus'inc.";
	
	return 0;
}

void display(){
	
	for (int x = 0; x < 2; x++){
		for (int y = 0; y < 11; y++){
			if (bus[x][y] == "[CR]"){
				cout<<" "<<bus[x][y];
				continue;
			}
			cout<<setw(4)<<bus[x][y]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for (int a = 0; a < 2; a++){
		for (int b = 0; b < 11; b++){
			if (bus[a][b] == "[CR]"){
				cout<<" "<<bus[a][b];
				continue;
			}
			cout<<setw(4)<<bus2[a][b]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int reserve(){
	int buss [2][11] = {{0,0,2,4,6,8,10,12,14,16,18},{0,1,3,5,7,9,11,13,15,17,18}};
	char sen, upsen, con, upcon;
	int seat;
	while (true){
		cout<<"\nAre you a Senior Citizen? (Y/N) ";
		cin>>sen;
		upsen = toupper(sen);
	
		switch (upsen){
			case 'Y':
				STry:
				cout<<"\nYou can reserve seats #1 to #17";
				cout<<"\nChoose a seat (1 - 17): ";
				while (true){
					cin>>seat;
					if (!cin){
						cout<<"\nOnly enter an integer.";
						cout<<"\nChoose a seat (1 - 17): ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;	
					}
					else break;
				}
            	
            	if(seat<=0||seat>18){
					cout<<"Please enter a number only within the options.\n";
					goto STry;
				}
				
				for (int r = 0; r < 2; r++){
					for (int c = 0; c < 11; c++){
							if (buss [r][c] == seat){
								if (bus [r][c] == "x" || bus [r][c] == "[CR]"){
									cout<<"\nYou are trying to reserve in an occupied seat.";
									cout<<"\nPlease check our available seats and try again."<<endl;
									goto STry;
								}
								else {								
									cout<<"\nRESERVED!";
									bus [r][c] = "x";		
								}
							}
					}
				}
				
				cout<<"\nUPDATED!\n"<<endl;
				display();
				
				Opt:
				cout<<"\nWould you like to continue? (Y/N) ";
				cin>>con;
				upcon = toupper(con);
				
				switch (upcon){
					case 'Y':
						system("cls");
						display();
						continue;
					case 'N':
						return 0;
					default:
						cout<<"\nThat was not an option...\nPlease try again"<<endl;
						goto Opt;
				}
				break;
			case 'N':
				NTry:
				cout<<"\nYou can reserve seats #4 to #17";
				cout<<"\nChoose a seat (4 - 17): ";
				while (true){
					cin>>seat;
					if (!cin){
						cout<<"\nOnly enter an integer.";
						cout<<"\nChoose a seat (4 - 17): ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;	
					}
					else break;
				}
            	
            	if(seat<=0||seat>18){
					cout<<"Please enter a number only within the options.\n";
					goto NTry;
				}
				
				for (int r = 0; r < 2; r++){
					for (int c = 0; c < 11; c++){
							if (buss [r][c] == seat){
								if (seat <= 3){
									cout<<"\nSorry to say but this is only for senior citizens.";
									cout<<"\nPlease try again."<<endl;
									goto NTry;
								}
								if (bus [r][c] == "x" || bus [r][c] == "[CR]"){
									cout<<"\nYou are trying to reserve in an occupied seat.";
									cout<<"\nPlease check our available seats and try again."<<endl;
									goto NTry;
								}
								else {								
									cout<<"\nRESERVED!";
									bus [r][c] = "x";		
								}
							}
					}
				}
				cout<<"\nUPDATED!\n"<<endl;
				display();
				
				Opt2:
				cout<<"\nWould you like to continue? (Y/N) ";
				cin>>con;
				upcon = toupper(con);
				
				switch (upcon){
					case 'Y':
						system("cls");
						display();
						continue;
					case 'N':
						return 0;
					default:
						cout<<"\nThat was not an option...\nPlease try again"<<endl;
						goto Opt2;
				}
				break;
				break;
			default:
				cout<<"\nThat was not an option...\nPlease try again"<<endl;
				continue;
		}
		break;	
	}
	return 0;
}

