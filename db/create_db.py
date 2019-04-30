import sqlite3
import datetime
import numpy as np

connection = sqlite3.connect("database.db")

cursor = connection.cursor()

# create the schema for our database

schema = [
  """drop table if exists T1;""",
  """drop table if exists T2;""",
  """drop table if exists T3;""",
  """drop table if exists T4;""",
  """drop table if exists T5;""",
  """drop table if exists T6;""",
  """create table T1(tankName text, date date, temp float, turco float);""",
  """create table T2(tankName text, date date, temp float);""",
  """create table T3(tankName text, date date, temp float, etchRateTi64 float,
                     etchRateTi6242 float, dissolvedTi float, HF float, HNO3 float);""",
  """create table T4(tankName text, date date, temp float);""",
  """create table T5(tankName text, date date, temp float, HNO3 float);""",
  """create table T6(tankName text, date date, temp float);"""]

for command in schema:
  cursor.execute(command)

# populate the tables using random, normally distributed variates
# a mean and a standard deviation is required to generate each variate

data = []
startDate = datetime.date(2018, 1, 1).toordinal()

for count in range(0, 364):
  recordDate = datetime.date.fromordinal(startDate + count).strftime("%m/%d/%Y")

  # populate T1
  temp = np.random.normal(190, .5)
  temp = str(round(temp, 2))
  turco = np.random.normal(10, .1)
  turco = str(round(turco,2)) 
  data.append( 
    """insert into T1 values ('Degrease',""" + "'" + recordDate + "'," + str(temp) + "," + str(turco) + ");")

  # populate T2
  temp = np.random.normal(64, .1)
  temp = str(round(temp, 2))
  data.append( 
    """insert into T2 values ('Rinse',""" + "'" + recordDate + "'," + str(temp) + ");")
  
  # populate T3
  temp = np.random.normal(67, .5)
  temp = str(round(temp, 2))
  etchRateTi64 = np.random.normal(220, .8)
  etchRateTi64 = str(round(etchRateTi64)) 
  etchRateTi6242 = np.random.normal(215, .6)
  etchRateTi6242 = str(round(etchRateTi6242)) 
  dissolvedTi = np.random.normal(7, .1)
  dissolvedTi = str(round(dissolvedTi, 2))
  HF = np.random.normal(2, .1)
  HF = str(round(HF, 2))
  HNO3 = np.random.normal(32, .1)
  data.append( 
    """insert into T3 values ('Etch',""" + "'" + recordDate + "'," + str(temp) + "," + str(etchRateTi64) + 
    """,""" + str(etchRateTi6242) + "," + str(dissolvedTi) + "," + str(HF) + "," + str(HNO3) + ");")

  # populate T4
  temp = np.random.normal(64, .1)
  temp = str(round(temp, 2))
  data.append( 
    """insert into T4 values ('Rinse',""" + "'" + recordDate + "'," + str(temp) + ");")

  # populate T5
  temp = np.random.normal(64, .1)
  temp = str(round(temp, 2))
  HNO3 = np.random.normal(43, .1)
  HNO3 = str(round(HNO3, 2))
  data.append( 
    """insert into T5 values ('Desmut',""" + "'" + recordDate + "'," + str(temp) + "," + str(HNO3) + ");")
 
  # populate T6
  temp = np.random.normal(64, .1)
  temp = str(round(temp, 2))
  data.append( 
    """insert into T6 values ('Rinse',""" + "'" + recordDate + "'," + str(temp) + ");")

for command in data:
  cursor.execute(command)

connection.commit()

connection.close()
