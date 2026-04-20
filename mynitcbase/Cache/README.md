 Q1
 create table Events(id NUM, title STR, location STR)
 create table Locations(name STR, capacity NUM)
 create table Participants(regNo NUM, event STR)

 insert into Participants values from participants.csv
 insert into Locations values from locations.csv
 insert into Events values from events.csv

 open table Locations 
 open table Events   
 open table Participants
# SELECT name FROM Locations JOIN Events INTO EventLocations WHERE Locations.name = Events.location

 SELECT * FROM Events INTO AudiEvents WHERE location=Audi
OPEN TABLE AudiEvents
OPEN TABLE Participants
SELECT regNo, event FROM Participants JOIN AudiEvents INTO AudiPeople WHERE Participants.event = AudiEvents.title

OPEN TABLE Locations
SELECT * FROM Locations INTO MidLocations WHERE capacity>=100
OPEN TABLE MidLocations
SELECT * FROM MidLocations INTO SmallLocations WHERE capacity<=200
OPEN TABLE SmallLocations
OPEN TABLE Events
SELECT * FROM Events JOIN SmallLocations INTO SmallEvents WHERE Events.location = SmallLocations.name
OPEN TABLE SmallEvents
OPEN TABLE Participants
SELECT regNo, event FROM Participants JOIN SmallEvents INTO MiniEventPeople WHERE Participants.event = SmallEvents.title


 Q2
 CREATE TABLE EventRating(id NUM, title STR, rating NUM)
OPEN TABLE Events
OPEN TABLE EventRating
SELECT * FROM Events JOIN EventRating INTO LocRating WHERE Events.id = EventRating.id
SELECT * FROM Events JOIN EventRating INTO LocRating WHERE Events.id = EventRating.name
SELECT * FROM Events JOIN EventRating INTO LocRating WHERE Events.id = EventRating.title


 Q3
CREATE TABLE Organizers(name STR, eventId NUM)
OPEN TABLE Organizers
INSERT INTO Organizers VALUES FROM organizers.csv
OPEN TABLE Participants
OPEN TABLE Events
SELECT * FROM Participants JOIN Events INTO ParticipantEvents WHERE Participants.event = Events.title
OPEN TABLE ParticipantEvents
OPEN TABLE Organizers
SELECT regNo, event, location, name FROM ParticipantEvents JOIN Organizers INTO ParticipantInfo WHERE ParticipantEvents.id = Organizers.eventId
OPEN TABLE Organizers
SELECT * FROM Organizers INTO ThomasOrg WHERE name=Thomas
OPEN TABLE ThomasOrg
OPEN TABLE Events
SELECT * FROM ThomasOrg JOIN Events INTO ThomasEvents WHERE ThomasOrg.eventId = Events.id
OPEN TABLE ThomasEvents
OPEN TABLE Participants
SELECT regNo, event FROM Participants JOIN ThomasEvents INTO ThomasParticipants WHERE Participants.event = ThomasEvents.title
