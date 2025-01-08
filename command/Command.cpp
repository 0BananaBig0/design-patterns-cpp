///////////////////////////////////////////////////////////////////////////
//  > File Name: Command.cpp
//  > Author: Huaxiao Liang
//  > Mail: 1184903633@qq.com
//  > Created Time: 01/08/2025-Wed-13:02:21
//  > Modified from: https://sourcemaking.com/design_patterns/command/cpp/2
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;

class Person;

class Command {
      // 1. Create a class that encapsulates an object and a member function
      // a pointer to a member function (the attribute's name is "_cmdAction")
      Person* _object;   //
      void ( Person::*_cmdAction )();

   public:
      explicit Command( Person* obj = nullptr,
                        void ( Person::*cmd_action )() = nullptr ) {
         _object = obj;   // the argument's name is "meth"
         _cmdAction = cmd_action;
      }

      void execute() {
         ( _object->*_cmdAction )();   // invoke the _cmdAction on the object
      }
};

class Person {
      string _name;

      // cmd is a "black box", it is a _cmdAction invocation
      // promoted to "full object status"
      Command _cmd;

   public:
      Person( string n, Command c ): _name( n ), _cmd( c ) {}

      void talk() {
         // "this" is the sender, cmd has the receiver
         cout << _name << " is talking" << endl;
         _cmd.execute();   // ask the "black box" to callback the receiver
      }

      void passOn() {
         cout << _name << " is passing on" << endl;

         // 4. When the sender is ready to callback to the receiver,
         // it calls execute()
         _cmd.execute();
      }

      void gossip() {
         cout << _name << " is gossiping" << endl;
         _cmd.execute();
      }

      void listen() { cout << _name << " is listening" << endl; }
};

int main() {
   // Fred will "execute" Barney which will result in a call to passOn()
   // Barney will "execute" Betty which will result in a call to gossip()
   // Betty will "execute" Wilma which will result in a call to listen()
   Person wilma( "Wilma", Command() );
   // 2. Instantiate an object for each "callback"
   // 3. Pass each object to its future "sender"
   Person betty( "Betty", Command( &wilma, &Person::listen ) );
   Person barney( "Barney", Command( &betty, &Person::gossip ) );
   Person fred( "Fred", Command( &barney, &Person::passOn ) );
   fred.talk();
}
