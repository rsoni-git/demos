
class A {
  public:
    int iNum1;
    A ( int iNum2 ) {};
};


int main ( void ) {
  // Statuc
  A obj1(2);

  // Dynamic
  A &obj2 = *(new A(2));

  // Dynamic
  A *obj3 = new A(3);
}

