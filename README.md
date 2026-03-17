git restore Disk/disk
git restore Disk/disk_run_copy

make

Q1:
open table Locations
Insert into Locations Values(elhc, 300);
Insert into Locations Values(nlhc, 300);
Insert into Locations Values(eclc, 500);
Insert into Locations Values(pits, 150);
Insert into Locations Values(oat, 950);
Insert into Locations Values(audi, 1000); 
SELECT * FROM Locations INTO null WHERE capacity>0;
close table Locations
SELECT * FROM RELATIONCAT INTO null WHERE RelName=Locations;

Q2:
in xfs_interface
 Create table Events(id NUM, title STR, location STR)

in ./nitcbase
 open table Events
 Insert into Events Values from venues.csv
 Select * from Events into Null where id>0

Q3:

in xfs_interface
 create table Participants(regNo NUM, event STR)

in ./nitcbase
 open table Participants
 insert into Participants values (43, Ragam, ELHC)
 insert into Participants values (four, Ragam)  
 insert into RELATIONCAT values (test)   