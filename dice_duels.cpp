// Dice Duels created by Michael A Berry in Q1 2017

// #include "stdafx.h" // for visual studio compiler
#include "dice_duels_header.h" // used to call functions in other cpp files
#include <iostream>
#include <cstdlib> // using rand and srand
#include <time.h> // using time to seed srand
using namespace std;

bool tutorial_mode = 0; // tutorial mode enabled if true

class Character
{
public:
    Character()   // constructor used to set stats
    {
        strength = 2;
        speed = 2;
        health = 5;
        stamina = 3;
        advantage = 0;
    }
    friend class Combat;
    int getHealth()
    {
        return health;    // used by main function to check for end game condition
    }
private:
    int strength, speed, health, stamina, advantage; // stats are private
    int *health_ptr = &health;
    int *advantage_ptr = &advantage;
};

class Combat
{
public:
    Character Player1;
    Character Player2;
    int Player1_d8_result, Player2_d8_result, Player2_selection, combat_score;
    void resolve_combat(int Player1_selection)
    {
        if (Player2.advantage == 0)
        {
            Player2_selection = rand() % 4 + 1;
        }
        else
        {
            Player2_selection = rand() % 2 + 1;
        }
        Player1_d8_result = rand() % 8 + 1; // roll d8 for Player 1
        Player2_d8_result = rand() % 8 + 1; // roll d8 for Player 2
        cin.ignore();
        if (Player1_selection == 1)
        {
            cout << "You selected strong attack and your opponent selected ";
            if (Player2_selection == 1)
            {
                cout << "strong attack.\n";
                cin.get();
                if (tutorial_mode)
                {
                    dice_duels_tutorial(1);
                }
                strong_vs_strong();
            }
            else if (Player2_selection == 2)
            {
                cout << "quick attack.\n";
                cin.get();
                if (tutorial_mode)
                {
                    dice_duels_tutorial(2);
                }
                strong_vs_quick();
            }
            else if (Player2_selection == 3)
            {
                cout << "block.\n";
                cin.get();
                if (tutorial_mode)
                {
                    dice_duels_tutorial(3);
                }
                strong_vs_block();
            }
            else if (Player2_selection == 4)
            {
                cout << "dodge.\n";
                cin.get();
                if (tutorial_mode)
                {
                    dice_duels_tutorial(4);
                }
                strong_vs_dodge();
            }
        }
        if (Player1_selection == 2)
        {
            cout << "You selected quick attack and your opponent selected ";
            if (Player2_selection == 1)
            {
                cout << "strong attack.\n";
                cin.get();
                if (tutorial_mode)
                {
                    dice_duels_tutorial(2);
                }
                quick_vs_strong();
            }
            else if (Player2_selection == 2)
            {
                cout << "quick attack.\n";
                cin.get();
                if (tutorial_mode)
                {
                    dice_duels_tutorial(5);
                }
                quick_vs_quick();
            }
            else if (Player2_selection == 3)
            {
                cout << "block.\n";
                cin.get();
                if (tutorial_mode)
                {
                    dice_duels_tutorial(6);
                }
                quick_vs_block();
            }
            else if (Player2_selection == 4)
            {
                cout << "dodge.\n";
                cin.get();
                if (tutorial_mode)
                {
                    dice_duels_tutorial(7);
                }
                quick_vs_dodge();
            }
        }
        if (Player1_selection == 3)
        {
            cout << "You selected block and your opponent selected ";
            if (Player2_selection == 1)
            {
                cout << "strong attack.\n";
                cin.get();
                if (tutorial_mode)
                {
                    dice_duels_tutorial(3);
                }
                block_vs_strong();
            }
            else if (Player2_selection == 2)
            {
                cout << "quick attack.\n";
                cin.get();
                if (tutorial_mode)
                {
                    dice_duels_tutorial(6);
                }
                block_vs_quick();
            }
            else if (Player2_selection == 3)
            {
                cout << "block.\n";
                cin.get();
                if (tutorial_mode)
                {
                    dice_duels_tutorial(8);
                }
                block_vs_block();
            }
            else if (Player2_selection == 4)
            {
                cout << "dodge.\n";
                cin.get();
                if (tutorial_mode)
                {
                    dice_duels_tutorial(9);
                }
                block_vs_dodge();
            }
        }
        if (Player1_selection == 4)
        {
            cout << "You selected dodge and your opponent selected ";
            if (Player2_selection == 1)
            {
                cout << "strong attack.\n";
                cin.get();
                if (tutorial_mode)
                {
                    dice_duels_tutorial(4);
                }
                dodge_vs_strong();
            }
            else if (Player2_selection == 2)
            {
                cout << "quick attack.\n";
                cin.get();
                if (tutorial_mode)
                {
                    dice_duels_tutorial(7);
                }
                dodge_vs_quick();
            }
            else if (Player2_selection == 3)
            {
                cout << "block.\n";
                cin.get();
                if (tutorial_mode)
                {
                    dice_duels_tutorial(9);
                }
                dodge_vs_block();
            }
            else if (Player2_selection == 4)
            {
                cout << "dodge.\n";
                cin.get();
                if (tutorial_mode)
                {
                    dice_duels_tutorial(10);
                }
                dodge_vs_dodge();
            }
        }
        reset_advantage();
        // display health totals for both players
        cout << "After this round of combat, you have " << Player1.health << " health and your opponent has " << Player2.health << " health.\n";
        cin.get();
    }
private:
    // functions for changing health and advantage
    void deal_damage(int damage, int player)
    {
        if (player == 1)
        {
            cout << "Your opponent deals " << damage << " damage to you.\n";
            *Player1.health_ptr -= damage;
        }
        else
        {
            cout << "You deal " << damage << " damage to your opponent.\n";
            *Player2.health_ptr -= damage;
        }
        cin.get();
    }
    void gain_advantage(int player)
    {
        // to simplify resetting advantage to zero each round, set advantage to 2
        // at the end of the round: if (advantage > 0) { advantage--; }
        // this will cause advantage to return to zero unless it was earned this round
        if (player == 1)
        {
            cout << "You gain advantage for the next turn.\n";
            *Player1.advantage_ptr = 2;
        }
        else
        {
            cout << "Your opponent gains advantage for the next turn.\n";
            *Player2.advantage_ptr = 2;
        }
        cin.get();
        if (tutorial_mode)
        {
            dice_duels_tutorial(11);
        }
    }
    void reset_advantage()
    {
        if (*Player1.advantage_ptr > 0)
        {
            (*Player1.advantage_ptr)--;
        }
        if (*Player2.advantage_ptr > 0)
        {
            (*Player2.advantage_ptr)--;
        }
    }
    // combat resolution functions
    void strong_vs_strong()
    {
        cout << "Press enter to roll a d8 for your strong attack...";
        cin.get();
        cout << "You rolled " << Player1_d8_result << " for a total of " << Player1_d8_result + Player1.advantage + Player1.strength << ".";
        cin.get();
        cout << "Your opponent rolled " << Player2_d8_result << " for a total of " << Player2_d8_result + Player2.advantage + Player2.strength << ".";
        cin.get();
        combat_score = (Player1_d8_result + Player1.advantage + Player1.strength) - (Player2_d8_result + Player2.advantage + Player2.strength);
        // determine the winner of combat and assign damage
        if (combat_score == 0)
        {
            cout << "The result is a tie; no damage is dealt.\n";
            cin.get();
        }
        else if (combat_score > 0 && combat_score <= 4)
        {
            deal_damage(1, 2);
        }
        else if (combat_score >= 5)
        {
            deal_damage(2, 2);
        }
        else if (combat_score < 0 && combat_score >= -4)
        {
            deal_damage(1, 1);
        }
        else if (combat_score <= -5)
        {
            deal_damage(2, 1);
        }
    }
    void strong_vs_quick()
    {
        cout << "Your opponent will roll a d8 to determine if her quick attack succeeds... ";
        cin.get();
        cout << "Your opponent rolled " << Player2_d8_result << " for a total of " << Player2_d8_result + Player2.advantage + Player2.speed << ".";
        cin.get();
        combat_score = Player2_d8_result + Player2.advantage + Player2.speed;
        if (combat_score >= 6)
        {
            cout << "Your opponent's quick attack succeeds.";
            cin.get();
            deal_damage(1, 1);
        }
        else
        {
            cout << "Your opponent's quick attack fails.";
            cin.get();
            cout << "Press enter to roll a d8 for your strong attack...";
            cin.get();
            cout << "You rolled " << Player1_d8_result << " for a total of " << Player1_d8_result + Player1.advantage + Player1.strength << ".";
            cin.get();
            combat_score = Player1_d8_result + Player1.advantage + Player1.strength;
            if (combat_score <= 4)
            {
                deal_damage(1, 2);
            }
            else if (combat_score >= 5 && combat_score <= 8)
            {
                deal_damage(2, 2);
            }
            else if (combat_score >= 9)
            {
                deal_damage(3, 2);
            }
        }
    }
    void strong_vs_block()
    {
        cout << "Press enter to roll a d8 for your strong attack...";
        cin.get();
        cout << "You rolled " << Player1_d8_result << " for a total of " << Player1_d8_result + Player1.advantage + Player1.strength << ".";
        cin.get();
        combat_score = Player1_d8_result + Player1.advantage + Player1.strength;
        if (combat_score < 9)
        {
            cout << "Your attack is blocked; no damage is dealt.\n";
            cin.get();
        }
        else if (combat_score >= 9)
        {
            cout << "Your attack smashes through your opponent's defenses!";
            cin.get();
            deal_damage(3, 2);
        }
    }
    void strong_vs_dodge()
    {
        cout << "Your opponent will roll a d8 to determine if her dodge succeeds...";
        cin.get();
        cout << "Your opponent rolled " << Player2_d8_result << " for a total of " << Player2_d8_result + Player2.advantage + Player2.speed << ".";
        cin.get();
        combat_score = Player2_d8_result + Player2.advantage + Player2.speed;
        if (combat_score >= 6)
        {
            cout << "Your opponent deftly evades your attack!";
            cin.get();
            gain_advantage(2);
        }
        else
        {
            cout << "Your opponent fumbles and is hit with the full force of your attack!";
            cin.get();
            deal_damage(3, 2);
        }
    }
    void quick_vs_strong()
    {
        cout << "Roll a d8 to determine if your quick attack succeeds... ";
        cin.get();
        cout << "You rolled " << Player1_d8_result << " for a total of " << Player1_d8_result + Player1.advantage + Player1.speed << ".";
        cin.get();
        combat_score = Player1_d8_result + Player1.advantage + Player1.speed;
        if (combat_score >= 6)
        {
            cout << "Your quick attack succeeds.";
            cin.get();
            deal_damage(1, 2);
        }
        else
        {
            cout << "Your quick attack fails. Your opponent will roll a d8 for her strong attack...";
            cin.get();
            cout << "Your opponent rolled " << Player2_d8_result << " for a total of " << Player2_d8_result + Player2.advantage + Player2.strength << ".";
            cin.get();
            combat_score = Player2_d8_result + Player2.advantage + Player2.strength;
            if (combat_score <= 4)
            {
                deal_damage(1, 1);
            }
            else if (combat_score >= 5 && combat_score <= 8)
            {
                deal_damage(2, 1);
            }
            else if (combat_score >= 9)
            {
                deal_damage(3, 1);
            }
        }
    }
    void quick_vs_quick()
    {
        cout << "Press enter to roll a d8 for your quick attack...";
        cin.get();
        cout << "You rolled " << Player1_d8_result << " for a total of " << Player1_d8_result + Player1.advantage + Player1.speed << ".";
        cin.get();
        cout << "Your opponent rolled " << Player2_d8_result << " for a total of " << Player2_d8_result + Player2.advantage + Player2.speed << ".";
        cin.get();
        combat_score = (Player1_d8_result + Player1.advantage + Player1.speed) - (Player2_d8_result + Player2.advantage + Player2.speed);
        // determine the winner of combat and assign damage
        if (combat_score == 0)
        {
            cout << "The result is a tie; no damage is dealt.\n";
            cin.get();
        }
        else if (combat_score > 0)
        {
            deal_damage(1, 2);
        }
        else
        {
            deal_damage(1, 1);
        }
    }
    void quick_vs_block()
    {
        cout << "Press enter to roll a d8 for your quick attack...";
        cin.get();
        cout << "You rolled " << Player1_d8_result << " for a total of " << Player1_d8_result + Player1.advantage + Player1.speed << ".";
        cin.get();
        combat_score = Player1_d8_result + Player1.advantage + Player1.speed;
        if (combat_score < 9)
        {
            cout << "Your attack is blocked; no damage is dealt.\n";
            cin.get();
        }
        else if (combat_score >= 9)
        {
            cout << "With lightning speed, you strike before your opponent can raise his defenses!";
            cin.get();
            deal_damage(1, 2);
        }
    }
    void quick_vs_dodge()
    {
        cout << "Press enter to roll a d8 for your quick attack...";
        cin.get();
        cout << "You rolled " << Player1_d8_result << " for a total of " << Player1_d8_result + Player1.advantage + Player1.speed << ".";
        cin.get();
        cout << "Your opponent will roll a d8 to determine if her dodge succeeds...";
        cin.get();
        cout << "Your opponent rolled " << Player2_d8_result << " for a total of " << Player2_d8_result + Player2.advantage + Player2.speed << ".";
        cin.get();
        combat_score = (Player1_d8_result + Player1.advantage + Player1.speed) - (Player2_d8_result + Player2.advantage + Player2.speed);
        // determine the winner of combat and assign damage
        if (combat_score == 0)
        {
            cout << "Tie goes to the runner. Your opponent narrowly evades your attack!\n";
            cin.get();
            gain_advantage(2);
        }
        else if (combat_score > 0)
        {
            cout << "Your opponent's attempt to evade your attack is in vain.";
            cin.get();
            deal_damage(1, 2);
        }
        else
        {
            cout << "Your opponent deftly evades your attack.\n";
            cin.get();
            gain_advantage(2);
        }
    }
    void block_vs_strong()
    {
        cout << "Your opponent will roll a d8 for her strong attack...";
        cin.get();
        cout << "Your opponent rolled " << Player2_d8_result << " for a total of " << Player2_d8_result + Player2.advantage + Player2.strength << ".";
        cin.get();
        combat_score = Player2_d8_result + Player2.advantage + Player2.strength;
        if (combat_score < 9)
        {
            cout << "You successfully block your opponent's attack; no damage is dealt.\n";
            cin.get();
        }
        else if (combat_score >= 9)
        {
            cout << "You attempt to stand your ground, but are overwhelmed by your opponent's ferocious attack!";
            cin.get();
            deal_damage(3, 1);
        }
    }
    void block_vs_quick()
    {
        cout << "Your opponent will roll a d8 for her quick attack...";
        cin.get();
        cout << "Your opponent rolled " << Player2_d8_result << " for a total of " << Player2_d8_result + Player2.advantage + Player2.speed << ".";
        cin.get();
        combat_score = Player2_d8_result + Player2.advantage + Player2.speed;
        if (combat_score < 9)
        {
            cout << "You block your opponent's attack; no damage is dealt.\n";
            cin.get();
        }
        else if (combat_score >= 9)
        {
            cout << "You attempt to raise your shield, but it is too late...";
            cin.get();
            deal_damage(1, 1);
        }
    }
    void block_vs_block()
    {
        cout << "You warily raise your shield; your opponent does the same.\n";
        cin.get();
    }
    void block_vs_dodge()
    {
        cout << "You defend yourself and carefully eye your opponent. She tries to flank you, but you cautiously follow her movements.\n";
        cin.get();
    }
    void dodge_vs_strong()
    {
        cout << "Roll a d8 to determine if your dodge succeeds... ";
        cin.get();
        cout << "You rolled " << Player1_d8_result << " for a total of " << Player1_d8_result + Player1.advantage + Player1.speed << ".";
        cin.get();
        combat_score = Player1_d8_result + Player1.advantage + Player1.speed;
        if (combat_score >= 6)
        {
            cout << "You deftly evade your opponent's attack!\n";
            cin.get();
            gain_advantage(1);
        }
        else
        {
            cout << "You fail to evade your opponent's devestating blow!";
            cin.get();
            deal_damage(3, 1);
        }
    }
    void dodge_vs_quick()
    {
        cout << "Your opponent will roll a d8 for her quick attack...";
        cin.get();
        cout << "Your opponent rolled " << Player2_d8_result << " for a total of " << Player2_d8_result + Player2.advantage + Player2.speed << ".";
        cin.get();
        cout << "Press enter to roll a d8 to determine if your dodge succeeds...";
        cin.get();
        cout << "You rolled " << Player1_d8_result << " for a total of " << Player1_d8_result + Player1.advantage + Player1.speed << ".";
        cin.get();
        combat_score = (Player1_d8_result + Player1.advantage + Player1.speed) - (Player2_d8_result + Player2.advantage + Player2.speed);
        // determine the winner of combat and assign damage
        if (combat_score == 0)
        {
            cout << "Tie goes to the runner. You narrowly evades your opponent's attack!\n";
            cin.get();
            gain_advantage(1);
        }
        else if (combat_score < 0)
        {
            cout << "Your attempt to evade your opponent's attack is in vain.";
            cin.get();
            deal_damage(1, 1);
        }
        else
        {
            cout << "You deftly evade your opponent's attack.\n";
            cin.get();
            gain_advantage(1);
        }
    }
    void dodge_vs_block()
    {
        cout << "Your opponent defends herself and watches you intently. You attempt to flank her, but she pivots and keeps you in here sight.\n";
        cin.get();
    }
    void dodge_vs_dodge()
    {
        cout << "You and your opponent circle one another, neither letting the other out of sight.\n";
        cin.get();
    }
};

int main()
{
    int response; // used for action selection by player
    srand(time(NULL));
    Combat duel; // create an object of type Combat

    cout << "Welcome to Dice Duels! You will duel against a computer opponent. Press enter to continue. Good luck!\n";
    cin.get();
    if (tutorial_mode)
    {
        dice_duels_tutorial(0);
    }
    while (duel.Player1.getHealth() > 0 && duel.Player2.getHealth() > 0)
    {
        //ask the player to make a selection
        cout << "Please select an action:\n1. Strong Attack\n2. Quick Attack\n";
        cout << "3. Block\n4. Dodge\n\nYour selection: ";
        cin >> response;
        while (cin.fail() || response < 1 || response > 4)
        {
            cin.clear();
            cin.ignore(99, '\n'); // ignore up to 99 characters
            cout << "Your selection is invalid. Please make a valid selection: ";
            cin >> response;
        }
        duel.resolve_combat(response);
    }
    if (duel.Player1.getHealth() <= 0)
    {
        cout << "The computer has won, better luck next time!\n\n";
    }
    else
    {
        cout << "You have bested your opponent. Good job!\n\n";
    }
    return 0;
}
