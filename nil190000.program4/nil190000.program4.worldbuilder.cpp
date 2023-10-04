#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;

struct User{
    string name;
    char map_symbol;
    string quest;
    string nonsense;
    int row_loc;
    int col_loc;
};

struct Creature{
    string creature_name;
    char creature_map_symbol;
    int creature_row_loc;
    int creature_col_loc;
};

struct Grid{
    char grid_map_symbol;
    int grid_row_loc;
    int grid_col_loc;
};

void myName(){
    cout << "Nathaniel Locklear\n";
    cout << "CS 1337.502\n";
    cout << "Program #4\n";
    cout << "--------------------\n";
}

void createUser(User *userPtr){
    string name;
    string quest;
    string answer;
    char symbol;
    int row;
    int col;

    cout << "What is your name?\n";
    getline(cin, name);
    cout << endl;
    cout << "What is your quest?\n";
    getline(cin, quest);

    int randNum = rand() % 3 + 1;
    if(randNum == 1){
        cout << "What is your favorite color?\n";
    }else if(randNum == 2){
        cout << "What is the capital of Assyria?\n";
    }else if(randNum == 3){
        cout << "What is the airspeed velocity of an unladen swallow?\n";
    }
    getline(cin, answer);

    cout << "What is your symbol?\n";
    cin >> symbol;
    cout << endl;

    cout << "What row are you in?\n";
    cin >> row;
    cout << endl;

    cout << "What column are you in?\n";
    cin >> col;
    cout << endl;

    userPtr -> name = name;
    userPtr -> quest = quest;
    userPtr -> map_symbol = symbol;
    userPtr -> row_loc = row;
    userPtr -> col_loc = col;
    userPtr -> nonsense = answer;
}

void createCreature(vector <Creature> *creaturePtr){
    string name;
    char symbol;
    int row;
    int col;

    cout << "What is its name?\n";
    getline(cin, name);
    cout << endl;

    cout << "What is its symbol?\n";
    cin >> symbol;
    cout << endl;

    cout << "What row is it in?\n";
    cin >> row;
    cout << endl;

    cout << "What column is it in?\n";
    cin >> col;
    cout << endl;

    struct Creature *newCreature;
    newCreature = new struct Creature;

    newCreature -> creature_name = name;
    newCreature -> creature_map_symbol = symbol;
    newCreature -> creature_row_loc = row;
    newCreature -> creature_col_loc = col;

    creaturePtr -> push_back(*newCreature);
}

void createTerrain(vector <Grid> *terrain){
    int row;
    string symbol_char;

    cout << "What row will this be?\n";
    cin >> row;
    cout << endl;

    cout << "Please type 10 characters\n";
    cin >> symbol_char;
    struct Grid *newGrid;
    for(int i = 0; i < 10; i++){

        newGrid = new struct Grid;
        newGrid -> grid_row_loc = row;
        newGrid -> grid_col_loc = i;
        newGrid -> grid_map_symbol = symbol_char[i];

        terrain -> push_back(*newGrid);
    }

}

void saveFile(User userFile, vector <Creature> creatureFile, vector <Grid> gridFile){
    ofstream saveFile;
    saveFile.open("bigGame.txt");

    if(saveFile.is_open()){
        saveFile << userFile.name << "," << userFile.quest << "," << userFile.nonsense << "," << userFile.map_symbol << ","
        << userFile.row_loc << "," << userFile.col_loc << endl;

        saveFile << creatureFile.size() << endl;
        for(int i = 0; i < creatureFile.size(); i++){
            saveFile << creatureFile[i].creature_name << "," << creatureFile[i].creature_map_symbol << ","
            << creatureFile[i].creature_row_loc << "," << creatureFile[i].creature_col_loc << endl;
        }

        saveFile << gridFile.size() << endl;
        for(int i = 0; i < gridFile.size(); i++){
            saveFile << gridFile[i].grid_map_symbol << "," << gridFile[i].grid_row_loc << ","
            << gridFile[i].grid_col_loc << endl;
        }
    }
    saveFile.close();
}

void menu(){
    vector <Grid> gridVec;
    vector <Creature> creatureVec;
    User user;
    int num = 0;

    while(num != 5){
        cout << "1. Create User\n";
        cout << "2. Create Creature\n";
        cout << "3. Create a row of terrain\n";
        cout << "4. Save File\n";
        cout << "5. Quit\n";
        cout << "==========================\n";
        cout << "::>";
        cin >> num;
        cin.ignore();

        switch(num){
            case 1 :
                createUser(&user);
                break;
            case 2 :
                createCreature(&creatureVec);
                break;
            case 3 :
                createTerrain(&gridVec);
                break;
            case 4 :
                saveFile(user, creatureVec, gridVec);
                break;
        }
    }
}



int main() {
    srand(time(NULL));
    myName();
    menu();
}
