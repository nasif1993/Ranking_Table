/*
Task: H1
Family Name: Mannan
Given Name: Nasif
Matriculation number: 3055949
Uni-Email: nasif.mannan@stud.uni-due.de
Course of Studies: ISE CSE
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;

struct team{
	string name;
	int collected_points;
	int done_matches;
};

bool mycompare(team a, team b){
	if(a.collected_points == b.collected_points)
		return a.done_matches < b.done_matches;
	return a.collected_points > b.collected_points;
}

void Initialization_Teams(team team_array[], int no_of_teams){
	/* Setting team names */
	cout<<"Input of Teams"<<endl;
	cout<<"====================="<<endl;
	int i = 0;
	for(i=0;i<no_of_teams;i++){
		string teamName;
		cout<<"team "<<i+1<<": ";
		cin>>teamName;
		team_array[i].name = teamName;
	}
	/* Setting team collected points and done matches to 0 */
	for(i=0;i<no_of_teams;i++)
		team_array[i].collected_points = 0;

	for(i=0;i<no_of_teams;i++)
		team_array[i].done_matches = 0;
}

void output_game_table(team team_array[], int no_of_teams){
	int i = 0;
	cout<<endl;
	cout<<left<<setw(15)<<"Points"<<left<<setw(15)<<"Done Matches"<<left<<setw(15)<<"Name"<<endl;
	for(i=0;i<no_of_teams;i++){
		cout<<left<<setw(15)<<team_array[i].collected_points<<left<<setw(15)<<team_array[i].done_matches
		<<left<<setw(15)<<team_array[i].name<<endl;
	}
}

int choose_team(team team_array[], int no_of_teams){
	int i = 0;
	cout<<endl;
	cout<<"teams"<<endl;
	cout<<"====================="<<endl;
	for(i=0;i<no_of_teams;i++){
		cout<<left<<setw(5)<<i+1<<left<<setw(15)<<team_array[i].name<<endl;
	}
	cout<<"choose team by number:";
	int team_chosen;
	cin>>team_chosen;
	return team_chosen-1;
}

void store_game_points(team team_array[], int no_of_teams, int index, int points){
	team_array[index].collected_points += points;
	team_array[index].done_matches += 1;
}

void reset_game_table(team team_array[], int no_of_teams){
	int i;
	/* Setting team collected points and done matches to 0 */
	for(i=0;i<no_of_teams;i++)
		team_array[i].collected_points = 0;

	for(i=0;i<no_of_teams;i++)
		team_array[i].done_matches = 0;
}

int main(){
	int no_of_teams;
	cout<<"number of teams: ";
	cin>>no_of_teams;
	team team_array[no_of_teams];
	Initialization_Teams(team_array, no_of_teams);
	cout<<"\nInitial ranking"<<endl;
	cout<<"====================="<<endl;
	output_game_table(team_array, no_of_teams);

	int flag = 0, choice;
	while(true){
		cout<<endl;
		cout<<"0  end"<<endl;
		cout<<"1  add result of a match"<<endl;
		cout<<"2  show ranking"<<endl;
		cout<<"9  reset points"<<endl;
		cout<<"your choice: ";
		cin>>choice;

		if(choice == 0){
			break;
		}

		if(choice == 1){
			cout<<"please choose team 1?"<<endl;
			int team1 = choose_team(team_array, no_of_teams);
			cout<<"please choose team 2?"<<endl;
			int team2 = choose_team(team_array, no_of_teams);
			if(team1 == team2)
				cout<<"*** sorry teams need to be different ***"<<endl;
			else{
				cout<<"Input as [points of "<<team_array[team1].name<<"] : [points of "<<team_array[team2].name<<"]? ";
				string score;
				getline(cin, score);
				getline(cin, score);
				string score1 = "", score2 = "";
				int length = score.length(), j = 0;
				while(score[j] != ' '){
					score1 += score[j];
					j++;
				}
				j++;
				while(score[j] != ' '){
					j++;
				}
				j++;
				while(j<length){
					score2 += score[j];
					j++;
				}
				store_game_points(team_array, no_of_teams, team1, atoi(score1.c_str()));
				store_game_points(team_array, no_of_teams, team2, atoi(score2.c_str()));
				// sort the array
				sort(team_array, team_array+no_of_teams, mycompare);
			}
		}
		else if(choice == 2){
			cout<<"\nranking"<<endl;
			cout<<"====================="<<endl;
			output_game_table(team_array, no_of_teams);
		}
		else if(choice == 9){
			reset_game_table(team_array, no_of_teams);
		}
	}
	return 0;
}
