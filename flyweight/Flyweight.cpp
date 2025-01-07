#include <iostream>
using namespace std;

// The shared part.
class Flyweight {
   public:
      explicit Flyweight( int shared_value_one ) {
         _mSharedValueOne = shared_value_one;
         cout << "ctor: " << _mSharedValueOne << '\n';
      }

      ~Flyweight() { cout << _mSharedValueOne << ' '; }

      void report( int unique_value_two ) {
         cout << _mSharedValueOne << unique_value_two << ' ';
      }

   private:
      int _mSharedValueOne;
};

class Factory {
   public:
      static Flyweight* getFly( int in ) {
         if( !_sPool[in] ) {
            _sPool[in] = new Flyweight( in );
         }
         return _sPool[in];
      }

      static void cleanUp() {
         cout << "dtors: ";
         for( int i = 0; i < _x; ++i ) {
            if( _sPool[i] ) {
               delete _sPool[i];
            }
         }
         cout << '\n';
      }

      static int _x, _y;

   private:
      static Flyweight* _sPool[];
};

int Factory::_x = 6, Factory::_y = 10;
Flyweight* Factory::_sPool[]
   = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };

int main() {
   for( int i = 0; i < Factory::_x; ++i ) {
      for( int j = 0; j < Factory::_y; ++j ) {
         // The unique part is computed by the client.
         Factory::getFly( i )->report( j );
      }
      cout << '\n';
   }
   Factory::cleanUp();
}
