#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

int CreateCharacter();
int SaveCharacter();
int LoadCharacter();
int DieRoller();
int CombatGenerator();
int TrackerExperience();
int TrackerInventory();
int TrackerEquipment();
int TrackerMagic();
//int HelpAndTips();
//int settingsMenu();

int characterBarbarianMoney();
int characterBardMoney();
int characterClericMoney();
int characterDruidMoney();
int characterFighterMoney();
int characterMonkMoney();
int characterPaladinMoney();
int characterRangerMoney();
int characterRogueMoney();
int characterSorcererMoney();
int characterWarlockMoney();
int characterWizardMoney();

int characterBarbarianHP();
int characterBardHP();
int characterClericHP();
int characterDruidHP();
int characterFighterHP();
int characterMonkHP();
int characterPaladinHP();
int characterRangerHP();
int characterRogueHP();
int characterSorcererHP();
int characterWarlockHP();
int characterWizardHP();

int AttributeModification();
int skillModAssignment();
int rollGeneratorAssignment();

int startingMoney, currentLevel, EXP,
    attributeStr, attributeDex, attributeCon, attributeInt, attributeWis, attributeCha,
    saveStr, saveDex, saveCon, saveInt, saveWis, saveCha,
    acrobatDex, animalHandleWis, arcanaInt, athleticStr, deceptionCha, historyInt,
    insightWis, intimidateCha, investigateInt, medicineWis, natureInt, perceptionWis,
    religionInt, handSlightDex, stealthDex, survivalWis, armourClass,
    initiative, speed, hitPoints, hitPointMax,
    modifierStr, modifierDex, modifierCon, modifierInt, modifierWis, modifierCha,
    AttributeModifier, AttributeToBeModified, rollOptionFun, attributeResult,
    rollAttr1, rollAttr2, rollAttr3, rollAttr4, rollAttr5, rollAttr6, rollAttr7;
string playerName, characterName, sex, race, alignment1, alignment2, Class, languagePrimary, languageSecondary;
int age;

