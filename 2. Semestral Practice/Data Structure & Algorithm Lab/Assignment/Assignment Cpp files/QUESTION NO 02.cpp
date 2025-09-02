#include <iostream>
#include <string>
using namespace std;  
struct Player {
    string name;
    Player* next;
};
Player* createPlayerList() {
    Player* team = new Player{"Batsman 1", new Player{"Batsman 2", new Player{"Batsman 3", 
	new Player{"Batsman 4", new Player{"Batsman 5", NULL}}}}};
    return team;
}
void rotateBatsmenClockwise(Player** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    Player* current = *head;
    Player* lastBatsman = NULL;

    while (current->next != NULL) {
        lastBatsman = current;
        current = current->next;
    }
    current->next = *head;
    *head = current;
    lastBatsman->next = NULL;
}

void printBattingOrder(Player* head) {
    Player* current = head;
    while (current != NULL) {
        cout << current->name;
        current = current->next;
        if (current != NULL) {
            cout << " -> ";
        }
    }
    cout << endl;
}

int main() {
    Player* team = createPlayerList();

    cout << "Batting Orders for 9 Matches:" << endl;

    for (int match = 1; match <= 9; match++) {
        cout << "Match " << match << ": ";
        printBattingOrder(team);
        rotateBatsmenClockwise(&team);
    }

    return 0;
}

