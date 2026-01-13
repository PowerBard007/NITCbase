/*#include "Buffer/StaticBuffer.h"
#include "Cache/OpenRelTable.h"
#include "Disk_Class/Disk.h"
#include "FrontendInterface/FrontendInterface.h"

int main(int argc, char *argv[]) 
{
  Disk disk_run;

  // create objects for the relation catalog and attribute catalog
  RecBuffer relCatBuffer(RELCAT_BLOCK);
  RecBuffer attrCatBuffer(ATTRCAT_BLOCK);

  HeadInfo relCatHeader;
  HeadInfo attrCatHeader;

  // load the headers of both the blocks into relCatHeader and attrCatHeader.
  // (we will implement these functions later)
  relCatBuffer.getHeader(&relCatHeader);
  attrCatBuffer.getHeader(&attrCatHeader);

  int i,j;

  for (i=0;i<;i++) {

    Attribute relCatRecord[RELCAT_NO_ATTRS]; // will store the record from the relation catalog

    relCatBuffer.getRecord(relCatRecord, i);

    printf("Relation: %s\n", relCatRecord[RELCAT_REL_NAME_INDEX].sVal);

    for (j=0;j<;j++) 
    {
      // declare attrCatRecord and load the attribute catalog entry into it

      if(/* attribute catalog entry corresponds to the current relation *) 
      {
        const char *attrType = attrCatRecord[ATTRCAT_ATTR_TYPE_INDEX].nVal == NUMBER ? "NUM" : "STR";
        printf("  %s: %s\n", /* get the attribute name *, attrType);
      }
    }
    printf("\n");
  }
  return 0;
}

*/

#include "Buffer/StaticBuffer.h"
#include "Cache/OpenRelTable.h"
#include "Disk_Class/Disk.h"
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {

  /* Initialize runtime disk */
  Disk disk_run;

  /* Buffers for relation and attribute catalogs */
  RecBuffer relCatBuffer(RELCAT_BLOCK);
  RecBuffer attrCatBuffer(ATTRCAT_BLOCK);

  HeadInfo relCatHeader;
  HeadInfo attrCatHeader;

  /* Read headers */
  relCatBuffer.getHeader(&relCatHeader);
  attrCatBuffer.getHeader(&attrCatHeader);

  /* Print relations and their attributes */
  for (int i = 0; i < relCatHeader.numEntries; i++) {

    /* Read relation catalog record */
    Attribute relCatRecord[RELCAT_NO_ATTRS];
    relCatBuffer.getRecord(relCatRecord, i);

    char *relName = relCatRecord[RELCAT_REL_NAME_INDEX].sVal;
    printf("Relation: %s\n", relName);

    /* Scan attribute catalog (single block only) */
    for (int j = 0; j < attrCatHeader.numEntries; j++) {

      Attribute attrCatRecord[ATTRCAT_NO_ATTRS];
      attrCatBuffer.getRecord(attrCatRecord, j);

      /* Match attributes belonging to the relation */
      if (strcmp(relName,
                 attrCatRecord[ATTRCAT_REL_NAME_INDEX].sVal) == 0) {

        const char *attrType =
            (attrCatRecord[ATTRCAT_ATTR_TYPE_INDEX].nVal == NUMBER)
                ? "NUM"
                : "STR";

        printf("  %s: %s\n",
               attrCatRecord[ATTRCAT_ATTR_NAME_INDEX].sVal,
               attrType);
      }
    }

    printf("\n");
  }

  return 0;
}