int main()
{
    int menuChoice;
    do
    {
        cout<<"\n  Dungeons & Dragons: Fifth Edition\n";
        cout<<"  1.  Create Character\n";        //player with gm (possible gm password for functions marked "with gm")
        cout<<"  2.  Save Character\n";          //player
        cout<<"  3.  Load Character\n";          //player
        cout<<"  4.  Roll Die\n";                //player with gm
        cout<<"  5.  Combat\n";                  //player with gm
        cout<<"  6.  Manage Experience\n";       //player with gm
        cout<<"  7.  Manage Inventory\n";        //player
        cout<<"  8.  Manage Equipped Items\n";   //player
        cout<<"  9.  Manage Magic\n";            //player
        cout<<"  10. Exit Game\n";               //player
        //cout<<"  11. Help\n";                    //player and/or gm
        //cout<<"  12. Settings\n";                //player with gm
        cout<<"  Enter your choice: ";
        cin>>menuChoice;
        while ((!cin)||(menuChoice<1)||(menuChoice>10))
        {
            if (!cin)
            {
                cout<<" ERROR: Your input was not recognized.\n";
                cin.clear();
                cin.ignore(100,'\n');
                cout<<"  Enter your choice: ";
                cin>>menuChoice;
            }
            else if ((menuChoice<1)||(menuChoice>10))
            {
                cout<<" ERROR: Your choice does not coincide with a menu choice.\n";
                cin.clear();
                cin.ignore(100,'\n');
                cout<<"  Enter your choice: ";
                cin>>menuChoice;
            }
        }
        switch (menuChoice)
        {
            case 1:
                CreateCharacter();
                break;
            case 2:
                SaveCharacter();
                break;
            case 3:
                LoadCharacter();
                break;
            case 4:
                DieRoller();
                break;
            case 5:
                CombatGenerator();
                break;
            case 6:
                TrackerExperience();
                break;
            case 7:
                TrackerInventory();
                break;
            case 8:
                TrackerEquipment();
                break;
            case 9:
                TrackerMagic();
                break;
            case 10:
                return 0;
            //case 11:
                //HelpAndTips();
        }
    }
    while (menuChoice!=10);
}
int CreateCharacter ()
{
    int rollOptionStr, rollOptionDex, rollOptionCon, rollOptionInt, rollOptionWis, rollOptionCha;
    srand((unsigned)time(0));
    currentLevel=1;
    cout<<"\n  Dungeons & Dragons: Fifth Edition Character Creator\n";
    cout<<"\n  Enter your name: ";
    cin>>playerName;

    cout<<"\n  Enter your character's name: ";
    cin>>characterName;

    cout<<"\n  Enter your character's sex: ";
    cin>>sex;

    cout<<"\n  Currently available Races: ";
    cout<<"\n 1.  Aasimar\n 2.  Teifling\n 3.  Elf\n 4.  Human\n 5.  Half-Elf\n 6.  Halfling\n 7.  Dwarf\n 8.  Half-Orc\n 9.  Lizardfolk\n 10. Goblin\n 11. Gnome";
    cout<<"\n  Enter the number of your character's race: ";
    int raceChoice;
    cin>>raceChoice;

    cout<<"\n  Enter your character's age: ";          //make option to roll for age
    cin>>age;
    while (!cin)
    {
        cout<<"\n  ERROR: Your input must be numerical.\n";
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"\n  Enter your character's age: ";
        cin>>age;
    }

    cout<<"\n  Enter your character's first alignment.";
    cout<<"\n  Lawful, Neutral, or Chaotic: ";
    cin>>alignment1;

    cout<<"\n  Enter your character's second alignment.";
    cout<<"\n  Good, Neutral, or Evil: ";
    cin>>alignment2;

    cout<<"\n  Currently available Classes: ";
    cout<<"\n 1.  Barbarian\n 2.  Bard\n 3.  Cleric\n 4.  Druid\n 5.  Fighter\n 6.  Monk\n 7.  Paladin\n 8.  Ranger\n 9.  Rogue\n 10. Sorcerer\n 11. Warlock\n 12. Wizard";
    cout<<"\n  Enter the number of your character's class: ";
    int ClassChoice;
    cin>>ClassChoice;

            //rewrite stat generator assignment into function and place call here
    int chancePercent1, chancePercent2, chancePercent3, chancePercent4, chancePercent5,  chancePercent6, chancePercent7;

    chancePercent1=(rand()%99+1);
    if (chancePercent1<=60)                          //60% chance for full range
        rollAttr1=(rand()%16+3);
    else if (chancePercent1<=100)                     //40% chance for weighted higher range
        rollAttr1=(rand()%12+7);

    chancePercent2=(rand()%99+1);
    if (chancePercent2<=60)
        rollAttr2=(rand()%16+3);
    else if (chancePercent2<=100)
        rollAttr2=(rand()%12+7);

    chancePercent3=(rand()%99+1);
    if (chancePercent3<=60)
        rollAttr3=(rand()%16+3);
    else if (chancePercent3<=100)
        rollAttr3=(rand()%12+7);

    chancePercent4=(rand()%99+1);
    if (chancePercent4<=60)
        rollAttr4=(rand()%16+3);
    else if (chancePercent4<=100)
        rollAttr4=(rand()%12+7);

    chancePercent5=(rand()%99+1);
    if (chancePercent5<=60)
        rollAttr5=(rand()%16+3);
    else if (chancePercent5<=100)
        rollAttr5=(rand()%12+7);

    chancePercent6=(rand()%99+1);
    if (chancePercent6<=60)
        rollAttr6=(rand()%16+3);
    else if (chancePercent6<=100)
        rollAttr6=(rand()%12+7);

    chancePercent7=(rand()%99+1);
    if (chancePercent7<=40)                         //40% chance for re-roll
        rollAttr7=(rand()%16+3);
    else if (chancePercent7<=100)                   //60% chance weighted higher for re-roll
        rollAttr7=(rand()%12+7);

    cout<<"  Roll One:   "<<rollAttr1<<endl;
    cout<<"  Roll Two:   "<<rollAttr2<<endl;
    cout<<"  Roll Three: "<<rollAttr3<<endl;
    cout<<"  Roll Four:  "<<rollAttr4<<endl;
    cout<<"  Roll Five:  "<<rollAttr5<<endl;
    cout<<"  Roll Six:   "<<rollAttr6<<endl;
    cout<<"  Roll Seven: "<<rollAttr7<<endl;

    cout<<"\n  Enter your selection using the number corresponding to the number of the roll for each of the following.";
    cout<<"\n  Strength Entry: ";
    cin>>rollOptionStr;
    while (!cin)
    {
        cout<<"  ERROR: Whatever you just entered isn't right. DO OVER!";
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"\n  Strength Entry: ";
        cin>>rollOptionStr;
    }
    while ((rollOptionStr<1)||(rollOptionStr>7))
    {
        cout<<"  ERROR: That number is NOT an option. DO OVER!";
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"\n  Strength Entry: ";
        cin>>rollOptionStr;
    }
    rollOptionFun=rollOptionStr;
    rollGeneratorAssignment();
    attributeStr=attributeResult;

    cout<<"  Roll One:   "<<rollAttr1<<endl;
    cout<<"  Roll Two:   "<<rollAttr2<<endl;
    cout<<"  Roll Three: "<<rollAttr3<<endl;
    cout<<"  Roll Four:  "<<rollAttr4<<endl;
    cout<<"  Roll Five:  "<<rollAttr5<<endl;
    cout<<"  Roll Six:   "<<rollAttr6<<endl;
    cout<<"  Roll Seven: "<<rollAttr7<<endl;

    cout<<"  Dexterity Entry: ";
    cin>>rollOptionDex;
    while (!cin)
    {
        cout<<"  ERROR: Whatever you just entered isn't right. DO OVER!";
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"\n  Dexterity Entry: ";
        cin>>rollOptionDex;
    }
    while ((rollOptionDex<1)||(rollOptionDex>7))
    {
        cout<<"  ERROR: That number is NOT an option. DO OVER!";
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"\n  Dexterity Entry: ";
        cin>>rollOptionDex;
    }
    rollOptionFun=rollOptionDex;
    rollGeneratorAssignment();
    attributeDex=attributeResult;

    cout<<"  Roll One:   "<<rollAttr1<<endl;
    cout<<"  Roll Two:   "<<rollAttr2<<endl;
    cout<<"  Roll Three: "<<rollAttr3<<endl;
    cout<<"  Roll Four:  "<<rollAttr4<<endl;
    cout<<"  Roll Five:  "<<rollAttr5<<endl;
    cout<<"  Roll Six:   "<<rollAttr6<<endl;
    cout<<"  Roll Seven: "<<rollAttr7<<endl;

    cout<<"  Constitution Entry: ";
    cin>>rollOptionCon;
    while (!cin)
    {
        cout<<"  ERROR: Whatever you just entered isn't right. DO OVER!";
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"\n  Constitution Entry: ";
        cin>>rollOptionCon;
    }
    while ((rollOptionCon<1)||(rollOptionCon>7))
    {
        cout<<"  ERROR: That number is NOT an option. DO OVER!";
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"\n  Constitution Entry: ";
        cin>>rollOptionCon;
    }
    rollOptionFun=rollOptionCon;
    rollGeneratorAssignment();
    attributeCon=attributeResult;

    cout<<"  Roll One:   "<<rollAttr1<<endl;
    cout<<"  Roll Two:   "<<rollAttr2<<endl;
    cout<<"  Roll Three: "<<rollAttr3<<endl;
    cout<<"  Roll Four:  "<<rollAttr4<<endl;
    cout<<"  Roll Five:  "<<rollAttr5<<endl;
    cout<<"  Roll Six:   "<<rollAttr6<<endl;
    cout<<"  Roll Seven: "<<rollAttr7<<endl;
    cout<<"  Intelligence Entry: ";
    cin>>rollOptionInt;
    while (!cin)
    {
        cout<<"  ERROR: Whatever you just entered isn't right. DO OVER!";
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"\n  Intelligence Entry: ";
        cin>>rollOptionInt;
    }
    while ((rollOptionInt<1)||(rollOptionInt>7))
    {
        cout<<"  ERROR: That number is NOT an option. DO OVER!";
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"\n  Intelligence Entry: ";
        cin>>rollOptionInt;
    }
    rollOptionFun=rollOptionInt;
    rollGeneratorAssignment();
    attributeInt=attributeResult;

    cout<<"  Roll One:   "<<rollAttr1<<endl;
    cout<<"  Roll Two:   "<<rollAttr2<<endl;
    cout<<"  Roll Three: "<<rollAttr3<<endl;
    cout<<"  Roll Four:  "<<rollAttr4<<endl;
    cout<<"  Roll Five:  "<<rollAttr5<<endl;
    cout<<"  Roll Six:   "<<rollAttr6<<endl;
    cout<<"  Roll Seven: "<<rollAttr7<<endl;
    cout<<"  Wisdom Entry: ";
    cin>>rollOptionWis;
    while (!cin)
    {
        cout<<"  ERROR: Whatever you just entered isn't right. DO OVER!";
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"\n  Wisdom Entry: ";
        cin>>rollOptionWis;
    }
    while ((rollOptionWis<1)||(rollOptionWis>7))
    {
        cout<<"  ERROR: That number is NOT an option. DO OVER!";
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"\n  Wisdom Entry: ";
        cin>>rollOptionWis;
    }
    rollOptionFun=rollOptionWis;
    rollGeneratorAssignment();
    attributeWis=attributeResult;

    cout<<"  Roll One:   "<<rollAttr1<<endl;
    cout<<"  Roll Two:   "<<rollAttr2<<endl;
    cout<<"  Roll Three: "<<rollAttr3<<endl;
    cout<<"  Roll Four:  "<<rollAttr4<<endl;
    cout<<"  Roll Five:  "<<rollAttr5<<endl;
    cout<<"  Roll Six:   "<<rollAttr6<<endl;
    cout<<"  Roll Seven: "<<rollAttr7<<endl;
    cout<<"  Charisma Entry: ";
    cin>>rollOptionCha;
    while (!cin)
    {
        cout<<"  ERROR: Whatever you just entered isn't right. DO OVER!";
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"\n  Charisma Entry: ";
        cin>>rollOptionCha;
    }
    while ((rollOptionCha<1)||(rollOptionCha>7))
    {
        cout<<"  ERROR: That number is NOT an option. DO OVER!";
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"\n  Charisma Entry: ";
        cin>>rollOptionCha;
    }
    rollOptionFun=rollOptionCha;
    rollGeneratorAssignment();
    attributeCha=attributeResult;

            //modifier call will be here first, then called for in TrackerExperience for level-ups
    AttributeToBeModified=attributeStr;
    AttributeModification();
    modifierStr=AttributeModifier;

    AttributeToBeModified=attributeDex;
    AttributeModification();
    modifierDex=AttributeModifier;

    AttributeToBeModified=attributeCon;
    AttributeModification();
    modifierCon=AttributeModifier;

    AttributeToBeModified=attributeInt;
    AttributeModification();
    modifierInt=AttributeModifier;

    AttributeToBeModified=attributeWis;
    AttributeModification();
    modifierWis=AttributeModifier;

    AttributeToBeModified=attributeCha;
    AttributeModification();
    modifierCha=AttributeModifier;
    skillModAssignment();

    switch (raceChoice)
    {
        case 1:
            race = "Aasimar";
            break;
        case 2:
            race = "Teifling";
            break;
        case 3:
            race = "Elf";
            break;
        case 4:
            race = "Human";
            break;
        case 5:
            race = "Half-Elf";
            break;
        case 6:
            race = "Halfling";
            break;
        case 7:
            race = "Dwarf";
            break;
        case 8:
            race = "Half-Orc";
            break;
        case 9:
            race = "Lizardfolk";
            break;
        case 10:
            race = "Goblin";
            break;
        case 11:
            race = "Gnome";
            break;
    }

    switch (ClassChoice)
    {
        case 1 :
            Class = "Barbarian";
            characterBarbarianMoney();
            characterBarbarianHP();
            break;
        case 2 :
            Class = "Bard";
            characterBardMoney();
            characterBardHP();
            break;
        case 3 :
            Class = "Cleric";
            characterClericMoney();
            characterClericHP();
            break;
        case 4 :
            Class = "Druid";
            characterDruidMoney();
            characterDruidHP();
            break;
        case 5 :
            Class = "Fighter";
            characterFighterMoney();
            characterFighterHP();
            break;
        case 6 :
            Class = "Monk";
            characterMonkMoney();
            characterMonkHP();
            break;
        case 7 :
            Class = "Paladin";
            characterPaladinMoney();
            characterPaladinHP();
            break;
        case 8 :
            Class = "Ranger";
            characterRangerMoney();
            characterRangerHP();
            break;
        case 9 :
            Class = "Rogue";
            characterRogueMoney();
            characterRogueHP();
            break;
        case 10 :
            Class = "Sorcerer";
            characterSorcererMoney();
            characterSorcererHP();
            break;
        case 11 :
            Class = "Warlock";
            characterWarlockMoney();
            characterWarlockHP();
            break;
        case 12 :
            Class = "Wizard";
            characterWizardMoney();
            characterWizardHP();
            break;
    }

            //rewrite race and class choices as functions for all details

    system("cls");
    cout<<"\n  Player Name:     "<<playerName<<endl<<endl;

    cout<<setw(21)<<"Your Character Outline:\n\n";
    cout<<setw(18)<<"Name: "<<characterName<<endl;
    cout<<setw(18)<<"Sex: "<<sex<<endl;
    cout<<setw(18)<<"Race: "<<race<<endl;
    cout<<setw(18)<<"Age: "<<age<<endl;
    cout<<setw(18)<<"Alignment: "<<alignment1<<" "<<alignment2<<endl;
    cout<<setw(18)<<"Class: "<<Class<<endl;
    cout<<setw(18)<<"Current Level: "<<currentLevel<<endl;
    cout<<setw(18)<<"Max HP: "<<hitPointMax<<endl;
    cout<<setw(18)<<"Class Money: "<<startingMoney<<endl;

    cout<<setw(23)<<"Attributes:"<<endl
        <<setw(20)<<"Strength: "<<attributeStr<<endl
        <<setw(20)<<"Dexterity: "<<attributeDex<<endl
        <<setw(20)<<"Constitution: "<<attributeCon<<endl
        <<setw(20)<<"Intelligence: "<<attributeInt<<endl
        <<setw(20)<<"Wisdom: "<<attributeWis<<endl
        <<setw(20)<<"Charisma: "<<attributeCha<<endl;

    cout<<setw(28)<<"Attribute Modifiers:"<<endl
        <<setw(25)<<"Strength Modifier: "<<modifierStr<<endl
        <<setw(25)<<"Dexterity Modifier: "<<modifierDex<<endl
        <<setw(25)<<"Constitution Modifier: "<<modifierCon<<endl
        <<setw(25)<<"Intelligence Modifier: "<<modifierInt<<endl
        <<setw(25)<<"Wisdom Modifier: "<<modifierWis<<endl
        <<setw(25)<<"Charisma Modifier: "<<modifierCha<<endl;

    cout<<setw(23)<<"Skill Modifiers:"<<endl
        <<setw(20)<<"Acrobatics: "<<acrobatDex<<endl
        <<setw(20)<<"Animal Handling: "<<animalHandleWis<<endl
        <<setw(20)<<"Arcana: "<<arcanaInt<<endl
        <<setw(20)<<"Athletics: "<<athleticStr<<endl
        <<setw(20)<<"Deception: "<<deceptionCha<<endl
        <<setw(20)<<"History: "<<historyInt<<endl
        <<setw(20)<<"Insight: "<<insightWis<<endl
        <<setw(20)<<"Intimidation: "<<intimidateCha<<endl
        <<setw(20)<<"Investigation: "<<investigateInt<<endl
        <<setw(20)<<"Medicine: "<<medicineWis<<endl
        <<setw(20)<<"Nature: "<<natureInt<<endl
        <<setw(20)<<"Perception: "<<perceptionWis<<endl
        <<setw(20)<<"Religion: "<<religionInt<<endl
        <<setw(20)<<"Slight of Hand: "<<handSlightDex<<endl
        <<setw(20)<<"Stealth: "<<stealthDex<<endl
        <<setw(20)<<"Survival: "<<survivalWis<<endl;
}
int SaveCharacter()
{
    //create file with formating to be read outside of program
    ofstream CharGenOutput;
    CharGenOutput.open("D&DFifthCharacter.txt");
    CharGenOutput<<"\n  Player Name:     "<<playerName<<endl<<endl;
    CharGenOutput<<setw(21)<<"Your Character Outline:\n\n";
    CharGenOutput<<setw(18)<<"Name: "<<characterName<<endl;
    CharGenOutput<<setw(18)<<"Sex: "<<sex<<endl;
    CharGenOutput<<setw(18)<<"Race: "<<race<<endl;
    CharGenOutput<<setw(18)<<"Age: "<<age<<endl;               //Option to roll for age
    CharGenOutput<<setw(18)<<"Alignment: "<<alignment1<<" "<<alignment2<<endl;
    CharGenOutput<<setw(18)<<"Class: "<<Class<<endl;
    CharGenOutput<<setw(18)<<"Current Level: "<<currentLevel<<endl;
    CharGenOutput<<setw(18)<<"Max HP: "<<hitPointMax<<endl;
    CharGenOutput<<setw(18)<<"Class Money: "<<startingMoney<<endl;
    CharGenOutput<<setw(23)<<"Attributes:"<<endl
                 <<setw(20)<<"Strength: "<<attributeStr<<endl
                 <<setw(20)<<"Dexterity: "<<attributeDex<<endl
                 <<setw(20)<<"Constitution: "<<attributeCon<<endl
                 <<setw(20)<<"Intelligence: "<<attributeInt<<endl
                 <<setw(20)<<"Wisdom: "<<attributeWis<<endl
                 <<setw(20)<<"Charisma: "<<attributeCha<<endl;
    CharGenOutput<<setw(28)<<"Attribute Modifiers:"<<endl
                 <<setw(25)<<"Strength Modifier: "<<modifierStr<<endl
                 <<setw(25)<<"Dexterity Modifier: "<<modifierDex<<endl
                 <<setw(25)<<"Constitution Modifier: "<<modifierCon<<endl
                 <<setw(25)<<"Intelligence Modifier: "<<modifierInt<<endl
                 <<setw(25)<<"Wisdom Modifier: "<<modifierWis<<endl
                 <<setw(25)<<"Charisma Modifier: "<<modifierCha<<endl;
    CharGenOutput<<setw(23)<<"Skill Modifiers:"<<endl
                 <<setw(20)<<"Acrobatics: "<<acrobatDex<<endl
                 <<setw(20)<<"Animal Handling: "<<animalHandleWis<<endl
                 <<setw(20)<<"Arcana: "<<arcanaInt<<endl
                 <<setw(20)<<"Athletics: "<<athleticStr<<endl
                 <<setw(20)<<"Deception: "<<deceptionCha<<endl
                 <<setw(20)<<"History: "<<historyInt<<endl
                 <<setw(20)<<"Insight: "<<insightWis<<endl
                 <<setw(20)<<"Intimidation: "<<intimidateCha<<endl
                 <<setw(20)<<"Investigation: "<<investigateInt<<endl
                 <<setw(20)<<"Medicine: "<<medicineWis<<endl
                 <<setw(20)<<"Nature: "<<natureInt<<endl
                 <<setw(20)<<"Perception: "<<perceptionWis<<endl
                 <<setw(20)<<"Religion: "<<religionInt<<endl
                 <<setw(20)<<"Slight of Hand: "<<handSlightDex<<endl
                 <<setw(20)<<"Stealth: "<<stealthDex<<endl
                 <<setw(20)<<"Survival: "<<survivalWis<<endl;
    CharGenOutput.close();

    cout<<"\n  Your character has been saved to a text file in the same folder this program is in.";
    cout<<"\n  Look for the file named \"D&DFifthCharacter\".";

    //create file that can be loaded in without the formatting
    ofstream CharBase;
    CharBase.open("CharacterLoadable.txt");
    CharBase<<playerName<<endl
            <<characterName<<endl
            <<sex<<endl
            <<race<<endl
            <<age<<endl
            <<alignment1<<endl
            <<alignment2<<endl
            <<Class<<endl
            <<currentLevel<<endl
            <<hitPointMax<<endl
            <<startingMoney<<endl
            <<attributeStr<<endl
            <<attributeDex<<endl
            <<attributeCon<<endl
            <<attributeInt<<endl
            <<attributeWis<<endl
            <<attributeCha<<endl
            <<modifierStr<<endl
            <<modifierDex<<endl
            <<modifierCon<<endl
            <<modifierInt<<endl
            <<modifierWis<<endl
            <<modifierCha<<endl
            <<acrobatDex<<endl
            <<animalHandleWis<<endl
            <<arcanaInt<<endl
            <<athleticStr<<endl
            <<deceptionCha<<endl
            <<historyInt<<endl
            <<insightWis<<endl
            <<intimidateCha<<endl
            <<investigateInt<<endl
            <<medicineWis<<endl
            <<natureInt<<endl
            <<perceptionWis<<endl
            <<religionInt<<endl
            <<handSlightDex<<endl
            <<stealthDex<<endl
            <<survivalWis<<endl;
    CharBase.close();
}
int LoadCharacter()
{
    //load file created without formatting
    ifstream BaseChar;
    BaseChar.open("CharacterLoadable.txt");
    BaseChar>>playerName
            >>characterName
            >>sex
            >>race
            >>age
            >>alignment1
            >>alignment2
            >>Class
            >>currentLevel
            >>hitPointMax
            >>startingMoney
            >>attributeStr
            >>attributeDex
            >>attributeCon
            >>attributeInt
            >>attributeWis
            >>attributeCha
            >>modifierStr
            >>modifierDex
            >>modifierCon
            >>modifierInt
            >>modifierWis
            >>modifierCha
            >>acrobatDex
            >>animalHandleWis
            >>arcanaInt
            >>athleticStr
            >>deceptionCha
            >>historyInt
            >>insightWis
            >>intimidateCha
            >>investigateInt
            >>medicineWis
            >>natureInt
            >>perceptionWis
            >>religionInt
            >>handSlightDex
            >>stealthDex
            >>survivalWis;
    BaseChar.close();
    cout<<"\n  Player Name:     "<<playerName<<endl<<endl;

    cout<<setw(21)<<"Your Character Outline:\n\n";
    cout<<setw(18)<<"Name: "<<characterName<<endl;
    cout<<setw(18)<<"Sex: "<<sex<<endl;
    cout<<setw(18)<<"Race: "<<race<<endl;
    cout<<setw(18)<<"Age: "<<age<<endl;
    cout<<setw(18)<<"Alignment: "<<alignment1<<" "<<alignment2<<endl;
    cout<<setw(18)<<"Class: "<<Class<<endl;
    cout<<setw(18)<<"Current Level: "<<currentLevel<<endl;
    cout<<setw(18)<<"Max HP: "<<hitPointMax<<endl;
    cout<<setw(18)<<"Class Money: "<<startingMoney<<endl;

    cout<<setw(23)<<"Attributes:"<<endl
        <<setw(20)<<"Strength: "<<attributeStr<<endl
        <<setw(20)<<"Dexterity: "<<attributeDex<<endl
        <<setw(20)<<"Constitution: "<<attributeCon<<endl
        <<setw(20)<<"Intelligence: "<<attributeInt<<endl
        <<setw(20)<<"Wisdom: "<<attributeWis<<endl
        <<setw(20)<<"Charisma: "<<attributeCha<<endl;

    cout<<setw(28)<<"Attribute Modifiers:"<<endl
        <<setw(25)<<"Strength Modifier: "<<modifierStr<<endl
        <<setw(25)<<"Dexterity Modifier: "<<modifierDex<<endl
        <<setw(25)<<"Constitution Modifier: "<<modifierCon<<endl
        <<setw(25)<<"Intelligence Modifier: "<<modifierInt<<endl
        <<setw(25)<<"Wisdom Modifier: "<<modifierWis<<endl
        <<setw(25)<<"Charisma Modifier: "<<modifierCha<<endl;

    cout<<setw(23)<<"Skill Modifiers:"<<endl
        <<setw(20)<<"Acrobatics: "<<acrobatDex<<endl
        <<setw(20)<<"Animal Handling: "<<animalHandleWis<<endl
        <<setw(20)<<"Arcana: "<<arcanaInt<<endl
        <<setw(20)<<"Athletics: "<<athleticStr<<endl
        <<setw(20)<<"Deception: "<<deceptionCha<<endl
        <<setw(20)<<"History: "<<historyInt<<endl
        <<setw(20)<<"Insight: "<<insightWis<<endl
        <<setw(20)<<"Intimidation: "<<intimidateCha<<endl
        <<setw(20)<<"Investigation: "<<investigateInt<<endl
        <<setw(20)<<"Medicine: "<<medicineWis<<endl
        <<setw(20)<<"Nature: "<<natureInt<<endl
        <<setw(20)<<"Perception: "<<perceptionWis<<endl
        <<setw(20)<<"Religion: "<<religionInt<<endl
        <<setw(20)<<"Slight of Hand: "<<handSlightDex<<endl
        <<setw(20)<<"Stealth: "<<stealthDex<<endl
        <<setw(20)<<"Survival: "<<survivalWis<<endl;
}
int DieRoller()
{
    //create general die roller for popular dice
    int coinFlip, threeSide, fourSide, sixSide, eightSide, tenSide, twelveSide, twentySide;
    int dieChoice;
    do
    {
        cout<<"  What die are you rolling?\n"
            <<"  1. Coin Flip/d2\n  2. d3\n  3. d4\n  4. d6\n  5. d8\n  6. d10\n  7. d12\n  8. d20\n  9. Exit"
            <<"  Your choice: ";
        cin>>dieChoice;
        while (dieChoice==1)
        {
            int numberOfRolls;
            cout<<"\n  Number of times to flip coin: ";
            cin>>numberOfRolls;
            for (int executions=1; executions<=numberOfRolls; executions++)
            {
                coinFlip=(rand()%2+1);
                cout<<setw(6)<<executions<<setw(12)<<coinFlip<<endl;
            }
            break;
        }
        while (dieChoice==2)
        {
            int numberOfRolls;
            cout<<"\n  Number of times to roll d3: ";
            cin>>numberOfRolls;
            for (int executions=1; executions<=numberOfRolls; executions++)
            {
                threeSide=(rand()%3+1);
                cout<<setw(6)<<executions<<setw(12)<<threeSide<<endl;
            }
            break;
        }
        while (dieChoice==3)
        {
            int numberOfRolls;
            cout<<"\n  Number of times to roll d4: ";
            cin>>numberOfRolls;
            for (int executions=1; executions<=numberOfRolls; executions++)
            {
                fourSide=(rand()%4+1);
                cout<<setw(6)<<executions<<setw(12)<<fourSide<<endl;
            }
            break;
        }
        while (dieChoice==4)
        {
            int numberOfRolls;
            cin>>numberOfRolls;
            for (int executions=1; executions<=numberOfRolls; executions++)
            {
                sixSide=(rand()%6+1);
                cout<<setw(6)<<executions<<setw(12)<<sixSide<<endl;
            }
            break;
        }
        while (dieChoice==5)
        {
            int numberOfRolls;
            cin>>numberOfRolls;
            for (int executions=1; executions<=numberOfRolls; executions++)
            {
                eightSide=(rand()%8+1);
                cout<<setw(6)<<executions<<setw(12)<<eightSide<<endl;
            }
            break;
        }
        while (dieChoice==6)
        {
            int numberOfRolls;
            cin>>numberOfRolls;
            for (int executions=1; executions<=numberOfRolls; executions++)
            {
                tenSide=(rand()%10+1);
                cout<<setw(6)<<executions<<setw(12)<<tenSide<<endl;
            }
            break;
        }
        while (dieChoice==7)
        {
            int numberOfRolls;
            cin>>numberOfRolls;
            for (int executions=1; executions<=numberOfRolls; executions++)
            {
                twelveSide=(rand()%12+1);
                cout<<setw(6)<<executions<<setw(12)<<twelveSide<<endl;
            }
            break;
        }
        while (dieChoice==8)
        {
            int numberOfRolls;
            cin>>numberOfRolls;
            for (int executions=1; executions<=numberOfRolls; executions++)
            {
                twentySide=(rand()%20+1);
                cout<<setw(6)<<executions<<setw(12)<<twentySide<<endl;
            }
            break;
        }
    }
    while (dieChoice!=9);
}
int CombatGenerator()
{
    //enemy generation based on choice and number of enemy chosen by gm
    //combat rolls referred to DieRoller
    //health tracking for enemy and player
    //rewards of coin, exp, and/or items
}
int TrackerExperience()
{
    //track exp and level-ups
}
int TrackerInventory()
{
    //track all items, coin, ect.
}
int TrackerEquipment()
{
    //track equipped items including, weapons, armor, clothes, accessories, ect. along with their stats
}
int TrackerMagic()
{
    //track spells, enchantments, and preparation, ect.
}
int AttributeModification()
{
    switch(AttributeToBeModified)
    {
        case 1:
        AttributeModifier = -5;
        break;
        case 2:
        AttributeModifier = -4;
        break;
        case 3:
        AttributeModifier = -4;
        break;
        case 4:
        AttributeModifier = -3;
        break;
        case 5:
        AttributeModifier = -3;
        break;
        case 6:
        AttributeModifier = -2;
        break;
        case 7:
        AttributeModifier = -2;
        break;
        case 8:
        AttributeModifier = -1;
        break;
        case 9:
        AttributeModifier = -1;
        break;
        case 10:
        AttributeModifier = 0;
        break;
        case 11:
        AttributeModifier = 0;
        break;
        case 12:
        AttributeModifier = 1;
        break;
        case 13:
        AttributeModifier = 1;
        break;
        case 14:
        AttributeModifier = 2;
        break;
        case 15:
        AttributeModifier = 2;
        break;
        case 16:
        AttributeModifier = 3;
        break;
        case 17:
        AttributeModifier = 3;
        break;
        case 18:
        AttributeModifier = 4;
        break;
        case 19:
        AttributeModifier = 4;
        break;
        case 20:
        AttributeModifier = 5;
        break;
        case 21:
        AttributeModifier = 5;
        break;
        case 22:
        AttributeModifier = 6;
        break;
        case 23:
        AttributeModifier = 6;
        break;
        case 24:
        AttributeModifier = 7;
        break;
        case 25:
        AttributeModifier = 7;
        break;
        case 26:
        AttributeModifier = 8;
        break;
        case 27:
        AttributeModifier = 8;
        break;
        case 28:
        AttributeModifier = 9;
        break;
        case 29:
        AttributeModifier = 9;
        break;
        case 30:
        AttributeModifier = 10;
        break;
    }
}
int skillModAssignment()
{
    acrobatDex=modifierDex;
    animalHandleWis=modifierWis;
    arcanaInt=modifierInt;
    athleticStr=modifierStr;
    deceptionCha=modifierCha;
    historyInt=modifierInt;
    insightWis=modifierWis;
    intimidateCha=modifierCha;
    investigateInt=modifierInt;
    medicineWis=modifierWis;
    natureInt=modifierInt;
    perceptionWis=modifierWis;
    religionInt=modifierInt;
    handSlightDex=modifierDex;
    stealthDex=modifierDex;
    survivalWis=modifierWis;
}
int rollGeneratorAssignment()
{
    if (rollOptionFun==1)
    {
        attributeResult=rollAttr1;
        rollAttr1=0;
    }
    else if (rollOptionFun==2)
    {
        attributeResult=rollAttr2;
        rollAttr2=0;
    }
    else if (rollOptionFun==3)
    {
        attributeResult=rollAttr3;
        rollAttr3=0;
    }
    else if (rollOptionFun==4)
    {
        attributeResult=rollAttr4;
        rollAttr4=0;
    }
    else if (rollOptionFun==5)
    {
        attributeResult=rollAttr5;
        rollAttr5=0;
    }
    else if (rollOptionFun==6)
    {
        attributeResult=rollAttr6;
        rollAttr6=0;
    }
    else if (rollOptionFun==7)
    {
        attributeResult=rollAttr7;
        rollAttr7=0;
    }
}
int characterBarbarianMoney()
{
    srand((unsigned)time(0));
    startingMoney=(rand()%7+2)*10;
}
int characterBardMoney()
{
    srand((unsigned)time(0));
    startingMoney=(rand()%16+5)*10;
}
int characterClericMoney()
{
    srand((unsigned)time(0));
    startingMoney=(rand()%16+5)*10;
}
int characterDruidMoney()
{
    srand((unsigned)time(0));
    startingMoney=(rand()%7+2)*10;
}
int characterFighterMoney()
{
    srand((unsigned)time(0));
    startingMoney=(rand()%16+5)*10;
}
int characterMonkMoney()
{
    srand((unsigned)time(0));
    startingMoney=(rand()%16+5);
}
int characterPaladinMoney()
{
    srand((unsigned)time(0));
    startingMoney=(rand()%16+5)*10;
}
int characterRangerMoney()
{
    srand((unsigned)time(0));
    startingMoney=(rand()%16+5)*10;
}
int characterRogueMoney()
{
    srand((unsigned)time(0));
    startingMoney=(rand()%13+4)*10;
}
int characterSorcererMoney()
{
    srand((unsigned)time(0));
    startingMoney=(rand()%10+3)*10;
}
int characterWarlockMoney()
{
    srand((unsigned)time(0));
    startingMoney=(rand()%13+4)*10;
}
int characterWizardMoney()
{
    srand((unsigned)time(0));
    startingMoney=(rand()%13+4)*10;
}
int characterBarbarianHP()
{
    srand((unsigned)time(0));
    int counter=2;
    while (currentLevel==1)
    {
        hitPointMax=12+modifierCon;
        break;
    }
    for (counter; currentLevel>=counter; counter++)
    {
        int hitDice;
        counter=currentLevel;
        hitDice=(rand()%11+1)+modifierCon;
        hitPointMax+=hitDice;
    }
}
int characterBardHP()
{
    srand((unsigned)time(0));
    int counter=2;
    while (currentLevel==1)
    {
        hitPointMax=8+modifierCon;
        break;
    }
    for (counter; currentLevel>=counter; counter++)
    {
        int hitDice;
        counter=currentLevel;
        hitDice=(rand()%7+1)+modifierCon;
        hitPointMax+=hitDice;
    }
}
int characterClericHP()
{
    srand((unsigned)time(0));
    int counter=2;
    while (currentLevel==1)
    {
        hitPointMax=8+modifierCon;
        break;
    }
    for (counter; currentLevel>=counter; counter++)
    {
        int hitDice;
        counter=currentLevel;
        hitDice=(rand()%7+1)+modifierCon;
        hitPointMax+=hitDice;
    }
}
int characterDruidHP()
{
    srand((unsigned)time(0));
    int counter=2;
    while (currentLevel==1)
    {
        hitPointMax=8+modifierCon;
        break;
    }
    for (counter; currentLevel>=counter; counter++)
    {
        int hitDice;
        counter=currentLevel;
        hitDice=(rand()%7+1)+modifierCon;
        hitPointMax+=hitDice;
    }
}
int characterFighterHP()
{
    srand((unsigned)time(0));
    int counter=2;
    while (currentLevel==1)
    {
        hitPointMax=10+modifierCon;
        break;
    }
    for (counter; currentLevel>=counter; counter++)
    {
        int hitDice;
        counter=currentLevel;
        hitDice=(rand()%9+1)+modifierCon;
        hitPointMax+=hitDice;
    }
}
int characterMonkHP()
{
    srand((unsigned)time(0));
    int counter=2;
    while (currentLevel==1)
    {
        hitPointMax=8+modifierCon;
        break;
    }
    for (counter; currentLevel>=counter; counter++)
    {
        int hitDice;
        counter=currentLevel;
        hitDice=(rand()%7+1)+modifierCon;
        hitPointMax+=hitDice;
    }
}
int characterPaladinHP()
{
    srand((unsigned)time(0));
    int counter=2;
    while (currentLevel==1)
    {
        hitPointMax=1+modifierCon;
        break;
    }
    for (counter; currentLevel>=counter; counter++)
    {
        int hitDice;
        counter=currentLevel;
        hitDice=(rand()%9+1)+modifierCon;
        hitPointMax+=hitDice;
    }
}
int characterRangerHP()
{
    srand((unsigned)time(0));
    int counter=2;
    while (currentLevel==1)
    {
        hitPointMax=10+modifierCon;
        break;
    }
    for (counter; currentLevel>=counter; counter++)
    {
        int hitDice;
        counter=currentLevel;
        hitDice=(rand()%9+1)+modifierCon;
        hitPointMax+=hitDice;
    }
}
int characterRogueHP()
{
    srand((unsigned)time(0));
    int counter=2;
    while (currentLevel==1)
    {
        hitPointMax=8+modifierCon;
        break;
    }
    for (counter; currentLevel>=counter; counter++)
    {
        int hitDice;
        counter=currentLevel;
        hitDice=(rand()%7+1)+modifierCon;
        hitPointMax+=hitDice;
    }
}
int characterSorcererHP()
{
    srand((unsigned)time(0));
    int counter=2;
    while (currentLevel==1)
    {
        hitPointMax=6+modifierCon;
        break;
    }
    for (counter; currentLevel>=counter; counter++)
    {
        int hitDice;
        counter=currentLevel;
        hitDice=(rand()%5+1)+modifierCon;
        hitPointMax+=hitDice;
    }
}
int characterWarlockHP()
{
    srand((unsigned)time(0));
    int counter=2;
    while (currentLevel==1)
    {
        hitPointMax=8+modifierCon;
        break;
    }
    for (counter; currentLevel>=counter; counter++)
    {
        int hitDice;
        counter=currentLevel;
        hitDice=(rand()%7+1)+modifierCon;
        hitPointMax+=hitDice;
    }
}
int characterWizardHP()
{
    srand((unsigned)time(0));
    int counter=2;
    while (currentLevel==1)
    {
        hitPointMax=6+modifierCon;
        break;
    }
    for (counter; currentLevel>=counter; counter++)
    {
        int hitDice;
        counter=currentLevel;
        hitDice=(rand()%5+1)+modifierCon;
        hitPointMax+=hitDice;
    }
}
