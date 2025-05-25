#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printASCIITitle() {
    cout << R"(
 _       _________ _______  _        _______  _        _______          ______            _______  _        _______ 
( (    /|\__   __/(  ____ \| \    /\(  ___  )( \      (  ___  )        (  ___ \ |\     /|(  ___  )( (    /|(  ___  )
|  \  ( |   ) (   | (    \/|  \  / /| (   ) || (      | (   ) |        | (   ) )| )   ( || (   ) ||  \  ( || (   ) |
|   \ | |   | |   | (_____ |  (_/ / | (___) || |      | (___) |        | (__/ / | |   | || (___) ||   \ | || (___) |
| (\ \) |   | |   (_____  )|   _ (  |  ___  || |      |  ___  |        |  __ (  | |   | ||  ___  || (\ \) ||  ___  |
| | \   |   | |         ) ||  ( \ \ | (   ) || |      | (   ) |        | (  \ \ | |   | || (   ) || | \   || (   ) |
| )  \  |___) (___/\____) ||  /  \ \| )   ( || (____/\| )   ( |        | )___) )| (___) || )   ( || )  \  || )   ( |
|/    )_)\_______/\_______)|_/    \/|/     \|(_______/|/     \|        |/ \___/ (_______)|/     \||/    )_)|/     \|
                                                                                                                    
)";
}

void printHealthStatus(int hp) {
    if (hp > 75) cout << "You feel strong and determined.\n";
    else if (hp > 50) cout << "You're wounded but still fighting.\n";
    else if (hp > 25) cout << "Your injuries are severe. Each step is painful.\n";
    else cout << "You're barely holding on. The end feels near.\n";
}

int main() {
    srand(time(0));
    int hp = 100;
    int stage = 1;
    bool alive = true;
    bool hasJournal = false;
    bool builtRaft = false;
    int choice;

    // Introduction with richer narrative
    printASCIITitle();
    cout << "=== The World of Niskala Buana ===\n\n";
    cout << "Niskala Buana is a world full of magic, conflict, and mystery.\n";
    cout << "It is divided into two major regions:\n";
    cout << "- Askara Dhara: bright, civilized, and full of life.\n";
    cout << "- Syama Dhara: dark, dangerous, and largely unexplored.\n\n";
    cout << "Among the brave who ventured into Syama Dhara,\n";
    cout << "stood a legendary couple — an elite adventurer and his warrior wife,\n";
    cout << "who was carrying their first child.\n\n";
    cout << "What was meant to be their final mission became a nightmare.\n";
    cout << "Trapped for months, ambushed by monsters, and surrounded by death,\n";
    cout << "they were the only survivors.\n\n";
    cout << "As her due date neared, the wife made a final sacrifice —\n";
    cout << "she gave all her magical energy to protect their unborn child.\n";
    cout << "Her life faded with that spell.\n\n";
    cout << "Now, the husband must fight alone — to protect their legacy.\n";
    cout << "\n[Press Enter to begin your journey...]\n";
    cin.ignore();

    while (stage <= 10 && alive) {
        system("cls||clear");
        cout << "\n=== Day " << stage << " in Syama Dhara ===\n";
        cout << "HP: " << hp << "/100\n";
        printHealthStatus(hp);

        // Show child's barrier status
        int barrierStrength = 50 + (rand() % 50);
        cout << "Child's Barrier: " << barrierStrength << "% - ";
        if (barrierStrength > 75) cout << "Strong and bright\n";
        else if (barrierStrength > 50) cout << "Flickering slightly\n";
        else if (barrierStrength > 25) cout << "Growing weak\n";
        else cout << "Dangerously faint\n";

        switch (stage) {
        case 1: {
            cout << "\nThe twisted trees of the Blackroot Forest whisper in the unnatural wind.\n";
            cout << "Your boots sink into the spongy moss as you navigate between gnarled roots.\n";
            cout << "A low growl rumbles from the undergrowth. Something is tracking you.\n\n";

            cout << "1. Hide in the thorn bushes (Risk injury but might avoid detection)\n";
            cout << "2. Stand your ground and prepare to fight\n";
            cout << "3. Run toward a nearby rock formation\n";
            cout << "4. Set an ambush using your remaining supplies\n";
            cout << "5. [Use Journal] Consult the journal for local creatures (if found)\n";

            cin >> choice;

            if (choice == 1) {
                int outcome = rand() % 100;
                if (outcome > 30) {
                    cout << "\nYou press into the thorny brush, ignoring the pain as spines pierce your skin.\n";
                    cout << "The beast sniffs the air but passes by. You emerge bleeding but alive.\n";
                    hp -= 15;
                }
                else {
                    cout << "\nThe creature detects your movement! It lunges through the bushes!\n";
                    cout << "You barely escape its claws, leaving shreds of your cloak behind.\n";
                    hp -= 30;
                }
            }
            else if (choice == 2) {
                cout << "\nYou stand tall, weapon ready. The creature - a mangled shadow-wolf - pounces!\n";
                cout << "After a brutal exchange, you drive it off with wounds to show for it.\n";
                hp -= 20;
            }
            else if (choice == 3) {
                int outcome = rand() % 100;
                if (outcome > 50) {
                    cout << "\nYou scramble up the rocks just as the beast snaps at your heels!\n";
                    cout << "From this vantage point, you spot a safer path forward.\n";
                }
                else {
                    cout << "\nYou trip on the slippery stones! The creature rakes your leg before you kick it away.\n";
                    hp -= 25;
                }
            }
            else if (choice == 4) {
                cout << "\nYou rig a snare with your last rope and retreat. A satisfying snap echoes\n";
                cout << "through the trees as the creature yelps in pain. You finish it off humanely.\n";
                cout << "+5 HP from the minor victory\n";
                hp = min(100, hp + 5);
            }
            else if (choice == 5 && hasJournal) {
                cout << "\nThe journal mentions these 'shadow-wolves' fear silver. You fashion a crude\n";
                cout << "amulet from a coin in your pouch. The beast whimpers and retreats!\n";
            }
            else {
                cout << "\nIndecision proves costly. The creature attacks before you act!\n";
                hp -= 25;
            }
            break;
        }

        case 2: {
            cout << "\nA yawning cave mouth gapes before you, its darkness more absolute than\n";
            cout << "the forest's twilight. Strange fungi glow faintly along its walls.\n";
            cout << "The air carries a metallic scent that makes your teeth ache.\n\n";

            cout << "1. Enter cautiously, using a glowstone for light\n";
            cout << "2. Circle around the cave (lose time but avoid danger)\n";
            cout << "3. Search the entrance for anything useful\n";
            cout << "4. [Use Raft] Attempt to float past via an underground stream (if built)\n";
            cout << "5. Call into the darkness to test for echoes\n";

            cin >> choice;

            if (choice == 1) {
                int outcome = rand() % 100;
                if (outcome > 40) {
                    cout << "\nThe cave provides shelter from predators. You find edible mushrooms\n";
                    cout << "and a small spring. The rest does you good.\n";
                    hp = min(100, hp + 20);
                }
                else {
                    cout << "\nDeep in the cave, something stirs! You barely escape as the walls\n";
                    cout << "themselves seem to come alive behind you!\n";
                    hp -= 30;
                }
            }
            else if (choice == 2) {
                cout << "\nThe detour takes hours but keeps you under open sky. As you round\n";
                cout << "the hillside, you spot a potential campsite for later.\n";
            }
            else if (choice == 3) {
                cout << "\nAt the cave mouth you find discarded tools - perhaps from another\n";
                cout << "unfortunate traveler. The rusted knife could prove useful.\n";
            }
            else if (choice == 4 && builtRaft) {
                cout << "\nYour raft serves you well as you navigate the subterranean waterways.\n";
                cout << "Though the journey is terrifying, you emerge unharmed on the far side.\n";
            }
            else if (choice == 5) {
                cout << "\nYour voice echoes strangely, returning layered with whispers that\n";
                cout << "weren't your own! A pressure builds in your skull. You stagger back.\n";
                hp -= 15;
            }
            else {
                cout << "\nYour hesitation leaves you exposed at the cave mouth. A rockfall\n";
                cout << "startled by your movement grazes your shoulder.\n";
                hp -= 10;
            }
            break;
        }

        
        case 3: {
            cout << "\nYou reach a clearing lit by pale moonlight. In the center stands a stone monolith\n";
            cout << "covered in runes. Nearby, a broken campfire still smolders.\n\n";
            cout << "1. Inspect the monolith closely\n";
            cout << "2. Rest at the abandoned campfire\n";
            cout << "3. Search the perimeter for threats\n";
            cout << "4. Attempt to decipher the runes\n";

            cin >> choice;

            if (choice == 1) {
                cout << "\nThe stone pulses as you touch it. A jolt of energy surges through you.\n";
                cout << "+10 HP, but a shadow now follows you silently...\n";
                hp = min(100, hp + 10);
            }
            else if (choice == 2) {
                cout << "\nYou rest briefly. A warmth lingers in the ashes.\n";
                cout << "You regain some strength.\n";
                hp = min(100, hp + 5);
            }
            else if (choice == 3) {
                cout << "\nYou find claw marks in the trees... you're not alone.\n";
                cout << "As you return, something darts through the trees.\n";
            }
            else if (choice == 4) {
                int outcome = rand() % 100;
                if (outcome > 50) {
                    cout << "\nYou decipher a passage about the 'Umbral Stalker' and how to weaken it.\n";
                    hasJournal = true;
                    cout << "You now carry the knowledge of ancient wards. (Journal found)\n";
                }
                else {
                    cout << "\nThe runes pulse violently! Your head throbs and you stagger.\n";
                    hp -= 10;
                }
            }
            else {
                cout << "\nYou hesitate, and the air turns cold. A distant scream chills your blood.\n";
                hp -= 5;
            }
            break;
        }

        case 4: {
            cout << "\nYou come across a deep ravine with an old rope bridge.\n";
            cout << "The wind howls, and the boards creak ominously.\n\n";
            cout << "1. Cross the rope bridge carefully\n";
            cout << "2. Climb down the ravine manually\n";
            cout << "3. Search for another route around\n";
            cout << "4. Wait and observe the area\n";

            cin >> choice;

            if (choice == 1) {
                int outcome = rand() % 100;
                if (outcome > 40) {
                    cout << "\nYou cross safely, though the bridge sways with every step.\n";
                }
                else {
                    cout << "\nHalfway across, a plank breaks! You fall and injure your leg.\n";
                    hp -= 20;
                }
            }
            else if (choice == 2) {
                cout << "\nThe climb is treacherous. You slip but manage to hold on.\n";
                hp -= 10;
            }
            else if (choice == 3) {
                cout << "\nIt takes hours, but you find an animal trail leading to a hidden path.\n";
                cout << "You also spot strange tracks...\n";
            }
            else if (choice == 4) {
                cout << "\nYou spot a creature waiting under the bridge.\n";
                cout << "You avoid a deadly ambush.\n";
            }
            else {
                cout << "\nYour indecision causes you to waste daylight. You grow more fatigued.\n";
                hp -= 5;
            }
            break;
        }

        case 5: {
            cout << "\nA river blocks your path, rushing violently.\n";
            cout << "Bits of debris float by — remnants of a previous camp?\n\n";
            cout << "1. Try to build a raft using debris\n";
            cout << "2. Wade through the shallows\n";
            cout << "3. Follow the river upstream\n";
            cout << "4. Set up camp and wait for dawn\n";

            cin >> choice;

            if (choice == 1) {
                cout << "\nYou spend hours lashing logs and rope together.\n";
                cout << "It floats! (Raft built)\n";
                builtRaft = true;
            }
            else if (choice == 2) {
                cout << "\nThe current is stronger than it looks! You nearly drown.\n";
                hp -= 30;
            }
            else if (choice == 3) {
                cout << "\nYou find a shallow crossing but are ambushed by river serpents!\n";
                hp -= 15;
            }
            else if (choice == 4) {
                cout << "\nYou rest fitfully. The river sings dark lullabies...\n";
                hp += 5;
            }
            else {
                cout << "\nWasting time near the river draws predators.\n";
                hp -= 10;
            }
            break;
        }

        case 6: {
            cout << "\nA ruined temple looms in the distance, half-buried in vines.\n";
            cout << "Flickers of arcane energy dance near the entrance.\n\n";
            cout << "1. Enter the temple\n";
            cout << "2. Search the surroundings\n";
            cout << "3. Meditate outside to connect with the energy\n";
            cout << "4. Destroy any remaining magic with a sigil\n";

            cin >> choice;

            if (choice == 1) {
                cout << "\nYou encounter cursed spirits but fight them off. You claim a relic.\n";
                hp -= 20;
                hasJournal = true;
            }
            else if (choice == 2) {
                cout << "\nYou find herbs and a healing tonic. +15 HP.\n";
                hp = min(100, hp + 15);
            }
            else if (choice == 3) {
                cout << "\nVisions of your wife and child guide you. You feel emotionally steadier.\n";
                hp += 10;
            }
            else if (choice == 4) {
                cout << "\nThe explosion of light blinds you temporarily. You avoid the temple’s pull.\n";
            }
            else {
                cout << "\nA phantom emerges, angered by your hesitation.\n";
                hp -= 10;
            }
            break;
        }

        case 7: {
            cout << "\nYou reach a burnt village. Ash covers everything.\n";
            cout << "A single figure stands motionless near a collapsed house.\n\n";
            cout << "1. Approach the figure\n";
            cout << "2. Search for supplies in ruins\n";
            cout << "3. Light a fire to signal allies\n";
            cout << "4. Leave quickly\n";

            cin >> choice;

            if (choice == 1) {
                cout << "\nThe figure vanishes. In its place: a journal left open.\n";
                hasJournal = true;
                cout << "(You now carry forbidden knowledge)\n";
            }
            else if (choice == 2) {
                cout << "\nYou find bandages and preserved food. +10 HP\n";
                hp = min(100, hp + 10);
            }
            else if (choice == 3) {
                cout << "\nYou see a faint signal far off. Someone may be watching...\n";
            }
            else if (choice == 4) {
                cout << "\nYou feel a chill as you leave. Something doesn’t want you to go...\n";
                hp -= 5;
            }
            else {
                cout << "\nThe ashes rise and form vague shapes. You choke and cough.\n";
                hp -= 15;
            }
            break;
        }

        case 8: {
            cout << "\nYou come to a cliffside path overlooking the River of Sighs far below.\n";
            cout << "Storm clouds gather, and the wind grows fierce.\n\n";
            cout << "1. Try to climb down early\n";
            cout << "2. Search for a sheltered ledge to wait\n";
            cout << "3. Use rope and tools to rappel safely\n";
            cout << "4. Call out for help\n";

            cin >> choice;

            if (choice == 1) {
                cout << "\nThe rocks are slick! You slip and bruise your side.\n";
                hp -= 15;
            }
            else if (choice == 2) {
                cout << "\nYou find a ledge and shelter from the storm.\n";
                hp += 5;
            }
            else if (choice == 3) {
                cout << "\nYour careful descent pays off. You reach the base safely.\n";
            }
            else if (choice == 4) {
                cout << "\nA strange voice answers... but it’s not human.\n";
                hp -= 10;
            }
            else {
                cout << "\nA lightning strike nearby jolts your nerves.\n";
                hp -= 5;
            }
            break;
        }

        case 9: {
            cout << "\nYou find a quiet glade where butterflies made of light dance around you.\n";
            cout << "This place feels... holy. Sacred.\n\n";
            cout << "1. Rest and let the light heal you\n";
            cout << "2. Offer a prayer for your child\n";
            cout << "3. Explore deeper\n";
            cout << "4. Take a sample of the glowing flora\n";

            cin >> choice;

            if (choice == 1) {
                cout << "\nYou fall into a peaceful sleep. When you wake, wounds are mended.\n";
                hp = min(100, hp + 20);
            }
            else if (choice == 2) {
                cout << "\nA soft voice responds: 'Your journey is not yet done.'\n";
                hp += 10;
            }
            else if (choice == 3) {
                cout << "\nYou find markings showing a secret path to the river.\n";
            }
            else if (choice == 4) {
                cout << "\nThe plant reacts violently! Spores sting your eyes.\n";
                hp -= 10;
            }
            else {
                cout << "\nThe magic of the place grows dim at your indecision.\n";
                hp -= 5;
            }
            break;
        }

        case 10: {
            cout << "\nThe River of Sighs marks the border between realms. Just across its\n";
            cout << "swift waters lies potential salvation. But something has been waiting.\n\n";

            cout << "The Umbral Stalker emerges from the treeline - a creature of living\n";
            cout << "shadow that has pursued you since the first day. It knows what you carry.\n\n";

            cout << "1. Make your final stand (Your HP determines outcome)\n";
            cout << "2. Attempt to cross the river with your child\n";
            cout << "3. Use forbidden magic from the journal (if found)\n";
            cout << "4. Offer yourself in exchange for the child's passage\n";

            cin >> choice;

            if (choice == 1) {
                if (hp > 75) {
                    cout << "\nWith a warrior's cry, you charge! The battle is brutal, but your\n";
                    cout << "sheer determination drives the creature back. As it recoils, you\n";
                    cout << "hurl your child across the boundary where the barrier flares to life!\n\n";

                    cout << "The Stalker turns its attention fully to you now...\n";
                    cout << "But your child is safe. That's all that matters.\n";
                    cout << "Ending: The Sacrifice Complete\n";
                }
                else if (hp > 30) {
                    cout << "\nYou fight with all your remaining strength. Just as you're about to\n";
                    cout << "fall, a group of border rangers appears! Their silver arrows drive\n";
                    cout << "the creature away. Both you and your child survive... for now.\n";
                    cout << "Ending: Bitter Rescue\n";
                }
                else {
                    cout << "\nYou raise your weapon, but your injuries are too great. The last\n";
                    cout << "thing you see is the creature enveloping your child's light...\n";
                    cout << "Ending: Darkness Prevails\n";
                    alive = false;
                }
            }
            else if (choice == 2) {
                if (builtRaft) {
                    cout << "\nYour raft holds as you paddle desperately. The Stalker's claws\n";
                    cout << "rake the water just behind you. You cross the boundary as the\n";
                    cout << "creature's howl of frustration echoes behind you.\n";
                    cout << "Ending: Narrow Escape\n";
                }
                else {
                    cout << "\nThe current is too strong! You're swept downstream into the\n";
                    cout << "creature's waiting grasp. Your child's light is extinguished...\n";
                    cout << "Ending: Taken by the Current\n";
                    alive = false;
                }
            }
            else if (choice == 3 && hasJournal) {
                cout << "\nYou recite the ancient words. Power floods your veins as the magic\n";
                cout << "tears the Stalker apart. But the price is high - your body begins\n";
                cout << "to petrify. With your last movement, you push your child to safety.\n";
                cout << "Ending: The Last Spell\n";
                alive = false;
            }
            else if (choice == 4) {
                cout << "\nThe creature seems to consider your offer. It takes you into its\n";
                cout << "embrace as your child is carried safely across by some unseen force.\n";
                cout << "Your final thought is of your wife's smile...\n";
                cout << "Ending: A Parent's Love\n";
                alive = false;
            }
            else {
                cout << "\nIndecision proves fatal. The Stalker strikes before you can act!\n";
                cout << "Ending: Swift Darkness\n";
                alive = false;
            }
            break;
        }
        }

        // Between stage events
        if (alive && stage < 10) {
            int event = rand() % 4;
            switch (event) {
            case 0:
                cout << "\n[The child's barrier flickers as something in the forest watches...]\n";
                break;
            case 1:
                cout << "\n[You hear distant howls that don't sound entirely animal...]\n";
                break;
            case 2:
                cout << "\n[Your wife's voice whispers in your mind: \"Stay strong...\"]\n";
                break;
            case 3:
                cout << "\n[The very air of Syama Dhara seems to drain your energy...]\n";
                hp -= 5;
                break;
            }
        }

        // Check for death
        if (hp <= 0) {
            cout << "\nYour vision darkens as the forest's whispers grow louder...\n";
            cout << "The last glimmer you see is your child's protective barrier fading...\n";
            cout << "Ending: Claimed by Syama Dhara\n";
            alive = false;
        }

        // Progress only if still alive
        if (alive) {
            stage++;
            cout << "\nPress enter to continue your journey...";
            cin.ignore();
            cin.ignore();
        }
    }

    cout << "\n=== Journey's End ===\n";
    cout << "Final HP: " << hp << "\n";
    if (hp > 50) cout << "You remained strong until the end.\n";
    else if (hp > 0) cout << "You barely survived each trial.\n";
    cout << "\nThank you for playing Niskala Buana: The Unseen Sacrifice.\n";
    return 0;
}