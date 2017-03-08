// this function displays the tutorial text if tutorial_mode == 1

// #include "stdafx.h" // for visual studio compiler
#include "dice_duels_header.h"
#include <iostream>
using namespace std;

void dice_duels_tutorial(int index)
{
    switch (index)
    {
    case 0:
        cout << "TUTORIAL: Each turn, you will select one of four actions:";
        cin.get();
        cout << "Strong attack: Can deal 1-3 damage. Less likely to hit than a quick attack.";
        cin.get();
        cout << "Quick attack: Can deal 1 damage. More likely to hit than a strong attack.";
        cin.get();
        cout << "Block: Can prevent damage from quick and strong attacks.";
        cin.get();
        cout << "Dodge: Attempt to evade. Can prevent damage from quick and strong attacks. Grants advantage if successful.\n";
        cin.get();
        break;
    case 1:
        cout << "TUTORIAL: Strong attack vs strong attack results in both characters rolling a d8.";
        cin.get();
        cout << "Each character's strength stat plus the die roll are compared.";
        cin.get();
        cout << "In the case of a tie, no damage is dealt. If there is a winner, damage is determined as follows:";
        cin.get();
        cout << "If a character won by 4 or less, deal 1 damage. If a character won by 5 or more, deal 2 damage.\n";
        cin.get();
        break;
    case 2:
        cout << "\nTUTORIAL: Strong attack vs quick attack results in the character who performed the quick attack rolling a d8.";
        cin.get();
        cout << "The quick attacker's speed stat plus the die roll represents how fast the attack is.";
        cin.get();
        cout << "If the result is 6 or more, the attack succeeds and 1 damage is dealt to the opponent.";
        cin.get();
        cout << "If the result is 5 or less, the attack fails and the opponent's strong attack succeeds.";
        cin.get();
        cout << "The strong attacker's strength stat plus the die roll represents how strong the attack is.";
        cin.get();
        cout << "If the result is 4 or less, the attack deals 1 damage.";
        cin.get();
        cout << "If the result is 5-8, the attack deals 2 damage.";
        cin.get();
        cout << "If the result is 9 or more, the attack deals 3 damage.\n";
        cin.get();
        break;
    case 3:
        cout << "\nTUTORIAL: Strong attack vs block results in the character who performed the attack rolling a d8.";
        cin.get();
        cout << "The attacker's strength stat plus the die roll represents how strong the attack is.";
        cin.get();
        cout << "If the result is 9 or more, the attack succeeds and 3 damage is dealt to the opponent.";
        cin.get();
        cout << "If the result is 8 or less, the attack is successfully blocked.\n";
        cin.get();
        break;
    case 4:
        cout << "\nTUTORIAL: Strong attack vs dodge results in the character who performed the dodge rolling a d8.";
        cin.get();
        cout << "The dodger's speed stat plus the die roll represents how quick his or her evasive maneuver is.";
        cin.get();
        cout << "If the result is 6 or more, the attack is successfully evaded. The evader has advantage on his or her next action.";
        cin.get();
        cout << "If the result is 5 or less, the attack is not evaded; it deals 3 damage.\n";
        cin.get();
        break;
    case 5:
        cout << "TUTORIAL: Quick attack vs quick attack results in both characters rolling a d8.";
        cin.get();
        cout << "Each character's speed stat plus the die roll are compared.";
        cin.get();
        cout << "In the case of a tie, no damage is dealt. If there is a winner, he or she deals 1 damage.\n";
        cin.get();
        break;
    case 6:
        cout << "\nTUTORIAL: Quick attack vs block results in the character who performed the attack rolling a d8.";
        cin.get();
        cout << "The attacker's speed stat plus the die roll represents how quick the attack is.";
        cin.get();
        cout << "If the result is 9 or more, the attack succeeds and 1 damage is dealt to the opponent.";
        cin.get();
        cout << "If the result is 8 or less, the attack is successfully blocked.\n";
        cin.get();
        break;
    case 7:
        cout << "TUTORIAL: Quick attack vs dodge results in both characters rolling a d8.";
        cin.get();
        cout << "Each character's speed stat plus the die roll are compared.";
        cin.get();
        cout << "If the attacker's result is greater, the attack succeeds and 1 damage is dealt to the opponent.";
        cin.get();
        cout << " If there is a tie or the dodger's result is greater, the attack is successfully evaded. The evader has advantage on his or her next action.\n";
        cin.get();
        break;
    case 8:
        cout << "TUTORIAL: Block vs block results in the end of the turn.\n";
        cin.get();
        break;
    case 9:
        cout << "TUTORIAL: Block vs dodge results in the end of the turn.\n";
        cin.get();
        break;
    case 10:
        cout << "TUTORIAL: Dodge vs dodge results in the end of the turn.\n";
        cin.get();
        break;
    case 11:
        cout << "TUTORIAL: Advantage grants +1 to any attack or dodge score for the next round only.\n";
        cin.get();
        break;
    }
}
