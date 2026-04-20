 create table Events(id NUM, title STR, location STR)
 create table Locations(name STR, capacity NUM)
 create table Participants(regNo NUM, event STR)

 open table Events
 open table Locations
 open table Participants

  SELECT name FROM Locations JOIN Events INTO EventLocations WHERE Locations.name = Events.location

 SELECT * FROM Events INTO AudiEvents WHERE location=Audi
 OPEN TABLE AudiEvents
 SELECT regNo, event FROM Participants JOIN AudiEvents INTO AudiPeople WHERE Participants.event = AudiEvents.title
 SELECT * FROM Locations INTO MidLocations WHERE capacity>=100
 OPEN TABLE MidLocations
 SELECT * FROM MidLocations INTO SmallLocations WHERE capacity<=200
 OPEN TABLE SmallLocations
 SELECT * FROM Events JOIN SmallLocations INTO SmallEvents WHERE Events.location = SmallLocations.name
 OPEN TABLE SmallEvents
 SELECT regNo, event FROM Participants JOIN SmallEvents INTO MiniEventPeople WHERE Participants.event = SmallEvents.title
 exit

 Q2

# CREATE TABLE EventRating(id NUM, title STR, rating NUM);
Relation EventRating created successfully
# open table EventRating
Relation EventRating opened successfully
 # open table Events                                             
Relation Events opened successfully
# SELECT * FROM Events JOIN EventRating INTO LocRating WHERE Events.id = EventRating.id 
Error: Duplicate attributes found
# SELECT * FROM Events JOIN EventRating INTO LocRating WHERE Events.id = EventRating.name  
Error: Attribute does not exist
# SELECT * FROM Events JOIN EventRating INTO LocRating WHERE Events.id = EventRating.title  
Error: Mismatch in attribute type


q3

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


this was changed 
// ❌ BUG: hardcoded 100 causes out-of-bounds access
for (int i = MIDDLE_INDEX_INTERNAL + 1; i <= 100; i++)

// ✅ FIX:
for (int i = MIDDLE_INDEX_INTERNAL + 1; i <= MAX_KEYS_INTERNAL; i++)
