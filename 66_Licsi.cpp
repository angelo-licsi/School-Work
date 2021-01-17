#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <ctime>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
void clrscr();
int main()
{   
	//initialization=======================================================================================================
	
	
	//declare variables    
    const int SuitNum = 2; //number of suits in a deck
    const int FacesNum = 13;//number of cards in each suit
    int CardNum = 0;// variable to keep track of number of cards in deck
    string card = ""; //variable to hold array combos being assigned to vector
    string p1name, p2name;
    int turn = 1;
    string PlayedCardP1;
    string PlayedCardP2;
    int scorep1 = 0;
    int scorep2 = 0;
    const string suits[] = {"H","S"}; //create array for card labels
  
	//unordered map for face labels and to hold values
    unordered_map<std::string,int> CardValue = 
	{
    {"2",2},
    {"3",3},
    {"4",4},
    {"5",5},
    {"6",6},
    {"7",7},
    {"8",8},
    {"9",9},
    {"10",10},
    {"J",11},
    {"Q",12},
    {"K",13},
    {"A",1}
    };
    
	//unordered map declaration to bind values to deck
    unordered_map<string,int> DeckValue;
  
	//Create vector to store deck names in & player's hands
    vector<string> Cards;    
	vector<string> P1Hand;
	vector<string> P2Hand;
	
	//Generate the deck
    for (int i = 0; i < SuitNum;i++) //iterate through suits
	{ 
       for (auto j : CardValue)
        {
            card = j.first + suits[i]; //declare card
            DeckValue[card] = CardValue[j.first];//add card to deck map and assign value
            Cards.push_back(card);  // add card to vector
            CardNum++;// raise card number for every card added to deck
        }
	}
	
	
	//intro================================================================================================================
	cout<<"Let's Get Started!\n";
	Sleep(1500);
	cout<<"Player 1 Enter Your Name: ", cin>>p1name;
	cout<<"Player 2 Enter Your Name: ", cin>>p2name;
	cout<<endl;	
	cout<<"Shuffling the Deck and Dealing the Cards...";
	Sleep(2000);
	{system("cls");}
	
		//game internal========================================================================================================
		
		//constant header
		cout<<"Welcome to 66!"<<endl;
		Sleep(1000);
		cout<<"Turn "<<turn<<endl;
 	
		//display cards for player 1
		cout<<endl;
		srand(time(0));
		cout<<p1name<<" (Score: "<<scorep1<<") ";
		while (CardNum > 13)
		{
 	       int RCard = rand()%CardNum;//generate a random number based on number of cards left in deck
 	       string DrawCard = Cards.at(RCard); // access a random card
 	       P1Hand.push_back(DrawCard); //add card to hand
		   Cards.erase(Cards.begin() + RCard); // remove cards from vector so they cant be called twice
 	       CardNum--; //lower available cards
 	       cout<<"["<<DrawCard<<"]"; //print card and its value
 	   	}
 	    cout<<endl;
	    cout<<"Select Card to Play: ",cin>>PlayedCardP1;
	    P1Hand.erase(std::find(P1Hand.cbegin(), P1Hand.cend(), PlayedCardP1)); // remove played card from available cards
 
 
 	   //display cards for player 2
		cout<<endl;
		srand(time(0));
		cout<<p2name<<" (Score: "<<scorep2<<") ";
		while (CardNum > 0)
		{
 	       int RCard = rand()%CardNum;//generate a random number based on number of cards left in deck
 	       string DrawCard = Cards.at(RCard); // access a random card
 	       P2Hand.push_back(DrawCard); //add card to hand
 	       Cards.erase(Cards.begin() + RCard); // remove cards from vector so they cant be called twice
 	       CardNum--; //lower available cards
 	       cout<<"["<<DrawCard<<"]"; //print card and its value
 	   	}
 	    cout<<endl;
		cout<<"Select Card to Play: ",cin>>PlayedCardP2;
 	    cout<<endl;
 	    P2Hand.erase(std::find(P2Hand.cbegin(), P2Hand.cend(), PlayedCardP2)); // remove played card from available cards
 	    
 	    //result
		cout<<PlayedCardP1<< " vs. "<<PlayedCardP2<<endl;
		cout<<endl;
		if ( DeckValue[PlayedCardP1] > DeckValue[PlayedCardP2] ) {scorep1=scorep1+DeckValue[PlayedCardP1]+DeckValue[PlayedCardP2], 
			cout<<"Player 1 Wins (+"<<DeckValue[PlayedCardP1]+DeckValue[PlayedCardP2]<<")\n";}
			else {scorep2=scorep2+DeckValue[PlayedCardP2]+DeckValue[PlayedCardP1],
			 cout<<"Player 2 Wins (+"<<DeckValue[PlayedCardP2]+DeckValue[PlayedCardP1]<<")\n";}
		Sleep(3000);
		
		
		//turns 2 and above
			do
			{
				{system("cls");}; //clear
				turn=turn+1;
				cout<<"Turn "<<turn<<endl;
				cout<<endl;
				cout<<p1name<<" (Score: "<<scorep1<<") ";
		 		for (const auto & s : P1Hand) std::cout<<"["<<s<<"]"; //display cards for p1
		 		cout<<endl;
			    cout<<"Select Card to Play: ",cin>>PlayedCardP1;
		 	    cout<<endl;
		 	    P1Hand.erase(std::find(P1Hand.cbegin(), P1Hand.cend(), PlayedCardP1)); // remove played card from available cards
		 	    
				cout<<p2name<<" (Score: "<<scorep2<<") ";
		 		for (const auto & s : P2Hand) std::cout<<"["<<s<<"]"; //display cards for p2
		 		cout<<endl;
			    cout<<"Select Card to Play: ",cin>>PlayedCardP2;
		 	    cout<<endl;
		 	    P2Hand.erase(std::find(P2Hand.cbegin(), P2Hand.cend(), PlayedCardP2)); // remove played card from available cards
		 	    
		 	    //result
				cout<<PlayedCardP1<< " vs. "<<PlayedCardP2<<endl;
				cout<<endl;
				if ( DeckValue[PlayedCardP1] > DeckValue[PlayedCardP2] ) {scorep1=scorep1+DeckValue[PlayedCardP1]+DeckValue[PlayedCardP2], 
					cout<<"Player 1 Wins (+"<<DeckValue[PlayedCardP1]+DeckValue[PlayedCardP2]<<")\n";}
				else {scorep2=scorep2+DeckValue[PlayedCardP2]+DeckValue[PlayedCardP1],
			 		cout<<"Player 2 Wins (+"<<DeckValue[PlayedCardP2]+DeckValue[PlayedCardP1]<<")\n";}
				Sleep(3000);
				
				//final output
				if (scorep1 >= 66 || scorep2 >= 66) 
				{
					if (scorep1 >= 66) {cout<<endl<<"With a score of "<<scorep1<<" "<<p1name<< "has won the game!\n";
							cout<<p2name<<" scored "<<scorep2<<"."; break;}
					else {cout<<endl<<"With a score of "<<scorep2<<" "<<p2name<< " has won the game!\n";
							cout<<p1name<<" scored "<<scorep1<<"."; break;}
				} 
			}while (scorep1 <= 66 || scorep2 <= 66);
}
