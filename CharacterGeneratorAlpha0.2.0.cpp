#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;
int characterBarbarian();
int characterBard();
int characterCleric();
int characterDruid();
int characterFighter();
int characterMonk();
int characterPaladin();
int characterRanger();
int characterRogue();
int characterSorcerer();
int characterWarlock();
int characterWizard();
int startingMoney;
int main()
{
    string playerName, characterName, sex, race, alignment1, alignment2, Class, languagePrimary;
    int age, currentLevel, EXP,
    attributeStr, attributeDex, attributeCon, attributeInt, attributeWis, attributeCha,
    saveStr, saveDex, saveCon, saveInt, saveWis, saveCha,
    acrobatDex, animalHandleWis, arcanaInt, athleticStr, deceptionCha, historyInt,
    insightWis, intimidateCha, investigateInt, medicineWis, natureInt, perceptionWis,
    religionInt, handSlaightDex, stealthDex, survivalWis, armourClass,
    initiative, speed, hitPoints, hitDice,
    rollOptionStr, rollOptionDex, rollOptionCon, rollOptionInt, rollOptionWis, rollOptionCha;
    char creationOption, attributeOption, saveOption;

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

    switch (ClassChoice)
    {
        case 1 :
            Class = "Barbarian";
            characterBarbarian();
            break;
        case 2 :
            Class = "Bard";
            characterBard();
            break;
        case 3 :
            Class = "Cleric";
            break;
        case 4 :
            Class = "Druid";
            break;
        case 5 :
            Class = "Fighter";
            break;
        case 6 :
            Class = "Monk";
            break;
        case 7 :
            Class = "Paladin";
            break;
        case 8 :
            Class = "Ranger";
            break;
        case 9 :
            Class = "Rogue";
            break;
        case 10 :
            Class = "Sorcerer";
            break;
        case 11 :
            Class = "Warlock";
            break;
        case 12 :
            Class = "Wizard";
            break;
    }
    int languageChoice;
    cout<<"\n  Currently available Languages: ";
    cout<<"\n 1. Common\n 2. Dwarvish\n 3. Elvish\n 4. Giant\n 5. Gnomish\n 6. Goblin\n 7. Halfling\n 8. Orcish";
    cout<<"\n  Enter your character's first language: ";
    cin>>languageChoice;
    //languagePrimary
    switch (languageChoice)
    {
        case 1 :
        languagePrimary = "Common";
        break;
        case 2 :
        languagePrimary = "Dwarvish";
        break;
        case 3 :
        languagePrimary = "Elvish";
        break;
        case 4 :
        languagePrimary = "Giant";
        break;
        case 5 :
        languagePrimary = "Gnomish";
        break;
        case 6 :
        languagePrimary = "Goblin";
        break;
        case 7 :
        languagePrimary = "Halfling";
        break;
        case 8 :
        languagePrimary = "Orcish";
    }

    cout<<"\n  Enter your character's age: ";
    cin>>age;
    while (!cin)
    {
        cout<<"\n  ERROR: Your input must be numerical.\n";
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"\n  Enter your character's age: ";
        cin>>age;
    }
    cout<<"\n  Is your character new or based on a previously made character? (N/P) ";
    cin>>creationOption;
    while ((creationOption=='n')||(creationOption=='N'))
    {
        cout<<"\n  Would you like to generate or manually enter your attributes? (G/M) ";
        cin>>attributeOption;
        if ((attributeOption=='g')||(attributeOption=='G'))
        {
            int rollAttr1, rollAttr2, rollAttr3, rollAttr4, rollAttr5, rollAttr6, rollAttr7; //one extra roll to replace the weakest roll chosen by the user
            int chancePercent1, chancePercent2, chancePercent3, chancePercent4, chancePercent5,  chancePercent6, chancePercent7;
            int choiceAttr;
            srand((unsigned)time(0));                                                        //Set RanNumGen for the attributes    for(int index=0; index<1; index++)

            chancePercent1=(rand()%99+1);
            if (chancePercent1<=22)                          //22% chance for full range
                rollAttr1=(rand()%16+3);
            else if (chancePercent1<=98)                     //76% chance for higher range
                rollAttr1=(rand()%12+7);
            else if (chancePercent1<=100)                    //2% chance for no negative modifiers
                rollAttr1=(rand()%9+10);

            chancePercent2=(rand()%99+1);
            if (chancePercent2<=22)
                rollAttr2=(rand()%16+3);
            else if (chancePercent2>=21)
                rollAttr2=(rand()%12+7);
            else if (chancePercent2<=100)
                rollAttr2=(rand()%9+10);

            chancePercent3=(rand()%99+1);
            if (chancePercent3<=22)
                rollAttr3=(rand()%16+3);
            else if (chancePercent3>=21)
                rollAttr3=(rand()%12+7);
            else if (chancePercent3<=100)
                rollAttr3=(rand()%9+10);

            chancePercent4=(rand()%99+1);
            if (chancePercent4<=22)
                rollAttr4=(rand()%16+3);
            else if (chancePercent4>=21)
                rollAttr4=(rand()%12+7);
            else if (chancePercent4<=100)
                rollAttr4=(rand()%9+10);

            chancePercent5=(rand()%99+1);
            if (chancePercent5<=22)
                rollAttr5=(rand()%16+3);
            else if (chancePercent5>=21)
                rollAttr5=(rand()%12+7);
            else if (chancePercent5<=100)
                rollAttr5=(rand()%9+10);

            chancePercent6=(rand()%99+1);
            if (chancePercent6<=22)
                rollAttr6=(rand()%16+3);
            else if (chancePercent6>=21)
                rollAttr6=(rand()%12+7);
            else if (chancePercent6<=100)
                rollAttr6=(rand()%9+10);

            chancePercent7=(rand()%99+1);
            if (chancePercent7<=22)
                rollAttr7=(rand()%16+3);
            else if (chancePercent7>=21)
                rollAttr7=(rand()%12+7);
            else if (chancePercent7<=100)
                rollAttr7=(rand()%9+10);

            cout<<"  Roll One:   "<<rollAttr1<<endl;
            cout<<"  Roll Two:   "<<rollAttr2<<endl;
            cout<<"  Roll Three: "<<rollAttr3<<endl;
            cout<<"  Roll Four:  "<<rollAttr4<<endl;
            cout<<"  Roll Five:  "<<rollAttr5<<endl;
            cout<<"  Roll Six:   "<<rollAttr6<<endl;
            cout<<"  Roll Seven: "<<rollAttr7<<endl;
            cout<<"\n  Enter your selection using the number corresponding to the number of the roll for each of the following."; //ask which value should be assigned to which attribute
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
            if (rollOptionStr==1)
            {
                attributeStr=rollAttr1;
                rollAttr1=0;
            }
            else if (rollOptionStr==2)
            {
                attributeStr=rollAttr2;
                rollAttr2=0;
            }
            else if (rollOptionStr==3)
            {
                attributeStr=rollAttr3;
                rollAttr3=0;
            }
            else if (rollOptionStr==4)
            {
                attributeStr=rollAttr4;
                rollAttr4=0;
            }
            else if (rollOptionStr==5)
            {
                attributeStr=rollAttr5;
                rollAttr5=0;
            }
            else if (rollOptionStr==6)
            {
                attributeStr=rollAttr6;
                rollAttr6=0;
            }
            else if (rollOptionStr==7)
            {
                attributeStr=rollAttr7;
                rollAttr7=0;
            }
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
            if (rollOptionDex==1)
            {
                attributeDex=rollAttr1;
                rollAttr1=0;
            }
            else if (rollOptionDex==2)
            {
                attributeDex=rollAttr2;
                rollAttr2=0;
            }
            else if (rollOptionDex==3)
            {
                attributeDex=rollAttr3;
                rollAttr3=0;
            }
            else if (rollOptionDex==4)
            {
                attributeDex=rollAttr4;
                rollAttr4=0;
            }
            else if (rollOptionDex==5)
            {
                attributeDex=rollAttr5;
                rollAttr5=0;
            }
            else if (rollOptionDex==6)
            {
                attributeDex=rollAttr6;
                rollAttr6=0;
            }
            else if (rollOptionDex==7)
            {
                attributeDex=rollAttr7;
                rollAttr7=0;
            }
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
            if (rollOptionCon==1)
            {
                attributeCon=rollAttr1;
                rollAttr1=0;
            }
            else if (rollOptionCon==2)
            {
                attributeCon=rollAttr2;
                rollAttr2=0;
            }
            else if (rollOptionCon==3)
            {
                attributeCon=rollAttr3;
                rollAttr3=0;
            }
            else if (rollOptionCon==4)
            {
                attributeCon=rollAttr4;
                rollAttr4=0;
            }
            else if (rollOptionCon==5)
            {
                attributeCon=rollAttr5;
                rollAttr5=0;
            }
            else if (rollOptionCon==6)
            {
                attributeStr=rollAttr6;
                rollAttr6=0;
            }
            else if (rollOptionCon==7)
            {
                attributeCon=rollAttr7;
                rollAttr7=0;
            }
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
            if (rollOptionInt==1)
            {
                attributeInt=rollAttr1;
                rollAttr1=0;
            }
            else if (rollOptionInt==2)
            {
                attributeInt=rollAttr2;
                rollAttr2=0;
            }
            else if (rollOptionInt==3)
            {
                attributeInt=rollAttr3;
                rollAttr3=0;
            }
            else if (rollOptionInt==4)
            {
                attributeInt=rollAttr4;
                rollAttr4=0;
            }
            else if (rollOptionInt==5)
            {
                attributeInt=rollAttr5;
                rollAttr5=0;
            }
            else if (rollOptionInt==6)
            {
                attributeInt=rollAttr6;
                rollAttr6=0;
            }
            else if (rollOptionInt==7)
            {
                attributeInt=rollAttr7;
                rollAttr7=0;
            }
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
            if (rollOptionWis==1)
            {
                attributeWis=rollAttr1;
                rollAttr1=0;
            }
            else if (rollOptionWis==2)
            {
                attributeWis=rollAttr2;
                rollAttr2=0;
            }
            else if (rollOptionWis==3)
            {
                attributeWis=rollAttr3;
                rollAttr3=0;
            }
            else if (rollOptionWis==4)
            {
                attributeWis=rollAttr4;
                rollAttr4=0;
            }
            else if (rollOptionWis==5)
            {
                attributeWis=rollAttr5;
                rollAttr5=0;
            }
            else if (rollOptionWis==6)
            {
                attributeWis=rollAttr6;
                rollAttr6=0;
            }
            else if (rollOptionWis==7)
            {
                attributeWis=rollAttr7;
                rollAttr7=0;
            }
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
            if (rollOptionCha==1)
            {
                attributeCha=rollAttr1;
                rollAttr1=0;
            }
            else if (rollOptionCha==2)
            {
                attributeCha=rollAttr2;
                rollAttr2=0;
            }
            else if (rollOptionCha==3)
            {
                attributeCha=rollAttr3;
                rollAttr3=0;
            }
            else if (rollOptionCha==4)
            {
                attributeCha=rollAttr4;
                rollAttr4=0;
            }
            else if (rollOptionCha==5)
            {
                attributeCha=rollAttr5;
                rollAttr5=0;
            }
            else if (rollOptionCha==6)
            {
                attributeCha=rollAttr6;
                rollAttr6=0;
            }
            else if (rollOptionCha==7)
            {
                attributeCha=rollAttr7;
                rollAttr7=0;
            }
            cout<<"  Strength:     "<<attributeStr<<endl;
            cout<<"  Dexterity:    "<<attributeDex<<endl;
            cout<<"  Constitution: "<<attributeCon<<endl;
            cout<<"  Intelligence: "<<attributeInt<<endl;
            cout<<"  Wisdom:       "<<attributeWis<<endl;
            cout<<"  Charisma:     "<<attributeCha<<endl;
            break;
        }
        else if ((attributeOption=='m')||(attributeOption=='M'))
        {
            cout<<"  Enter Strength: ";                                  //Prompt for manual input of attributes to specific attribute
            cin>>attributeStr;
            while (!cin)
            {
                cout<<"\n  ERROR: Your input must be numerical.\n";
                cin.clear();
                cin.ignore(100,'\n');
                cout<<"\n  Enter Strength: ";
                cin>>attributeStr;
            }
            cout<<"  Enter Dexterity: ";
            cin>>attributeDex;
            while (!cin)
            {
                cout<<"\n  ERROR: Your input must be numerical.\n";
                cin.clear();
                cin.ignore(100,'\n');
                cout<<"\n  Enter Dexterity: ";
                cin>>attributeDex;
            }
            cout<<"  Enter Constitution: ";
            cin>>attributeCon;
            while (!cin)
            {
                cout<<"\n  ERROR: Your input must be numerical.\n";
                cin.clear();
                cin.ignore(100,'\n');
                cout<<"\n  Enter Constitution: ";
                cin>>attributeCon;
            }
            cout<<"  Enter Intelligence: ";
            cin>>attributeInt;
            while (!cin)
            {
                cout<<"\n  ERROR: Your input must be numerical.\n";
                cin.clear();
                cin.ignore(100,'\n');
                cout<<"\n  Enter Intelligence: ";
                cin>>attributeInt;
            }
            cout<<"  Enter Wisdom: ";
            cin>>attributeWis;
            while (!cin)
            {
                cout<<"\n  ERROR: Your input must be numerical.\n";
                cin.clear();
                cin.ignore(100,'\n');
                cout<<"\n  Enter Wisdom: ";
                cin>>attributeWis;
            }
            cout<<"  Enter Charisma: ";
            cin>>attributeCha;
            while (!cin)
            {
                cout<<"\n  ERROR: Your input must be numerical.\n";
                cin.clear();
                cin.ignore(100,'\n');
                cout<<"\n  Enter Charisma: ";
                cin>>attributeCha;
            }
        }
    }
    while ((creationOption=='p')||(creationOption=='P'))
    {
        cout<<"  Enter Strength: ";                                  //Prompt for manual input of attributes to specific attribute
        cin>>attributeStr;
        while (!cin)
        {
            cout<<"\n  ERROR: Your input must be numerical.\n";
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\n  Enter Strength: ";
            cin>>attributeStr;
        }
        cout<<"  Enter Dexterity: ";
        cin>>attributeDex;
        while (!cin)
        {
            cout<<"\n  ERROR: Your input must be numerical.\n";
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\n  Enter Dexterity: ";
            cin>>attributeDex;
        }
        cout<<"  Enter Constitution: ";
        cin>>attributeCon;
        while (!cin)
        {
            cout<<"\n  ERROR: Your input must be numerical.\n";
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\n  Enter Constitution: ";
            cin>>attributeCon;
        }
        cout<<"  Enter Intelligence: ";
        cin>>attributeInt;
        while (!cin)
        {
            cout<<"\n  ERROR: Your input must be numerical.\n";
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\n  Enter Intelligence: ";
            cin>>attributeInt;
        }
        cout<<"  Enter Wisdom: ";
        cin>>attributeWis;
        while (!cin)
        {
            cout<<"\n  ERROR: Your input must be numerical.\n";
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\n  Enter Wisdom: ";
            cin>>attributeWis;
        }
        cout<<"  Enter Charisma: ";
        cin>>attributeCha;
        while (!cin)
        {
            cout<<"\n  ERROR: Your input must be numerical.\n";
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\n  Enter Charisma: ";
            cin>>attributeCha;
        }
        break;
    }
    // Attribute modifier
    /* 1 == -5, 2-3 == -4, 4-5 ==-3, 6-7 == -2, 8-9 == -1, 10-11 == 0, 12-13 == 1, 14-15 == 2, 16-17 == 3, 18-19 == 4, 20-21 == 5,
    22-23 == 6, 24-25 == 7, 26-27 == 8, 28-29 == 9, 30 ==10*/
    int modifierStr=-6, modifierDex=-6, modifierCon=-6, modifierInt=-6, modifierWis=-6, modifierCha=-6;

    while (modifierStr==-6)
    {
        int AttributeToBeModified=attributeStr,
            AttributeModifier;
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
        modifierStr=AttributeModifier;
    }
    while (modifierDex==-6)
    {
        int AttributeToBeModified=attributeDex,
            AttributeModifier;
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
        modifierDex=AttributeModifier;
    }
    while (modifierCon==-6)
    {
        int AttributeToBeModified=attributeCon,
            AttributeModifier;
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
        modifierCon=AttributeModifier;
    }
    while (modifierInt==-6)
    {
        int AttributeToBeModified=attributeInt,
            AttributeModifier;
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
        modifierInt=AttributeModifier;
    }
    while (modifierWis==-6)
    {
        int AttributeToBeModified=attributeWis,
            AttributeModifier;
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
        modifierWis=AttributeModifier;
    }
    while (modifierCha==-6)
    {
        int AttributeToBeModified=attributeCha,
            AttributeModifier;
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
        modifierCha=AttributeModifier;
    }


    cout<<"\n  Player Name:    "<<playerName;
    cout<<"\n\n   Your Character Outline:\n\n";
    cout<<"\n  Name:           "<<characterName;
    cout<<"\n  Sex:            "<<sex;
    cout<<"\n  Race:           "<<race;
    cout<<"\n  Alignment:      "<<alignment1<<" "<<alignment2;
    cout<<"\n  Class:          "<<Class;
    cout<<"\n  Class Money     "<<startingMoney;
    cout<<"\n  Age:            "<<age;
    cout<<"\n    Attributes:"<<endl;
    cout<<"  Strength:         "<<attributeStr<<endl;
    cout<<"  Dexterity:        "<<attributeDex<<endl;
    cout<<"  Constitution:     "<<attributeCon<<endl;
    cout<<"  Intelligence:     "<<attributeInt<<endl;
    cout<<"  Wisdom:           "<<attributeWis<<endl;
    cout<<"  Charisma:         "<<attributeCha<<endl;
    cout<<modifierStr<<endl<<modifierDex<<endl<<modifierCon<<endl<<modifierInt<<endl<<modifierWis<<endl<<modifierCha<<endl;
    cout<<"\n  Would you like to save this character? (S/D)";
    cin>>saveOption;

    while ((saveOption=='D')||(saveOption=='d'))
    {
        char deleteCheck;
        cout<<"\n  Your character will be deleted and the program closed.";
        cout<<"\n  Are you sure? (Y/N)";
        cin>>deleteCheck;
        while ((deleteCheck=='Y')||(deleteCheck=='y'))
            return 0;
        while ((deleteCheck=='N')||(deleteCheck=='n'))
        {
            cout<<"\n  Would you like to save this character? (S/D)";
            cin>>saveOption;
            break;
        }
    }
    while ((saveOption=='S')||(saveOption=='s'))
    {
        ofstream CharGenOutput;
    CharGenOutput.open("D&DFifthCharacter.txt");
    CharGenOutput<<"\n  Player Name:    "<<playerName;
    CharGenOutput<<"\n\n   Your Character Outline:\n\n";
    CharGenOutput<<"\n  Name:           "<<characterName;
    CharGenOutput<<"\n  Sex:            "<<sex;
    CharGenOutput<<"\n  Race:           "<<race;
    CharGenOutput<<"\n  Alignment:      "<<alignment1<<" "<<alignment2;
    CharGenOutput<<"\n  Class:          "<<Class;
    CharGenOutput<<"\n  Age:            "<<age;
    CharGenOutput<<"\n    Attributes:"<<endl;
    CharGenOutput<<"  Strength:         "<<attributeStr<<endl;
    CharGenOutput<<"  Dexterity:        "<<attributeDex<<endl;
    CharGenOutput<<"  Constitution:     "<<attributeCon<<endl;
    CharGenOutput<<"  Intelligence:     "<<attributeInt<<endl;
    CharGenOutput<<"  Wisdom:           "<<attributeWis<<endl;
    CharGenOutput<<"  Charisma:         "<<attributeCha<<endl;
    cout<<"\n  Your character has been saved to a text file in the same folder this program is in.";
    cout<<"\n  Look for the file named \"D&DFifthCharacter\".";
    break;
    }

    cout<<"\n\n  Enter anything to close the program: ";
    string GTFO;
    cin>>GTFO;
    return 0;
}
int characterBarbarian()
{

    srand((unsigned)time(0));
    startingMoney=(rand()%7+2)*10;
}
int characterBard()
{

    srand((unsigned)time(0));
    startingMoney=(rand()%16+5)*10;
}
int characterCleric()
{

    srand((unsigned)time(0));
    startingMoney=(rand()%16+5)*10;
}
int characterDruid()
{

    srand((unsigned)time(0));
    startingMoney=(rand()%7+2)*10;
}
int characterFighter()
{

    srand((unsigned)time(0));
    startingMoney=(rand()%16+5)*10;
}
int characterMonk()
{

    srand((unsigned)time(0));
    startingMoney=(rand()%16+5);
}
int characterPaladin()
{

    srand((unsigned)time(0));
    startingMoney=(rand()%16+5)*10;
}
int characterRanger()
{

    srand((unsigned)time(0));
    startingMoney=(rand()%16+5)*10;
}
int characterRogue()
{

    srand((unsigned)time(0));
    startingMoney=(rand()%13+4)*10;
}
int characterSorcerer()
{

    srand((unsigned)time(0));
    startingMoney=(rand()%10+3)*10;
}
int characterWarlock()
{

    srand((unsigned)time(0));
    startingMoney=(rand()%13+4)*10;
}
int characterWizard()
{

    srand((unsigned)time(0));
    startingMoney=(rand()%13+4)*10;
}
