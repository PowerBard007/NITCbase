Q1 
fdisk 
exit

run s11.txt 
exit 

schema S11_Students
export S11_c_Students c_students.csv
export S11_9_Students 9_students.csv

Q2

create index on RELATIONCAT.RelName
drop index on S11_Students.name
open table S11_Students    
drop index on S11_Students.name