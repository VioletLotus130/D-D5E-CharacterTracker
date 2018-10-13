#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    system("color f0");

    string playerName, characterName, sex, race, alignment1, alignment2, Class, languagePrimary;
    int age, currentLevel, EXP,
    attributeStr, attributeDex, attributeCon, attributeInt, attributeWis, attributeCha,
    saveStr, saveDex, saveCon, saveInt, saveWis, saveCha,
    acrobatDex, animalHandleWis, arcanaInt, athleticStr, deceptionCha, historyInt,
    insightWis, intimidateCha, investigateInt, medicineWis, natureInt, perceptionWis,
    religionInt, handSlaightDex, stealthDex, survivalWis, armourClass,
    initiative, speed, hitPoints, hitDice,
    rollOptionStr, rollOptionDex, rollOptionCon, rollOptionInt, rollOptionWis, rollOptionCha;
    char creationOption, attributeOption;

    cout<<"\n  Dungeons & Dragons: Fifth Edition Character Creator\n";
    cout<<"\n  Enter your name: ";
    cin>>playerName;
    cout<<"\n  Enter your character's name: ";
    cin>>characterName;
    cout<<"\n  Enter your character's sex: ";
    cin>>sex;
    cout<<"\n  Currently available Races: ";
    cout<<"\n 1.  Aasimar\n 2.  Teifling\n 3.  Elf\n 4.  Human\n 5.  Half-Elf\n 6.  Halfling\n 7.  Dwarf\n 8.  Half-Orc\n 9.  Lizardfolk\n 10. Goblin\n 11. Gnome";
    cout<<"\n  Enter your character's race: ";
    cin>>race;
    cout<<"\n  Enter your character's first alignment.";
    cout<<"\n  Lawful, Neutral, or Chaotic: ";
    cin>>alignment1;
    cout<<"\n  Enter your character's second alignment.";
    cout<<"\n  Good, Neutral, or Evil: ";
    cin>>alignment2;
    cout<<"\n  Currently available Classes: ";
    cout<<"\n 1.  Barbarian\n 2.  Bard\n 3.  Cleric\n 4.  Druid\n 5.  Fighter\n 6.  Monk\n 7.  Paladin\n 8.  Ranger\n 9.  Rogue\n 10. Sorcerer\n 11. Warlock\n 12. Wizard";
    cout<<"\n  Enter your character's class: ";
    cin>>Class;
    cout<<"\n  Currently available Languages: ";
    cout<<"\n 1. Common\n 2. Dwarvish\n 3. Elvish\n 4. Giant\n 5. Gnomish\n 6. Goblin\n 7. Halfling\n 8. Orcish";
    cout<<"\n  Enter your character's first language: ";
    cin>>languagePrimary;
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
            int choiceAttr;
            srand((unsigned)time(0));                                                        //Set RanNumGen for the attributes
            for(int index=0; index<1; index++)
                rollAttr1=(rand()%14+4);
            for(int index=0; index<1; index++)
                rollAttr2=(rand()%14+4);
            for(int index=0; index<1; index++)
                rollAttr3=(rand()%14+4);
            for(int index=0; index<1; index++)
                rollAttr4=(rand()%14+4);
            for(int index=0; index<1; index++)
                rollAttr5=(rand()%14+4);
            for(int index=0; index<1; index++)
                rollAttr6=(rand()%14+4);
            for(int index=0; index<1; index++)
                rollAttr7=(rand()%14+4);
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
    }
    cout<<"\n  Player Name:    "<<playerName;
    cout<<"\n\n   Your Character Outline:\n\n";
    cout<<"\n  Name:           "<<characterName;
    cout<<"\n  Sex:            "<<sex;
    cout<<"\n  Race:           "<<race;
    cout<<"\n  Alignment:      "<<alignment1<<" "<<alignment2;
    cout<<"\n  Class:          "<<Class;
    cout<<"\n  Age:            "<<age;
    cout<<"\n    Attributes:"<<endl;
    cout<<"  Strength:         "<<attributeStr<<endl;
    cout<<"  Dexterity:        "<<attributeDex<<endl;
    cout<<"  Constitution:     "<<attributeCon<<endl;
    cout<<"  Intelligence:     "<<attributeInt<<endl;
    cout<<"  Wisdom:           "<<attributeWis<<endl;
    cout<<"  Charisma:         "<<attributeCha<<endl;
    cout<<"\n\n  Enter anything to close the program: ";
    string GTFO;
    cin>>GTFO;
    return 0;
}
