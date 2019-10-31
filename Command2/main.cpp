#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Document
{
   vector<string> data;
public:
   Document()
   {
       data.reserve(100); // at least for 100 lines
   }

   void Insert( int line, const string & str )
   {
      if ( line <= data.size() )
         data.insert( data.begin() + line, str );
      else
         cout << "Error!" << endl;
   }

   void Remove( int line )
   {
      if( !( line>data.size() ) )
         data.erase( data.begin() + line );
      else
         cout << "Error!" << endl;
   }

   string & operator [] ( int x )
   {
      return data[x];
   }

   void Show()
   {
      for( int i = 0; i<data.size(); ++i )
      {
         cout << i + 1 << ". " << data[i] << endl;
      }
   }
};

class Command
{
protected:
   Document * doc;
public:
   virtual ~Command() {}
   virtual void Execute() = 0;
   virtual void unExecute() = 0;

   void setDocument( Document * _doc )
   {
      doc = _doc;
   }
};

class InsertCommand : public Command
{
   int line;
   string str;
public:
   InsertCommand( int _line, const string & _str ): line( _line ), str( _str ) {}

   void Execute()
   {
      doc->Insert( line, str );
   }

   void unExecute()
   {
      doc->Remove( line );
   }
};

class Invoker
{
   vector<Command*> DoneCommands;
   Document doc;
   Command* command;
public:
   void Insert( int line, string str )
   {
      command = new InsertCommand( line, str );
      command->setDocument( &doc );
      command->Execute();
      DoneCommands.push_back( command );
   }

   void Undo()
   {
      if( DoneCommands.size() == 0 )
      {
         cout << "There is nothing to undo!" << endl;
      }
      else
      {
         command = DoneCommands.back();
         DoneCommands.pop_back();
         command->unExecute();
         // Don't forget to delete command!!!
         delete command;
      }
   }

   void Show()
   {
      doc.Show();
   }
};

int main()
{
   char s = '1';
   int line, line_b;
   string str;
   Invoker inv;
   while( s!= 'e' )
   {
      cout << "What to do: \n1.Add a line\n2.Undo last command" << endl;
      cin >> s;
      switch( s )
      {
      case '1':
         cout << "What line to insert: ";
         cin >> line;
         --line;
         cout << "What to insert: ";
         cin >> str;
         inv.Insert( line, str );
         break;
      case '2':
         inv.Undo();
         break;
      }
      cout << "$$$DOCUMENT$$$" << endl;
      inv.Show();
      cout << "$$$DOCUMENT$$$" << endl;
   }
}
