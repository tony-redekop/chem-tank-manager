#include "counter.hpp"

void Counter::setValue(int value)
{
  if(value != m_value) {
    m_value = value;
   // emit valueChanged(value);
  }
}

int main(int argc, char *argv[])
{
  Counter a;
  Counter b;
 // QObject::connect(&a, &Counter::valueChanged,
  //                 &b, &Counter::setValue);
  return 0;
}

  

