/*
 * C++ Design Patterns: Template Method
 * Author: Jakub Vojvoda [github.com/JakubVojvoda]
 * 2016
 *
 * Source code is licensed under MIT License
 * (for more details see LICENSE)
 *
 */

#include <iostream>

/*
 * AbstractClass
 * implements a template method defining the skeleton of an algorithm
 */
class TemplateClass {
   public:
      virtual ~TemplateClass() {}

      void templateUniqueMethod() {
         // ...
         criticalStep1();
         sharedStep1();
         // ...
         sharedStep2();
         critialStep2();
         // ...
      }

      void sharedStep1() {
         // ...
      };
      void sharedStep2() {
         // ...
      };
      // ...

      virtual void criticalStep1() = 0;
      virtual void critialStep2() = 0;
      // ...
};

/*
 * Concrete Algorithm Class
 * implements the critical steps of the algorithm,
 * there may be many Concrete classes, each implementing
 * the full set of the required steps
 */
class ConcreteAlgorithmClass: public TemplateClass {
   public:
      ~ConcreteAlgorithmClass() {}

      void criticalStep1() {
         std::cout << "Critical step 1" << std::endl;
         // ...
      }

      void critialStep2() {
         std::cout << "Critical step 2" << std::endl;
         // ...
      }

      // ...
};

int main() {
   TemplateClass* tm = new ConcreteAlgorithmClass;
   tm->templateUniqueMethod();

   delete tm;
   return 0;
}
