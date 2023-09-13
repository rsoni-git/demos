/*
 * @Func: Demonstration of singleton class
 */


#include <iostream>

using namespace std;

// Demonstration pointer method
class SingletonClass {
  private:
    // Declare member pointer variable of class type
    static SingletonClass* m_pSingletonClass;

    // Disable constructor
    SingletonClass ( void ) {}

    // Disable destructor
    ~SingletonClass ( void ) {}

  public:
    static SingletonClass* getInstance ( void ) {
      if ( ! m_pSingletonClass )
        m_pSingletonClass = new SingletonClass();

      return m_pSingletonClass;
    }

    void print ( void ) {
      cout << "Print this message from SingletonClass::print()" << endl;
    }

};


// Demonstration meyer method
class SingletonClassMeyer {
  private:
    // Disable constructor
    SingletonClassMeyer ( void ) {}

    // Disable Destructor
    ~SingletonClassMeyer ( void ) {}

    // Disable copy constructor
    SingletonClassMeyer(const SingletonClassMeyer&) = delete;

    // Disable assignment operator
    SingletonClassMeyer& operator = (const SingletonClassMeyer&) = delete;

  public:
    static SingletonClassMeyer& getInstance ( void ) {
      static SingletonClassMeyer objSingletonClassMeyer;
      return objSingletonClassMeyer;
    }

    void print ( void ) {
      cout << "Print this message from SingletonClassMeyer::print()" << endl;
    }
};

SingletonClass* SingletonClass::m_pSingletonClass = nullptr;

int main ( void ) {
  SingletonClass::getInstance()->print();

  SingletonClassMeyer::getInstance().print(); 
}

