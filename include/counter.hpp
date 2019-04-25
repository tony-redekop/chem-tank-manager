#ifndef CHEM_TANK_MANAGER_COUNTER_HPP_
#define CHEM_TANK_MANAGER_COUNTER_HPP_

#include <QObject>

class Counter : public QObject
{
  Q_OBJECT

  public: 
    Counter() { m_value = 0; }
    int value() const { return m_value; }

 // public slots:
    void setValue(int value);
 
  //signals:
    void valueChanged(int newValue);

  private:
    int m_value;
};

#endif  // header guard
