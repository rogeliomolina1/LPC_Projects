#include "Location.h"
#include "Item.h"
#include "Food.h"
#include <iostream>
#include <map>
using namespace std;

// Global variable
map<string, void(*)(string, Location *)> availableActions;

void RunGame(Location * location);
void ShowCommands();
void DoAction(string action, string target, Location * loc);
void GetInput(string & cmd, string & other);
void ProcessLook(string target, Location * loc);
void ProcessExamine(string target, Location * loc);
void ProcessEat(string target, Location * loc);
void SetupActions();


int main()
{
  Location * kitchen = new Location("Kitchen", "This is the kitchen.");

  Item * plate = new Item("plate", "A plain blue plate.");
  Item * fork = new Item("fork", "An ordinary metal fork.");
  Item * pie = new Food("pie", "A lemon custard pie", "lemony");

  kitchen->AddItem(plate);
  kitchen->AddItem(fork);
  kitchen->AddItem(pie);

  /*
  kitchen->ExamineItem("plate");
  kitchen->ExamineItem("fork");
  kitchen->ExamineItem("pie");
  kitchen->ExamineItem("cake"); /// Should tell me there is no cake here

  kitchen->EatFood("plate"); /// Should tell me the plate is not edible
  kitchen->EatFood("cake"); /// Should tell me (again) there is no cake here
  kitchen->EatFood("pie");
  */

  RunGame(kitchen);

}

void GetInput(string & cmd, string & other)
{
  string line;
  cout << "> ";
  getline(cin, line);
  line = Utility::ConvertToLowercase(line);
  size_t pos = line.find(" ");
  if (pos != string::npos)
    {
      cmd = line.substr(0, pos);
      other = line.substr(pos+1);
    }
  else
    {
      cmd = line;
      other = "";
    }

}

void RunGame(Location * location)
{
  SetupActions();
  string command;
  string name;
  cout << "\n";
  location->Describe();
  while (true)
    {
      cout << "\n";
      ShowCommands();
      GetInput(command, name);
      if (command == "q" || command == "quit")
	break;
      cout << "\n";
      DoAction(command, name, location);
    }
  cout << "\n        GAME OVER\n";
  cout << "   Thank you for playing!\n\n";
}

void ShowCommands()
{
  cout << "Commands: [L]ook, e[X]amine, [E]at, [Q]uit\n";
}

void SetupActions()
{
  availableActions["look"] = ProcessLook;
  availableActions["examine"] = ProcessExamine;
  availableActions["eat"] = ProcessEat;
  availableActions["l"] = ProcessLook;
  availableActions["x"] = ProcessExamine;
  availableActions["e"] = ProcessEat;
}

void DoAction(string action, string target, Location * loc)
{
  map<string, void(*)(string, Location *)>::iterator iter = availableActions.find(action);
  if (iter == availableActions.end())
    {
      cout << "*** There is no '" << action << "' command.\n";
      return;
    }
  iter->second(target, loc);
}

void ProcessLook(string target, Location * loc)
{
  if (target != "")
    cout << "*** Invalid command -- Type LOOK or L by itself.\n";
  else
    {
      loc->Describe();
    }
}

void ProcessExamine(string target, Location * loc)
{
  if (target == "")
    cout << "*** Invalid command -- EXAMINE __WHAT?__\n";
  else
    loc->ExamineItem(target);
}

void ProcessEat(string target, Location * loc)
{
  if (target == "")
    cout << "*** Invalid command -- EAT __WHAT?__\n";
  else
    loc->EatFood(target);
}
