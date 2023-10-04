#include <iostream>
#include <string>
#include <vector>
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

void loadFile(User *userPtr, vector <Creature> *creatureVec, vector <Grid> *gridVec){
    ifstream loadFile;
    loadFile.open("bigGame.txt");
    string data;
    string numC;
    string numT;

    if(loadFile.is_open()){
        getline(loadFile, data, ',');
        userPtr -> name = data;
        getline(loadFile, data, ',');
        userPtr -> quest = data;
        getline(loadFile, data, ',');
        userPtr -> nonsense = data;
        getline(loadFile, data, ',');
        userPtr -> map_symbol = data[0];
        getline(loadFile, data, ',');
        userPtr -> row_loc = stoi(data);
        getline(loadFile, data, '\n');
        userPtr -> col_loc = stoi(data);

        getline(loadFile, numC);
        for(int i = 0; i < stoi(numC); i++){
            Creature *newCreature = new Creature;
            getline(loadFile, data, ',');
            newCreature -> creature_name = data;
            getline(loadFile, data, ',');
            newCreature -> creature_map_symbol = data[0];
            getline(loadFile, data, ',');
            newCreature -> creature_row_loc = stoi(data);
            getline(loadFile, data, '\n');
            newCreature -> creature_col_loc = stoi(data);

            creatureVec->push_back(*newCreature);
        }
        getline(loadFile, numT);
        for(int i = 0; i < stoi(numT); i++){
            Grid *newGrid = new Grid;
            getline(loadFile, data, ',');
            newGrid -> grid_map_symbol = data[0];
            getline(loadFile, data, ',');
            newGrid -> grid_row_loc = stoi(data);
            getline(loadFile, data, '\n');
            newGrid -> grid_col_loc = stoi(data);

            gridVec->push_back(*newGrid);
        }
    }
}

void display(User user, vector <Creature> creature, vector <Grid> grid) {
    char display[10][10];
    int row;
    int col;

    for(row = 0; row < 10; row++){
        for(col = 0; col < 10; col++){
            display[row][col] = '.';
        }
    }

    for(int i = 0; i < grid.size(); i++){
        display[grid[i].grid_row_loc][grid[i].grid_col_loc] = grid[i].grid_map_symbol;
    }

    for(int i = 0; i < creature.size(); i++){
        display[creature[i].creature_row_loc][creature[i].creature_col_loc] = creature[i].creature_map_symbol;
    }
    display[user.row_loc][user.col_loc] = user.map_symbol;

    for(row = 0; row < 10; row++){
        for(col = 0; col < 10; col++){
            cout << display[row][col];
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < creature.size(); i++){
        cout << creature[i].creature_map_symbol << ":" << creature[i].creature_name << endl;
    }
    cout << endl;
    cout << user.map_symbol << ":" << user.name << endl;
    cout << user.quest << endl;
    cout << user.nonsense << endl;
}

void myName(){
    cout << "Nathaniel Locklear\n";
    cout << "CS 1337.502\n";
    cout << "Program #4\n";
    cout << "--------------------\n";
}

int main(){
    User user;
    vector <Creature> creature;
    vector <Grid> grid;

    myName();
    loadFile(&user, &creature, &grid);
    display(user, creature, grid);
}

