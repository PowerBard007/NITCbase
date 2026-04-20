git restore Disk/disk
git restore Disk/disk_run_copy

make
q1

 CREATE TABLE Numbers(key NUM)
 OPEN TABLE Numbers
 INSERT INTO Numbers values FROM numbers1.csv

 SELECT * FROM Numbers INTO BigNumbers WHERE key > 165000
 CREATE INDEX ON Numbers.key
 OPEN TABLE Numbers
SELECT * FROM Numbers INTO BigNums2 WHERE key > 165000
